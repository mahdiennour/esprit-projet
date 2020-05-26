#ifndef SAUV_H_INCLUDED
#define SAUV_H_INCLUDED


 typedef struct Enemy
 {
             SDL_Surface *image[3];
             SDL_Surface *image2[3];
             SDL_Surface *Hit;
             SDL_Surface *imageActuel;
             SDL_Rect position;
             SDL_Rect positionO;
             int frame;
             int direction;
 
 }Enemy;



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


typedef struct 
{
               SDL_Surface *image;
               //Mix_Music *music;
               //Mix_chunk *son;
               SDL_Rect positionback;
               //TTF_Font *texte;
        } background;


	
typedef struct
       {
		int num; 
		SDL_Surface *afficher_map; 
		SDL_Rect pos_map;   
                SDL_Surface *afficher_perso;
                SDL_Rect pos_perso; 
                
            
	}map;

void sauvegarde (char nomfich[20]);
void lire (char nomfich[20]);

//structure//
background back;
Enemy E;
hero perso;
map M;

#endif




