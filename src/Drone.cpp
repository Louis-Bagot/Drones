#include "../include/Drone.h"
#include "../include/VecteurR3.h"
#include <cstddef>

Drone::Drone(const float rayonDrone, const VecteurR3 posInit, const std::vector<Capteur> vCap, const VecteurR3 _gravite,const VecteurR3 vitInit) {
  rayon = rayonDrone;
  position = posInit;
  vitesse = vitInit;
  acceleration = VecteurR3();
  vCapteurs = vCap;
  fonctionne = true;
  porteColis = false;
  gravite = _gravite;
}

Drone::~Drone() {
  //dtor
}

VecteurR3 Drone::getPremierObjectif() const {return vObjectifs.front();}
std::queue<VecteurR3> Drone::getVObjectifs() const {return vObjectifs;}
std::vector<Capteur> Drone::getVCapteurs() const {return vCapteurs;}
void Drone::setAcceleration(const VecteurR3& _acc) {acceleration = _acc;}
VecteurR3 Drone::getPosition() const {return position;}
VecteurR3 Drone::getVitesse() const {return vitesse;}
VecteurR3 Drone::getAcceleration() const {return acceleration;}
void Drone::setPosition(const VecteurR3 nvllPos) {position=nvllPos;}
void Drone::setVitesse(const VecteurR3 nvllVit) {vitesse=nvllVit;}
void Drone::setAcceleration(const VecteurR3 nvllAcc) {acceleration=nvllAcc;}
float Drone::getRayon() const {return rayon;}
void Drone::neFonctionnePlus() {fonctionne = false;}
bool Drone::estFonctionnel() const {return fonctionne;}
bool Drone::aObjectif() const {return vObjectifs.size()>0;}
bool Drone::porteUnColis() const {return porteColis;}

bool Drone::atteintObjectif() {
  bool ret = false;
  if(position.egal(getPremierObjectif()), rayon*0.1) {
    ret = true;
    vObjectifs.pop();
  }
  return ret;
}

void Drone::operator++() {
    //Update capteurs
    for(const auto &capteur : vCapteurs){
        capteur.updateDistanceDetectee();
    }

    //Deplacement
    atteintObjectif();
    if (fonctionne) {
      if (aObjectif()) {
        acceleration = comportement->allerPoint(position,getPremierObjectif(),vCapteurs);
      } else acceleration = gravite*(-1);
    } else //Sinon accélération nulle, il ne fonctionne plus...
      acceleration = VecteurR3();
}

void Drone::ajouterObjectif(const VecteurR3 &obj){
    vObjectifs.push(obj);
}
void Drone::livrerColis(const VecteurR3& retrait, const VecteurR3& depot)
{
    ajouterObjectif(retrait);
    ajouterObjectif(depot);
}
