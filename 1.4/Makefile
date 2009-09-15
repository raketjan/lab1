CC=g++
VSN=1.4

test:
	../cxxtest/cxxtestgen.py --error-printer -o $(VSN).cpp test_$(VSN).cpp
	$(CC) -o test_$(VSN) -I ../cxxtest/ $(VSN).cpp

test_int:
	
alex_fet:
	$(CC) -o cprog09lab14 cprog09lab14.cpp

clean:
	rm -f *.o test_$(VSN)