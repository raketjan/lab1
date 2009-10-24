#include "matrix.cpp"
#include <iostream>
#include <string>
#include <cxxtest/TestSuite.h>
using namespace std;
class MyTestSuite:public CxxTest::TestSuite
{
  
public:
  void test_initialized(){
    Matrix m(2,2);
    Matrix m2(2,2);
    m2[0][0]=10;
    TS_ASSERT_EQUALS(m.size(), 4);
    m[0][0]= 5;
    TS_ASSERT_EQUALS(m[0][0], 5);
    std::cout << m << endl;

    TS_ASSERT_EQUALS((m2+m)[0][0], 15);
    std::cout << m2 << endl;
    std::cout << m2+m << endl;
    std::cout << m2 << endl;
    std::cout << m2*m << endl;
    
  }
  
  void test_mult(){
    Matrix m1(3,2);
    Matrix m2(2,3);
    m1[0][0]=2;
    m1[0][1]=9;
    m1[1][0]=2;
    m1[1][1]=3;
    m2[0][0]=5;
    m2[0][1]=2;
    m2[1][0]=5;
    m2[1][1]=1;
    
    std::cout << m1*m2 << endl;
    std::cout << m1*-(1) << endl;
    
  }

  void test_sub(){
    Matrix m1(2,2);
    Matrix m2(2,2);
    m1[0][0]=2;
    m1[0][1]=9;
    m1[1][0]=2;
    m1[1][1]=3;
    m2[0][0]=5;
    m2[0][1]=2;
    m2[1][0]=5;
    m2[1][1]=1;
    std::cout << m1-m2 << endl;
    
  }

  void test_equals(){
    Matrix m1(5,2);
    Matrix m2(2,2);
    m1[0][0]=2;
    m1[0][1]=9;
    m1[1][0]=2;
    m1[1][1]=3;
    m2[0][0]=5;
    m2[0][1]=2;
    m2[1][0]=5;
    m2[1][1]=1;
    m1=m2;
    std::cout << m1 << endl;
    std::cout << m2 << endl;
    Matrix m3(2,2);
    Matrix m4(2,2);
    m3=m4;
  }

  void test_id(){
    Matrix m1(2,2);
    m1[0][0]=2;
    m1[0][1]=9;
    m1[1][0]=2;
    m1[1][1]=3;
    m1.id();
    std::cout << m1 << endl;
  }

  void test_T(){
    Matrix m1(2,3);
    m1[0][0]=2;
    m1[0][1]=9;
    m1[1][0]=2;
    m1[1][1]=3;
    m1[1][2]=10;
    std::cout << m1 << endl;
    std::cout << m1.T() << endl;

  
  }
};
