#include "../include/Essaim.h"
#include "../include/Environnement.h"

Essaim::Essaim() {

}

Essaim::Essaim(Environnement env, int nbDrones) {
  float rayonDrone = env.getCote()/40. ;
  if (nbDrones <= 7) { // arbitraire pour début de projet
    VecteurR3 posDrone = VecteurR3(-0.9,-0.9,0);
    VecteurR3 vitDrone = VecteurR3(2,0.5,1);
    int portee = rayonDrone*5;
    vector<Capteur> vCapteur;
    VecteurR3 dirX = VecteurR3(1,0,0);
    VecteurR3 dirY = VecteurR3(0,1,0);
    VecteurR3 dirZ = VecteurR3(0,0,1);
    vCapteur.push_back(Capteur(portee,dirX,&env));
    vCapteur.push_back(Capteur(portee,dirX*-1,&env));
    vCapteur.push_back(Capteur(portee,dirY,&env));
    vCapteur.push_back(Capteur(portee,dirY*-1,&env));
    vCapteur.push_back(Capteur(portee,dirZ,&env));
    vCapteur.push_back(Capteur(portee,dirZ*-1,&env));
    VecteurR3 incrementPos = VecteurR3(0,0.5,0);
    VecteurR3 incrementVit = VecteurR3(0.5,-0.1,0.2);
    for (size_t i = 0; i < nbDrones; i++) {
      vDrones.push_back(new Drone(rayonDrone,posDrone,vitDrone,vCapteur));
      posDrone+=incrementPos;
      vitDrone-=incrementVit;
      std::cout << "drone créé en " << posDrone.getX() <<", "
                                    << posDrone.getY() <<", "
                                    << posDrone.getZ() << '\n';
    }
  } else throw std::invalid_argument("Trop de drones ! <=5 pour l'instant please");
}

vector<Drone*> Essaim::getVDrones() const {
  return vDrones;
}

Essaim::~Essaim()

{
    //dtor
}
