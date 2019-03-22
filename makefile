output: snake.o
	g++ -o snakeGame snakeGame.cc -lcurses
clean:
	rm *.o *.out
