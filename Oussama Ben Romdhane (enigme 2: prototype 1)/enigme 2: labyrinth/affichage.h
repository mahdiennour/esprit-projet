#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <SDL/SDL.h>
#include "constantes.h"
 
/* contantes concernant l'affichage */
#define TAILLE_BLOC             20
#define TAILLE_PORTE            2
#define HAUTEUR_FENETRE         TAILLE_BLOC * HAUTEUR + NOMBRE_PORTE_HAUTEUR * TAILLE_PORTE
#define LARGEUR_FENETRE         TAILLE_BLOC * LARGEUR + NOMBRE_PORTE_LARGEUR * TAILLE_PORTE
 
int quadrille(SDL_Surface *ecran);
int nombreLignes();
void ouvrePorte(SDL_Surface *ecran, int x, int y, int direction);
SDL_Color GetPixel(SDL_Surface *back,int x,int y);
int Collision_Parfaite_laby(SDL_Surface *back,int x, int y);
void menu(SDL_Surface *ecran);
void play(SDL_Surface *ecran);
#endif
