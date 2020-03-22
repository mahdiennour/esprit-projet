#include <SDL/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


#include "algorithme.h"
#include "constantes.h"
#include "affichage.h"
 
void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
 
int main(int argc, char **argv)
{
    p_labyrinthe lab;
    SDL_Surface *ecran = NULL;
 
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "%s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    srand(time(NULL)); // initialisation de la graine pour les nombres aléatoires
    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32,
                                   SDL_HWSURFACE | SDL_DOUBLEBUF);
TTF_Init();
    if (!ecran)
    {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
 
    if (!quadrille(ecran))
    {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
 
    lab = creeLabyrinthe(ecran);
    if (!lab)
    {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

SDL_SaveBMP (ecran, "back.bmp");

int continuer=1,continuer1=1, d=2, xa=0, ya=0, x,y,collision,succcond=200;


SDL_Surface *back = NULL;
SDL_Surface *player = NULL;
SDL_Surface *texte = NULL;
SDL_Surface *texte1 = NULL;
SDL_Surface *texte1_1 = NULL;
SDL_Surface *texte2 = NULL;
SDL_Event event;
SDL_Event event1;
TTF_Font *police = NULL;
TTF_Font *police1 = NULL;
TTF_Font *police2 = NULL;
SDL_Color couleurvert = {0, 255, 00};
SDL_Color couleurNoire = {0, 0, 0};
SDL_Color couleurBlanche = {255, 255, 255};
SDL_Rect positionback,positionplayer,positiontexte,positiontexte1,positiontexte2;

back =SDL_LoadBMP("back.bmp");
player= IMG_Load("player.png");

positionback.x=0;
positionback.y=0;

positiontexte.x=back->w/3;
positiontexte.y=back->h/3.5;
positiontexte1.x=back->w/5;
positiontexte1.y=back->h/2;
positiontexte2.x=back->w/5.5;
positiontexte2.y=back->h/3;

positionplayer.x=xa;
positionplayer.y=ya;


Uint8 *keystate = SDL_GetKeyState(0);




 

/* Chargement de la police */
    police = TTF_OpenFont("heavy_data.TTF", 70);
    police1 = TTF_OpenFont("heavy_data.TTF", 50);
   police2 = TTF_OpenFont("heavy_data.TTF", 100);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
texte = TTF_RenderText_Blended(police, "Ready?", couleurvert);
texte1 = TTF_RenderText_Blended(police1, "press z to start", couleurvert);

texte2 = TTF_RenderText_Blended(police2, "Success", couleurvert);
texte1_1 = TTF_RenderText_Blended(police1, "press q to quit", couleurvert);

SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(texte, NULL, ecran, &positiontexte); /* Blit du texte */
SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1); /* Blit du texte */
SDL_Flip(ecran);
SDL_Color GetPixel(SDL_Surface *back,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) back->pixels;
pPosition+= (back->pitch * y);
pPosition+= (back->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,back->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,back->format, &color.r, &color.g, &color.b);
return (color);
}

int Collision_Parfaite(SDL_Surface *back,int x, int y)
     {int collision=0;
     SDL_Color color;
     color=GetPixel(back,x,y);
     if (color.r==0 && color.g==255 && color.b==0)
     {collision=1;}
     return collision;}

SDL_EnableKeyRepeat(10,10);
while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer=0;
                break;
}
while (continuer1)
{
if (SDL_WaitEvent(&event)) {
if(event.type==SDL_QUIT)
{continuer=0;
continuer1=0;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));}
        if(event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_z) {

continuer1=0;

     }}}}

SDL_BlitSurface(back, NULL, ecran, &positionback);
SDL_BlitSurface(player, NULL, ecran, &positionplayer);
SDL_Flip(ecran);



if((positionplayer.x+player->w)>back->w)
{positionplayer.x -=d;}
if((positionplayer.y+player->h)>back->h)
{positionplayer.y -=d;}

 
if (positionplayer.y>=succcond)
{
SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2); /* Blit du texte */
SDL_BlitSurface(texte1_1, NULL, ecran, &positiontexte1); /* Blit du texte */
SDL_Flip(ecran);
if (keystate[SDLK_q])
{
continuer=0;
}
}
if (keystate[SDLK_LEFT])
{positionplayer.x -=d;
y=positionplayer.y;
x=positionplayer.x;
while (!collision && y<=(positionplayer.y+positionplayer.h))
{
collision= Collision_Parfaite(back,x,y);y++;
							if (collision)
							{positionplayer.x++;
							y=positionplayer.y;
							x=positionplayer.x;
							collision=0;}}
}
if (keystate[SDLK_RIGHT])
{positionplayer.x +=d;

y=positionplayer.y;
x=positionplayer.x+positionplayer.w;

   while ((!collision) &&(y<=(positionplayer.y+positionplayer.h))) 
                                                    
                          {collision=  Collision_Parfaite(back,x,y);y++;
                         
                          if (collision)
                          {//collision
                    
                          positionplayer.x--;
                          y=positionplayer.y;
                          x=positionplayer.x+positionplayer.w;
                           collision=0;
//return
/*y=positionplayer.y=ya;
x=positionplayer.x=xa;
collision=0;*/
}}
}

if (keystate[SDLK_UP])
{positionplayer.y -=d;
y=positionplayer.y;
x=positionplayer.x;
							
while (!collision && x<=(positionplayer.x+positionplayer.w))
{
collision= Collision_Parfaite(back,x,y);
x++;
							if (collision)
							{positionplayer.y++;
							y=positionplayer.y;
							x=positionplayer.x;
							collision=0;
/*y=positionplayer.y=ya;
x=positionplayer.x=xa;
collision=0;*/
}}
}

if (keystate[SDLK_DOWN])
{positionplayer.y +=d;

y=positionplayer.y+positionplayer.h;
x=positionplayer.x;
while (!collision && x<=(positionplayer.x+positionplayer.w))
{
collision= Collision_Parfaite(back,x,y);
x++;
					    if (collision)
					    {positionplayer.y--;
					    x=positionplayer.x;
					    y=positionplayer.y+positionplayer.h;
							collision=0;
/*y=positionplayer.y=ya;
x=positionplayer.x=xa;
collision=0;*/
}}
}



SDL_BlitSurface(player, NULL, ecran, &positionplayer);
SDL_Flip(ecran);

}
SDL_FreeSurface(back);
SDL_FreeSurface(player);
TTF_CloseFont(police);
SDL_FreeSurface(texte);
TTF_CloseFont(police1);
TTF_CloseFont(police2);
SDL_FreeSurface(texte1);
SDL_FreeSurface(texte1_1);
SDL_FreeSurface(texte2);
TTF_Quit();

 
    detruitLabyrinthe(lab);
 
    SDL_Quit();
    return EXIT_SUCCESS;
}
