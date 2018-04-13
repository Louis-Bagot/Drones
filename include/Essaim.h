#ifndef ESSAIM_H
#define ESSAIM_H
/**
* @author Timothé, Simon
* La classe Essaim est celle qui contient l'ensemble des drones
* et a pour objectif de contrôler leurs objectifs (Attribution des colis aux drones, formations, ...)
*
*/

class Essaim {
    public:
        Essaim();
        virtual ~Essaim();
        /// Ordre d'aller retirer un colis. Le drone qui doit aller le colis au point B est determiné dans le corps de la fonction et non passé en entrée
        void retirerColis(VecteurR3 B);

        /// Ordre aux drones de l'essaim de réaliser une formation
        void formation(Formation F);
    protected:

    private:
        /// L'ensemble des drones qui composent l'essaim
        vector<Drone> vDrones;
        /**
        * @return Vecteur qui donne l'ordre des drones dans le vecteur pos (vecteur d'entrée)
        * ex : vector<int> = [2, 1, 3], le drone numéro 2 ira à vPosFormation[1]
        */
        vector<int> affecterDronePos(vector<VecteurR3> vPosFormation);
};

#endif // ESSAIM_H
