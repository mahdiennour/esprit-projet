#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct objet{

	SDL_Surface *afficher_objet;
	SDL_Rect pos_objet;
}objet;
void initialiser_objet(objet *enemie1);
void afficher_objet(objet *enemie1,SDL_Surface *ecran, hero evan);
int Collision_Bounding_Box (hero evan ,objet enemie1 );
