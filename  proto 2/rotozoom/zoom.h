#ifndef zoom_H
#define zoom_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
typedef struct zoom
	{
SDL_Surface *ecran; 
SDL_Surface *image;
SDL_Surface *rotation;
SDL_Rect rect;
SDL_Event event;
int continuer;
int tempsPrecedent,tempsActuel;
}zoom;
SDL_Surface * rotozoomSurface (SDL_Surface *src, double angle, double zoom, int smooth);
#endif
