#ifndef DLITE_H
#define DLITE_H

#include <Comportement.h>

/**
* Type de Comportement: algorithme Dlite: amélioration dynamique de l'algorithme de pathfinding conventionnel A*. */
class Dlite : public Comportement {
    public:
        /** Constructeur de l'algorithme. */
        Dlite();
        /** Destructeur de l'algorithme. */
        virtual ~Dlite();

    protected:

    private:
};

#endif // DLITE_H
