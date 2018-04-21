#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "../include/VecteurR3.h"
#include<vector>
/**
* Classe des obstacles qui seront dans l'environnement
* On cosidère que tous les obstacles sont des cubes.
* Cette classe est donc en fait une simple liste de points representant les sommets de l'obstacle
*
* @author Simon
*/

using namespace std;

class Obstacle {
    public:
        Obstacle(vector<VecteurR3>);
        virtual ~Obstacle();
        /** Renvoie la vector des sommets */
        vector<VecteurR3> getSommets();
    protected:

    private:
        vector<VecteurR3> sommets;
};

#endif // OBSTACLE_H
