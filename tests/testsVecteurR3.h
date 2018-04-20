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
    CPPUNIT_TEST(testSoustraction);
    CPPUNIT_TEST(testAffectation);
    CPPUNIT_TEST(testMultiplication);
    CPPUNIT_TEST(testMultiplicationScalaire);
    CPPUNIT_TEST(testIncrementation);
    CPPUNIT_TEST(testNorme22);
    CPPUNIT_TEST(testprodVec);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp(void);
        void tearDown(void);
    protected:
        void testAddition(void);
        void testSoustraction(void);
        void testAffectation(void);
        void testMultiplication(void);
        void testMultiplicationScalaire(void);
        void testIncrementation(void);
        void testNorme22(void);
        void testprodVec(void);
    
    private:
};

#endif // TESTSVECTEURR3_H

