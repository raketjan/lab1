CC=g++
FLAGS=-Wall -g

all:vector.h test_erik

test:
	cxxtestgen.pl --error-printer -o $@.cpp $@.h
	$(CC) $(FLAGS) -o $@ $@.cpp
	./$@
test_erik:vector.h vector.cpp vector_bool.cpp test_erik.h bool_const_iterator.h
	cxxtestgen.pl --error-printer -o $@.cpp $@.h
	$(CC) $(FLAGS) $@.cpp -o $@
	./$@

valgrind:test
	valgrind --leak-check=yes ./test

valgrind_erik:test_erik
	valgrind --leak-check=yes ./test_erik 

alex_fet:
	$(CC) $(FLAGS) -o cprog09lab15 cprog09lab15.cpp

submit:
	submit.py -p cprog09lab15 vector.h cprog09lab15.cpp
clean:
	rm -f *.o test test_erik cprog09lab15 test_erik.cpp test.cpp
	rm -r test test_erik