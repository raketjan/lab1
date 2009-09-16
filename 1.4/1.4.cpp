/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "test_1.4.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "test_1.4.cpp", 5, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_MyTestSuite_test_index : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_index() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 10, "test_index" ) {}
 void runTest() { suite_MyTestSuite.test_index(); }
} testDescription_MyTestSuite_test_index;

static class TestDescription_MyTestSuite_test_equals : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_equals() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "test_equals" ) {}
 void runTest() { suite_MyTestSuite.test_equals(); }
} testDescription_MyTestSuite_test_equals;

#include <cxxtest/Root.cpp>
