#ifndef DRONE_H
#define DRONE_H

#include "../include/VecteurR3.h"
#include "../include/Comportement.h"
#include <cstddef>
#include<vector>
#include<queue>

/**
* Agent du réseau qui a pour principale fonctionnalité de pouvoir se rendre d'un point à un autre, en suivant liste d'objectifs. Il se déplace en se donnant un vecteur accélération, qui donnera sa vitesse et position en temps t+1 via la classe Environnement.
* @author Louis, Quentin
*/
class Drone {
  private:
    /** Rayon du Drone, puisqu'il est modélisé comme une sphère */
    float rayon;
    /** Indique si le Drone porte un colis. */
    bool porteColis;
    /** Indique si le Drone ne s'est pas pris un Obstacle (fixe) ou un autre Drone. */
    bool fonctionne;
    /** Classe gestionnaire du vecteur accélération, en se basant sur les objectifs et les Capteurs du Drone. */
    Comportement comportement;
    /** Position du Drone dans l'espace. */
    VecteurR3 position;
    /** Vitesse du Drone, calculée à partir de l'accélération et de la vitesse en t-1. */
    VecteurR3 vitesse;
    /** Vecteur accélération du Drone, donné par le Comportement en fonction de son voisinage. Mis à jour à chaque tour de boucle. */
    VecteurR3 acceleration;
    /** Ensemble des Capteurs du Drones, répartis autour de ce dernier. Cela permet de discrétiser son voisinage et les informations reçues. */
    std::vector<Capteur> vCapteurs;
    /** Liste des objectifs du Drone - c'est-à-dire liste de colis à livrer ou de position de formation à laquelle aller. */
    std::queue<VecteurR3> vObjectifs;
    /** Fonction qui renvoie vrai si le drone a atteint le premier de ses objectifs */
    bool objectifDone();
    /** Setter de l'accélération */
    void setAcceleration(const VecteurR3& acc);

  public:

    /** Constructeur de Drone pour tests */
    Drone(const std::vector<Capteur>&);
    /** Constructeur avec simplement la position initiale */
    Drone(const std::vector<Capteur>&,const VecteurR3);
    /** Constructeur de Drone, initialisant les attributs spatio-temporels à 0. Nécessite un Comportement, une taille, un nombre de capteurs */
    Drone(const Comportement&, std::vector<VecteurR3>);
    /** Constructeur de Drone, initialisant la position à celle demandée. */
    Drone(const Comportement&, std::vector<VecteurR3>, VecteurR3);
    /** Constructeur de Drone, initialisant la position et la vitesse à celles demandées. */
    Drone(const Comportement&, std::vector<VecteurR3>, VecteurR3, const VecteurR3&);
    /** Constructeur effectif de Drone. Prend une position initiale, un rayon et un vecteur de Capteurs. */
    Drone(float rayon, VecteurR3, std::vector<Capteur>);
    /** Constructeur effectif de Drone. Prend une position et vitesse initiales, un rayon et un vecteur de Capteurs. */
    Drone(float rayon, VecteurR3 pos, VecteurR3 vit, std::vector<Capteur>);

    void operator++();
    /** Destructeur de Drone. */
    virtual ~Drone();

    /** Getter des objectifs du Drone */
    std::vector<VecteurR3> getObjectifs() const;
    /** Getter du vecteur de capteurs */
    std::vector<Capteur> getvCapteurs() const;
    /** Getter du vecteur position */
    VecteurR3 getPosition() const;
    /** Getter du vecteur vitesse */
    VecteurR3 getVitesse() const;
    /** Getter du vecteur acceleration */
    VecteurR3 getAcceleration() const;
    /** Setter du vecteur position */
    void setPosition(const VecteurR3);
    /** Setter du vecteur vitesse */
    void setVitesse(const VecteurR3);
    /** Setter du vecteur acceleration */
    void setAcceleration(const VecteurR3);
    /** Getter du rayon du Drone */
    float getRayon() const;
    /** affecte au bool 'fonctionne' la valeur false. */
    void neFonctionnePlus();
    /** Getter sur l'état du drone */
    bool estFonctionnel() const;
    /**
    * Méthode qui ajoute une destination à la liste des objectifs.
    * @param obj le point de R3 à ajouter à la liste d'objectifs.
    */
    void ajouterObjectif(const VecteurR3& obj);
    /**
    * Ajoute à liste des objectifs le point de retrait et de dépôt du colis.
    * @param retrait Le point auquel récupérer le colis.
    * @param depot Le point auquel déposer le colis.
    */
    void livrerColis(const VecteurR3& retrait, const VecteurR3& depot);
};

#endif // DRONE_H
