#include <SDL/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


#include "algorithme.h"
#include "constantes.h"
#include "affichage.h"
 

int main(int argc, char **argv)
{
    p_labyrinthe lab;
    SDL_Surface *ecran = NULL;
 
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "%s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    srand(time(NULL)); // initialisation de la graine pour les nombres aléatoires
    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32,
                                   SDL_HWSURFACE | SDL_DOUBLEBUF);
TTF_Init();
    if (!ecran)
    {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
 
    if (!quadrille(ecran))
    {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
 
    lab = creeLabyrinthe(ecran);
    if (!lab)
    {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

SDL_SaveBMP (ecran, "back.bmp");
  detruitLabyrinthe(lab);
menu(ecran);
play(ecran);


    SDL_Quit();
    return EXIT_SUCCESS;
}
