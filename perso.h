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
	
	typedef struct 
	{
		int mouv;
                int mouv2;
		SDL_Rect pos_hero;
                SDL_Rect pos_hero2;
		SDL_Surface *image_hero[6];
	        SDL_Surface *image_hero2[6];
		int num,num2;
		int vie,vie2;
		int score,score2;
                int heromoved,heromoved2;
                int direction,direction2;

	}hero;
	void initialiser_evan(hero *hero);
        void initialiser_evan1(hero *hero);
	int animation_perso(hero hero);
        int animation_perso2(hero hero);
	void afficher_hero(hero hero,SDL_Surface *ecran);
	int deplacement1(hero *hero,SDL_Event *event);
        int deplacement2(hero *hero,SDL_Event *event);
	/*void AfficheScore(hero hero,screen *e);
        int Collision_perso(hero hero, background back);*/
 	/*SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);*/
        /*int Collision_perfect_pixel(SDL_Surface *screen, hero *hero);*/
       SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
       int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);
       int collision_Parfaite2(SDL_Surface *calque2,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);
       void GestionVie(SDL_Surface *ecran, hero hero);
      
       #endif
