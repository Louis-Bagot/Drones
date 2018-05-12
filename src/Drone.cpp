#include "../include/Drone.h"
#include "../include/VecteurR3.h"
#include <cstddef>


Drone::Drone()
{
    //ctor
}

Drone::Drone(float rayonDrone, VecteurR3 posInit, std::vector<Capteur> vCap) {
  rayon = rayonDrone;
  position = posInit;
  vitesse = VecteurR3();
  acceleration = VecteurR3();
  vCapteurs = vCap;
  fonctionne = true;
}

Drone::Drone(float rayonDrone, VecteurR3 posInit,VecteurR3 vitInit, std::vector<Capteur> vCap) {
  rayon = rayonDrone;
  position = posInit;
  vitesse = vitInit;
  acceleration = VecteurR3();
  vCapteurs = vCap;
  fonctionne = true;
}

Drone::~Drone()
{
    //dtor
}

VecteurR3 Drone::getPosition() const {return position;}
VecteurR3 Drone::getVitesse() const {return vitesse;}
VecteurR3 Drone::getAcceleration() const {return acceleration;}
void Drone::setPosition(const VecteurR3 nvllPos) {position=nvllPos;}
void Drone::setVitesse(const VecteurR3 nvllVit) {vitesse=nvllVit;}
void Drone::setAcceleration(const VecteurR3 nvllAcc) {acceleration=nvllAcc;}
float Drone::getRayon() const {return rayon;}
void Drone::neFonctionnePlus() {fonctionne = false;}
bool Drone::estFonctionnel() const {return fonctionne;}
