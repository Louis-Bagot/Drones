#ifndef NAIF_H
#define NAIF_H

#include "../include/Comportement.h"

/**
* Classe héritant de Comportement, c'est donc un algo possible de déplacement des drones.
* Il consiste à monter en altitude lorsque le drone rencontre un obstacle devant lui afin de passer au dessus.
*
* @author Simon
*/
class Naif : public Comportement {
    public:
        Naif();
        virtual ~Naif();
        /** Méthode fondamentale de Comportement des Drones.
        * A partir des positions du Drone, de son premier objectif et des capteurs, détermine le vecteur accélération pour la frame suivante.
        * @param posActuelle la position du Drone au temps t.
        * @param destination la position à atteindre.
        * @param vCapteurs, le vecteur des Capteurs donnant l'information sensorielle du Drone.
        * @return le vecteur accélération
        */
        VecteurR3 allerPoint(VecteurR3 posActuelle, VecteurR3 destination, std::vector<Capteur> vCapteurs);
    protected:

    private:
};

#endif // NAIF_H
