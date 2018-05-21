
#include "../tests/testsDrone.h"

void testsDrone::testAjouterObjectif() {
    Drone d = Drone(VecteurR3());
    VecteurR3 posObj = VecteurR3(1,0,0);
    d.ajouterObjectif(posObj);
    CPPUNIT_ASSERT(d.getVObjectifs().size() == 1 && d.getVObjectifs().front() == posObj);
}

void testsDrone::testLivrerColis() {
  Drone d = Drone(VecteurR3());
  VecteurR3 posRetrait = VecteurR3(0,1,0);
  VecteurR3 posDepot = VecteurR3(0.5,0.25,0);
  d.livrerColis(posRetrait, posDepot);
  CPPUNIT_ASSERT(d.getVObjectifs().size() == 2 &&
                 d.getVObjectifs().front() == posRetrait &&
                 d.getVObjectifs().back() == posDepot);
}

void testsDrone::testAtteintObjectif() {
  Drone d = Drone(VecteurR3());
  d.ajouterObjectif(VecteurR3());
  CPPUNIT_ASSERT(d.atteintObjectif() && !d.aObjectif());
}
