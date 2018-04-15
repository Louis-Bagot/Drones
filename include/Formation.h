#ifndef FORMATION_H
#define FORMATION_H

/**
 * \file formation.h
 * \brief classe abstraite
 * \author Margot, Théau et Morgan
 * \date 13/04/18
 *
 */


class Formation
{
	
    public:
        Formation();
        virtual ~Formation();
        
 /**
 * \fn virtual Vector<VecteurR3> générerMaillage() = 0;
 * \brief Fonction permettant de générer le maillage
 * \return Retourne une nouvelle liste de vecteurs
 */
        virtual Vector<VecteurR3> générerMaillage() = 0;

    protected:
    float altitude; /*! Altitude de la formation */
	int nbDrones; /*! Le nombre de drones qui composent la formation */
	
    private:
};

#endif // FORMATION_H
