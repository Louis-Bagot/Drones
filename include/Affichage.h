#ifndef AFFICHAGE_H
#define AFFICHAGE_H

/**
* @author Timothé, Simon
* Classe qui permet d'afficher en 3D l'environnement
* i.e. drones, obstacles
* utilise openGL et SDL
*/
class Affichage
{
    public:
        Affichage(const &Environnement);
        virtual ~Affichage();
        /// affiche l'envrionnement
        void draw();
    protected:

    private:
        /// attribut passé dans le constructeur, contient tous les éléments à afficher
        Environnement env;
};

#endif // AFFICHAGE_H
