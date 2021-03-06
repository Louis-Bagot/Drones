#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "../include/VecteurR3.h"
#include<vector>
/**
* Classe des obstacles qui seront dans l'environnement
* On cosid�re que tous les obstacles sont des cubes.
* Cette classe est donc en fait une simple liste de points representant les sommets de l'obstacle
*
* @author Simon
*/

using namespace std;

class Obstacle {
    public:
        Obstacle(vector<VecteurR3>);
        virtual ~Obstacle();
        /** Renvoie le vector des sommets */
        vector<VecteurR3> getVSommets();
    protected:

    private:
        vector<VecteurR3> vSommets;
};

#endif // OBSTACLE_H
