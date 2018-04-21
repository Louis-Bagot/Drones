#include "testsEssaim.h"
#include "../include/VecteurR3.h"
#include "../include/Cubique.h"
#include "../include/Essaim.h"

void testsEssaim::setUp(void)
{
    essaim = new Essaim();
}
void testsEssaim::tearDown()
{
   delete essaim;
}
void testsEssaim::testRetirerColis()
{
    //On ajoute des drones dans l'environnement
    essaim.ajouterDrone(new Drone(new VecteurR3(1,0,0)));
    essaim.ajouterDrone(new Drone(new VecteurR3(0,1,0)));
    essaim.ajouterDrone(new Drone(new VecteurR3(0,0,1)));
    Drone designatedDrone = new Drone(new VecteurR3(0.2,0.2,0.2));
    essaim.ajouterDrone(designatedDrone);
    // Ordre d'aller retirer un colis au centre de l'environnement
    retrait = new VecteurR3(0.5,0.5,0.5);
    depot = new VecteurR3(1,0,0);
    essaim.retirerColis(retrait, depot);

    CPPUNIT_ASSERT(designatedDrone.objectifs.at(0)==retrait && designatedDrone.objectifs.at(1)==depot);
}
void testsEssaim::affectationDronePos()
{
    essaim = new Essaim();
    //On positioone des drones proches de la où vont se trouver les noeuds du maillage de la formation
    Drone d1 = new Drone(new VecteurR3(0.9,0.1,0.1));
    Drone d2 = new Drone(new VecteurR3(0.9,0.9,0.1));
    Drone d3 = new Drone(new VecteurR3(0.9,0.9,0.9));
    Drone d4 = new Drone(new VecteurR3(0.1,0.9,0.1));
    Drone d5 = new Drone(new VecteurR3(0.1,0.9,0.9));
    Drone d6 = new Drone(new VecteurR3(0.1,0.1,0.9));
    Drone d7 = new Drone(new VecteurR3(0.9,0.1,0.9));
    Drone d8 = new Drone(new VecteurR3(0.1,0.1,0.1));

    essaim.ajouterDrone(d1);
    essaim.ajouterDrone(d2);
    essaim.ajouterDrone(d3);
    essaim.ajouterDrone(d4);
    essaim.ajouterDrone(d5);
    essaim.ajouterDrone(d6);
    essaim.ajouterDrone(d7);
    essaim.ajouterDrone(d8);

    //Méthode à tester : formation donne l'objectif au drone d'aller au noeud le plus proche
    essaim.formation(new Cubique(0,0,0), 1, 8);
    //On vérifie
    CPPUNIT_ASSERT(
                   d1.objectifs.at(0) == new VecteurR3(1,0,0) &&
                   d2.objectifs.at(0) == new VecteurR3(1,1,0) &&
                   d3.objectifs.at(0) == new VecteurR3(1,1,1) &&
                   d4.objectifs.at(0) == new VecteurR3(0,1,0) &&
                   d5.objectifs.at(0) == new VecteurR3(0,1,1) &&
                   d6.objectifs.at(0) == new VecteurR3(0,0,1) &&
                   d7.objectifs.at(0) == new VecteurR3(1,0,1) &&
                   d8.objectifs.at(0) == new VecteurR3(0,0,0)
                    );

}

