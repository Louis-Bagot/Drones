#include "../include/Capteur.h"

Capteur::Capteur(const float &p, const float &d, const VecteurR3 &dir, const Environnement &environnement);
{
  portee = p;
  distanceDectectee = d;
  Environnement = env;
  direction = dir;
}

Capteur::~Capteur()
{

}
