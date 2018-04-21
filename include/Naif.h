#ifndef NAIF_H
#define NAIF_H

#include "../include/Comportement.h"

/**
* Classe h�ritant de Comportement, c'est donc un algo possible de d�placement des drones.
* Il consiste � monter en altitude lorsque le drone rencontre un obstacle devant lui afin de passer au dessus.
*
* @author Simon
*/
class Naif : public Comportement {
    public:
        Naif();
        virtual ~Naif();
        /** M�thode fondamentale de Comportement des Drones.
        * A partir des positions du Drone, de son premier objectif et des capteurs, d�termine le vecteur acc�l�ration pour la frame suivante.
        * @param posActuelle la position du Drone au temps t.
        * @param destination la position � atteindre.
        * @param vCapteurs, le vecteur des Capteurs donnant l'information sensorielle du Drone.
        * @return le vecteur acc�l�ration
        */
        VecteurR3 allerPoint(VecteurR3 posActuelle, VecteurR3 destination, std::vector<Capteur> vCapteurs);
    protected:

    private:
};

#endif // NAIF_H
