FLAGS = -pedantic-errors -std=c++11
board.o : board.cpp board.h
	g++ $(FLAGS) -c $<
game_play.o : game_play.cpp game_play.h
	g++ $(FLAGS) -c $<
judge.o : judge.cpp judge.h
	g++ $(FLAGS) -c $<
judge_helper.o : judge_helper.cpp judge_helper.h
	g++ $(FLAGS) -c $<
main.o : main.cpp game_play.h board.h judge.h save_load.h
	g++ $(FLAGS) -c $<
save_load.o : save_load.cpp save_load.h
	g++ $(FALGS) -c $<

main : board.o game_play.o judge.o judge_helper.o main.o save_load.o
	g++ $(FLAGS) $^ -o $@

