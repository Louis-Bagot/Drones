#include "../include/Drone.h"
#include "../include/VecteurR3.h"


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

Drone::Drone(const float r,const std::vector<Capteur>& _vCapteurs,const VecteurR3 pos )
{
    rayon = 2000; // Louis t'es un gros con
    porteColis = false;
    fonctionne = true;
    comportement = new Naif();
    position = pos;
    acceleration = new VecteurR3(0,0,0);
    vCapteurs = _vCapteurs;
}
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
