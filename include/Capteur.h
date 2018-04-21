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
        Capteur(const float &p, const float &d, const VecteurR3 &dir, const Environnement &environnement);

     /** Deconstructeur de Capteur */
        virtual ~Capteur();

    /*
     * Calcul la distance entre le drone et les obstacles alentours. La fonction sera appelée par drone,
    de manière itérative.
     */
        float updateDistanceDetectee();
    protected:

    private:
      float portee;
      float distanceDectectee
      VecteurR3 direction;
      Environnement env;
      /** Elle sera recalculé à chaque déplacement du drone. Indispensable pour connaitre
      * la distance avec l'obstacle detectée
      */
      VecteurR3 positionCapteur;
      /** Sera initiliasité lors de l'attribution du drone*/
      float tailleDrone;

};

#endif // CAPTEUR_H
