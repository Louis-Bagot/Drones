#include "../include/Drone.h"
#include "../include/VecteurR3.h"
#include <cstddef>


Drone::Drone(const float r, const std::vector<Capteur>& _vCapteurs)
{
    rayon = r;
    porteColis = false;
    fonctionne = true;
    comportement = new Naif();
    position = new VecteurR3(0,0,0);
    acceleration = new VecteurR3(0,0,0);
    vCapteurs = _vCapteurs;
}

Drone::Drone(const float rayonDrone, const VecteurR3 posInit, const std::vector<Capteur> vCap) {
  rayon = rayonDrone;
  position = posInit;
  vitesse = VecteurR3();
  acceleration = VecteurR3();
  vCapteurs = vCap;
  fonctionne = true;
}

Drone::Drone(const float rayonDrone,const VecteurR3 posInit, const VecteurR3 vitInit, const std::vector<Capteur> vCap) {
  rayon = rayonDrone;
  position = posInit;
  vitesse = vitInit;
  acceleration = VecteurR3();
  vCapteurs = vCap;
  fonctionne = true;


Drone::Drone(const float r,const std::vector<Capteur>& _vCapteurs, const Comportement& _comportement, const VecteurR3 pos)
{
    rayon = r;
    porteColis = false;
    fonctionne = true;
    comportement = _comportement;
    position = pos;
    acceleration = new VecteurR3(0,0,0);
    vCapteurs = _vCapteurs;
}

Drone::Drone(const float r, const std::vector<Capteur>& _vCapteurs, const Comportement& _comportement, const VecteurR3 _pos, const VecteurR3 _acc)
{
    rayon = r;
    porteColis = false;
    fonctionne = true;
    comportement = _comportement;
    position = pos;
    acceleration = _acc;
    vCapteurs = _vCapteurs;
}

VecteurR3 Drone::getObjectif() const
{
    return vObjectifs.front();
}
VecteurR3 Drone::getVitesse() const
{
    return vitesse;
}
void Drone::setVitesse(_vitesse)
{
    vitesse = _vitesse;
}
bool Drone::objectifDone()
{
    if(Drone.position.egal(Drone.getObjectif()))
    {
        vObjectifs.pop();
        return true;
    }else return false;
}
void Drone::operator++()
{
    objectifDone();
    setAcceleration(comportement.allerPoint());
}
std::vector<Capteur> Drone::getvCapteurs() const
{
    return vCapteurs;
}
void Drone::ajouterObjectif(const VecteurR3 &obj)
{
    vObjectifs.po;
}
void Drone::livrerColis(const VecteurR3& retrait, const VecteurR3& depot)
{
    ajouterObjectif(retrait);
    ajouterObjectif(depot);
}
void Drone::setAcceleration(const VecteurR3& _acc)
{
    acceleration = _acc;
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
