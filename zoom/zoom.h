#ifndef zoom_H
#define zoom_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#define SMOOTHING_OFF		0
#define SMOOTHING_ON		1
#define VALUE_LIMIT	0.001
typedef struct zoom
	{
SDL_Surface *ecran; 
SDL_Surface *image;
SDL_Surface *rotation;
SDL_Rect rect;
SDL_Event event;
SDL_Surface *rz_src;
SDL_Surface *rz_dst;
double zoominv;
double radangle, sanglezoom, canglezoom, sanglezoominv, canglezoominv;
int dstwidthhalf, dstwidth, dstheighthalf, dstheight;
double x, y, cx, cy, sx, sy;
int is32bit;
int i, src_converted;
}zoom;
SDL_Surface *rotozoomSurface (SDL_Surface * src, double angle, double zoom, int smooth);
#endif
