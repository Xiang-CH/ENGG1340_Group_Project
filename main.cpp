//
// Created by 陈想 on 1/5/2022.
//
#include "game_play.h"
#include "board.h"
#include "judge.h"

using namespace std;

int main(){
    int width;
    int height;
    Player player1 = {"", 1, -1, -1, '!'};
    Player player2 = {"", 2, -1, -1, '!'};
    Player currentPlayer;
    user_defined_board_size(width, height);

    // Declare gameBoard as a 2D dynamic array
    char **gameBoard = new char*[height];
    for (int i = 0; i < height; i++) {
        gameBoard[i] = new char[width];
    }

    //pre-game
    init_board(width, height, gameBoard);
    addPlayers(player1, player2);
    num_guess(player1, player2, currentPlayer);

    //Game starts
    cout << "\n---------------------------------------------" << endl;
    cout << "The game starts now" << endl;
    print_board(width, height, gameBoard);
    while (true){
        place_go(gameBoard, width, height, currentPlayer);
        print_board( width, height, gameBoard);
        // check if five in a row
        if (judge(currentPlayer.x, currentPlayer.y, gameBoard, width, height)){
            cout << currentPlayer.name << " Won!" << endl;
            break;
        }

        switch_player(player1, player2, currentPlayer);
    }




}