//
// Created by 陈想 on 1/5/2022.
//
#include "game_play.h"
#include "board.h"
#include "judge.h"
#include "save_load.h"

using namespace std;

int main(){
    int width = 0;
    int height = 0;
    int option; // for user to select game options
    Player player1 = {"", 1, -1, -1, '!'};
    Player player2 = {"", 2, -1, -1, '!'};
    Player currentPlayer;
    char **gameBoard;
    
    // use to store the number of go in the gameBoard
    int count = 0 ;


    cout << "Heart Beat Go Bang" << endl;
    cout << "---------Menu------------" << endl;
    cout << "1. New game" << endl;
    cout << "2. Load previous game" << endl;
    cout << "-------------------------" << endl;
    cout << "Please select (1 or 2): ";
    cin >> option;
    if (option == 1){
        user_defined_board_size(width, height);
        // Declare gameBoard as a 2D dynamic array
        gameBoard = new char*[height];
        for (int i = 0; i < height; i++)
            gameBoard[i] = new char[width];
        //pre-game
        init_board(width, height, gameBoard);
        addPlayers(player1, player2);
        num_guess(player1, player2, currentPlayer);
    }
    else{
        if (get_board_dimension(width, height)){
            //no previously saved file
            user_defined_board_size(width, height);
            // Declare gameBoard as a 2D dynamic array
            gameBoard = new char*[height];
            for (int i = 0; i < height; i++)
                gameBoard[i] = new char[width];
            //pre-game
            init_board(width, height, gameBoard);
            addPlayers(player1, player2);
            num_guess(player1, player2, currentPlayer);
        }
        else {
            //There is previously saved file
            gameBoard = new char *[height];
            for (int i = 0; i < height; i++)
                gameBoard[i] = new char[width];

            load_game(currentPlayer, player1, player2, gameBoard);
        }
    }

    count = count_go (gameBoard ,width , height );

    //Game starts
    cout << "\n---------------------------------------------" << endl;
    cout << "The game starts now" << endl;
    print_board(width, height, gameBoard);
    while (true){
        if(place_go(gameBoard, width, height, currentPlayer)){
            save_game(currentPlayer, player1, player2, gameBoard, width, height);
            break;
        }
        print_board( width, height, gameBoard);
        count++;
        // check if five in a row
        if (judge(currentPlayer.x, currentPlayer.y, gameBoard, width, height)){
            cout << currentPlayer.name << " Won!" << endl;
            break;
        }
        if(count%10==0){
            //switch two go
            if(switch_go(gameBoard,width,height,player1,player2)){
                break;
            }
        }
        switch_player(player1, player2, currentPlayer);
    }


    cout << endl << "Game end" << endl;
}
