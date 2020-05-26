#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "sauvgarde.h"

void sauvegarde (char nomfich[20])
{
	int i;
	FILE *fichier;
	
	fichier=fopen(nomfich,"wb");
   if (fichier==NULL)
	printf("erreur, fichier ne peut pas etre ouvert\n");

   else 
  {
     for (i=0;i<sizeof(back);i++)
	{
         fwrite(&perso,sizeof(hero),1,fichier);
         fwrite(&M,sizeof(map),1,fichier);
         fwrite(&E,sizeof(Enemy),1,fichier);
        }
	
	fclose(fichier);
  }
	
}


void lire (char nomfich[20])
{
	int i;
	FILE *fichier;
	
	fichier=fopen(nomfich,"rb");
    if (fichier==NULL)
	{
		printf("erreur, fichier ne peut pas etre ouvert\n");
		exit(0);
	}
	
    else
    {   
          for (i=0;i<sizeof(back);i++)
	     {
               fread(&perso,sizeof(hero),1,fichier);
	       fread(&E,sizeof(Enemy),1,fichier);
               fread(&M,sizeof(map),1,fichier); 
             }	
    }
	
	fclose(fichier);

}

void main()
{

char nomfich[]="sauvegarde.bin";
    FILE *fichier;
	SDL_Surface *ecran =NULL;
	int continuer =1;
	background back;
        Enemy E;
        hero perso;
        map M;
       while(continuer)
	 {
          sauvegarde (nomfich);
          lire (nomfich);
         }
	//fclose(fichier);
        SDL_Flip(ecran);
}





