#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
int main(void){
SDL_Surface *screen;
SDL_Surface *image;
SDL_Surface *det;
SDL_Rect positionecran;
SDL_Rect positiondet;
SDL_Event event;
int t=1,r=1;
char pause;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("Unable to initialize SDL:%s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(1600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen == NULL){
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}
image=SDL_LoadBMP("background.bmp");
if(image==NULL){
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}
positionecran.x = 0;
positionecran.y = 0;
positionecran.w = image->w;
positionecran.h = image->h;
positiondet.x =800;
positiondet.y =200;
det=IMG_Load("detectiive.png");
SDL_SetColorKey(det,SDL_SRCCOLORKEY,SDL_MapRGB(det->format,255,255,255));
SDL_EnableKeyRepeat(10,10);
while(t==1)
{
while(positiondet.x<850&&r==1)
{
SDL_PollEvent(&event);
switch(event.type)
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_ESCAPE:
r=0;
SDL_ShowCursor(SDL_DISABLE);
break;
}
positiondet.x++;
SDL_BlitSurface(image,NULL,screen, &positionecran);
SDL_BlitSurface(det,NULL,screen, &positiondet);
SDL_Flip(screen);
}
while(positiondet.x>700&&r==1)
{
SDL_PollEvent(&event);
switch(event.type)
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_ESCAPE:
r=0;
SDL_ShowCursor(SDL_DISABLE);
break;
}
positiondet.x--;
SDL_BlitSurface(image,NULL,screen, &positionecran);
SDL_BlitSurface(det,NULL,screen, &positiondet);
SDL_Flip(screen);
}
SDL_PollEvent(&event);
switch(event.type)
{case SDL_QUIT:
t=0;
break;
/*case SDL_MOUSEBUTTONUP:*/
//positiondet.x=event.button.x;
//positiondet.y=event.button.y;
/*while((positiondet.x!=event.button.x)||(positiondet.y!=event.button.y))
{*/
if(positiondet.x<850)
{
positiondet.x++;
}
if(positiondet.x>800)
{
positiondet.x--;
}

/*if(event.button.button==SDL_BUTTON_RIGHT)
{
positiondet.x++;
}
else if(event.button.button==SDL_BUTTON_LEFT)
{
positiondet.x--;
}
break;*/
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_ESCAPE:
t=0;
SDL_ShowCursor(SDL_DISABLE);
break;
/*case SDLK_UP:
positiondet.y--;
break;
case SDLK_DOWN:
positiondet.y++;
break;
case SDLK_RIGHT:
positiondet.x++;
break;
case SDLK_LEFT:
positiondet.x--;
break;*/
}
break;
}
SDL_BlitSurface(image,NULL,screen, &positionecran);
SDL_BlitSurface(det,NULL,screen, &positiondet);
SDL_Flip(screen);
}
SDL_FreeSurface(image);
SDL_FreeSurface(det);
SDL_Quit();
return 0;
}
