
build: 2048.c highscores salvare2048
	gcc 2048.c -o 2048 -lm -lcurses
run:
	./2048
highscores:
	touch highscores
	echo "0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n">highscores
salvare2048:
	touch salvare2048
	echo "0 0 2 0\n0 0 0 0\n0 0 4 0\n0 0 0 0\n0">salvare2048

clean:
	rm -f ./2048
	rm -f salvare2048
	rm -f highscores
