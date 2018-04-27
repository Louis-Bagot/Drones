#include "../include/Drone.h"
#include "../include/VecteurR3.h"


Drone::Drone(const std::vector<Capteur>& _vCapteurs)
{
    rayon = 0.05;
    porteColis = false;
    fonctionne = true;
    comportement = new Naif();
    position = new VecteurR3(0,0,0);
    acceleration = new VecteurR3(0,0,0);
    vCapteurs = _vCapteurs;
}

Drone::Drone(const std::vector<Capteur>& _vCapteurs,const VecteurR3 pos )
{
    rayon = 0.05;
    porteColis = false;
    fonctionne = true;
    comportement = new Naif();
    position = pos;
    acceleration = new VecteurR3(0,0,0);
    vCapteurs = _vCapteurs;
}
Drone::Drone(const std::vector<Capteur>& _vCapteurs, const Comportement& _comportement, const VecteurR3 pos)
{
    rayon = 0.05;
    porteColis = false;
    fonctionne = true;
    comportement = _comportement;
    position = pos;
    acceleration = new VecteurR3(0,0,0);
    vCapteurs = _vCapteurs;
}

Drone::Drone(const std::vector<Capteur>& _vCapteurs, const Comportement& _comportement, const VecteurR3 pos)
{
    rayon = 0.05;
    porteColis = false;
    fonctionne = true;
    comportement = _comportement;
    position = pos;
    acceleration = new VecteurR3(0,0,0);
    vCapteurs = _vCapteurs;
}

Drone::Drone(const std::vector<Capteur>& _vCapteurs, const Comportement& _comportement, const VecteurR3 _pos, const VecteurR3 _acc)
{
    rayon = 0.05;
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
VecteurR3 Drone::objectifDone()
{

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
Drone::~Drone()
{
    //dtor
}
