#include "../include/Essaim.h"
#include<limits>
#define inf std::numeric_limits<float>::max()

Essaim::Essaim() {

}

Essaim::Essaim(Environnement env, int nbDrones) {
  float rayonDrone = env.getCote()/40. ;
  if (nbDrones <= 7) { // arbitraire pour début de projet
    VecteurR3 posDrone = VecteurR3(0,0,0);
    //VecteurR3 vitDrone = VecteurR3(2,0.5,1);
    VecteurR3 vitDrone = VecteurR3();
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
    VecteurR3 incrementVit = VecteurR3(0,0,0);
    for (size_t i = 0; i < nbDrones; i++) {
      vDrones.push_back(new Drone(rayonDrone,posDrone,vCapteur,env.getGravite(),vitDrone));
      posDrone+=incrementPos;
      vitDrone-=incrementVit;


    }
    std::cout << "Essaim : apres construction drones" << std::endl;

  } else throw std::invalid_argument("Trop de drones ! <=5 pour l'instant please");
}

Essaim::~Essaim() {
    for (auto& pDrone : vDrones)
        delete pDrone;
}


vector<Drone*> Essaim::getVDrones() const {
  return vDrones;
}
void Essaim::ajouterDrone(Drone& drone){
    vDrones.push_back(&drone);
}
void Essaim::retirerColis(VecteurR3 retrait, VecteurR3 depot){
    float minDist = inf;
    Drone *pDroneMin = getVDrones()[0];
    for (auto& pDrone : getVDrones()) {
        if(pDrone->aObjectif()){
            float distToObj = (pDrone->getPosition()-retrait).norme22();
            if(distToObj < minDist) {
                minDist = distToObj;
                pDroneMin = pDrone;
            }
        }
    }
    pDroneMin->livrerColis(retrait, depot);
    std::cout << pDroneMin->getPremierObjectif()  << std::endl;
}
