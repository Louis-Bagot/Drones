#include "../include/Capteur.h"

Capteur::Capteur(const float &p, const VecteurR3 &dir, Environnement *environnement) {
  portee = p;
  env = environnement;
  direction = dir;
  distanceDectectee = updateDistanceDetectee();
}

Capteur::~Capteur() {

}

float Capteur::updateDistanceDetectee() {
  // TODO
  return portee;
}
