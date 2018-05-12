#include "../include/Obstacle.h"

Obstacle::Obstacle(VecteurR3 _init, float _taillex, float _tailley, float _taillez){
  taillex = _taillex;
  tailley = _tailley;
  taillez = _taillez;
  init = _init;
  vSommets.push_back(_init);
  _init+=VecteurR3(0,tailley,0);
  vSommets.push_back(_init);
  _init+=VecteurR3(taillex,0,0);
  vSommets.push_back(_init);
  _init+=VecteurR3(0,-tailley,0);
  vSommets.push_back(_init);
  _init+=VecteurR3(0,0,taillez);
  vSommets.push_back(_init);
  _init+=VecteurR3(-taillex,0,0);
  vSommets.push_back(_init);
  _init+=VecteurR3(0,tailley,0);
  vSommets.push_back(_init);
  _init+=VecteurR3(taillex,0,0);
  vSommets.push_back(_init);
}

Obstacle::~Obstacle()
{
    //dtor
}
vector<VecteurR3> Obstacle::getVSommets() const {
    return vSommets;
}

vector<VecteurR3> Obstacle::getFaceYGauche() const {
  std::vector<VecteurR3> vSommetsFace;
  vSommetsFace.push_back(vSommets[0]);
  vSommetsFace.push_back(vSommets[5]);
  vSommetsFace.push_back(vSommets[4]);
  vSommetsFace.push_back(vSommets[3]);
  return vSommetsFace;
}
vector<VecteurR3> Obstacle::getFaceYDroite() const {
  std::vector<VecteurR3> vSommetsFace;
  vSommetsFace.push_back(vSommets[2]);
  vSommetsFace.push_back(vSommets[1]);
  vSommetsFace.push_back(vSommets[6]);
  vSommetsFace.push_back(vSommets[7]);
  return vSommetsFace;
}
vector<VecteurR3> Obstacle::getFaceXAvant() const {
  std::vector<VecteurR3> vSommetsFace;
  vSommetsFace.push_back(vSommets[3]);
  vSommetsFace.push_back(vSommets[2]);
  vSommetsFace.push_back(vSommets[7]);
  vSommetsFace.push_back(vSommets[4]);
  return vSommetsFace;
}
vector<VecteurR3> Obstacle::getFaceXArriere() const {
  std::vector<VecteurR3> vSommetsFace;
  vSommetsFace.push_back(vSommets[1]);
  vSommetsFace.push_back(vSommets[6]);
  vSommetsFace.push_back(vSommets[5]);
  vSommetsFace.push_back(vSommets[0]);
  return vSommetsFace;
}
vector<VecteurR3> Obstacle::getFaceZHaut() const {
  std::vector<VecteurR3> vSommetsFace;
  vSommetsFace.push_back(vSommets[7]);
  vSommetsFace.push_back(vSommets[6]);
  vSommetsFace.push_back(vSommets[5]);
  vSommetsFace.push_back(vSommets[4]);
  return vSommetsFace;
}
vector<VecteurR3> Obstacle::getFaceZBasse() const {
  std::vector<VecteurR3> vSommetsFace;
  vSommetsFace.push_back(vSommets[3]);
  vSommetsFace.push_back(vSommets[2]);
  vSommetsFace.push_back(vSommets[1]);
  vSommetsFace.push_back(vSommets[0]);
  return vSommetsFace;
}

VecteurR3 Obstacle::getInit() const {return init;}
float Obstacle::getTailleX() const {return taillex;}
float Obstacle::getTailleY() const {return tailley;}
float Obstacle::getTailleZ() const {return taillez;}
