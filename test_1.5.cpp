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
    TS_ASSERT_EQUALS(v.size(), 3);  
  }
  void test_empty(){
    Vector<int> v(0);
    TS_ASSERT_EQUALS(v.size(), 0);  
  }
  void test_push_back(){
    Vector<int> v(2);
    TS_ASSERT_EQUALS(v.get_array_size(), 4);
    v.push_back(2);
    TS_ASSERT_EQUALS(v[2], 2);
    TS_ASSERT_EQUALS(v.get_array_size(), 4);
    TS_ASSERT_EQUALS(v.size(), 3);
    TS_ASSERT_EQUALS(v.get_array_size(), 4);
    v.push_back(3);
    v.push_back(4);
    TS_ASSERT_EQUALS(v.get_array_size(), 8);
    v.push_back(5);
    TS_ASSERT_EQUALS(v.get_array_size(), 8);
    TS_ASSERT_EQUALS(v[4], 4);
    TS_ASSERT_EQUALS(v.size(), 6);
  }
   
  void test_insert(){
    Vector<int> v(2);
    v.insert(1,1);
    TS_ASSERT_EQUALS(v[1], 1);   
    v.insert(0,1000);
    TS_ASSERT_EQUALS(v[0], 1000);   
    TS_ASSERT_EQUALS(v[2], 1);   
    v.insert(4,222);
    TS_ASSERT_EQUALS(v[4], 222);   
    
  }

  void test_erase(){
    Vector<int> v(2);
    v.erase(0);
    TS_ASSERT_EQUALS(v[0], 0);
    TS_ASSERT_EQUALS(v.size(), 1);
    v.erase(0);
    TS_ASSERT_EQUALS(v.size(), 0);   
    v.erase(0);
    TS_ASSERT_EQUALS(v.size(), 0);
  }


};
