#include <cxxtest/TestSuite.h>

#include "vector.h"

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
    TS_ASSERT_THROWS(v.erase(0), std::out_of_range);
    Vector<const char *> v2(1000,"hoho");
    v2.erase(50);
    TS_ASSERT_EQUALS(v2.size(), 999);

}

  void test_clear(){
    Vector<int> v(2);
    v.clear();
    TS_ASSERT_EQUALS(v.size(), 0);
    Vector<const char *> v2;
    TS_ASSERT_EQUALS(v2.size(), 0);
  }

  void test_sort(){
    Vector<int> v(7);
    v.sort(true);
    TS_ASSERT_EQUALS(v[0], 0);
    v[0]=6;
    v[1]=19;
    v[2]=1;
    v[3]=11;
    v[4]=77;
    v[5]=6;
    v[6]=6;
    v.sort(true);
    TS_ASSERT_EQUALS(v[0], 1);
    TS_ASSERT_EQUALS(v[1], 6);
    TS_ASSERT_EQUALS(v[2], 6);
    TS_ASSERT_EQUALS(v[3], 6);
    TS_ASSERT_EQUALS(v[4], 11);
    TS_ASSERT_EQUALS(v[5], 19);
    TS_ASSERT_EQUALS(v[6], 77);
    v[0]=6;
    v[1]=19;
    v[2]=1;
    v[3]=11;
    v[4]=77;
    v[5]=6;
    v[6]=6;
    v.sort(false);
    TS_ASSERT_EQUALS(v[0], 77);
    TS_ASSERT_EQUALS(v[1], 19);
    TS_ASSERT_EQUALS(v[2], 11);
    TS_ASSERT_EQUALS(v[3], 6);
    TS_ASSERT_EQUALS(v[4], 6);
    TS_ASSERT_EQUALS(v[5], 6);
    TS_ASSERT_EQUALS(v[6], 1);
  }
  void test_strings(){
    Vector<std::string> v(3,"hej");
    v.insert(1,"då");
    TS_ASSERT_EQUALS(v[1], "då");
    Vector<std::string> v2(2,"hoho");
    v2=v;
    TS_ASSERT_EQUALS(v2[1], "då");
  }
};
