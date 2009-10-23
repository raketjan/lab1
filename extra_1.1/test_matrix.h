#include "matrix.cpp"
#include <iostream>
#include <string>
#include <cxxtest/TestSuite.h>
class MyTestSuite:public CxxTest::TestSuite
{
  
public:
  void test_initialized(){
    Matrix m(2,2);
    TS_ASSERT_EQUALS(m.size(), 4);
    m[0][0]= 5;
    TS_ASSERT_EQUALS(m[0][0], 5);
    std::cout << m;
  }
};
