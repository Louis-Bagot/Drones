#include "../include/Drone.h"
#include "../include/VecteurR3.h"


Drone::Drone(std::vector<Capteur> _vCapteurs)
{
    rayon = 0.1;
    porteColis = false;
    fonctionne = true;
    comportement = new Naif();
    position = new VecteurR3(0,0,0);
    acceleration = new VecteurR3(0,0,0);

    vCapteurs = _vCapteurs;
}

Drone::Drone(std::vector<Capteur> _vCapteurs,const VecteurR3 pos )
{
    rayon = 0.1;
    porteColis = false;
    fonctionne = true;
    comportement = new Naif();
    position = pos;
    acceleration = new VecteurR3(0,0,0);
    int porteeCapteur = 0.5;
    vCapteurs = _vCapteurs;
}

Drone::~Drone()
{
    //dtor
}
