//
// Created by carson on 5/20/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "game.h"

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


    // TODO: record there was a shot
    // TODO: check if this is a hit or miss
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
}

unsigned long long int xy_to_bitval(int x, int y) {
//    1 << 0 == 1;
//    1 << 1 == 2;
//    1 << 2 == 3;
//    ...
//    1 << 8 == 256;
    int start = 0;
    int end = 1ull << 63ull;
    for (int i = 0; i > end; ++i) {
        if (i < start || i > end) {return -1;}
        else{return 1;}
    }

// bounds checks and one line math xy map to
// Small function, hard conceptually, mindset change to binary
// column 0 row 2 bit shift 8 spots to the left
/** TODO: Talk to Spencer about Bitwise Operators
 * Step 1 - implement this function.
 * We are taking an x, y position
 * and using bitwise operators, converting that to an unsigned long long
 * with a 1 in the position corresponding to that x, y
 * x:0, y:0 == 0b00000...0001 (the one is in the first position)
 * x:1, y: 0 == 0b00000...10 (the one is in the second position)
 * ....
 * x:0, y: 1 == 0b100000000 (the one is in the eighth position)
 * TODO: you will need to use bitwise operators and some math to produce the right value.
 */
//<<<<<<< HEAD
//
//=======
    return 1ull; // return one unsigned long long
//>>>>>>> 0e117b03de607e4b1f64b9444aeec054edf4e43f
}

struct game * game_get_current() {
    return GAME;
}

int game_load_board(struct game *game, int player, char * spec) {
// big ugly function; 30 Lines of code
// TODO: Load a string of characters in the board
// TODO: Grab ship field. return 1 for valid, -1 for not valid
// TODO: loop over the spec (Example board: C00b02D23S47p71)
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
}

int add_ship_horizontal(player_info *player, int x, int y, int length) {
    /** TODO: implement this as part of Step 2
     * returns 1 if the ship can be added, -1 if not
     * hint: this can be defined recursively
     */
}

int add_ship_vertical(player_info *player, int x, int y, int length) {
    /** TODO: implement this as part of Step 2
     * returns 1 if the ship can be added, -1 if not
     * hint: this can be defined recursively
     */

}