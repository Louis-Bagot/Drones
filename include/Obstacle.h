#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "../include/VecteurR3.h"
#include <vector>
/**
* Classe des obstacles qui seront dans l'environnement
* On considere que tous les obstacles sont des pavés droits.
* Cette classe est donc en fait une simple liste de points representant les sommets de l'obstacle
*
* @author Simon
*/

using namespace std;

class Obstacle {
  public:
      /** Constructeur de pavé droit
      * Ordre : base en horaire; haut en horaire (sens de rotation)
      * @param init la position du coin aux coordonnées x,y,z minimales
      */
      Obstacle(VecteurR3 init, float taillex, float tailley, float taillez);
      virtual ~Obstacle();
      /** Renvoie le vector des sommets */
      vector<VecteurR3> getVSommets() const;
      // Getters des faces de l'Obstacle
      /** Getter face gauche, Y constant. (4 sommets) */
      vector<VecteurR3> getFaceYGauche() const;
      /** Getter face droite, Y constant. (4 sommets) */
      vector<VecteurR3> getFaceYDroite() const;
      /** Getter face avant, X constant. (4 sommets) */
      vector<VecteurR3> getFaceXAvant() const;
      /** Getter face arriere, X constant. (4 sommets) */
      vector<VecteurR3> getFaceXArriere() const;
      /** Getter face haute, Z constant. (4 sommets) */
      vector<VecteurR3> getFaceZHaut() const;
      /** Getter face basse, Z constant. (4 sommets) */
      vector<VecteurR3> getFaceZBasse() const;
      /** Getter point inital (coordonnées x,y,z minimales) */
      VecteurR3 getInit() const;
      /** Getter taille de cote en x */
      float getTailleX() const;
      /** Getter taille de cote en y */
      float getTailleY() const;
      /** Getter taille de cote en z */
      float getTailleZ() const;
  protected:

  private:
      vector<VecteurR3> vSommets;
      VecteurR3 init;
      float taillex;
      float tailley;
      float taillez;
};

#endif // OBSTACLE_H
