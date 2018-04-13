#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

/**
* @author Timothé, Simon
* Classe contenant les éléments de l'environnement et leurs positions (i.e Essaim, Obstacles, colis)
* Gère la détection de collision et le calcul de la position des drones.
* C'est le moteur physique du projet.
*/
class Environnement
{
    public:
        Environnement();
        virtual ~Environnement();
        ///Surchage de l'opérateur ++, afin de passer au temps+1
        operator++();

    protected:

    private:
        /// Liste des obstacles de l'environnement
        vector<Obstacle> vObstacles;
        /// Essaim de drone, c'est l'ensemble de drone
        Essaim essaim;
        /// constante gravité subit par les drones
        const float g;
        /// liste des colis présents dans l'environnement
        vector<VecteurR3> vColis;
        /// calcule la position d'un drone en prenant en compte le vecteur accélération du drone et la gravité de l'environnement
        void calculerPos(Drone);
        /// vérifie si un drone entre en collision et un obstacle ou un autre drone.
        bool collision(Drone);
};

#endif // ENVIRONNEMENT_H
