CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system  -lsfml-audio

all: main

main: main.cpp ./src/ventana.cpp
	gcc *.cpp ./src/*.cpp  -g -o main $(CFLAGS) 

