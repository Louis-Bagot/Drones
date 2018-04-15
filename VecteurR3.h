#ifndef VECTEURR3_H
#define VECTEURR3_H

#include <math.h>
/**
 * \brief gestion du type VecteurR3
 * \authors : Margot, Morgan, Théau
 * \version 1.0
 * \13 avril 2018
 * \Implementation des méthodes permettant l'initialisation d'un vecteur dans R3 + Comparaison et opérations (+,-,*,/,produit scalaire, norme)
 */

class VecteurR3
{
    float x,y,z;
    vector<double> v;
    
    public:
    
    /**
    * \fn Vecteur()
    * \brief Création d'un vecteur avec composantes nulles :
    */
    Vecteur()
    {
        for(int i=0; i<3;i++)
        {
            v.push_back(0.0);
        }
    }
    
    // Remplissage d'un vecteur :
    VecteurR3(float x,y,z)
    {
        V([1])=x;
        V([2])=y;
        V([3])=z;
    }
    
    //Comparaison de deux vecteurs :
    bool operator== (Vecteur V)
    {
        bool res = true;
        int i = 0;
        while(res && i < 3)
        {
            if(v[i] != V(i))
                res = false;
            i++;
        }
        return res;
    }
    
    //Addition de deux vecteurs composantes par composantes :
    VecteurR3 operator+(Vecteur V)
    {
        Vecteur Vres(3);
        for(int i=0;i<3;i++)
        {
            Vres.set(i, v[i]+V(i));
        }
        return Vres;
    }
    
    //Comparaison de deux vecteurs composantes par composantes :
    bool operator== (Vecteur V)
    {
        bool res = true;
        int i = 0;
        while(res && i < 3)
        {
            if(v[i] != V(i))
                res = false;
            i++;
        }
        return res;
    }
    
    //Affectation d'un vecteur :
    void operator=(Vecteur V)
    {
        for(int i=0;i<3;i++)
            v[i] = V(i);
    }
    
    //Soustraction de deux vecteurs composantes par composantes :
    Vecteur operator-(Vecteur V)
    {
        Vecteur Vres(3);
        for(int i=0;i<3;i++)
        {
            Vres.set(i, v[i]-V(i));
        }
        return Vres;
    }
    
    //Produit scalaire de deux vecteurs :
    float operator*(Vecteur V)
    {
        double res = 0;
        for (int i=0;i<3;i++)
            res += v[i]*V(i);
        return res;
    }
    
    //Multiplication d'un vecteur par un scalaire :
    Vecteur operator*(double scal)
    {
        Vecteur res(3);
        for(int i=0;i<3;i++)
            res.set(i,v[i]*scal);
        return res;
    }
    
    //Division de deux vecteurs composantes par composantes :
    Vecteur operator/(double scal)
    {
        Vecteur res(3);
        for(int i=0;i<3;i++)
            res.set(i,v[i]/scal);
        return res;
    }
    
    //Affectation d'une composante d'un vecteur :
    void set(int l,double val)
    {
        v[l] = val;
    }
    
    //Calcul de la norme du vecteur :
    float norme2()
    {
        double res = 0 ;
        for (int i=0; i<3; i++) {
            res += v[i]*v[i];
        }
        return sqrt(res);
    }
    
};

#endif // VECTEURR3_H
