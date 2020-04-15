#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"dep.h"
void dep(SDL_Surface *zozor,SDL_Surface *ecran)
{ SDL_Rect positionZozor;
    SDL_Event event;
int pos;
int i;
   
SDL_WaitEvent(&event);
        switch(event.type)
        {
            
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    
                   
                    case SDLK_RIGHT:
                        positionZozor.x++;
                        break;
                    case SDLK_LEFT:
                        positionZozor.x--;
                        break;
                }
                break;
   case SDL_MOUSEBUTTONUP:
     if ((event.button.button==SDL_BUTTON_LEFT)&&(positionZozor.x < event.button.x))
     { for(i=0;i<3;i++){
                                positionZozor.x+=4;
                                
                            }}
else if ((event.button.button==SDL_BUTTON_LEFT)&&(positionZozor.x >event.button.x))
{for(i=0;i<3;i++){
                                positionZozor.x-=4;

}}
     break ;

        }
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
        SDL_Flip(ecran);
}
