#ifndef CUBIQUE_H
#define CUBIQUE_H

#include <Formation.h>

/**
 * \file Cubique.h
 * \brief classe fille de Formation
 * \author Margot, Théau et Morgan
 * \date 13/04/18
 *
 */

class Cubique : public Formation
{
    public:
        Cubique();
        virtual ~Cubique();

    protected:
    
    Vector<VecteurR3> vPointsCube; /*! Liste des points formant le cube*/
    float longueurCote; /*! Longueur du côté du cube*/

    private:
};

#endif // CUBIQUE_H
