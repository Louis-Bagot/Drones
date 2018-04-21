#ifndef TESTSCUBIQUE_H
#define TESTSCUBIQUE_H

#include "../include/Cubique.h"

/**
* @author Simon
* classe de test de la classe Cubique
*/
class testsCubique  public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(testsCubique);
    CPPUNIT_TEST(testsGenererMaillage());
    CPPUNIT_TEST_SUITE_END();
    public:
        void setUp(void);
        void tearDown(void);
    protected:
        /** A partir des informations relatives à la formation cubique (nbre drones, longeur  coté et origine
        On verifie que le maillage est celui attendu */
        void testsGenererMaillage();
    private:
        Cubique fCubique
};

#endif // TESTSCUBIQUE_H
