#include <cxxtest/TestSuite.h>

#include "vector.cpp"

class MyTestSuite : public CxxTest::TestSuite 
{

public:

  void test_index(){
    Vector v(3);
    v[2]=2;
    TS_ASSERT_EQUALS(v[2], 2);  
  }
  void test_equals(){
    Vector v1(3), v2(2), v3(100);
    v1[2]=2;
    v2[1]=100;
    v1=v2;
    TS_ASSERT_EQUALS(v1[1], 100);  
    v3=v3;
    v3=v2;
    TS_ASSERT_EQUALS(v3[1], 100);  
  }
};
