#ifndef NAIF_H
#define NAIF_H

#include <vector>
#include "../include/VecteurR3.h"
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
        * A partir des positions du Drone, de son premier objectif et des capteurs, d�termine le vecteur acc�l�ration pour la frame suivante.
        * @param posActuelle la position du Drone au temps t.
        * @param destination la position � atteindre.
        * @param vCapteurs, le vecteur des Capteurs donnant l'information sensorielle du Drone.
        * @return le vecteur acc�l�ration
        */
        VecteurR3 allerPoint(const VecteurR3 &posActuelle,const VecteurR3 &destination, std::vector<Capteur> vCapteurs)const;

        VecteurR3 setTrajectory(const VecteurR3 &posActuelle,const VecteurR3 &destination)const;

        bool atteintFinal(const VecteurR3 &posActuelle,const VecteurR3 &destination)const;

        bool atteint(const VecteurR3 &posActuelle,const VecteurR3 &destination) const;

        bool presenceObstacles(std::vector<Capteur> vCapteurs) const;

        VecteurR3 surmonter(const VecteurR3 &posActuelle) const;

        VecteurR3 gererHauteur(const VecteurR3 &destination) const;


    protected:

    private:
};

#endif // NAIF_H
