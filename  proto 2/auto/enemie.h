#ifndef Ennemi_H
#define Ennemi_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
typedef enum STATE STATE;
enum STATE {WAITING,FOLLOWING,ATTACKING};
struct ennemi
{
SDL_Surface* image;
SDL_Rect positionAbsolue;
SDL_Rect position;
SDL_Surface *image[3];
SDL_Surface *image2[3];
SDL_Surface *Hit;
SDL_Surface *imageActuel;
SDL_Rect position;
SDL_Rect positionO;
SDL_Rect pos_Enemy;
int frame;
int direction;
int died;
STATE State;
};
typedef struct ennemi Ennemi;
Enemy InitEnemy(Enemy Ennemie,int x, int y);
void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen);
Enemy AnimateEnemy(Enemy Ennemie,int stat);
Enemy MoveEnemy(Enemy Ennemie,SDL_Rect personnage,int *stat,int mouvment);
Enemy diedennemie(Enemy Ennemie,int coe);
#endif
