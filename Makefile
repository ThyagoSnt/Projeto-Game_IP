
all:compile run
compile:
	gcc -o game $(wildcard ./src/*/*.c  ./src/*.c) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
run:
	./game
