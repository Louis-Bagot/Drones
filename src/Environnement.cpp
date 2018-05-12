#include "../include/Environnement.h"
#include "../include/Obstacle.h"
#include "../include/Drone.h"
#include "../include/Essaim.h"
#include <iostream>
#include<vector>

/**
* @authors Timothé, Simon
*/
Environnement::Environnement() {
  origineEnv = VecteurR3(-1,-1,-1);
  cote = 2.;
  g=VecteurR3(0,0,-3.5); // valeur du vect acc de gravité
  // Eventuellement créer des obstacles
}

Environnement::Environnement(const float tailleCote) {
  cote = tailleCote;
  origineEnv = VecteurR3(-cote/2.,-cote/2.,-cote/2.);
  g=VecteurR3(0,0,-3.5); // valeur du vect acc de gravité
  // Eventuellement créer des obstacles
  dt = 0.015;
  absorb = 0.5;
}

Environnement::~Environnement() {

}

float Environnement::getCote() const {return cote;}
VecteurR3 Environnement::getOrigineEnv() const {return origineEnv;}
std::vector<Obstacle> Environnement::getVObstacles() const{return vObstacles;}

Environnement Environnement::operator++(int a) {
  collisionsInterDrones();
  for (auto& pDrone : essaim.getVDrones()) {
    collisionBords(*pDrone);
    for (auto& obs : vObstacles)
      collisionObstacle(*pDrone, obs);
    calculerPos(*pDrone);
  }
  return *this;
}

void Environnement::ajouterObstacle(const Obstacle& obs) {
  vObstacles.push_back(obs);
}

void Environnement::calculerPos(Drone& drone) {
  // f(t+dt) = f(t) + f'(t)*dt
  // TODO metter l'acceleration à 0 dans le Drone quand il n'est pas fonctionnel
  drone.setVitesse(drone.getVitesse()+(drone.getAcceleration()+g)*dt);
  drone.setPosition(drone.getPosition()+drone.getVitesse()*dt);
}

void Environnement::collisionsInterDrones() {
  std::vector<Drone*> vPDrone = essaim.getVDrones();
  size_t sizeV = vPDrone.size(); // éviter deux accès
  for (size_t i = 0; i < sizeV; i++) {
    for (size_t j = i+1; j < sizeV; j++) {
      // ce couple (i,j) n'a nécessairement encore jamais été étudié
      VecteurR3 diffPos = vPDrone[i]->getPosition() - vPDrone[j]->getPosition();
      if (diffPos.norme2() < vPDrone[i]->getRayon()+vPDrone[j]->getRayon()) {
        vPDrone[i]->neFonctionnePlus();
        vPDrone[j]->neFonctionnePlus();
        VecteurR3 vColl = diffPos*(1./diffPos.norme2()); // Vecteur unitaire orthogonal au plan de collision
        // ici il serait plus opti de calculer une seule fois la matrice H(u) ...
        vPDrone[i]->setVitesse(vColl.reflexionPlanOrtho(vPDrone[i]->getVitesse())*absorb);
        vPDrone[j]->setVitesse(vColl.reflexionPlanOrtho(vPDrone[j]->getVitesse())*absorb);
        vPDrone[j]->setPosition(vPDrone[i]->getPosition()-diffPos*1.1);
      }
    }
  }
}

void Environnement::collisionBords(Drone& drone) {
  // Vérifications bords de l'Environnement
  float rayon = drone.getRayon();
  VecteurR3 dronePos = drone.getPosition();
  // Plans Z
  if (dronePos.getZ()-rayon < origineEnv.getZ()) {
    dronePos.setZ(origineEnv.getZ()+rayon);
    drone.setPosition(dronePos);
    drone.setVitesse(VecteurR3(0,0,1).reflexionPlanOrtho(drone.getVitesse())*absorb);
  } else if (dronePos.getZ()+rayon > origineEnv.getZ()+cote) {
    drone.neFonctionnePlus();
    dronePos.setZ(origineEnv.getZ()-rayon+cote);
    drone.setPosition(dronePos);
    drone.setVitesse(VecteurR3(0,0,-1).reflexionPlanOrtho(drone.getVitesse())*absorb);
  }
  // Plans X
  if (dronePos.getX()-rayon < origineEnv.getX()) {
    drone.neFonctionnePlus();
    dronePos.setX(origineEnv.getX()+rayon);
    drone.setPosition(dronePos);
    drone.setVitesse(VecteurR3(1,0,0).reflexionPlanOrtho(drone.getVitesse())*absorb);
  } else if (dronePos.getX()+rayon > origineEnv.getX()+cote) {
    drone.neFonctionnePlus();
    dronePos.setX(origineEnv.getX()-rayon+cote);
    drone.setPosition(dronePos);
    drone.setVitesse(VecteurR3(-1,0,0).reflexionPlanOrtho(drone.getVitesse())*absorb);
  }
  // Plans Y
  if (dronePos.getY()-rayon < origineEnv.getY()) {
    drone.neFonctionnePlus();
    dronePos.setY(origineEnv.getY()+rayon);
    drone.setPosition(dronePos);
    drone.setVitesse(VecteurR3(0,1,0).reflexionPlanOrtho(drone.getVitesse())*absorb);
  } else if (dronePos.getY()+rayon > origineEnv.getY()+cote) {
    drone.neFonctionnePlus();
    dronePos.setY(origineEnv.getY()-rayon+cote);
    drone.setPosition(dronePos);
    drone.setVitesse(VecteurR3(0,-1,0).reflexionPlanOrtho(drone.getVitesse())*absorb);
  }
}

void Environnement::collisionObstacle(Drone& drone, Obstacle& obs) {
  std::cout << "in collisionObstacle" << '\n';
  float posx = drone.getPosition().getX();
  float posy = drone.getPosition().getY();
  float posz = drone.getPosition().getZ();
  float minx = obs.getInit().getX();
  float miny = obs.getInit().getY();
  float minz = obs.getInit().getZ();
  float maxx = minx + obs.getTailleX();
  float maxy = miny + obs.getTailleY();
  float maxz = minz + obs.getTailleZ();
  float rayon = drone.getRayon();
  // Vérification naïve : considérer la phère comme un cube
  if ((posx>minx-rayon) && (posx<maxx+rayon) &&
      (posy>miny-rayon) && (posy<maxy+rayon) &&
      (posz>minz-rayon) && (posz<maxz+rayon)) {
    drone.neFonctionnePlus();
    
  }
}

void Environnement::ajouterColis(VecteurR3& colis){
  vColis.push_back(colis);
}

void Environnement::associerEssaim(Essaim& e) {
  essaim = e;
}

std::vector<Drone*> Environnement::getEssaimDrones() const {
  return essaim.getVDrones();
}
