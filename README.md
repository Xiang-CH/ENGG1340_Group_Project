# Heart-Beat Gobang (ENGG1340_Group_Project)
2021-2022 ENGG1340 Group 170

Team members:
1. Xiang Chen 3035951868
2. Ruiyi Lin  3035948419

\n\n

Project Proposal:

Our current idea is to make a abbrivated version of gobang game (five in a row), for two players, with a board of ten rows or more.

**Rule of the game:**
Each player will have a kind of go: cross or circle. 
The player who come out to have a series of five same go first wins. It can be horizontal, verticle, or diagonal. 

The game will start by the program initalizing three gos on the board, 2 crosses and 1 circle. 
Then each player will need to enter a number, the computer will also generate a number, the player who guesses more closely will get to choose which go (cross or circle) they intent to play.

The player playing circle will start first then followed by player playing cross.

In the game, the computer will intervene the game at some point or at a regular pattern to increase the uncertainity，excitement and entertainment.
Which will also make this chess game more 'balance' to some extent.

  - After 4 rounds, before the next player start placing, the computer will randomly swap 2 gos (of difference team).

\n\n
**Features**

void init_board() - Code Requirement 1 & 2 \n
  // For intializing the board will x row and column demanding on a user input \n
  // Randomly place the three go \n
int num_guess() - Code Requirement 1\n
  // Randomly generates a number between 0 and 99\n
  // Promote players to enter a number\n
  // return the player with the closer guess\n
  \n
void place_go(int x, int y) \n
  // For placing the go on the board\n
  // Input are the x and y coordinated of where to place \n
  \n
bool judge(int x, int y) - Code Requirement 5\n
  // For judgeing if their is five in a row\n
  // Input are the x and y coordinated of where the go is placed\n
  // Outputs whether win or not\n
  bool judge_horizontal(int x, int y)\n
    // Helper function for the judge function, see if five in a row in the horizontal direction\n
    // Input are the x and y coordinated of where the go is placed\n
    // Outputs whether their is five in a row\n
  bool judge_vertical(int x, int y)\n
    // Helper function for the judge function, see if five in a row in the vertical direction\n
    // Input are the x and y coordinated of where the go is placed\n
    // Outputs whether their is five in a row\n
  bool judge_diagonal(int x, int y)\n
    // Helper function for the judge function, see if five in a row in the diagonal direction\n
    // Input are the x and y coordinated of where the go is placed\n
    // Outputs whether their is five in a row\n
  \n
void switch() - Code Requirement 5\n
  // Switches two go that are of different kinds\n
 \n
void save_game() - Code Requirement 4 & 5\n
  // save the current state of the board to a text file\n
void load_game() - Code Requirement 4 & 5\n
  // load the board data in the text file into the current board\n



