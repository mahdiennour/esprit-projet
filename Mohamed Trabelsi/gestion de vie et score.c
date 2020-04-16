#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "perso.h"
#include <string.h>
#include <SDL/SDL_ttf.h>
#include <enemie.h>
void GestionVie(SDL_Surface *screen, caractere hero)
{
SDL_Surface *hp=NULL,*hp1=NULL,*hp2=NULL,*hp3=NULL,*texte = NULL;
TTF_Font *police=NULL;
SDL_Color couleurRouge={255,0,0};
SDL_Rect positionhp;
SDL_Rect positionscore;
positionhp.x=100;
positionhp.y=100;
positionscore.x=150;
positionscore.y=100;
hp = SDL_LoadBMP("hp.bmp");
hp1 = SDL_LoadBMP("hp1.bmp");
hp2 = SDL_LoadBMP("hp2.bmp");
hp3 = SDL_LoadBMP("hp3.bmp");
SDL_BlitSurface(hp,NULL,screen,&positionhp);
SDL_Flip (screen);
hero.vie=0;
while (hero.vie<4)
{
if(/*condition qui diminue le niveau de vie*/)
{
hero.vie++;
}
}
if(hero.vie==1)
{
SDL_BlitSurface(hp1,NULL,screen,&positionhp);
SDL_Flip (screen);
}
if(hero.vie==2)
{
SDL_BlitSurface(hp2,NULL,screen,&positionhp);
SDL_Flip (screen);
}
if(hero.vie==3)
{
SDL_BlitSurface(hp3,NULL,screen,&positionhp);
SDL_Flip (screen);
}
while (hero.vie>0)
{
if (/*condition qui augmente le niveau de vie*/)
{
hero.vie--;
}
}
if(hero.vie==0)
{
SDL_BlitSurface(hp,NULL,screen,&positionhp);
SDL_Flip (screen);
}
if(hero.vie==1)
{
SDL_BlitSurface(hp1,NULL,screen,&positionhp);
SDL_Flip (screen);
}
if(hero.vie==2)
{
SDL_BlitSurface(hp2,NULL,screen,&positionhp);
SDL_Flip (screen);
}
hero.score[5]="00000";
int i;
if (/*condition pour augmantation du score*/)
{
i++;
}
if(/*condition pour diminution du score*/&&(i!=0))
{
i--;
}
sprintf(hero.score, "Score : %d",i);
police= TTF_OpenFont("LionCub-Regular-2.ttf", 65);
texte= TTF_RenderText_Blended(police,hero.score, couleurRouge);
SDL_BlitSurface(texte,NULL,screen,positionscore);
SDL_Flip(screen);
}
