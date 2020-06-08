#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include"objet.h"
void initialiser_objet(objet *enemie1) {
	enemie1->afficher_objet=NULL;
	enemie1->afficher_objet=IMG_Load("s1.png");

	enemie1->pos_objet.x=1000;
	enemie1->pos_objet.y=0;
}



void afficher_objet(objet *enemie1,SDL_Surface *ecran,hero evan){

	if (enemie1->pos_objet.x==0){
			srand(time(NULL)); 
		chouka->pos_objet.x=(rand()%900)+450;  
		chouka->pos_objet.y=0;
	}
	if ((enemie1->pos_objet.y<600)&&(evan.pos_hero2.x<=300)){
		if ((evan.heromoved==1)&&(evan.pos_hero2.x==300)){
			enemie1->pos_objet.x=enemie1->pos_objet.x-5;
				

				}
			enemie1->pos_objet.y++;
			if (evan.heromoved==2){
				enemie1->pos_objet.x=enemie1->pos_objet.x+5;
			
			}


			
			
				enemie1->pos_objet.y+=5;
	}

	else {
			srand(time(NULL)); 
		enemie1->pos_objet.x=(rand()%900+300);  
		enemie1->pos_objet.y=0;
	}
	if(evan.pos_hero2.x>100)
		SDL_BlitSurface(enemie1->afficher_objet,NULL,ecran,&(enemie1->pos_objet));
	else if (evan.pos_hero2.x>300)
		 enemie1->afficher_objet=NULL;
}
int Collision_Bounding_Box (hero evan ,objet enemie1 ) 
{
	int colli =1 ; 
	 
	if ((evan.pos_hero2.x<((enemie1.pos_objet.x)+10))&&(evan.pos_hero2.y+10<=((enemie1.pos_objet.y)+85))&&((evan.pos_hero2.x+110)>((enemie1.pos_objet.x)+30))&&((evan.pos_hero2.y+250)>=(enemie1.pos_objet.y)))
	{
		colli=0 ; 
	}
	//printf ("%d \n",chouka.pos_objet.x);
	return colli ; 

}
