#ifndef Ennemi_H
#define Ennemi_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
typedef struct hero
	{
		int mouv; //droite ou gauche //
		SDL_Rect pos_hero[6];
		SDL_Surface *image_hero[6];
	        SDL_Rect positionhero;
		int num;
		int vie;
		int score;
	}hero;
typedef struct Enemy
{
  SDL_Surface *image[3];
  SDL_Surface *image2[3];
  SDL_Surface *Hit;
  SDL_Surface *imageActuel;
  SDL_Rect position;
  SDL_Rect positionO;
  SDL_Rect pos_Enemy;
  int frame;
  int direction;
  

}Enemy;
typedef struct Ennemi Ennemi;

void initialiser_evan(hero *evan); 
void afficher_evan(hero evan,SDL_Surface *ecran);
Enemy InitEnemy(Enemy Ennemie,int x, int y);
void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen);
Enemy AnimateEnemy(Enemy Ennemie,int stat);
Enemy MoveEnemy(Enemy Ennemie,SDL_Rect personnage,int *stat,int mouvment);
int Collision_Bounding_Box (hero evan ,Enemy Ennemie );
#endif
