#include "../include/Environnement.h"
#include "../include/Obstacle.h"
#include "../include/Drone.h"
#include "../include/Essaim.h"
#include<vector>

/**
* @authors Timothé, Simon
*/
Environnement::Environnement( const float _g)
{
    g = _g;
    essaim = new Essaim();

}

Environnement::~Environnement()
{
    //dtor
}

void Environnement::ajouterObstacle(std::vector<VecteurR3> &positionObstacle) {
  vObstacles.push_back(new Obstacle(positionObstacle));
}

void Environnement::operator++()
{
    vector<Drone> vDrones = essaim.getVDrones();
    for(std::vector<Drone>::iterator it = vDrones.begin(); it !=vDrones.end(); ++it)
    {
        collision(*it);
        calculerPos(*it);
    }
}


void Environnement::calculerPos(Drone &drone)
{

}

bool Environnement::collision(const Drone drone)
{
    return false;
}
