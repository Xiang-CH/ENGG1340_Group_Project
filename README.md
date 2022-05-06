# Heart-Beat Gobang (ENGG1340_Group_Project)
2021-2022 ENGG1340 Group 170

Team members:
1. Xiang Chen 3035951868
2. Ruiyi Lin  3035948419

**important**: The random seed in the program is currently set to a fixed seed for accuracy of the sample input/output file. If you desire a more random game please follow the instructions under global seed part in "board.h" and "game_play.h" (uncomment a line of code).  

<br />

## Project Proposal

Our project creates an abbreviated version of goBang game (five in a row), for two players, with a dynamic board.

Demo Video: https://connecthkuhk-my.sharepoint.com/:v:/g/personal/cxiang_connect_hku_hk/EXIIh-GB1aNMvIvUcBjaIDoB_hQ8frl4nYsu-wd08foXuA?e=tJgWdt

Tested on Academy 21

<br />

## Rule of the game:

Each player will have a kind of go: cross or circle.
They will play alternately.
The player who come out to have a series of five same go first wins. It can be horizontal, vertical, or diagonal.

The game will start by the program initializing 1-3 gos on the board.
Then each player will need to enter a number, the computer will also generate a number, the player who guesses more closely will get to choose which go (cross or circle) they intend to play.

The player playing circle will start first then followed by player playing cross.

In the game, the computer will intervene the game at every 10 go placed to increase the uncertainty，excitement and entertainment.
Which will also make this chess game more 'balance' to some extent.

  - After 4 rounds, before the next player start placing, the computer will randomly swap 2 gos (of difference team).

<br />

## Features

- Initialize player data
  - prompt for user name
  - name, go type, last played coordinate are stored in a player data structure - Code Requirement 2


- User determined board size
  - prompt user to enter desired board size
  - create a dynamic array for storing the board - Code Requirement 2 & 3


- Initialize board - Code Requirement 5

  - For initializing an empty board
  - Randomly place the 1-3 go  - Code Requirement 1


- Number guess game - Code Requirement 5

  - Randomly generates a number between 0 and 99 - Code Requirement 1
  - Promote players to enter a number
  - return the player with the closer guess


- Judge win or not - Code Requirement 5

  - For judging if their are five in a row
  - Input are the x and y coordinated of where the go is placed
  - Outputs whether win or not



- Heartbeat time: switch go - Code Requirement 5

  - Switches two go that are of different kinds after every 10 rounds


- Save game - Code Requirement 4 & 5

  - save the current state of the board to a text file
  - Save the player datas into a text file


- Load game - Code Requirement 4 & 5

  - load the board data in the text file into the current board
  - load the player data in the test file into the current players variable




## Sample TestCases
- Test case 1
  - Create a new game
  - board width 6 , board height 6 
  - A player win 
  - delete the last play file 
- Test case 2 
  - load last play(failed)
  - init a new board 
  - A player win 
  - delete the last play file 

