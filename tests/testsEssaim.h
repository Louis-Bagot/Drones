#ifndef TESTSESSAIM_H
#define TESTSESSAIM_H

#include<vector>
#include"../include/VecteurR3.h"
#include"../include/Essaim.h"

/**
* classe de test pour la classe Essaim
* @author Simon
*/
class testsEssaim  : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(testsEssaim);
    CPPUNIT_TEST(testRetirerColis());
    CPPUNIT_TEST(testAffectationDronePos());
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp(void);
        void tearDown(void);
    protected:

        /** teste la méthode retirer colis. On va faire apparaitre un colis a un endroit et on vérifie que le drone le plus proche a bien reçu l'ordre de s'y rendre.
        * Pour cela on regarde que les points de retrait et dépose ont été ajouté à la liste des objectifs du drone le plus proche.
        */
        void testRetirerColis();
        /** teste si la méthode affecterDronePos affecte au drone le noeud du maillage le plus proche de sa position
        * C'est une méthode fastidieuse à tester. On va tester un exemple simple.
        * Etant donné 8 noeuds issus d'un maillage d'une formation cubique, on créé 8 drones légèrement décalé au 8 sommets.
        * On vérifie que chaque drone a comme objectif d'aller au sommet à coté de lui.
        */
        void testAffectationDronePos(vector<VecteurR3>) vector<int>;
    private:
        /** Objet à tester */
        Essaim essaim;
};

#endif // TESTSESSAIM_H
