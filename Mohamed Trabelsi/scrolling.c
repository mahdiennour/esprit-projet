#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "background.h"
void Scrolling(background back,SDL_Surface *screen)
{
SDL_Event event;
SDL_EnableKeyRepeat(10,10);
int continuer=1;
while (continuer)
{
SDL_WaitEvent(&event);
switch (event.type)
{
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_RIGHT:
back.positionback.x++;
SDL_BlitSurface(image->back,&back.positionback,screen,NULL);
SDL_Flip(screen);
break;
case SDLK_LEFT:
back.positionback.x--;
SDL_BlitSurface(image->back,&back.positionback,screen,NULL);
SDL_Flip(screen);
break;
case SDLK_UP:
back.positionback.y--;
SDL_BlitSurface(image->back,&back.positionback,screen,NULL);
SDL_Flip(screen);
break;
case SDLK_DOWN:
back.positionback.y++;
SDL_BlitSurface(image->back,&back.positionback,screen,NULL);
SDL_Flip(screen);
break;
}
break;
}
SDL_Flip(ecran);
} SDL_Delay(10);
SDL_FreeSurface(back);
}
