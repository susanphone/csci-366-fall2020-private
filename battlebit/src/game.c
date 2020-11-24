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
 // done by inspections
 // mutex in file and log all interactions
 // create a lock and sync to game state
 pthread_mutex_lock();

static game *GAME = NULL;

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

    int opponent = (player + 1) % 2; // stupid trick in C: add one mod by 2
    // ^- lets you flip between players
    game->players[player].ships;
//    game_init_player_info((player_info *) opponent);

    //empty_game
    if (game->status != INITIALIZED) {
        return 0;
    }
    //game status
    if (game->players[0].ships == 0) {
        game->status = PLAYER_0_WINS;
    } else if (game->players[1].ships == 0){
        game->status = PLAYER_1_WINS;
    }
    if (opponent == 0) {
        game->status = PLAYER_0_TURN;
    } else if (opponent == 1) {
        game->status = PLAYER_1_TURN;
    }

    // BOUNDS
    if (x > 7 || y > 7 || x < 0 || y < 0) {
        return 0;
    }

    if (xy_to_bitval(x, y) != 0ULL) {
//        game->players[player].ships;
        return 1;
    } else {
        //update game
        return 0;
    }

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

    // check game over boolean
}

unsigned long long int xy_to_bitval(int x, int y) {
    // bounds
    if (x > 7 || y > 7 || x < 0 || y < 0) {
        return 0;
    }
    // math formula to bit shift
    return 1ull << ((8 * y) + x);
}

struct game *game_get_current() {
    return GAME;
}

int game_load_board(struct game *game, int player, char *spec) {

    // TODO: if spec contains other letters, return -1
    if (spec == NULL) {
        return -1;
    }
    bool isTakenB = false;
    bool isTakenC = false;
    bool isTakenD = false;
    bool isTakenP = false;
    bool isTakenS = false;
    // 15 characters
    for (int i = 0; i < 15; i += 3) {
        if (!isdigit(spec[i+1]) || !isdigit(spec[i+2])) {
            return -1;
        }
        int x = spec[i + 1]-'0';
        int y = spec[i + 2]-'0';

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
                break;
            case 'b':
                lengthOfShip = 4;
                if (isTakenB) {
                    return -1;
                } else {
                    isTakenB = true;
                }
                break;
            case 's':
                lengthOfShip = 3;
                if (isTakenS) {
                    return -1;
                } else {
                    isTakenS = true;
                }
                break;
            case 'd':
                lengthOfShip = 3;
                if (isTakenD) {
                    return -1;
                } else {
                    isTakenD = true;
                }
                break;
            case 'p':
                lengthOfShip = 2;
                if (isTakenP) {
                    return -1;
                } else {
                    isTakenP = true;
                }
                break;
            default:
                lengthOfShip = 0;
                break;
        }

        if (spec[i] >= 'A' && spec[i] <= 'Z') {
            if (add_ship_horizontal((player_info *)&player, x, y, lengthOfShip) == 1) {
                &GAME->players[player];
                continue;
            }
        } else {
            if (add_ship_vertical((player_info *)&player, x, y, lengthOfShip) == 1) {
                &GAME->players[player];
                continue;
            } else {
                if ((game->players->ships & xy_to_bitval(x, y)) != 0ULL) {
                    return -1;
                }
                return -1;
            }
        }

    }
    if (isTakenB == true && isTakenC == true && isTakenD == true && isTakenP && isTakenS == true)
    {


        return 1;
    }
    return -1;
}

int add_ship_horizontal(player_info *player, int x, int y, int length) {
    // cannot be added; out of bounds
    if (xy_to_bitval(x, y) == 0) {
        return -1;
    }
//if occupy return -1
    if ((player->ships & xy_to_bitval(x, y)) != 0ULL) {
        return -1;
    }

    if (length > 1) {
        if (add_ship_horizontal(player, x + 1, y, length - 1) == 1) {
            player->ships |= xy_to_bitval(x, y);
            return 1;
        }
    } else {
        player->ships |= xy_to_bitval(x, y);
        return 1;
    }
}

int add_ship_vertical(player_info *player, int x, int y, int length) {
    // cannot be added; out of bounds
    if (xy_to_bitval(x, y) == 0) {
        return -1;
    }
//if occupy return -1
    if ((player->ships & xy_to_bitval(x, y)) != 0ULL) {
        return -1;
    }

    if (length > 1) {
        if (add_ship_vertical(player, x, y + 1, length - 1) == 1) {
            player->ships |= xy_to_bitval(x, y);
            return 1;
        }
    } else {
        player->ships |= xy_to_bitval(x, y);
        return 1;
    }
}