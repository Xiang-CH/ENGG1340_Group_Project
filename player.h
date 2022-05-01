//player.h
#ifndef player_h
#define player_h
#include <string>
using namespace std; 

struct Player{
    string name;
    int id;
    int x;  // x coordinate of the last placed go
    int y;  // y coordinate of the last placed go
    char go;
};

#endif
