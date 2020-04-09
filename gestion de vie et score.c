#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "perso.h"
#include <string.h>
#include <SDL/SDL_ttf.h>
void GestionVie()
{
SDL_Surface *ecran=NULL, *hp=NULL,*hp1=NULL,*hp2=NULL,*hp3=NULL,*texte = NULL;
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
SDL_BlitSurface(hp,NULL,ecran,&positionhp);
SDL_Flip (ecran);
int etat=0;
while (etat<4)
{
if(/*condition qui diminue le niveau de vie*/)
{
etat++;
}
}
if(etat==1)
{
SDL_BlitSurface(hp1,NULL,ecran,&positionhp);
SDL_Flip (ecran);
}
if(etat==2)
{
SDL_BlitSurface(hp2,NULL,ecran,&positionhp);
SDL_Flip (ecran);
}
if(etat==3)
{
SDL_BlitSurface(hp3,NULL,ecran,&positionhp);
SDL_Flip (ecran);
}
while (etat>0)
{
if (/*condition qui augmente le niveau de vie*/)
{
etat--;
}
}
if(etat==0)
{
SDL_BlitSurface(hp,NULL,ecran,&positionhp);
SDL_Flip (ecran);
}
if(etat==1)
{
SDL_BlitSurface(hp1,NULL,ecran,&positionhp);
SDL_Flip (ecran);
}
if(etat==2)
{
SDL_BlitSurface(hp2,NULL,ecran,&positionhp);
SDL_Flip (ecran);
}
char score[5]"0";
int i;
if (/*condition pour augmantation du score*/)
{
i++;
}
if(/*condition pour diminution du score*/&&(i!=0))
{
i--;
}
sprintf(score, "Score : %d",i);
police= TTF_OpenFont("LionCub-Regular-2.ttf", 65);
texte= TTF_RenderText_Blended(police, score, couleurRouge);
SDL_BlitSurface(texte,NULL,ecran,positionscore);
SDL_Flip(ecran);
}
