#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

/**
* @author Timothé, Simon
* Classe contenant les éléments de l'environnement et leurs positions (i.e Essaim, Obstacles, colis)
* Gère la détection de collision et le calcul de la position des drones.
* C'est le moteur physique du projet.
*/
class Environnement {
    private:
        /** Liste des obstacles de l'environnement */
        vector<Obstacle> vObstacles;
        /** Essaim de drone, c'est l'ensemble de drones */
        Essaim essaim;
        /** Constante de gravité, perpétuellement subie par les drones */
        const float g;
        /** Liste des colis présents dans l'environnement */
        vector<VecteurR3> vColis;

        /** Calcule la position d'un drone en prenant en compte le vecteur accélération du drone et la gravité de l'environnement */
        void calculerPos(Drone);
        /** Vérifie si un drone entre en collision avec un obstacle ou un autre drone. */
        bool collision(Drone);
    public:
        Environnement();
        virtual ~Environnement();
        /** Surchage de l'opérateur ++, afin de passer au temps+1 */
        operator++();

    protected:
};

#endif // ENVIRONNEMENT_H
