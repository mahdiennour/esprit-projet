#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "labyrinth.h"
void main()
{
int continuer=1,continuer1=1,continuer2=1, d=2, xa=91, ya=62, W=600, H=600, x,y,collision=0,labyrinth_upcol=60,labyrinth_downcol=535, i=0;


SDL_Surface *back = NULL;
SDL_Surface *ecran = NULL;
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
SDL_Color couleurvert = {0, 255, 135};
SDL_Color couleurNoire = {0, 0, 0};
SDL_Color couleurBlanche = {255, 255, 255};
SDL_Rect positionback,positionplayer,positiontexte,positiontexte1,positiontexte2;

positionback.x=0;
positionback.y=0;

positiontexte.x=W/3;
positiontexte.y=H/3.5;
positiontexte1.x=W/5;
positiontexte1.y=H/2;
positiontexte2.x=W/5.5;
positiontexte2.y=H/3;

positionplayer.x=xa;
positionplayer.y=ya;


Uint8 *keystate = SDL_GetKeyState(0);

SDL_Init( SDL_INIT_AUDIO|SDL_INIT_VIDEO );
TTF_Init();
ecran = SDL_SetVideoMode( W,H, 32, SDL_HWSURFACE| SDL_DOUBLEBUF);

back =SDL_LoadBMP("maze.bmp");
player= IMG_Load("player.png");


 

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

while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer=0;
                break;
}
while (continuer1)
{
if (SDL_PollEvent(&event)) {
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



if((positionplayer.x+player->w)>W)
{positionplayer.x -=d;}
if((positionplayer.y+player->h)>H)
{positionplayer.y -=d;}

 

if (positionplayer.y<=labyrinth_upcol)
{positionplayer.y+=d;
}

if (positionplayer.y>=labyrinth_downcol)
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
x=positionplayer.x+player->w;

   while ((!collision) &&(y<=(positionplayer.y+player->h))) 
                                                    
                          {collision=  Collision_Parfaite(back,x,y);y++;
                         
                          if (collision)
                          {//collision
                    
                          positionplayer.x--;
                          y=positionplayer.y;
                          x=positionplayer.x+positionplayer.h;
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
							
while (!collision && x<=(positionplayer.x+player->w))
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
					    y=positionplayer.y+positionplayer.w;
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
}

