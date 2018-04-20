#ifndef TESTSESSAIM_H
#define TESTSESSAIM_H

#include<vector>
#include"../include/VecteurR3.h"
#include"../include/Essaim.h"

/**
* @author Simon
* classe de test pour la classe Essaim
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

        /** teste la méthode retirer colis. On va faire apparaitre un colis a un endroit et on vérifie que le drone le plus proche a bien reçu l'ordre de s'y rendre */
        void testRetirerColis();
        /** teste si la méthode affecterDronePos affecte au drone le noeud du maillage le plus proche de sa position */
        void testAffectationDronePos(vector<VecteurR3>) vector<int>;
    private:
        Essaim essaim;
};

#endif // TESTSESSAIM_H
