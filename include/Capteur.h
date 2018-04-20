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
      /** Constructeur de Capteur */
        Capteur(const float &p, const float &d, const VecteurR3, const Environnement);

     /** Deconstructeur de Capteur */
        virtual ~Capteur();

    /*
     * Calcul la distance entre le drone et les obstacles alentours. La fonction sera appelée par drone,
    de manière itérative.
     */
        float distanceObstacle();
    protected:

    private:
      float portee;
      float distanceDectectee
      VecteurR3 direction;
      Environnement env;

};

#endif // CAPTEUR_H
