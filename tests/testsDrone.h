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
        /** Teste l'ajout d'un objectif dans la liste des points à atteindre du Drone.
         * ASSERT si l'objectif a bien été ajouté; c'est-à-dire que la liste est plus grande d'un élément, qui est celui affiché.
         * La vérification de la validité du point n'est pas du ressort du Drone (et donc de cette fonction).
         */
        void testAjouterObjectif(void);

        /** Teste l'ordre de livraison de colis.
          * Réalise globalement les mêmes tests que testAjouterObjectif, sur deux points.
          * @see testAjouterObjectif
          */
        void testLivrerColis(void);

        /** Teste la modification des capteurs.
          * Vérifie que les méthodes updateDistanceDetectee ont bien été appelées. 
          */
        void testUpdateCapteurs(void);
    private:
};

#endif // TESTSDRONE_H
