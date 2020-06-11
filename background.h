#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include <stdio.h>
	#include <stdlib.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
	#include <SDL/SDL_mixer.h>
	#include <SDL/SDL_ttf.h>
	#include <time.h>
	#include <unistd.h>
#include"perso.h"



typedef struct 
{
SDL_Surface *image;
SDL_Surface *image2;
SDL_Surface *calque;
SDL_Surface *calque2;
Mix_Music *music;
/*Mix_chunk *son;*/
SDL_Rect positionback;
SDL_Rect positionback2;
SDL_Rect cam1;
SDL_Rect poscam1;
TTF_Font *texte;
} background;
void initialiser_background(background *back);
void Affiche_back(background back,SDL_Surface *ecran);
void scrolling1 (hero *hero,background *back,int d,int co);
void scrolling2 (hero *hero,background *back,int d2,int co);
#endif
