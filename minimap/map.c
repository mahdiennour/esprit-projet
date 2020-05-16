
        #include <stdio.h>
	#include <stdlib.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
	#include <SDL/SDL_mixer.h>
	#include <SDL/SDL_ttf.h>
	#include"map.h"

void initialiser_map(map *Map)
{
                Map->afficher_map=NULL;
		Map->afficher_map=IMG_Load("fondgrand.jpg");
		Map->pos_map.x=50;
		Map->pos_map.y=10;
	        
	
		Map->afficher_perso=NULL;
		Map->afficher_perso=IMG_Load("grandperso.jpg");
	
		Map->pos_perso.x=50;
		Map->pos_perso.y=300;
		Map->num=0;
	


}

void initialiser_minimap(minimap *Mmap)
{

                Mmap->afficher_minimap=NULL;
		Mmap->afficher_minimap=IMG_Load("fondpetit.jpg");
		Mmap->pos_minimap.x=725;
		Mmap->pos_minimap.y=10;
	        
	
		Mmap->afficher_miniperso=NULL;
		Mmap->afficher_miniperso=IMG_Load("miniperso.jpg");
	
		Mmap->pos_miniperso.x=725; 
		Mmap->pos_miniperso.y=80;
		Mmap->num1=0;


}

  //le rapport k=4//
void afficher_map(map *Map,minimap*Mmap,SDL_Surface *screen,int mouv)
{  

SDL_BlitSurface(Map->afficher_map,NULL,screen,&Map->pos_map);
SDL_BlitSurface(Mmap->afficher_minimap,NULL,screen,&Mmap->pos_minimap);


SDL_BlitSurface(Map->afficher_perso,NULL,screen,&Map->pos_perso);
SDL_BlitSurface(Mmap->afficher_miniperso,NULL,screen,&Mmap->pos_miniperso);  


//--------------------------Clavier droit-----------------//
if (mouv==1)
	Map->num++;
        Mmap->num1++;
		
	
	    if (Map->num==9)
                {
                      if ((Map->pos_perso.x<=986)&&(Map->pos_perso.x>=50))
                     {
			Map->pos_perso.x+=4;
			Map->num=0;
                        Mmap->pos_miniperso.x+=1;
			Mmap->num1=0;
                         
                         
                      }

//retour//        
    
                      else 
                      { 
                       Map->pos_perso.x=50;
                       Mmap->pos_miniperso.x=725;
                       
                      }


                }
       

//--------------------------Clavier gauche-----------------//


if (mouv==2)
	Map->num--;
        Mmap->num1--;
		
	
	    if (Map->num==-9)
                {
                      if ((Map->pos_perso.x>=52)&&(Map->pos_perso.x<=986)&& (Mmap->pos_miniperso.x>=725))
                      {
			Map->pos_perso.x-=4;
			Map->num=0;
                        Mmap->pos_miniperso.x-=1;
			Mmap->num1=0;
      
                      }

//retour// 
                      else 
                      { 
                        
                        Map->pos_perso.x=986;
                        Mmap->pos_miniperso.x=960;
                        Map->pos_perso.x-=4;
			Map->num=0;
                        Mmap->pos_miniperso.x-=1;
			Mmap->num1=0;
                        
                      }
                }



}  


void main(){
		SDL_Surface *screen =NULL,*texte=NULL;
                SDL_Rect positionD;  
                SDL_Rect positionG;  
		map Map;   
                minimap Mmap;
                TTF_Font *police = NULL; int i; 
                SDL_Color couleurNoire = {255, 255, 255}, couleurBlanche = {0, 0,0};
		int continuer =1;
                int posActuel = 0; int resultat;
                char position[20] = ""; /* Tableau de char suffisamment grand */
                char pause; 
		SDL_Event event;
		initialiser_map(&Map);
                initialiser_minimap(&Mmap);
		int mouv; 
	
		SDL_Init(SDL_INIT_VIDEO);
                TTF_Init();
	        screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	        SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);
                /* Chargement de la police */
                police = TTF_OpenFont("angelina.ttf", 29);
                texte = TTF_RenderText_Shaded(police, position, couleurNoire, couleurBlanche);
           

		while(continuer){
		afficher_map(&Map,&Mmap,screen,mouv);
                positionD.x = 870; 
                positionD.y = 15;
                SDL_BlitSurface(texte, NULL, screen, &positionD); 
	      
	 SDL_PollEvent(&event);
	 switch (event.type)
	 {
	 case SDL_QUIT:
	 mouv=0; continuer=0;
	 break;
		break;
	 case SDL_KEYDOWN:
	 switch (event.key.keysym.sym)
	 {
	 break;
	 case SDLK_RIGHT:
         mouv=1;
 
         sprintf(position, "position : %d",Map.pos_perso.x);
         SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
         texte = TTF_RenderText_Shaded(police, position, couleurNoire, couleurBlanche); /* On écrit la chaine position dans la SDL_Surface */
     
	 break;

	 case SDLK_LEFT:
	 mouv=2;       
         sprintf(position, "position : %d",Map.pos_perso.x); 
         SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
         texte = TTF_RenderText_Shaded(police, position, couleurNoire, couleurBlanche); /* On écrit la chaine temps dans la SDL_Surface */


	 break;
	 }
	 break;
   
	 default: mouv=9;
	 }
 
	SDL_Flip(screen);
          
          }
	pause=getchar();
        TTF_CloseFont(police);
        TTF_Quit();

        SDL_FreeSurface(texte);
        SDL_Quit();

	}





          
