#include "../include/Capteur.h"
#include "../include/Environnement.h"
#include<cmath>
Capteur::Capteur(const float &p, const VecteurR3 &dir, Environnement *environnement) {
  portee = p;
  env = environnement;
  direction = dir;
  distanceDetectee = updateDistanceDetectee();
}

Capteur::~Capteur() {}

float Capteur::getDistanceDetectee() const {return distanceDetectee;}
float Capteur::getPortee() const {return portee;}
VecteurR3 Capteur::getDirection() const {return direction;}

bool Capteur::detecteQQch() const {
  return distanceDetectee<portee;
}

float Capteur::updateDistanceDetectee() {
  // TODO
  //On itére sur les obstacles

    for (auto& obs : env->getVObstacles()){


        VecteurR3 centreObs = obs.getCentre();
        vector<VecteurR3> face; //C'est la face de l'obstacle vers lequel le capteur pointe

        //On répère la face pointée le capteur
        if(direction.getX() != 0){
            if((centreObs - positionDrone).getX() > 0 ){ //C'est la face arriere
                face = obs.getFaceXArriere();
            }else{
                face = obs.getFaceXAvant();
            }
        }else if(direction.getY() != 0){
            if((centreObs - positionDrone).getY() > 0 ){
                face = obs.getFaceYGauche();
            }else{
                face = obs.getFaceYDroite();
            }
        }else if(direction.getZ() != 0){
            if((centreObs - positionDrone).getZ() > 0 ){
                face = obs.getFaceZBasse();
            }else{
                face = obs.getFaceZHaut();
            }
        }

        //On calcule les sommets de la face
        float xmin = min(face[0].getX(), face[2].getX());
        float xmax = min(face[0].getX(), face[2].getX());
        float ymin = min(face[0].getY(), face[2].getY());
        float ymax = max(face[0].getY(), face[2].getY());
        float zmin = min(face[0].getZ(), face[2].getZ());
        float zmax = max(face[0].getZ(), face[2].getZ());

        //On calcule la distance détectée
        //Pour cela il faut vérifier que le drone est bien en face de la face et non pas en dehors
        //Dans ce cas la distance détectée est calculée
        //Sinon elle est "infinie" du coup on renverra la portée du capteur
        if(direction.getX() != 0){
            if(positionDrone.getY() >= ymin && positionDrone.getY() <= ymax && positionDrone.getZ() >= zmin && positionDrone.getZ() <= zmax){
                if((centreObs - positionDrone).getX() > 0 ){ //Face arriere
                    distanceDetectee = abs(positionDrone.getX() - xmin);
                }else{ //face avant
                    distanceDetectee = abs(xmax - positionDrone.getX());
                }
            }

        }else if(direction.getY() != 0){
            if(positionDrone.getX() >= xmin && positionDrone.getX() <= xmax && positionDrone.getZ() >= zmin && positionDrone.getZ() <= zmax){
                if((centreObs - positionDrone).getY() > 0 ){
                    distanceDetectee = abs(ymin - positionDrone.getY());
                }else{
                    distanceDetectee = abs(ymax - positionDrone.getY());
                }
            }
        }else if(direction.getZ() != 0){
            if(positionDrone.getY() >= ymin && positionDrone.getY() <= ymax && positionDrone.getX() >= xmin && positionDrone.getX() <= xmax){
                if((centreObs - positionDrone).getZ() > 0 ){
                    distanceDetectee = abs(zmin - positionDrone.getZ());
                }else{
                    distanceDetectee = abs(zmax - positionDrone.getZ());
                }
            }
        }
    }
    distanceDetectee = min(portee, distanceDetectee);
    return distanceDetectee;

}
