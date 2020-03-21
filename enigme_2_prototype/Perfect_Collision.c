#include "Perfect_Collision.h"

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
     if (color.r==0 && color.g==0 && color.b==0)
     {collision=1;}
     return collision;}

