CC=g++
FLAGS=-Wall -g
VSN=1.5

test:
	../cxxtest/cxxtestgen.py --error-printer -o $(VSN).cpp test_$(VSN).cpp
	$(CC) $(FLAGS) -o test_$(VSN) -I ../cxxtest/ $(VSN).cpp
	./test_$(VSN)
test_erik:
	../cxxtest/cxxtestgen.pl --error-printer -o vector_test_runner.cpp vector_test.h
	$(CC) $(FLAGS) vector_test_runner.cpp -o vector_test_runner
	./vector_test_runner

valgrind:test
	valgrind --leak-check=yes ./test_$(VSN)

valgrind_erik:test_erik
	valgrind --leak-check=yes ./vector_test_runner 

alex_fet:
	$(CC) $(FLAGS) -o cprog09lab15 cprog09lab15.cpp

submit:
	submit.py -p cprog09lab15 vector.h cprog09lab15.cpp
clean:
	rm -f *.o test_$(VSN) cprog09lab15 vector_test_runner.cpp $(VSN).cpp
	rm -r test_$(VSN) vector_test_runner 