//
// Created by carson on 5/20/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include <ctype.h>



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
    int opponent = (player + 1) % 2; // ^- lets you flip between players
    GAME->players[player].ships;
    game_get_current();
    //empty_game
    if (&GAME->status == CREATED) {
            return 0;
        }

    // game status players turn
    if (GAME->status == PLAYER_0_TURN) {
        GAME->status = PLAYER_1_TURN;
    } else {
        GAME->status = PLAYER_0_TURN;
    }

    // BOUNDS
    if (x > 7 || y > 7 || x < 0 || y < 0) {
        return 0;
    }
    // hit or miss
    if ((GAME->players[opponent].ships & xy_to_bitval(x, y)) != 0ULL) {
        GAME->players[player].hits |= xy_to_bitval(x, y);
        GAME->players[opponent].ships ^= xy_to_bitval(x, y);
        if (GAME->players[0].ships == 0) {
            GAME->status = PLAYER_1_WINS;

        } else if (game->players[1].ships == 0){
            GAME->status = PLAYER_0_WINS;
        }
        return 1;

    } else {
        GAME->players[player].shots |= xy_to_bitval(x, y);
        return 0;
    }


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

        // make sure there is one of each type of ship
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
            if (add_ship_horizontal(&GAME->players[player], x, y, lengthOfShip) == 1) {
                &GAME->players[player].ships;
                continue;
            }

        } else {
            if (add_ship_vertical(&GAME->players[player], x, y, lengthOfShip) == 1) {
                &GAME->players[player].ships;
                continue;

            } else {
                if ((game->players->ships & xy_to_bitval(x, y)) != 0ULL) {
                    return -1;
                }

                return -1;
            }
        }

    }

    if (isTakenB == true && isTakenC == true && isTakenD == true && isTakenP && isTakenS == true) {
        game_get_current();
        if (GAME->players == 2) {
            GAME->status = INITIALIZED;
        }

        if (player == 1) {
            GAME->status = PLAYER_0_TURN;
        }
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

    //Recursion
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

    // Recursion
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
