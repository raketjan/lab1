CC=g++
VSN=1.5

all:
#	$(CC) -c Vectorizor.cpp
#	$(CC) -o Vectorizor Vectorizor.o
	make test

test:
## 	Generates 1.5.cpp 
## 	From test_1.5

	cxxtest/cxxtestgen.py --error-printer -o $(VSN).cpp test_$(VSN).cpp
	$(CC) -o test_$(VSN) -I cxxtest/ $(VSN).cpp 

clean:
	rm -f Vector Vectorizor test_$(VSN) test_*.o $(VSN).cpp