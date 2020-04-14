#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include"perso.h"


void initialiser_evan(hero *hero)
{
			hero->image_hero[0]=IMG_Load("droite1.jpg");
			hero->image_hero[1]=IMG_Load("droite2.jpg");
			hero->image_hero[2]=IMG_Load("droite3.jpg");
			hero->image_hero[3]=IMG_Load("gauche1.jpg");
			hero->image_hero[4]=IMG_Load("gauche2.jpg");
			hero->image_hero[5]=IMG_Load("gauche3.jpg");
			
	
		hero->num=0;
		
		hero->positionhero.x=100;
		 hero->positionhero.y=50;
   hero->score=0;
   hero->vie=5; 

}


void afficher_hero(hero hero,SDL_Surface *ecran)
       {
		
		SDL_BlitSurface(hero.image_hero[hero.num],NULL,ecran,&(hero.positionhero));
                SDL_Delay(300);
	}



int animation_perso(hero hero)
{
		
int num=hero.num;

	switch(hero.mouv)
{
	
	case 1:
	  if (num<6)
	      num++;
	  else num=0;
             usleep(100);  // retarde l 'execution du programme pendant qsq microseconde//					
	     break;
        case 2:
	   if (num<6)
        	num++;
	   else num=0;			
	     usleep(100);		
	     break;	
}
	return num;
}

int deplacement(hero evan,SDL_Event *event){
	
	 	int mouv;
	
	 	SDL_PollEvent(event);
	 	switch (event->type)
	        {
	        case SDL_QUIT:
	           mouv=0;
	            break;
	        case SDL_KEYDOWN:
	            switch (event->key.keysym.sym)
	            {
	            case SDLK_ESCAPE:
	                mouv=0;
	                break;
	            case SDLK_RIGHT: //flechedroite//
			mouv=1;
	                break;
	            case SDLK_LEFT: 	            
                       mouv=2;          
	                break;
	            case SDLK_UP: 
	                mouv=3;  
	                 break;
	            }
	            break;
	             
	     }
	 
	 return mouv;
	
	}



int main(  int argc,  char *argv[]  )
{
		SDL_Surface *ecran =NULL;
		hero hero ;
		int continuer =1;
		SDL_Init(SDL_INIT_VIDEO);
		initialiser_evan(&hero);
		hero.num=0;
		SDL_Event event;
		ecran = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
		while(continuer)
       {
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
			hero.mouv=deplacement(hero,&event);
			afficher_hero(hero,ecran);
			hero.num=animation_perso(hero);
	
			SDL_Flip(ecran);
		
	}

               
}

	

