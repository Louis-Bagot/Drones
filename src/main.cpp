#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>

#include "../include/trackballcamera.h"
#include "../include/sdlglutils.h"
#include "../include/Environnement.h"
#include "../include/Essaim.h"
#include "../include/Affichage.h"

/**
 * \file main.cpp
 * Fichier contenant la fonction main, à lancer pour démarrer l'application Drone
*/

#define FPS 50
#define LARGEUR_FENETRE 1366
#define HAUTEUR_FENETRE 700

TrackBallCamera * camera;

void stop() {
    delete camera;
    SDL_Quit();
}

int main(int argc, char *argv[]) {
    //-- INITIALISATION DE L'ENVIRONNEMENT, ESSAIM, AFFICHAGE
    int nbDrones = 4;
    float envTailleCote = 2.;
    // Création des instances d'Essaim et Environnement
    Environnement env = Environnement(envTailleCote);
    env.ajouterObstacle(Obstacle(VecteurR3(0,0,env.getOrigineEnv().getZ()),1,0.5,0.5));
    env.ajouterObstacle(Obstacle(VecteurR3(-1,-1,env.getOrigineEnv().getZ()),0.5,0.5,1));
    Essaim essaim = Essaim(env, nbDrones);
    
    //Test retrait colis
    VecteurR3 retrait = new VecteurR3();
    VecteurR3 depot = new VecteurR3(0.5,0.5,0.5);
    env.ajouterColis(retrait);
    essaim.retirerColis(retrait, depot);
    
    // attribution de l'essaim  l'Environnement
    env.associerEssaim(essaim);
    // création de l'Affichage et lien à l'Environnement
    Affichage aff = Affichage(env);

    //-- INITIALISATIONS SDL / OPENGL

    SDL_Event event;
    const Uint32 time_per_frame = 1000/FPS;
    unsigned int width = LARGEUR_FENETRE;
    unsigned int height = HAUTEUR_FENETRE;

    Uint32 last_time,current_time,elapsed_time; //for time animation
    Uint32 start_time,stop_time; //for frame limit

    SDL_Init(SDL_INIT_VIDEO);
    atexit(stop);

    SDL_WM_SetCaption("Drone de L'ombre", NULL);
    SDL_SetVideoMode(width, height, 32, SDL_OPENGL);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    gluPerspective(70,(double)width/height,0.001,1000);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);


    GLuint droneText = loadTexture("image/DroneText.jpg");

    camera = new TrackBallCamera();
    camera->setScrollSensivity(0.1);

    last_time = SDL_GetTicks();
    for (;;) { // Boucle infinie, tant que l'utilisateur ne la break pas
        start_time = SDL_GetTicks();

        // GESTION D'ÉVÊNEMENT (INPUT UTILISATEUR)
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                exit(0);
                break;
                case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_p:
                      takeScreenshot("screen.bmp");
                      break;
                    case SDLK_ESCAPE:
                      exit(0);
                      break;
                    default :
                      camera->OnKeyboard(event.key);
                }
                break;
                case SDL_MOUSEMOTION:
                camera->OnMouseMotion(event.motion);
                break;
                case SDL_MOUSEBUTTONUP:
                case SDL_MOUSEBUTTONDOWN:
                camera->OnMouseButton(event.button);
                break;
            }
        }

        // CALCUL DE DELTA TEMPS pour le contrôle FPS
        current_time = SDL_GetTicks();
        elapsed_time = current_time - last_time;
        last_time = current_time;

        // NOUVELLE FRAME ENVIONNEMENT
        env++;
        // UPDATE VECTEURS ACC DRONES
        for (auto& pDrone : essaim.getVDrones()) {
            pDrone++;
        }
        // FONCTION D'AFFICHAGE
        aff.draw(camera, droneText);

        // Gestion du temps en cas de besoin (retardement si boucle trop rapide)
        stop_time = SDL_GetTicks();
        if ((stop_time - last_time) < time_per_frame) {
            //SDL_Delay(time_per_frame - (stop_time - last_time));
        }
    }

    return 0;
}
