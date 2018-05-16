#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "../include/VecteurR3.h"
class Environnement;

/**
* @authors Timothé
* @date 20 Avril 2018
*
* Les capteurs sont les outils nécéssaires aux drones pour detecter les
* obstacles alentours à une distance donnée.
*/

class Capteur {
    public:
     /** Constructeur de Capteur initialisant tous ses paramètres à des valeurs données en entrée. */
        Capteur(const float &p, const VecteurR3 &dir, Environnement *environnement);

     /** Déstructeur de Capteur */
        virtual ~Capteur();
    /** Getter de la distance detectee par le capteur */
    float getDistanceDetectee() const;
    /**
     * Calcul la distance entre le drone et les obstacles alentours. La fonction sera appelée par drone,
    de manière itérative.
     */
    float updateDistanceDetectee();
    /** Getter de la direction du capteur */
    VecteurR3 getDirection() const;
    /** Renvoie un boolean donnant si le capteur detecte un obstacle (distDetectee<portee) */
    bool detecteQQch() const;
    protected:

    private:
      /** Distance maximale à laquelle peut "voir" un Capteur */
      float portee;
      /** Distance actuellement détectée. <= portee. */
      float distanceDetectee;
      /** Direction dans laquelle le Capteur regarde, relativement au Drone. */
      VecteurR3 direction;

      /** Environnement dans lequel se trouve le Drone et donc son Capteur. Permet à ce dernier de se donner une valeur à chaque instant. */
      Environnement *env;
      /** Position du Drone associé au Capteur, permettant le calcul de distanceDectectee
      */
      VecteurR3 positionDrone;
      /** Sera initialisé lors de l'attribution du drone */
      float tailleDrone;
};

#endif // CAPTEUR_H
