CC=g++
FLAGS=-Wall -g

all: test_matrix

test:test.o
	$(CC) $(FLAGS) -o $@ $@.cpp	

test_matrix: matrix.o matrix.h matrix.cpp test_matrix.h
	cxxtestgen.pl --error-printer -o $@.cpp $@.h 
	$(CC) $(FLAGS) -o $@ $@.cpp

%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

valgrind:test_matrix
	valgrind --leak-check=yes ./test_matrix

clean:
	rm -f *.o test_matrix test_matrix.cpp test
