#include "save_load.h"

using namespace std;

void save_game(const Player& current_player, const Player& p1, const Player& p2, char ** gameBoard, int width, int height){
    ofstream fout (File_Name); //open file
    if (fout.fail()){
        cout << "failed to save progress" << endl;
        exit(1);
    }

    // write player data, and game board metadata
    fout << width << " " << height << endl;
    fout << current_player.name << endl;
    fout << p1.name << "," << p1.go << endl;
    fout << p2.name << "," << p2.go << endl;
    // write game board data
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++)
            fout << gameBoard[i][j] << " ";
        fout << endl;
    }

    fout.close();
}


void load_game(Player& current_player, Player &p1, Player &p2, char ** gameBoard){
    string player1_data;  // temporarily storing the data for player 1
    string player2_data;  // temporarily storing the data for player 2
    string temp_board_content;   // temporarily storing the board element of string before converting to char
    int width, height;   // holds the game board width and height, used in later processing of game board

    ifstream fin (File_Name);  // open file for read
    if (fin.fail()) {
        cout << "failed to load progress" << endl;
        exit(1);
    }

    fin >> width >> height ;


    getline(fin, current_player.name); // read empty line
    getline(fin, current_player.name);
    getline(fin, player1_data);
    getline(fin, player2_data);

    //read game board data in to the current game board
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++) {
            fin >> temp_board_content;
            gameBoard[i][j] = temp_board_content[0];
        }
    }

    fin.close();

    // processing the player data into the desired data structure
    p1.name = player1_data.substr(0, player1_data.find(','));
    player1_data = player1_data.erase( 0, player1_data.find(',') + 1);
    p1.go = player1_data[0];

    p2.name = player2_data.substr(0, player2_data.find(','));
    player2_data = player2_data.erase( 0, player2_data.find(',') + 1);
    p2.go = player2_data[0];

    // determine the current player
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


void delete_game_data(){
    ofstream fout (File_Name);
    if (!(fout.fail())){  // if a previous game status file exists
        char delete_game; // for storing user input
        cout << "This round of game is over\nDo you want to delete the previously saved checkpoint? (Y/N): ";

        // input validation
        while (!(cin >> delete_game) and (tolower(delete_game) != 'y' or tolower(delete_game) != 'n' )){
            cout<<"Please enter a valid character (Y/N): ";
            cin.clear();//clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //cin>>delete_game;
        }
        // delete previous file if needed
        if (tolower(delete_game)=='y'){
           if (remove(File_Name) == 0){
               cout << "Previous checkpoint deleted";
           }
           else{
               cout << "Failed to delete previous checkpoint";
           }
        }
    }
}