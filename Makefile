FILE=./src/main.c ./src/draw.c ./src/handleTexture.c ./src/initFuctions.c ./src/mechanicGame.c
all:compile run
compile:
	gcc -o game $(FILE) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
run:
	./game
