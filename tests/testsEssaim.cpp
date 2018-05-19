
#include "testsEssaim.h"
#include "../include/VecteurR3.h"
#include "../include/Cubique.h"
#include "../include/Essaim.h"

void testsEssaim::setUp(void){
  essaim = Essaim();
  Drone d1 = Drone(VecteurR3());
  Drone d2 = Drone(VecteurR3(1,0,0));
  essaim.ajouterDrone(d1);
  essaim.ajouterDrone(d2);
}
void testsEssaim::tearDown(){
}

void testsEssaim::testRetirerColis() {
  /*VecteurR3 test = essaim.getVDrones()[0]->getPosition();
  std::cout << "" << '\n';
  std::cout << "premier " << test << '\n';
  std::cout << "deuxieme " << test << '\n';
  std::cout << "troisieme " << test << '\n'; */
  std::cout << "D0 pos" << essaim.getVDrones()[1]->getPosition() << '\n';
/*  VecteurR3 retrait = VecteurR3(.8,0,0);
  std::cout << "apres : premier " << test << '\n';
  std::cout << "apres : deuxieme " << test << '\n';
  std::cout << "apres : troisieme " << test << '\n'; */
  //VecteurR3 depot = VecteurR3(.8,0,1);
  // Appel de la fonciton à vérifier
  //essaim.retirerColis(retrait, depot);
  /*
  std::queue<VecteurR3> vObjD1 = vPDrone[1]->getVObjectifs();
  bool resD1 = (vObjD1.size() == 2);
  resD1 &= (vObjD1.front()==retrait);
  resD1 &= (vObjD1.back()==depot);
  std::cout << "resD1 =" << resD1 << '\n';
  */
  CPPUNIT_ASSERT(!essaim.getVDrones()[0]->aObjectif() && true);
}

void testsEssaim::testAffectationDronePos(){
  CPPUNIT_ASSERT(false);
}
