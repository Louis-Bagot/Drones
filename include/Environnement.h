#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

/**
* @author Timoth�, Simon
* Classe contenant les �l�ments de l'environnement et leurs positions (i.e Essaim, Obstacles, colis)
* G�re la d�tection de collision et le calcul de la position des drones.
* C'est le moteur physique du projet.
*/
class Environnement
{
    public:
        Environnement();
        virtual ~Environnement();
        ///Surchage de l'op�rateur ++, afin de passer au temps+1
        operator++();

    protected:

    private:
        /// Liste des obstacles de l'environnement
        vector<Obstacle> vObstacles;
        /// Essaim de drone, c'est l'ensemble de drone
        Essaim essaim;
        /// constante gravit� subit par les drones
        const float g;
        /// liste des colis pr�sents dans l'environnement
        vector<VecteurR3> vColis;
        /// calcule la position d'un drone en prenant en compte le vecteur acc�l�ration du drone et la gravit� de l'environnement
        void calculerPos(Drone);
        /// v�rifie si un drone entre en collision et un obstacle ou un autre drone.
        bool collision(Drone);
};

#endif // ENVIRONNEMENT_H
