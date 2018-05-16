#include <vector>
#include "../include/VecteurR3.h"
#include "../include/Naif.h"
#include "../include/Capteur.h"
#include<cmath>

Naif::Naif() {
    //ctor
}

Naif::~Naif() {
    //dtor
}

// Permet le calcul de la trajectoire, seulement en x et en y. La hauteur est gérée séparément.
VecteurR3 Naif::setTrajectory(const VecteurR3 &posActuelle,const VecteurR3 &destination) const {
    float distObj = (destination-posActuelle).norme22();
    return VecteurR3((destination.getX()-posActuelle.getX())*distObj*0.2,(destination.getY()-posActuelle.getY())*distObj*0.2,0);
}


// Indique si le drone se trouve au dessus/en dessous de l'objectif
bool Naif::atteint(const VecteurR3 &posActuelle, const VecteurR3 &destination, const float &epsilon) const {
    return((std::abs(posActuelle.getX()-destination.getX())<epsilon)&&(std::abs(posActuelle.getY()-destination.getY())<epsilon));
}


// Méthode qui selectionne les capteurs pertinents en fonction du vecteur directionnel, et regarde s'ils indiquent la présence ou non d'un obstacle
bool Naif::presenceObstacles(const VecteurR3 posActuelle, const VecteurR3 destination,  const std::vector<Capteur> vCapteurs) const {
    bool res = false;
    for (auto& capteur : vCapteurs)
      if ((capteur.getDirection()*(destination-posActuelle)>0)&&(capteur.detecteQQch())) {
        res = true;
        break;
      }
    std::cout << "in presenceObstacles : " << res << std::endl;
    return res;
}

// Retourne un vecteur direction qui fait seulement monter le drone(+1)
VecteurR3 Naif::surmonter(const VecteurR3 &posActuelle) const {
    return VecteurR3(0,0,1);
}

// Méthode qui fait monter le drone s'il est en dessous de l'objectif, descendre s'il est au dessus
VecteurR3 Naif::gererHauteur(const VecteurR3 &posActuelle, const VecteurR3 &destination, const VecteurR3 vitesse) const {
    float distObj = (destination-posActuelle).norme22();
    return VecteurR3(-vitesse.getX()*2, -vitesse.getY()*2, (destination.getZ()-posActuelle.getZ())*distObj*0.2);
}


// Retourne le vecteur accélération en fonction du cas dans lequel on se trouve
VecteurR3 Naif::allerPoint(const VecteurR3 &posActuelle,const VecteurR3 &destination,const std::vector<Capteur> vCapteurs, const VecteurR3 vitesse ) {
    if(presenceObstacles(posActuelle,destination,vCapteurs)) {
        return surmonter(posActuelle);
    }
    else if (atteint(posActuelle, destination, 0.1)) {
        std::cout << "gerer hauteur" << std::endl;
        return gererHauteur(posActuelle, destination, vitesse);
    }else{
        std::cout << "gerer trajectory" << std::endl;
        return setTrajectory(posActuelle,destination);
    }
}
