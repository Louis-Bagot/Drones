#ifndef PYRAMIDALE_H
#define PYRAMIDALE_H

#include <Formation.h>

/**
 * \file Pyramidale.h
 * \brief classe fille de Formation
 * \author Margot, Théau et Morgan
 * \date 13/04/18
 *
 */

class Pyramidale : public Formation
{
    public:
        Pyramidale();
        virtual ~Pyramidale();
        
        afficher

    protected:
    
	Vector<VecteurR3> vPointsBase;  /*! Points formant la base de la pyramide*/
	VecteurR3 sommet;  /*! Sommet de la pyramide*/
	
    private:
};

#endif // PYRAMIDALE_H
