#include "../include/Capteur.h"

Capteur::Capteur(const float &p, const VecteurR3 &dir, Environnement *environnement) {
  portee = p;
  env = environnement;
  direction = dir;
  distanceDectectee = updateDistanceDetectee();
}

Capteur::~Capteur() {}

float Capteur::getDistanceDetectee() const {return distanceDetectee;}
VecteurR3 Capteur::getDirection() const {return direction;}
bool Capteur::detecteQQch() const {
  return distanceDetectee<portee;
}

float Capteur::updateDistanceDetectee() {
  // TODO
  return portee;
}
