CC=g++

all:
##	$(CC) -c Vector.h Vector.cpp Vectorizor.cpp
##	$(CC) -o Vector Vector.o
##	$(CC) -c Vectorizor.cpp
	$(CC) -o Vectorizor Vectorizor.cpp
##	./cxxtestgen.py --error-printer -o 1.4t.cpp test_1.4t.cpp
##	$(CC) -o test_1.4t -I cxxtest/ 1.4t.cpp Vector.o