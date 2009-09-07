CC=g++
all:
	$(CC) -c Vector.h Vector.cpp
	$(CC) -o Vector Vector.o 