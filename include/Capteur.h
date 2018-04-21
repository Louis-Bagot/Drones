#ifndef CAPTEUR_H
#define CAPTEUR_H
/**
* @authors Timothé
* @ 20 Avril 2018
*
* Les capteurs sont les outils nécéssaires aux drones pour detecter les
* obstacles alentours à une distance donnée.
*/


class Capteur {
    public:


      /** Constructeur de Capteur initialisant tous ses paramètres à des valeurs données en entrée. */
        Capteur(const float &p, const float &d, const VecteurR3 &dir, const Environnement &environnement);

     /** Déstructeur de Capteur */
        virtual ~Capteur();

    /**
     * Calcul la distance entre le drone et les obstacles alentours. La fonction sera appelée par drone,
    de manière itérative.
     */
        float updateDistanceDetectee();
    protected:

    private:
      /** Distance maximale à laquelle peut "voir" un Capteur */
      float portee;
      /** Distance actuellement détectée. <= portee. */
      float distanceDectectee
      /** Direction dans laquelle le Capteur regarde, relativement au Drone. */
      VecteurR3 direction;
      /** Environnement dans lequel se trouve le Drone et donc son Capteur. Permet à se dernier de se donner une valeur à chaque instant. */
      Environnement env;
      /** Position du Drone associé au Capteur, permettant le calcul de distanceDectectee
      */
      VecteurR3 positionDrone;
      /** Sera initiliasité lors de l'attribution du drone */
      float tailleDrone;
};

#endif // CAPTEUR_H
