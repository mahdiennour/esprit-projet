#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ennemi.h"
#include "background.h"
int load_enemie(enemie* E)
{
	A->image = IMG_Load("../images/Ennemi.png");

	if(A->image == NULL) {
		printf("Unable to load Ennemi jpg:%s\n", SDL_GetError());
		return (-1);
	}

	SDL_SetColorKey( A->image, SDL_SRCCOLORKEY, SDL_MapRGB(A->image->format, 255, 255, 255) );

	return (0);
}


void Init_enemie(enemie* E)
{
	E->positionAbsolue.x = 1000;
	E->positionAbsolue.y = 250;
	E->positionAbsolue.w = Ennemi_WIDTH;
	E->positionAbsolue.h = Ennemi_HEIGHT;
	E->positionAnimation.x = 0;
	E->positionAnimation.y = 0;
	E->positionAnimation.w = Ennemi_WIDTH;
	E->positionAnimation.h = Ennemi_HEIGHT;
}
void blitEnnemi(Ennemi E, SDL_Surface* screen)
{
	SDL_BlitSurface(E.image, &E.positionAnimation, screen, &E.positionAbsolue);
}
void freeEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
}
int Collision_enemie(Ennemi E,caractere hero)
{
while(SDL_PollEvent(&event))

    {

     switch(event.type)

     {
if((hero.x + hero. w< Ennemi. x) || (hero.x> Ennemi. x + Ennemi. w)||(hero.y + hero.h< Ennemi. y) || (hero.y> Ennemi. y + Ennemi. h ))
{
colision=0;
else 
colision=1;
}
}
void deplacerPerso(enemie *E)
{
while(SDL_PollEvent(&event))

    {

     switch(event.type)

     {
if (E.PositionAbsolue.x> PosMax)
{
E.Direction=Left
}
if (E.PositionAbsolue.x<PosMin)
{
E.direction=Right
}
if (E.direction=Right)
{
E.Position.x++ ;
else 
E.Position.x-- ;
}}
