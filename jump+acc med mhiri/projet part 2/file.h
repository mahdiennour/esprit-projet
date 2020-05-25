#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>

typedef struct {
	SDL_Surface *textDt;
	SDL_Surface *textPosition;
	//SDL_Surface *textVitesse;
	SDL_Surface *textAcceleration;
}Text;
 

typedef struct
{
    SDL_Surface *image;
    SDL_Rect postion;
}image;



typedef struct
{  
    int sens;
    SDL_Surface *image;
    SDL_Rect postion;
    float acceleration;
    float vitesse;
}perso;

typedef struct
{
  int x;
  int y;
   
}pos;



typedef struct
{
  image background;
  perso person;
  
   
}ttimage;

void initText(Text *T);
int loadFont(TTF_Font **police);
void displayText(TTF_Font *police,Text *T,SDL_Surface *screen,ttimage *allin,Uint32 dt);
int fnparabole(int x);
void affichejump(ttimage *allin,SDL_Surface *screen);
void initialiser_image_position(ttimage *allin);
void move(ttimage *allin ,SDL_Event event ,SDL_Surface *screen,int *gameover,Uint32 dt);
void affichesimple(SDL_Surface *image ,SDL_Rect pos,SDL_Surface *screen);
void afficheall(ttimage *allin,SDL_Surface *screen);

#endif // FILE_H_INCLUDED
