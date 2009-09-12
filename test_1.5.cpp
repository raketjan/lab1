#include <cxxtest/TestSuite.h>

#include "Vector.h"

class MyTestSuite : public CxxTest::TestSuite 
{

public:
  void test_init( void )
  {
    Vector<int> v(3);    
    TS_ASSERT_EQUALS(v[0], 0);
    Vector<const char *> v2(2,"hej");
    TS_ASSERT_EQUALS(v2[0], "hej");
    TS_ASSERT_EQUALS(v2[1], "hej");
  }
  void test_size(){
    Vector<int> v(3);
    TS_ASSERT_EQUALS(v.getSize(), 3);  
  }
  void test_empty(){
    Vector<int> v(0);
    TS_ASSERT_EQUALS(v.getSize(), 0);  
  }
  void test_newsize(){
    Vector<int> v(3);
    v[2]=5;
    v[1]=1;
    v.setSize(5);
    TS_ASSERT_EQUALS(v[4], 0);
    TS_ASSERT_EQUALS(v[2], 5);
    v.setSize(2);
    TS_ASSERT_EQUALS(v[1], 1);    
    TS_ASSERT_EQUALS(v.getSize(), 2);  
  }
};
