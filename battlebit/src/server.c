//
// Created by carson on 5/20/20.
//


// TODO: added pthread locks into file
#include "stdio.h"
#include "stdlib.h"
#include "server.h"
#include "char_buff.h"
#include "game.h"
#include "repl.h"
#include "pthread.h"
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h>    //inet_addr
#include<unistd.h>    //write
#include <stdio.h>
#include <netinet/in.h>
static game_server *SERVER;

void init_server() {            // initialize game server struct
    if (SERVER == NULL) {
        SERVER = calloc(1, sizeof(struct game_server));
    } else {
        printf("Server already started");
    }
}


int handle_client_connect(int player) {
    pthread_mutex_t unlock;
    int client_socket_fd = SERVER->player_sockets[player];

    char raw_buffer[2000];
    char_buff *input_buffer = cb_create(2000);
    char_buff *output_buffer = cb_create(2000);

    int read_size;
    cb_append(output_buffer, "\nbattleBit (? for help) > ");
    cb_write(client_socket_fd, output_buffer);

    while ((read_size = recv(client_socket_fd, raw_buffer, 2000, 0)) > 0) {
        cb_reset(output_buffer);
        cb_reset(input_buffer);
        if (read_size > 0) {
            raw_buffer[read_size] = '\0';

            pthread_mutex_unlock(&unlock);
            cb_append(input_buffer, raw_buffer);

            char *command = cb_tokenize(input_buffer, " \r\n");
            if (strcmp(command, "help") == 0) {
                cb_append(output_buffer, "A useful help message...");
                cb_append(output_buffer, command);

                cb_write(client_socket_fd, output_buffer);
            } else if (strcmp(command, "quit") == 0) {
                close(client_socket_fd);
            } else if (command != NULL) {
                cb_append(output_buffer, "Command was : ");
                cb_append(output_buffer, command);

                cb_write(client_socket_fd, output_buffer);
            }
            cb_reset(output_buffer);
            cb_append(output_buffer, "\nbattleBit (? for help) > ");
            cb_write(client_socket_fd, output_buffer);
            server_broadcast(input_buffer);
        }
    }
}
void server_broadcast(char_buff *msg) {
    // say command
    handle_client_connect(msg);
    // TODO: send message to all players using client sockets
    // player sockets and administrative console
        // that's why you have an array of player sockets

}

int run_server() {
    pthread_mutex_t lock;

    int server_socket_fd = socket(AF_INET,
                                  SOCK_STREAM,
                                  IPPROTO_TCP);
    if (server_socket_fd == -1) {
        printf("Could not create socket\n");
    }

    int yes = 1;
    setsockopt(server_socket_fd,
               SOL_SOCKET,
               SO_REUSEADDR, &yes, sizeof(yes));

    struct sockaddr_in server;

    // fill out the socket information
    server.sin_family = AF_INET;
    // bind the socket on all available interfaces
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(9876);

    int request = 0;
    if (bind(server_socket_fd,
            // Again with the cast
             (struct sockaddr *) &server,
             sizeof(server)) < 0) {
        puts("Bind failed");
    } else {
        puts("Bind worked!");
        listen(server_socket_fd, 88);

        //Accept an incoming connection
        puts("Waiting for incoming connections...");


        struct sockaddr_in client;
        socklen_t size_from_connect;
        int client_socket_fd;
        int player = 0;

        while ((client_socket_fd == accept(server_socket_fd,
                                          (struct sockaddr *) &client,
                                          &size_from_connect)) > 0) {
            SERVER->player_sockets[player] = pthread_create((pthread_t *) &SERVER->player_threads, NULL, (void *) run_server(), player);
            player++;
            if (player > 1) {
                break;
            }
        }
    }
    pthread_mutex_lock(&lock);
}

int server_start() {

    init_server();
    pthread_create(&SERVER->server_thread, NULL, (void *) run_server(), NULL);

}
