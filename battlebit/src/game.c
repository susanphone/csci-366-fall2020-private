//
// Created by carson on 5/20/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include <ctype.h>

/**TODO: STEP 10 - Synchronization: the GAME structure will be accessed by both players interacting
 * asynchronously with the server.  Therefore the data must be protected to avoid race conditions.
 * Add the appropriate synchronization needed to ensure a clean battle.
 */

static game * GAME = NULL;

void game_init() {
    if (GAME) {
        free(GAME);
    }
    GAME = malloc(sizeof(game));
    GAME->status = CREATED;
    game_init_player_info(&GAME->players[0]);
    game_init_player_info(&GAME->players[1]);
}

void game_init_player_info(player_info *player_info) {
    player_info->ships = 0;
    player_info->hits = 0;
    player_info->shots = 0;
}

int game_fire(game *game, int player, int x, int y) {
    // Tricky code but not a lot of code
    int opponent = (player + 1) % 2; // stupid trick in C: add one mode by 2
    // ^- lets you flip between players


    unsigned long long var = xy_to_bitval(x, y); // going to hit here

    // TODO: record there was a shot
    // TODO: check if this is a hit or miss, call repl_print_hits
    // look at xy and see if there is something there
        // go and update the game boards. call repl here
    // TODO: remove the bit in the other players board
    // bitmask to update the bit in player_info
    /**Step 5 - This is the crux of the game.
     * You are going to take a shot from the given player and
     TODO: update all the bit values that store our game state.
        * - You will need up update the players 'shots' value
        * - you You will need to see if the shot hits a ship in the opponents ships value.
     If so, record a hit in the current players hits field
     * - If the shot was a hit, TODO: you need to flip the ships value to 0 at that position for the opponents ships field
     * If the opponents ships value is 0, they have no remaining ships, and
     * TODO: you should set the game state to PLAYER_1_WINS or PLAYER_2_WINS depending on who won.
     */
     // did the person win on this turn of not?
}

unsigned long long int xy_to_bitval(int x, int y) {
    // bounds
    if (x > 7 || y > 7 || x < 0 || y < 0) {
        return 0;
    }
    // math formula to bit shift
    return 1ull << (8 * y) + x;
}

struct game * game_get_current() {
    return GAME;
}

int game_load_board(struct game *game, int player, char * spec) {

// big ugly function; 30 Lines of code
// TODO: Load a string of characters in the board
// TODO: Grab ship field. return 1 for valid, -1 for not valid
// TODO: Loop through each spec make sure sure boats stay in bounds(Example board: C00b02D23S47p71)
    // 1. Look at character, three at a time
    // 2. Look at xy and upper or lowercase
    // 3. is it a valid point?
    // 4. HINT: add_ship_horizontal and add_ship_vertical as recursive method for adding ship to bit value
    /** Step 2 - implement this function.
     * Here you are taking a C
     * string that represents a layout of ships,
     * TODO: then testing to see if it is a valid layout (no off-the-board positions
     * and no overlapping ships) *
     * if it is valid, TODO: you should write the corresponding unsigned
     * long long value into the Game->players[player].ships data
     * slot and return 1 *
     * if it is invalid, TODO: you should return -1
     */
    if (spec == NULL){
        return -1;
    }
    bool isTakenB = false;
    bool isTakenC = false;
    bool isTakenD = false;
    bool isTakenP = false;
    bool isTakenS = false;

    for (int i = 0; i < 15; i++) {
        if (!isdigit(spec[i+1]) || !isdigit(spec[i+2])) {
            return -1;
        }
        if (spec[i] == NULL) {
            return -1;
        }
        char temp = tolower(spec[i]);
        int lengthOfShip;
        switch (temp) {
            case 'c':
                lengthOfShip = 5;
                if (isTakenC) {
                    return -1;
                } else {
                    isTakenC = true;
                }
            case 'b':
                lengthOfShip = 4;
                if (isTakenB) {
                    return -1;
                } else {
                    isTakenB = true;
                }
            case 's':
                lengthOfShip = 3;
                if (isTakenS) {
                    return -1;
                } else {
                    isTakenS = true;
                }
            case 'd':
                lengthOfShip = 3;
                if (isTakenD) {
                    return -1;
                } else {
                    isTakenD = true;
                }
            case 'p':
                lengthOfShip = 2;
                if (isTakenP) {
                    return -1;
                } else {
                    isTakenP = true;
                }
            default:
                lengthOfShip = 0;
        }
        if (spec[i] >= 'A' && spec[i] <= 'Z') {
            add_ship_horizontal(player, spec[i+1], spec[i+2], lengthOfShip);
            i = i+2;
        } else {
            add_ship_vertical(player, spec[i+1], spec[i+2], lengthOfShip);
            i = i+2;
        }
    }
}

int add_ship_horizontal(player_info *player, int x, int y, int length) {
    // cannot be added
    if (x > 7 || y > 7 || x < 0 || y < 0 ||length ==0) {
        return -1;
    }
    if (length == 1 && x < 7 && y < 7) { //base case
        return 1;
    }
    add_ship_horizontal(player, x+1, y, length-1);

    /** TODO: implement this as part of Step 2
     * returns 1 if the ship can be added, -1 if not
     * hint: this can be defined recursively
     */
}

int add_ship_vertical(player_info *player, int x, int y, int length) {
    if (x > 7 || y > 7 || x < 0 || y < 0 ||length ==0) {
        return -1;
    }
    if (length == 1 && x < 7 && y < 7) { //base case
        return 1;
    }
    add_ship_vertical(player, x, y+1, length-1);
    /** TODO: implement this as part of Step 2
     * returns 1 if the ship can be added, -1 if not
     * hint: this can be defined recursively
     */

}