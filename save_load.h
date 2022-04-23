//save_laod.h
#ifndef saveLoad_h
#define saveLoad_h
#include "player.h"

void save_game(Player* current_player, Player p1, Player p2, Char ** gameBoard);

void load_game(Player *& current_player, Player &p1, Player &p2, Char **& gameBoard);

#endif