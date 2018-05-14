#ifndef TESTSDRONE_H
#define TESTSDRONE_H

#include <iostream>
#include <string>
#include <cppunit/*>

#include "../include/Drone.h"

class testsDrone : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(testsDrone);
    CPPUNIT_TEST(testAjouterObjectif);
    CPPUNIT_TEST(testLivrerColis);
    CPPUNIT_TEST(testUpdateCapteurs);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp(void);
        void tearDown(void);
    protected:
        /** Teste l'ajout d'un objectif */
        void testAjouterObjectif(void);
        /** Teste l'ordre de livraison de colis */
        void testLivrerColis(void);
        /** Teste la modification des capteurs */
        void testUpdateCapteurs(void);
    private:
};

#endif // TESTSDRONE_H
