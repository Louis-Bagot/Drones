#ifndef TESTSCUBIQUE_H
#define TESTSCUBIQUE_H

#include "../include/Cubique.h"

/**
* classe de test de la classe Cubique
* @author Simon
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
        /** A partir des informations relatives � la formation cubique (nbre drones, longeur  cot� et origine
        On verifie que le maillage est celui attendu.
        * Plus pr�cisement on va cr�er une formation � l'origine du rep�re, de longueur 1 pour 8 drones.
        * On v�rifie alors que le retour de la fonction est les 8 sommets du cube.
        */
        void testsGenererMaillage();
    private:
        /** Objet a tester */
        Cubique fCubique
};

#endif // TESTSCUBIQUE_H
