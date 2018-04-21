#ifndef TESTSCAPTEUR_H
#define TESTSCAPTEUR_H

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
#include <cpputestNorme22nit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include "../include/Capteur.h"

/*
*
*/


class testsVecteurR3 : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(testsCapteur);
    CPPUNIT_TEST(testUpdateDistanceDetectee);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp(void);
        void tearDown(void);
    protected:
        void testUpdateDistanceDetectee(void);

    private:
};

#endif // TESTSVECTEURR3_H
