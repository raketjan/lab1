CC=g++

all:
	$(CC) -c Vector.h Vector.cpp 
	$(CC) -o Vector Vector.o
##	./cxxtestgen.py --error-printer -o 1.4t.cpp test_1.4t.cpp
##	$(CC) -o test_1.4t -I cxxtest/ 1.4t.cpp Vector.o