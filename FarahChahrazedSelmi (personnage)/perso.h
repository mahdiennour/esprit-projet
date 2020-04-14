#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED
	#include <stdio.h>
	#include <stdlib.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
	#include <SDL/SDL_mixer.h>
	#include <SDL/SDL_ttf.h>
	#include <time.h>
	#include <unistd.h>
	
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
	void initialiser_evan(hero *hero);
	int animation_perso(hero hero);
	void afficher_hero(hero hero,SDL_Surface *ecran);
	int deplacement(hero hero,SDL_Event *event);
	/*void AfficheScore(hero hero,screen *e);
        int Collision_perso(hero hero, background back);*/
 	#endif
