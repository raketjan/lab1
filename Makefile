CC=g++

all:
	$(CC) -c Vectorizor.cpp
	$(CC) -o Vectorizor Vectorizor.o

##	./cxxtestgen.py --error-printer -o 1.4t.cpp test_1.4t.cpp
##	$(CC) -o test_1.4t -I cxxtest/ 1.4t.cpp Vector.o

clean:
	rm -f Vector Vectorizor *.o