all: output.txt

game: game.c
	gcc game.c -o game

output.txt: game
	./game > output.txt