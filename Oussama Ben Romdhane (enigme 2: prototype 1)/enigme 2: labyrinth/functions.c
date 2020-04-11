#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

#include "affichage.h"
#include "constantes.h"

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

int Collision_Parfaite_laby(SDL_Surface *back,int x, int y)
     {int collision1=0;
     SDL_Color color;
     color=GetPixel(back,x,y);
     if (color.r==0 && color.g==255 && color.b==0)
     {collision1=1;}
     return collision1;}


/* quadrille le terrain : fermeture de toutes les portes */
int quadrille(SDL_Surface *ecran)
{
    int i, j;
    SDL_Surface **portes = NULL;
    SDL_Rect pos;
 
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    if (! (portes = malloc(sizeof(SDL_Surface *) * nombreLignes())))
    {
        fprintf(stderr, "Erreur lors de l'allocation mémoire pour le\
                tableau *portes : SDL_Surface *\n");
        return -1;
    }
 
    // crée les lignes en mémoire et les affiches
    pos.x = 0;
    for (i = 0; i < NOMBRE_PORTE_HAUTEUR; i++)
    {
        pos.y = (i + 1) * TAILLE_BLOC + i * TAILLE_PORTE;
        portes[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_FENETRE,
                                         TAILLE_PORTE, 32, 0, 0, 0, 0);
        SDL_FillRect(portes[i], NULL, SDL_MapRGB(ecran->format, 0, 255, 0));
        SDL_BlitSurface(portes[i], NULL, ecran, &pos);
    }
    pos.y = 0;
    for (i = 0; i < NOMBRE_PORTE_LARGEUR; i++)
    {
        pos.x = (i + 1) * TAILLE_BLOC + i * TAILLE_PORTE;
        portes[NOMBRE_PORTE_HAUTEUR + i] = SDL_CreateRGBSurface(SDL_HWSURFACE,
                                                            TAILLE_PORTE,
                                                            HAUTEUR_FENETRE,
                                                            32, 0, 0, 0, 0);
        SDL_FillRect(portes[NOMBRE_PORTE_HAUTEUR + i], NULL,
                     SDL_MapRGB(ecran->format, 0, 255, 0));
        SDL_BlitSurface(portes[NOMBRE_PORTE_HAUTEUR + i], NULL, ecran, &pos);
    }
    SDL_Flip(ecran); // on affiche le résultat à l'écran
 
    for (i = 0; i < nombreLignes(); i++) // on libère les surfaces lignes
            SDL_FreeSurface(portes[i]);
 
    free(portes);
 
    return 1;
}
 
/* renvoie le nombre de lignes du labyrinthe quadrillé */
int nombreLignes()
{
    return NOMBRE_PORTE_HAUTEUR + NOMBRE_PORTE_LARGEUR;
}
 
/* enleve le mur d'une cellule selon sa direction */
void ouvrePorte(SDL_Surface *ecran, int x, int y, int direction)
{
    SDL_Surface *blanc = NULL;
    int w, h;
    SDL_Rect pos;
 
    // définit les dimensions du blanc en fonction de la direction
    w = (direction == NORD || direction == SUD) ? TAILLE_BLOC : TAILLE_PORTE;
    h = (direction == NORD || direction == SUD) ? TAILLE_PORTE : TAILLE_BLOC;
 
    // position du blanc
    switch (direction)
    {
        case SUD:
            y++;
        case NORD:
            pos.x = (TAILLE_PORTE + TAILLE_BLOC) * x;
            pos.y = y * TAILLE_BLOC + TAILLE_PORTE * y - 2;
            break;
        case EST:
            x++;
        case OUEST:
            pos.x = x * TAILLE_BLOC + TAILLE_PORTE * x - 2;
            pos.y = y * (TAILLE_PORTE + TAILLE_BLOC);
            break;
    }
 
    pos.w = w; pos.h = h;
SDL_FillRect(ecran, &pos, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_Flip(ecran);
}

void menu(SDL_Surface *ecran)
{
int continuer=1;
SDL_Surface *back = NULL;
SDL_Surface *texte = NULL;
SDL_Surface *texte1 = NULL;
SDL_Event event;
TTF_Font *police = NULL;
TTF_Font *police1 = NULL;
SDL_Color couleurvert = {0, 255, 0};
SDL_Color couleurNoire = {0, 0, 0};
SDL_Color couleurBlanche = {255, 255, 255};
SDL_Rect positiontexte,positiontexte1,positionback;

back =SDL_LoadBMP("back.bmp");


positionback.x=0;
positionback.y=0;


positiontexte.x=back->w/3;
positiontexte.y=back->h/3.5;
positiontexte1.x=back->w/5;
positiontexte1.y=back->w/2;







 

/* Chargement de la police */
    police = TTF_OpenFont("heavy_data.TTF", 70);
    police1 = TTF_OpenFont("heavy_data.TTF", 50);

    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
texte = TTF_RenderText_Blended(police, "Ready?", couleurvert);
texte1 = TTF_RenderText_Blended(police1, "press z to start", couleurvert);


SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(texte, NULL, ecran, &positiontexte); /* Blit du texte */
SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1); /* Blit du texte */
SDL_Flip(ecran);







while (continuer)
{
if (SDL_WaitEvent(&event)) {
if(event.type==SDL_QUIT)
{
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_Quit();

}

else{
        if(event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_z) {

continuer=0;

     }}}}
}
SDL_FreeSurface(texte);
SDL_FreeSurface(texte1);
TTF_CloseFont(police);

}
void play(SDL_Surface *ecran)
{srand(time(NULL));
int continuer=1, d=2, xa=(rand()%(LARGEUR_FENETRE-0+1)), ya=(rand()%(HAUTEUR_FENETRE-0+1)), x,y,collision1=0,collision2=0,xb=(rand()%(LARGEUR_FENETRE-0+1)), yb=(rand()%(HAUTEUR_FENETRE-0+1));

SDL_Surface *back = NULL;
SDL_Surface *player = NULL;
SDL_Surface *endpoint = NULL;
SDL_Surface *texte1_1 = NULL;
SDL_Surface *texte2 = NULL;
SDL_Event event;
TTF_Font *police1 = NULL;
TTF_Font *police2 = NULL;
SDL_Color couleurvert = {0, 255, 0};
SDL_Color couleurNoire = {0, 0, 0};
SDL_Color couleurBlanche = {255, 255, 255};
SDL_Rect positionback,positionplayer,positionendpoint,positiontexte1,positiontexte2;

back =SDL_LoadBMP("back.bmp");
player= IMG_Load("player.png");
endpoint= IMG_Load("endpoint.png");

positionback.x=0;
positionback.y=0;


positiontexte1.x=back->w/5;
positiontexte1.y=back->h/2;
positiontexte2.x=back->w/5.5;
positiontexte2.y=back->h/3;

positionplayer.x=xa;
positionplayer.y=ya;

positionendpoint.x=xb;
positionendpoint.y=yb;

Uint8 *keystate = SDL_GetKeyState(0);




 

/* Chargement de la police */

    police1 = TTF_OpenFont("heavy_data.TTF", 50);
   police2 = TTF_OpenFont("heavy_data.TTF", 100);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
texte2 = TTF_RenderText_Blended(police2, "Success", couleurvert);
texte1_1 = TTF_RenderText_Blended(police1, "press q to quit", couleurvert);
SDL_BlitSurface(back, NULL, ecran, &positionback);
SDL_BlitSurface(endpoint, NULL, ecran, &positionendpoint);
SDL_SaveBMP (ecran, "back.bmp");
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_Flip(ecran);


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



SDL_BlitSurface(back, NULL, ecran, &positionback);
SDL_BlitSurface(player, NULL, ecran, &positionplayer);
SDL_BlitSurface(endpoint, NULL, ecran, &positionendpoint);
SDL_Flip(ecran);






if((positionplayer.x+player->w)>back->w-2)
{positionplayer.x =1;}
if((positionplayer.y+player->h)>back->h-2)
{positionplayer.y =1;}
if(positionplayer.x==0)
{positionplayer.x=positionplayer.x-player->w+back->w;}
if(positionplayer.y==0)
{positionplayer.y=positionplayer.y-player->h+back->h;}



if (!(positionendpoint.x+(endpoint->w) < positionplayer.x || positionendpoint.x > positionplayer.x+(player->w) || positionendpoint.y+(endpoint->h) < positionplayer.y || positionendpoint.y > positionplayer.y+(player->h)))
{
collision2=1;
if (collision2)
{
SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2); /* Blit du texte */
SDL_BlitSurface(texte1_1, NULL, ecran, &positiontexte1); /* Blit du texte */
SDL_Flip(ecran);
if (keystate[SDLK_q])
{
continuer=0;
}
}
collision2=0;
}


if (keystate[SDLK_LEFT])
{positionplayer.x -=d;
y=positionplayer.y;
x=positionplayer.x;
while ((!collision1) && (y<=(positionplayer.y+positionplayer.h)))
{
collision1= Collision_Parfaite_laby(back,x,y);y++;
							if (collision1)
							{positionplayer.x++;
							y=positionplayer.y;
							x=positionplayer.x;
							collision1=0;}
}
}
if (keystate[SDLK_RIGHT])
{positionplayer.x +=d;

y=positionplayer.y;
x=positionplayer.x+positionplayer.w;

   while ((!collision1) &&(y<=(positionplayer.y+positionplayer.h))) 
                                                    
                          {collision1=  Collision_Parfaite_laby(back,x,y);y++;
                         
                          if (collision1)
                          {//collision
                    
                          positionplayer.x--;
                          y=positionplayer.y;
                          x=positionplayer.x+positionplayer.w;
                           collision1=0;
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
							
while ((!collision1) && (x<=(positionplayer.x+positionplayer.w)))
{
collision1= Collision_Parfaite_laby(back,x,y);
x++;
							if (collision1)
							{positionplayer.y++;
							y=positionplayer.y;
							x=positionplayer.x;
							collision1=0;
/*y=positionplayer.y=ya;
x=positionplayer.x=xa;
collision=0;*/
}}

}

if (keystate[SDLK_DOWN])
{positionplayer.y +=d;

y=positionplayer.y+positionplayer.h;
x=positionplayer.x;
while ((!collision1) && (x<=(positionplayer.x+positionplayer.w)))
{
collision1= Collision_Parfaite_laby(back,x,y);
x++;
					    if (collision1)
					    {positionplayer.y--;
					    x=positionplayer.x;
					    y=positionplayer.y+positionplayer.h;
							collision1=0;
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


TTF_CloseFont(police1);
TTF_CloseFont(police2);

SDL_FreeSurface(texte1_1);
SDL_FreeSurface(texte2);
TTF_Quit();
}
