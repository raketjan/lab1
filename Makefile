CC=g++
VSN=1.5

all:
	make test

test:
## 	Generates 1.5.cpp
## 	From test_1.5

	cxxtest/cxxtestgen.py --error-printer -o $(VSN).cpp test_$(VSN).cpp
	$(CC) -o test_$(VSN) -I cxxtest/ $(VSN).cpp 

alex:
	$(CC) -o test_template_vec test_template_vec.cpp

clean:
	rm -f test_template_vec test_$(VSN) test_*.o $(VSN).cpp *.o