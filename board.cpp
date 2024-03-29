#include "board.h"


void user_defined_board_size(int &w, int &h){
    cout << "Please enter the desired board width (5 - 20): ";

    //when the invalid input encounter, clear the input buffer, ignore the char start new line
    //prompt for input again
    while(!(cin >> w) or w < 5 or w > 20 ){
        cout<<"Please enter a valid width (5 - 20): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Please enter the desired board height (5 - 20): ";

    //when the invalid input encounter, clear the input buffer, ignore the char start new line
    //prompt for input again
    while(!(cin >> h) or h < 5 or h > 20 ){
        cout<<"Please enter a valid height (5 - 20): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}



void init_board(int x, int y, char **gameBoard){

    //two for loops initialise the empty board with char _
    for(int row = 0 ; row  < y ; row ++ ){
        for(int column = 0 ; column <x ; column++ ){
            gameBoard[row][column]='_';
        }
    }

    //randomly place three go with computer
    srand(seed1); //randomise
    char init[3]={'X','O','X'};
    for(char i : init){
        int row = rand()%y;
        int column = rand()%x;
        gameBoard[row][column] = i;
    }

}



void print_board(int w, int h, char **gameBoard){

    //print the column number in first line
    cout << " x  ";
    for (int i=0; i < w; i++){
        if(i<10){
            cout << i << "   ";
        }
        else{
            cout<< i <<"  ";
        }

    }

    cout << endl << "y";
    // print the row with row number at the beginner
    for(int row = 0 ; row < h ; row++){
        if(row<10){
            cout << "\n" << row << "   ";
        }
        else{
            cout << "\n" << row << "  ";
        }
        for(int column = 0 ; column < w ; column++){
            cout<<gameBoard[row][column]<<"   ";
        }
        cout<<endl;
    }

}
