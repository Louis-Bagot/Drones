#ifndef VECTEURR3_H
#define VECTEURR3_H

/**
 * Classe d'un vecteur dans R3, avec trois coordonnées et les opérations classiques des ensembles vectoriels.
 * @authors : Margot, Morgan, Théau, Louis
 * @version 1.0
 * @13 avril 2018
 */

class VecteurR3 {
  private:
    float x,y,z;

  public:

    /**
    * Constructeur de VecteurR3 initilisant les coordonnées à l'origine.
    */
    VecteurR3();
    /** Constructeur de VecteurR3 à partir de trois coordonnées données. */
    VecteurR3(const float& x,const float &y, const float& z);
    /** Destructeur d'un VecteurR3. */
    virtual ~VecteurR3();

    // Getters des coordonnées
    float getX() const;
    float getY() const;
    float getZ() const;
    /** Alternative aux getters : operateur [] */
    float operator[](const int&) const;

    /**Comparaison de deux vecteurs à un voisinage de rayon donné près
     * @param vComp le VecteurR3 auquel se comparer
     * @param epsilon la marge d'erreur que l'on se laisse
     * @return si le vecteur est bien le même que celui en entrée, à une précision epsilon
     */
    bool egal (const VecteurR3& vComp, const float& epsilon=0) const;

    /**Addition de deux vecteurs composante par composante */
    VecteurR3 operator+(const VecteurR3&) const;

    /**Soustraction de deux vecteurs composante par composante */
    VecteurR3 operator-(const VecteurR3&) const;

    /**Affectation d'un vecteur à partir d'un autre*/
    void operator=(const VecteurR3&);

    /** Addition des coordonnées acutelles avec celles d'un autre (raccourci +=)*/
    void operator+=(const VecteurR3&);

    /** Produit scalaire de ce vecteur avec un autre*/
    float operator*(const VecteurR3&) const;

    /**Multiplication d'un vecteur par un scalaire */
    VecteurR3 operator*(const float&) const;

    /** Norme AU CARRE du vecteur (pour optimisation, lorsque la distance même n'est pas nécessaire) */
    float norme22() const;

    /** Norme (ou distance à l'origine) du vecteur. Calcule simplement la racine de norme22. */
    float norme2() const;
};

#endif // VECTEURR3_H
