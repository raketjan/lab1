all:
	cxxtestgen.pl --error-printer -o vector_test_runner.cpp vector_test.h
	g++ vector_test_runner.cpp ../vector.cpp -o vector_test_runner
	./vector_test_runner

clean:
	rm -f vector.o vector_test_runner vector_test_runner.cpp
