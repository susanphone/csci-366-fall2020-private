//
// Created by carson on 5/20/20.
//

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


// repl.c  : void repl_execute_command
// At this point we will have updated player_socket with the socket we create in step 8
// keep track of which player with count. increment the counter
// each player has a thread. both players can interact with the server at the same time.
// pass in a player integer
int handle_client_connect(int player) {
    /**TODO: STEP 9 - This is the big one: you will need to re-implement the REPL code from
     * the repl.c file, but with a twist: you need to make sure that
     * TODO: a player only fires when the game is initialized and it is there turn.
     * TODO:They can broadcast a message whenever, but they can't just shoot unless it is their turn.
     * The commands will obviously not take a player argument, as with the system level
     * REPL, but they will be similar: load, fire, etc.
     * TODO: You must broadcast informative messages after each shot (HIT! or MISS!) and let
     * the player print out their current board state at any time.
     * This function will end up looking a lot like repl_execute_command, except you will
     * be working against network sockets rather than standard out, and
     * TODO: you will need to coordinate turns via the game::status field.
     */
    char_buff buffer[110];
    char *command = cb_tokenize(buffer, " \n");
    if (command) {
        // TODO: Loop reading commands
        char *arg1 = cb_next_token(buffer);
        char *arg2 = cb_next_token(buffer);
        char *arg3 = cb_next_token(buffer);
        if (strcmp(command, "exit") == 0) {
            printf("goodbye!");
            exit(EXIT_SUCCESS);
        } else if (strcmp(command, "?") == 0) {
            printf("? - show help\n");
            // TODO: output a command prompt
            // TODO: Know Which player, Load isn't option. Load ships or fire
//            printf("load [0-1] <string> - load a ship layout file for the given player\n");
//            printf("show [0-1] - shows the board for the given player\n");
//            printf("fire [0-1] [0-7] [0-7] - fire at the given position\n");
            // Todo: output what happened
            printf("say <string> - Send the string to all players as part of a chat\n");
            printf("reset - reset the game\n");
            printf("server - start the server\n");
            printf("exit - quit the server\n");
        } else if (strcmp(command, "server") == 0) {
            server_start();
        } else if (strcmp(command, "show") == 0) {

            // work with repl_print_board

        } else if (strcmp(command, "reset") == 0) {

            game_init();

        } else if (strcmp(command, "load") == 0) {

            // work with game_load_board

        } else if (strcmp(command, "fire") == 0) {

            // work with game_fire
        } else if (strcmp(command, "shortcut") == 0) {
            // update player 1 to only have a single ship in position 0, 0
            game_get_current()->players[1].ships = 1ull;
        } else {
            printf("Unknown Command: %s\n", command);
        }
    }
}

void server_broadcast(char_buff *msg) {
    // TODO: send message to all players
    // player sockets and administrative console
        // that's why you have an array of player sockets

}

int run_server() {
/**TODO: STEP 8 - implement the server code to put this on the network.
 * Here you will need to initialize a server socket and wait for incoming connections.
 *
 * When a connection occurs, store the corresponding new client socket in the SERVER.player_sockets array
 * as the corresponding player position.
 *
 * You will then create a thread running handle_client_connect, passing the player number out
 * so they can interact with the server asynchronously
 */
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
        int request_count = 0;
        // first client to connect player 1 and second client to connect is player 1
        // TODO: within the while loop call pthread_create function
        // within loop we accept new connections
        // when connection occurs, add a client socket, and create a pthread
        while ((client_socket_fd = accept(server_socket_fd,
                                          (struct sockaddr *) &client,
                                          &size_from_connect)) > 0) {
            char message[100] = {0};
            // the pthread is responsible for interacting with the client (accepting commands and showing output)
            //TODO: Spin off another thread
            //TODO: Accept commands and show output
            //TODO: call handle_client_connect
            pthread_t player1;
            pthread_create(&player1, NULL, run_server, NULL);
            send(client_socket_fd, message,
                 strlen(message), 0);
            close(client_socket_fd);
        }
    }
}

int server_start() {
    // Hard Part but 70% of grade is passing tests :)
    // TODO: create a p_thread and set it in to server_thread
    /**TODO: STEP 7 - using a pthread, run the run_server() function asynchronously, so you can still
     * interact with the game via the command line REPL
     */
    // Concurrency.c
    // TODO: store into server struct
    // pthread: path threads, two players on different threads. 
    pthread_t player1, player2;
    // TODO: Create a pthread struct pthread_create
    pthread_create(&player1, NULL, run_server, 0);
    pthread_create(&player2, NULL, run_server, 1);
    pthread_join(player2, NULL);
    //TODO: pass in a pointer for execute that thread
    init_server();
    //TODO: run function in that thread
}
