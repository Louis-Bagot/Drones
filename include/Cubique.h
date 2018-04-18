#ifndef CUBIQUE_H
#define CUBIQUE_H

#include <Formation.h>

/**
 * Classe fille de Formation, qui permet de dessiner un cube.
 * @author Margot, Théau et Morgan
 * @date 13/04/18
 */
class Cubique : public Formation {
    public:
        /** Constructeur de la Formation. */
        Cubique();
        /** Destructeur usuel de la Formation. */
        virtual ~Cubique();

    protected:
    /** Liste des points formant le cube. */
    Vector<VecteurR3> vPointsCube;
    /** Longueur du côté du cube*/
    float longueurCote;

    private:
};

#endif // CUBIQUE_H
