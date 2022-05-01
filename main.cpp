//
// Created by 陈想 on 1/5/2022.
//
#include "game_play.h"
#include "board.h"

using namespace std;

int main(){
    int width;
    int height;
    Player player1 = {"", 1, '!'};
    Player player2 = {"", 2, '!'};
    user_defined_board_size(width, height);

    // Declare gameBoard as a 2D dynamic array
    char **gameBoard = new char*[height];
    for (int i = 0; i < height; i++) {
        gameBoard[i] = new char[width];
    }

    //pre-game
    init_board(width, height, gameBoard);
    print_board(width, height, gameBoard);
    addPlayers(player1, player2);
    num_guess(player1, player2);





}