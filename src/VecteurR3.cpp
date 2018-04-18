#include "../include/VecteurR3.h"
#include <math.h>

VecteurR3::VecteurR3() {
  x=0;
  y=0;
  z=0;
}

VecteurR3::VecteurR3(const float &cx, &cy, &cz) {
  x=cx;
  y=cy;
  z=cz;
}

VecteurR3::~VecteurR3() {
  // Destructeur vide (suppression de type float géré par le langage)
}

float getX() const {return x;};
float getY() const {return y;};
float getZ() const {return z;};

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

bool VecteurR3::operator== (const VecteurR3 &vComp, const float &epsilon) const {
  return((abs(x-vComp.getX())<epsilon)&&abs(y-vComp.getY())<epsilon)
                                      &&abs(z-vComp.getZ())<epsilon));
}

VecteurR3 VecteurR3::operator+(const VecteurR3 &v) const {
  return(VecteurR3(x+v.getX(), y+v.get(Y), z+v.getZ()));
}

VecteurR3 VecteurR3::operator-(const VecteurR3 &v) const {
  return(VecteurR3(x-v.getX(), y-v.get(Y), z-v.getZ()));
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

VecteurR3 VecteurR3::operator*(const float &scal) const {
  x*=scal;
  y*=scal;
  z*=scal;
}

float VecteurR3::norme22() const {
  return(x*x+y*y+z*z);
}

float VecteurR3::norme2() const {
  return(sqrt(VecteurR3::norme22()));
}
