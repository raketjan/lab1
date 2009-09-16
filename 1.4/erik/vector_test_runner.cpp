/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "vector_test.h"

static vector_test suite_vector_test;

static CxxTest::List Tests_vector_test = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_vector_test( "vector_test.h", 6, "vector_test", suite_vector_test, Tests_vector_test );

static class TestDescription_vector_test_test_initialized : public CxxTest::RealTestDescription {
public:
 TestDescription_vector_test_test_initialized() : CxxTest::RealTestDescription( Tests_vector_test, suiteDescription_vector_test, 15, "test_initialized" ) {}
 void runTest() { suite_vector_test.test_initialized(); }
} testDescription_vector_test_test_initialized;

static class TestDescription_vector_test_test_set_and_get : public CxxTest::RealTestDescription {
public:
 TestDescription_vector_test_test_set_and_get() : CxxTest::RealTestDescription( Tests_vector_test, suiteDescription_vector_test, 29, "test_set_and_get" ) {}
 void runTest() { suite_vector_test.test_set_and_get(); }
} testDescription_vector_test_test_set_and_get;

static class TestDescription_vector_test_test_throw : public CxxTest::RealTestDescription {
public:
 TestDescription_vector_test_test_throw() : CxxTest::RealTestDescription( Tests_vector_test, suiteDescription_vector_test, 37, "test_throw" ) {}
 void runTest() { suite_vector_test.test_throw(); }
} testDescription_vector_test_test_throw;

static class TestDescription_vector_test_test_assignment : public CxxTest::RealTestDescription {
public:
 TestDescription_vector_test_test_assignment() : CxxTest::RealTestDescription( Tests_vector_test, suiteDescription_vector_test, 42, "test_assignment" ) {}
 void runTest() { suite_vector_test.test_assignment(); }
} testDescription_vector_test_test_assignment;

static class TestDescription_vector_test_test_diff_size_assignment : public CxxTest::RealTestDescription {
public:
 TestDescription_vector_test_test_diff_size_assignment() : CxxTest::RealTestDescription( Tests_vector_test, suiteDescription_vector_test, 57, "test_diff_size_assignment" ) {}
 void runTest() { suite_vector_test.test_diff_size_assignment(); }
} testDescription_vector_test_test_diff_size_assignment;

#include <cxxtest/Root.cpp>
