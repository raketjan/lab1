CC=g++
FLAGS=-Wall -g
VSN=1.1

test:
	$(CC) $(FLAGS) -c matrix.cpp
	../cxxtest/cxxtestgen.py --error-printer -o $(VSN).cpp test_matrix_$(VSN).h 
	$(CC) $(FLAGS) -o test_matrix_$(VSN) -I ../cxxtest/ $(VSN).cpp
	./test_matrix_$(VSN)

valgrind:test
	valgrind --leak-check=yes ./test_matrix_$(VSN)

clean:
	rm -f *.o test_matrix_$(VSN) vector_test_runner.cpp $(VSN).cpp
	rm -r test_matrix_$(VSN) vector_test_runner