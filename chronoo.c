#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigmes.h"

void afficher_chrono(chrono *c)
{int done=1;   
SDL_Surface *fenetre;
   SDL_Surface *background;
 SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurBlanc = {29, 156, 4 };
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0;
    char temps[20] = ""; /* Tableau de char suffisamment grand */

   fenetre=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE);
   SDL_Rect positionbg;
   positionbg.x=0;
   positionbg.y=0;

    TTF_Init();
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

    /* Chargement de la police */
    police = TTF_OpenFont("LionCub-Regular-2.ttf", 65);

    /* Initialisation du temps et du texte */
    tempsActuel = SDL_GetTicks();
    sprintf(temps, "Temps : %d", compteur);
    c->texte = TTF_RenderText_Blended(police, temps, couleurBlanc);

    while (done)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                done = 0;

                break;
        }
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 100) /* Si 100 ms au moins se sont écoulées */
        {
            compteur += 100; /* On rajoute 100 ms au compteur */
            sprintf(temps, "Temps : %d", compteur); /* On écrit dans la chaîne "temps" le nouveau temps */
            SDL_FreeSurface(c->texte); /* On supprime la surface précédente */
            c->texte = TTF_RenderText_Blended(police, temps, couleurBlanc); /* On écrit la chaîne temps dans la SDL_Surface */
            tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
        }
        c->poschrono.x = 180;
        c->poschrono.y = 210;
        background=IMG_Load ("images.jpg");
   SDL_BlitSurface(background,NULL,fenetre,&positionbg);
   SDL_Flip(fenetre);
        
        SDL_BlitSurface(c->texte, NULL,fenetre, &c->poschrono); /* Blit du texte */
        SDL_Flip(fenetre);


    }
TTF_Quit();
TTF_CloseFont(police);
  SDL_FreeSurface(c->texte);
    SDL_Quit();
}
int main(int argc, char** argv)
{chrono c;
afficher_chrono(&c);

    
return 1;

}
