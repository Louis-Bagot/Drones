#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "../include/Environnement.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include "../include/sdlglutils.h"
#include "../include/trackballcamera.h"
#include <iostream>
#include <vector>

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

        void drawDrones();
        /** Fonction d'affichage appelée dans la fonction principale 'draw',
         * gère l'affichage des Drones. Prend aussi les paramètres quadratiques pour éviter les répétitions.
         * @see draw */
        void drawDrone(const Drone&,GLUquadric*) const;
        void drawObstacles();
        void drawColis();
        /** Fonction d'affichage appelée dans la fonction principale 'draw',
        * gère l'affichage des Obstacles. @see draw */
        void drawObstacle();
        
    public:

        /** Un constructeur utilisant un environnement pour s'y lier par pointeur.
        * initialise aussi la texture des drones directement par une valeur donnée dans le constructeur.
        * @param env l'Environnement vers lequel pointer; sur lequel Affichage devra faire son travail.
        */
        Affichage(const Environnement& env);
        /** Simple Destructeur de l'Affichage. */
        virtual ~Affichage();
        /** Méthode principale, affichant l'Environnement en attribut */
        void draw(TrackBallCamera*, GLuint);
    protected:
};

#endif // AFFICHAGE_H
