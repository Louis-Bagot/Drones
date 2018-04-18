#ifndef PYRAMIDALE_H
#define PYRAMIDALE_H

#include <Formation.h>

/**
 * Classe fille de Formation; dessine une pyramide.
 * @author Margot, Théau et Morgan
 * @date 13/04/18
 */

class Pyramidale : public Formation
{
    public:
        Pyramidale();
        virtual ~Pyramidale();

    protected:
  /** Points formant la base de la pyramide*/
	Vector<VecteurR3> vPointsBase;
  /** Point sommet de la pyramide*/
	VecteurR3 sommet;

    private:
};

#endif // PYRAMIDALE_H
