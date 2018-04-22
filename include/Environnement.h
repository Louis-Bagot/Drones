#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include<vector>
#include "../include/Obstacle.h"
#include "../include/Essaim.h"
#include "../include/Drone.h"
#include "../include/VecteurR3.h"


/**
*
* Classe contenant les éléments de l'environnement et leurs positions (i.e Essaim, Obstacles, colis)
* Gère la détection de collision et le calcul de la position des drones.
* C'est le moteur physique du projet.
*
* @authors Timothé, Simon
*/
class Environnement {
    private:
        /** Point le plus négatif dans le cube de travail */
        VecteurR3 origineEnv;
        /** coté du cube */
        int cote;
        /** Liste des obstacles de l'environnement */
        std::vector<Obstacle> vObstacles;

        /** Essaim de drone, c'est l'ensemble de drones */
        Essaim essaim;

        /** Constante de gravité, perpétuellement subie par les drones */
        float g;
        /** Liste des colis présents dans l'environnement */
        std::vector<VecteurR3> vColis;

        /** Calcule la position d'un drone en prenant en compte le vecteur accélération du drone et la gravité de l'environnement */
        void calculerPos(&Drone);

        /** Vérifie si un drone entre en collision avec un obstacle ou un autre drone. */
        bool collision(Drone);

    public:
        /** Constructeur vide */
        Environnement(const float);
        /** Constructeur principal de l'Environnement */
        Environnement(const std::vector<Obstacle>&, const Essaim&, const float&);
        virtual ~Environnement();
        /** Surchage de l'opérateur ++, afin de passer au temps+1 */
        void operator++();
        void ajouterObstacle(std::vector<VecteurR3> &positionObstacle);
    protected:
};

#endif // ENVIRONNEMENT_H
