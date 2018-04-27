#include "../include/Affichage.h"

Affichage::Affichage(const Environnement& originEnv) {
  env = originEnv; // Copie par référence : ils pointent maintenant sur le même objet
}

Affichage::~Affichage() {
    //dtor
}

void Affichage::draw() {
  // Affichage des Obstacles
  
  // Affichage des Drones

  // Affichage éventuel des colis (TODO, plus tard)
}
