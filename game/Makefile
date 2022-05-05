FILE=./src/main.c
all:compile run
#./src/draw.c ./src/handleTexture.c ./src/initFuctions.c ./src/mechanicGame.c
compile:
	gcc -o game $(FILE) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
run:
	./game
