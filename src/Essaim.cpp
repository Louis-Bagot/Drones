#include "../include/Essaim.h"
#include "../include/Capteurs.h"
#include<vector>

Essaim::Essaim(const Environnement &env)
{
    int _porteeCapteur = 0.5;
    std::vector<Capteur> vCapteurs;
    vCapteurs.push_back(porteeCapteur, new VecteurR3(0,0,1),  env)
    vCapteurs.push_back(porteeCapteur, new VecteurR3(0,0,-1), env  )
    vCapteurs.push_back(porteeCapteur, new VecteurR3(0,1,0), env )
    vCapteurs.push_back(porteeCapteur, new VecteurR3(0,-1,0), env )
    vCapteurs.push_back(porteeCapteur, new VecteurR3(1,0,0),  env)
    vCapteurs.push_back(porteeCapteur, new VecteurR3(-1,0,0),  env)
}

Essaim::~Essaim()
{
    //dtor
}
