//
// Created by 陈想 on 3/5/2022.
//
#include "save_load.h"

using namespace std;

void save_game(const Player& current_player, const Player& p1, const Player& p2, char ** gameBoard, int width, int height){
    ofstream fout (File_Name);
    if (fout.fail()){
        cout << "failed to save progress" << endl;
        exit(1);
    }

    fout << width << " " << height << endl;
    fout << current_player.name << endl;
    fout << p1.name << "," << p1.go << endl;
    fout << p2.name << "," << p2.go << endl;

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++)
            fout << gameBoard[i][j] << " ";
        fout << endl;
    }
    fout.close();
}


void load_game(Player& current_player, Player &p1, Player &p2, char ** gameBoard){
    string player1_data;
    string player2_data;
    string temp_board_content;
    int width, height;

    ifstream fin (File_Name);
    if (fin.fail()) {
        cout << "failed to load progress" << endl;
        exit(1);
    }

    fin >> width >> height;


    getline(fin, current_player.name); // read empty line
    getline(fin, current_player.name);
    getline(fin, player1_data);
    getline(fin, player2_data);


    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++) {
            fin >> temp_board_content;
            gameBoard[i][j] = temp_board_content[0];
        }
    }

    fin.close();

    p1.name = player1_data.substr(0, player1_data.find(','));
    player1_data = player1_data.erase( 0, player1_data.find(',') + 1);
    p1.go = player1_data[0];

    p2.name = player2_data.substr(0, player2_data.find(','));
    player2_data = player2_data.erase( 0, player2_data.find(',') + 1);
    p2.go = player2_data[0];

    if (current_player.name == p1.name)
        current_player = p1;
    else
        current_player = p2;
}

bool get_board_dimension(int &w, int &h){
    ifstream fin (File_Name);
    if (fin.fail()) {
        cout << "Failed to load progress. Starting a New Game Instead!!" << endl;
        return true;
    }
    fin >> w >> h;
    fin.close();
    return false;
}