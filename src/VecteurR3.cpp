#include "../include/VecteurR3.h"
#include <cmath>
#include <stdexcept>

VecteurR3::VecteurR3() {
  x=0;
  y=0;
  z=0;
}

VecteurR3::VecteurR3(const float & cx,const float & cy,const float & cz) {
  x=cx;
  y=cy;
  z=cz;
}

VecteurR3::~VecteurR3() {
  // Destructeur vide (suppression de type float géré par le langage)
}

float VecteurR3::getX() const {return x;};
float VecteurR3::getY() const {return y;};
float VecteurR3::getZ() const {return z;};

float VecteurR3::operator[](const int& index) const {
  switch (index) {
    case 0: return x;
            break;
    case 1: return y;
            break;
    case 2: return z;
            break;
    default: throw std::out_of_range ("Index hors limites (0,1 ou 2 uniquement)");
  }
}

bool VecteurR3::egal (const VecteurR3 &vComp, const float &epsilon) const {
  return((std::abs(x-vComp.getX())<epsilon)&&std::abs(y-vComp.getY())<epsilon)
                                      &&std::abs(z-vComp.getZ())<epsilon;
}

VecteurR3 VecteurR3::operator+(const VecteurR3 &v) const {
  return(VecteurR3(x+v.getX(), y+v.getY(), z+v.getZ()));
}

VecteurR3 VecteurR3::operator-(const VecteurR3 &v) const {
  return(VecteurR3(x-v.getX(), y-v.getY(), z-v.getZ()));
}

void VecteurR3::operator=(const VecteurR3 &v) {
  x=v.getX();
  y=v.getY();
  z=v.getZ();
}

void VecteurR3::operator+=(const VecteurR3 &v) {
  x+=v.getX();
  y+=v.getY();
  z+=v.getZ();
}

float VecteurR3::operator*(const VecteurR3 &v) const {
  return(x*v.getX()+y*v.getY()+z*v.getZ());
}

VecteurR3 VecteurR3::operator*(const float &scal) const{
    float new_x, new_y, new_z;
  new_x=x*scal;
  new_y=y*scal;
  new_z=z*scal;

  return VecteurR3(x,y,z);
}

float VecteurR3::norme22() const {
  return(x*x+y*y+z*z);
}

float VecteurR3::norme2() const {
  return(sqrt(VecteurR3::norme22()));
}
