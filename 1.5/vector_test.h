#include <cxxtest/TestSuite.h>
#include "vector.h"
#include <iostream>
#include <string>

class vector_test : public CxxTest::TestSuite
{
    static const size_t vector_size = 100;

public:

    vector_test() : vec(vector_size) {
    }

    void test_initialized()
    {
        TS_ASSERT_EQUALS(vec.size(), vector_size);

        TS_ASSERT_EQUALS( vec[0], 0 );
        TS_ASSERT_EQUALS( vec[vector_size-1], 0 );

    }
    
    void test_assignment_string()
    {
        Vector<std::string> bajs;
        std::string rumpa = "foo";
        bajs.push_back(rumpa);

        Vector<std::string> kiss;
        kiss = bajs;

        kiss = kiss;
    }
    void test_const_string() {
        Vector<std::string> apor;
        Vector<std::string> apor2;
        
        const std::string apa1 = "foo";
        apor.push_back(apa1);
        TS_ASSERT_EQUALS( apor[0], "foo" );
        
        const std::string apa2 = "foo2";
        apor2.push_back(apa2);
        TS_ASSERT_EQUALS( apor2[0], "foo2" );
    
        apor = apor2;

        TS_ASSERT_EQUALS( apor[0], "foo2" );
    

    }

    void test_static() {
        Vector<unsigned int> banan(10,4);
        TS_ASSERT_EQUALS(banan[9], 4);
        }

    void test_set_and_get() {
        TS_ASSERT_EQUALS( vec[0], 0);

        vec[0] = 3;

        TS_ASSERT_EQUALS( vec[0], 3);
    }

    void test_throw() 
    {
        TS_ASSERT_THROWS(vec[vector_size], std::out_of_range);
    }

    void test_assignment()
    {
        Vector<unsigned int> a(10);
        a[1] = 2;
        Vector<unsigned int> b = a;
        a[2] = 3;
        TS_ASSERT_EQUALS(b[1], 2);
        TS_ASSERT_EQUALS(b[2], 0);
        b[3] = 5;
        a = b;
        TS_ASSERT_EQUALS(a[3], 5);
        b[4] = 2;
        b = b;
        TS_ASSERT_EQUALS(b[4], 2);
    }
    void test_diff_size_assignment()
    {
        Vector<unsigned int> a(20);
        Vector<unsigned int> b(10);
        a[5] = 10;
        a[9] = 123;
        b = a;
        TS_ASSERT_EQUALS(b.size(), a.size());
        TS_ASSERT_EQUALS(b[5], 10);
        TS_ASSERT_EQUALS(b[9], 123);
        b[15] = 15;
        TS_ASSERT_EQUALS(b[15], 15);
        b[5] = 20;
        a = b;
        TS_ASSERT_EQUALS(a.size(), b.size());
        TS_ASSERT_EQUALS(a[5], 20);
        TS_ASSERT_EQUALS(a[15], 15);
    }
    void test_push_back()
    {
        Vector<int> a(3);
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        a.push_back(4);

        Vector<int> b;
        b.push_back(15);
    }

    void test_insert()
    {
        Vector<int> a;
        TS_ASSERT_THROWS(a.insert(1, 123), std::out_of_range);
        TS_ASSERT_THROWS(a.insert(-1, 123), std::out_of_range);

        TS_ASSERT_EQUALS(a.size(), 0);

        a.insert(0, 13);
        TS_ASSERT_EQUALS(a[0], 13);
        TS_ASSERT_EQUALS(a.size(), 1);


        TS_ASSERT_THROWS(a.insert(2, 123), std::out_of_range);

        a.insert(1, 14);

        TS_ASSERT_EQUALS(a[0], 13);
        TS_ASSERT_EQUALS(a[1], 14);

        TS_ASSERT_EQUALS(a.size(), 2);

        a.insert(0, 12);

        TS_ASSERT_EQUALS(a[0], 12);
        TS_ASSERT_EQUALS(a[1], 13);
        TS_ASSERT_EQUALS(a[2], 14);

        TS_ASSERT_EQUALS(a.size(), 3);

        a.insert(1, 1337);

        TS_ASSERT_EQUALS(a[0], 12);
        TS_ASSERT_EQUALS(a[1], 1337);
        TS_ASSERT_EQUALS(a[2], 13);
        TS_ASSERT_EQUALS(a[3], 14);

        TS_ASSERT_EQUALS(a.size(), 4);

    }

    void test_erase()
    {
        Vector<int> a;
        TS_ASSERT_THROWS(a.erase(0), std::out_of_range);

        a.push_back(20);
        TS_ASSERT_EQUALS(a[0], 20);
        TS_ASSERT_EQUALS(a.size(), 1);

        a.erase(0);
        TS_ASSERT_THROWS(a[0], std::out_of_range);
        TS_ASSERT_EQUALS(a.size(), 0);

        a.push_back(20);
        a.push_back(21);
        a.push_back(22);
        a.push_back(23);
        a.push_back(24);

        TS_ASSERT_EQUALS(a.size(), 5);

        TS_ASSERT_EQUALS(a[0], 20);
        TS_ASSERT_EQUALS(a[1], 21);
        TS_ASSERT_EQUALS(a[2], 22);
        TS_ASSERT_EQUALS(a[3], 23);
        TS_ASSERT_EQUALS(a[4], 24);

        a.erase(1);
        TS_ASSERT_EQUALS(a.size(), 4);

        TS_ASSERT_EQUALS(a[0], 20);
        TS_ASSERT_EQUALS(a[1], 22);
        TS_ASSERT_EQUALS(a[2], 23);
        TS_ASSERT_EQUALS(a[3], 24);
    }

    void test_clear() {
        Vector<int> a;
        Vector<int> b(10);

        TS_ASSERT_EQUALS(a.size(), 0);
        TS_ASSERT_EQUALS(b.size(), 10);

        a.clear();

        a.push_back(20);
        a.push_back(21);
        a.push_back(22);
        a.push_back(23);
        a.push_back(24);

        TS_ASSERT_EQUALS(a.size(), 5);

        a.clear();
        b.clear();

        TS_ASSERT_EQUALS(a.size(), 0);
        TS_ASSERT_EQUALS(b.size(), 0);
    }

    void test_sort() {
        Vector<int> a;

        a.sort();
        a.sort(false);

        a.push_back(4);

        a.sort();

        TS_ASSERT_EQUALS(a.size(), 1);
        TS_ASSERT_EQUALS(a[0], 4);

        a.sort(false);

        TS_ASSERT_EQUALS(a.size(), 1);
        TS_ASSERT_EQUALS(a[0], 4);

        a.push_back(3);
        a.push_back(8);
        a.push_back(2);

        TS_ASSERT_EQUALS(a[0], 4);
        TS_ASSERT_EQUALS(a[1], 3);
        TS_ASSERT_EQUALS(a[2], 8);
        TS_ASSERT_EQUALS(a[3], 2);

        a.sort();

        TS_ASSERT_EQUALS(a[0], 2);
        TS_ASSERT_EQUALS(a[1], 3);
        TS_ASSERT_EQUALS(a[2], 4);
        TS_ASSERT_EQUALS(a[3], 8);

        a.sort(false);

        TS_ASSERT_EQUALS(a[3], 2);
        TS_ASSERT_EQUALS(a[2], 3);
        TS_ASSERT_EQUALS(a[1], 4);
        TS_ASSERT_EQUALS(a[0], 8);

        a.sort();

        a.push_back(3);
        a.push_back(8);
        a.push_back(8);

        TS_ASSERT_EQUALS(a[0], 2);
        TS_ASSERT_EQUALS(a[1], 3);
        TS_ASSERT_EQUALS(a[2], 4);
        TS_ASSERT_EQUALS(a[3], 8);
        TS_ASSERT_EQUALS(a[4], 3);
        TS_ASSERT_EQUALS(a[5], 8);
        TS_ASSERT_EQUALS(a[6], 8);

        a.sort();

        TS_ASSERT_EQUALS(a.size(), 7);

        TS_ASSERT_EQUALS(a[0], 2);
        TS_ASSERT_EQUALS(a[1], 3);
        TS_ASSERT_EQUALS(a[2], 3);
        TS_ASSERT_EQUALS(a[3], 4);
        TS_ASSERT_EQUALS(a[4], 8);
        TS_ASSERT_EQUALS(a[5], 8);
        TS_ASSERT_EQUALS(a[6], 8);

        a.sort(false);

        TS_ASSERT_EQUALS(a[6], 2);
        TS_ASSERT_EQUALS(a[5], 3);
        TS_ASSERT_EQUALS(a[4], 3);
        TS_ASSERT_EQUALS(a[3], 4);
        TS_ASSERT_EQUALS(a[2], 8);
        TS_ASSERT_EQUALS(a[1], 8);
        TS_ASSERT_EQUALS(a[0], 8);

    }

private:
    Vector<unsigned int> vec;

};
