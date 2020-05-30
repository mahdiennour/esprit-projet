#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32

int main ( int argc, char *argv[] )
{
  SDL_Surface *screen, *temp, *sprite, *grass;
  SDL_Rect rcSprite, rcGrass;
  SDL_Event event;

  int colorkey, gameover;
int z=0,d=0;

  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);

  /* set the title bar */
  SDL_WM_SetCaption("SDL Move", "SDL Move");

  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);


  /* load sprite */
  temp   = SDL_LoadBMP("sprite.bmp");
  sprite = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* setup sprite colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

  /* load grass */
  temp  = SDL_LoadBMP("grass.bmp");
  grass = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* set sprite position */
  rcSprite.x = 0;
  rcSprite.y = 206;

  gameover = 0;

  /* message pump */
  while (!gameover)
  {
    /* look for an event */
    if (SDL_PollEvent(&event)) {
      /* an event was found */
      switch (event.type) {
        /* close button clicked */
        case SDL_QUIT:
          gameover = 1;
          break;

        /* handle the keyboard */
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
            case SDLK_q:
              gameover = 1;
              break;
          }
          break;
        case SDL_MOUSEMOTION :
         
         //Get the mouse offsets
          z = event.motion.x;
          d = event.motion.y;
                rcSprite.x = z;
                rcSprite.y =d;
                SDL_BlitSurface(grass, NULL, screen, &rcGrass);
         SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
            SDL_UpdateRect(screen, 0, 0, 0, 0);
         

         break;
      }
    }
    //draw the grass 
    for (int x = 0; x < SCREEN_WIDTH / SPRITE_SIZE; x++) {
      for (int y = 0; y < SCREEN_HEIGHT / SPRITE_SIZE; y++) {
        rcGrass.x =0;
        rcGrass.y =0;
        SDL_BlitSurface(grass, NULL, screen, &rcGrass);
      }
    }
   //draw the sprite
   SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
  
    /* update the screen */
    SDL_UpdateRect(screen, 0, 0, 0, 0);
  }

  /* clean up */
  SDL_FreeSurface(sprite);
  SDL_FreeSurface(grass);
  SDL_Quit();

  return 0;
}
