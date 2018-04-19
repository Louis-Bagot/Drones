#ifndef TESTSVECTEURR3_H
#define TESTSVECTEURR3_H

#include <iostream>
#include <string>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>

#include "../include/VecteurR3.h"

class testsVecteurR3 : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(testsVecteurR3);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST(testMultiplication);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp(void);
        void tearDown(void);
    protected:
        void testAddition(void);
        void testMultiplication(void);
    private:
};

#endif // TESTSVECTEURR3_H

