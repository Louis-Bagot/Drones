#include "../include/Environnement.h"
/**
* @authors Timothé
*/
Environnement::Environnement()
{
    //ctor
}

Environnement::~Environnement()
{
    //dtor
}

Environnement::ajouterObstacle(vector<VecteurR3> &positionObstacle)
{
  Environnement.vObstacles.push_back(new Obstacle(positionObstacle));
}
