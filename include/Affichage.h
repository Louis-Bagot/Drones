#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "../include/Environnement.h"

/**
* Classe qui permet d'afficher en 3D l'Environnement.
* Cela inclut principalement les Drones et les Obstacles.
* Utilise openGL et SDL
* @authors Timothé, Simon
*/
class Affichage {
    private:
        /** Attribut passé dans le constructeur et Environnement vers lequel pointer; contient tous les éléments à afficher. */
        Environnement env;
    public:
        /** Un constructeur utilisant un environnement pour s'y lier par pointeur.
        * @param env l'Environnement vers lequel pointer; sur lequel Affichage devra faire son travail.
        */
        Affichage(const Environnement& env);
        /** Simple Destructeur de l'Affichage. */
        virtual ~Affichage();
        /** Méthode principale, affichant l'Environnement en attribut */
        void draw();
    protected:
};

#endif // AFFICHAGE_H
