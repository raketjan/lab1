#include <cxxtest/TestSuite.h>

#include "Vector.h"

class MyTestSuite : public CxxTest::TestSuite 
{

public:
    void test_init( void )
    {
      Vector<int> v(3);
      
      TS_ASSERT_EQUALS(v[0], 0);
    }
};
