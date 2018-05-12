#include "../include/Affichage.h"

Affichage::Affichage(const Environnement& _env) {
  env = _env; // Copie par référence : ils pointent maintenant sur le même objet
}

Affichage::~Affichage() {
    //dtor
}

void Affichage::draw(TrackBallCamera *camera, GLuint droneText) {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity( );

  camera->look();
  glClearColor(0.1,0.1,0.1,0.1);
  drawAxis();
  drawBox(env.getCote());

  // Affichage des Obstacles
  drawObstacles();

  // Affichage des Drones (préparation spheres: quadratic)
  GLUquadric* params = gluNewQuadric();
  gluQuadricTexture(params,GL_TRUE);
  glBindTexture(GL_TEXTURE_2D,droneText);

  for (const auto & pDrone : env.getEssaimDrones())
    drawDrone(*pDrone,params);

  gluDeleteQuadric(params);

  // Affichage éventuel des colis (TODO, plus tard)

  // Fin de méthode, clean openGL
  glFlush();
  SDL_GL_SwapBuffers();

}

void Affichage::drawObstacles() {
  glBegin(GL_QUADS);
    for (auto& obs : env.getVObstacles()) {
      int color = 100;
      int colorInc = 20;
      glColor3ub(color,color,color); //face grise claire

      // Affichage de chaque face :
      // Faces Y constant
      for (auto& point : obs.getFaceYGauche())
        glVertex3d(point.getX(), point.getY(), point.getZ());
      color+=colorInc;
      glColor3ub(color,color,color);

      for (auto& point : obs.getFaceYDroite())
        glVertex3d(point.getX(), point.getY(), point.getZ());
      color+=colorInc;
      glColor3ub(color,color,color);

      //Faces X constant
      for (auto& point : obs.getFaceXAvant())
        glVertex3d(point.getX(), point.getY(), point.getZ());
      color+=colorInc;
      glColor3ub(color,color,color);

      for (auto& point : obs.getFaceXArriere())
        glVertex3d(point.getX(), point.getY(), point.getZ());
      color+=colorInc;
      glColor3ub(color,color,color);

      // Faces Z constant
      for (auto& point : obs.getFaceZHaut())
        glVertex3d(point.getX(), point.getY(), point.getZ());
      color+=colorInc;
      glColor3ub(color,color,color);

      for (auto& point : obs.getFaceZBasse())
        glVertex3d(point.getX(), point.getY(), point.getZ());
      color+=colorInc;
      glColor3ub(color,color,color);
    }
    glEnd();
}

void Affichage::drawDrone(const Drone& drone, GLUquadric* params) const {
  if (drone.estFonctionnel()) {
    glColor3ub(255,255,255);
  } else {
    glColor3ub(255,0,0);
  }
  VecteurR3 pos = drone.getPosition();
  glTranslated(pos.getX(),pos.getY(),pos.getZ());
  gluSphere(params,drone.getRayon(),10,10);
  glTranslated(pos.getX()*-1,pos.getY()*-1,pos.getZ()*-1);
}
