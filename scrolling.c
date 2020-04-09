#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "background.h"
void Scrolling(background back,screen * ecran)
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
positionbg.x++;
SDL_BlitSurface(back,&positionbg,ecran,NULL);
SDL_Flip(ecran);
break;
case SDLK_LEFT:
positionbg.x--;
SDL_BlitSurface(back,&positionbg,ecran,NULL);
SDL_Flip(ecran);
break;
case SDLK_UP:
positionbg.y--;
SDL_BlitSurface(back,&positionbg,ecran,NULL);
SDL_Flip(ecran);
break;
case SDLK_DOWN:
positionbg.y++;
SDL_BlitSurface(back,&positionbg,ecran,NULL);
SDL_Flip(ecran);
break;
}
break;
}
SDL_Flip(ecran);
} SDL_Delay(10);
SDL_FreeSurface(back);
}
