/**
* @file jeu.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include <stdio.h>
#include "perso.h"
#include "enemie.h"
#include"sauv.h"
#include"background.h"
#include"enigmes.h"
#include"objet.h"
void jouer (int test,int cont,int *mi)
{
SDL_Surface *ecran =NULL;
		hero hero ;
		background back;
pmap pmap;
int continuer =1;
int stat;
int c=1;
int enigme;
		SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
		objet enemie1;
		hero.num=0;
		Enemy e;
                SDL_Event event;
		initialiser_evan(&hero,test);
                initialiser_pmap(&pmap);
                initialiser_objet(&enemie1);
e=InitEnemy(e,5500,350);
initialiser_background(&back);
ecran = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	        SDL_EnableKeyRepeat(10, 10);	
while(continuer)
       {
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		Affiche_back(back,ecran);
               afficher_hero(hero,ecran);
afficher_pmap(&pmap,ecran,hero.heromoved);
                afficher_objet(&enemie1,ecran,hero) ;   
 if (cont==2)
                        {hero.mouv=deplacement(&hero,&event);}
   /*else if (cont==3)
{hero.mouv=mouvmentarduino(evan,f);}*/


			hero.num=animation_perso(hero);
	                e=MoveEnemy(e,hero.pos_hero2,&stat,hero.heromoved);
			e=AnimateEnemy(e,stat);

                        AfficherEnemy(e,ecran);
//GestionVie(ecran,&hero,enigme);
SDL_Flip(ecran);


int z=0;
z=end1(ecran,&event);
*mi=z; 


      scrolling (&hero,&back,c);
if(Collision_Bounding_Box (hero,enemie1 )==0){
				hero.hit=1;
				enemie1.pos_objet.y=1000;
				SDL_Delay(1000);
			}
		       c=collision_Parfaite(back.calque,hero.image_hero[hero.num],hero.pos_hero2,back.positionback2);

if (c==1)
enigme=enigmi();

if((z==1)||(z==2))
continuer=0;
}


	

}


