#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include <math.h>
#include "file.h"
#include <stdio.h>
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define FPS 60


void initText(Text *T)
{
	T->textDt=NULL;
	T->textPosition=NULL;
	//T->textVitesse=NULL;
	T->textAcceleration=NULL;
}

int loadFont(TTF_Font **police)
{
	if(TTF_Init() == -1) {
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return EXIT_FAILURE;
	}
	*police = TTF_OpenFont("../images/Ubuntu-Title.ttf", 20);
	return EXIT_SUCCESS;
}


void displayText(TTF_Font *police,Text *T,SDL_Surface *screen,ttimage *allin,Uint32 dt)
{
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};
	SDL_Rect positionTextDt;
	SDL_Rect positionTextPos;
	//SDL_Rect positionTextVitesse;
	SDL_Rect positionTextAcceleration;

	positionTextDt.x=150;
	positionTextPos.x=150;
	//positionTextVitesse.x=300;
	positionTextAcceleration.x=150;

	positionTextDt.y=20;
	positionTextPos.y=50;
	//positionTextVitesse.y=80;
	positionTextAcceleration.y=80;

	char DT[50];
	//char vitesse[50];
	char acceleration[50];
	char position[50];

	//dt
	sprintf(DT,"dt= %d ms",dt);
	T->textDt = TTF_RenderText_Shaded(police,DT,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->textDt, SDL_SRCCOLORKEY, SDL_MapRGB(T->textDt->format, 255, 255, 255));

	//position
	sprintf(position,"pos x=%d pixels",allin->background.postion.x);
	T->textPosition = TTF_RenderText_Shaded(police,position,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->textPosition, SDL_SRCCOLORKEY, SDL_MapRGB(T->textPosition->format, 255, 255, 255));
	//vitesse
	//sprintf(vitesse,"vitesse= %f m/s",V.velocity);
	//T->textVitesse = TTF_RenderText_Shaded(police,vitesse,couleurNoire, couleurBlanche);
	//SDL_SetColorKey(T->textVitesse, SDL_SRCCOLORKEY, SDL_MapRGB(T->textVitesse->format, 255, 255, 255));
	//acceleration
sprintf(acceleration,"acceleration= %f m/s/s",allin->person.acceleration);
	T->textAcceleration = TTF_RenderText_Shaded(police,acceleration,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->textAcceleration, SDL_SRCCOLORKEY, SDL_MapRGB(T->textAcceleration->format, 255, 255, 255));
	//clean screen &&
	//Flip the backbuffer to the primary Hardware Video Memory
	SDL_BlitSurface(T->textDt,NULL,screen,&positionTextDt);
	SDL_BlitSurface(T->textPosition,NULL,screen,&positionTextPos);
	//SDL_BlitSurface(T->textVitesse,NULL,screen,&positionTextVitesse);
	SDL_BlitSurface(T->textAcceleration,NULL,screen,&positionTextAcceleration);

}

int fnparabole(int x)
{
int y;
y=((-(x*x))+4);
if(y%10==0)
  return y;

}
void affichejump(ttimage *allin,SDL_Surface *screen)
{

SDL_BlitSurface(allin->background.image, &allin->background.postion, screen, NULL);
SDL_BlitSurface(allin->person.image, NULL, screen, &allin->person.postion);
SDL_UpdateRect(screen, 0, 0, 0, 0);  

}



void initialiser_image_position(ttimage *allin)
{
     allin->background.image = SDL_LoadBMP("grass.bmp");
     allin->background.postion.x=0;
     allin->background.postion.y=0;
       
     allin->person.image=IMG_Load("detective1-1.png");
     allin->person.postion.x=0;
     allin->person.postion.y=398;
     allin->person.sens=1;
     allin->person.acceleration=0.001;
allin->person.vitesse=1;
    
}
void affichesimple(SDL_Surface *image ,SDL_Rect pos,SDL_Surface *screen)
{
SDL_BlitSurface(image, NULL, screen, &pos);
}

void afficheall(ttimage *allin,SDL_Surface *screen)
{

SDL_BlitSurface(allin->background.image, NULL, screen, &allin->background.postion);
affichesimple(allin->person.image ,allin->person.postion,screen);
SDL_UpdateRect(screen, 0, 0, 0, 0);
}
void move(ttimage *allin ,SDL_Event event ,SDL_Surface *screen,int *gameover,Uint32 dt)
{
int x,i;
SDL_Rect tmp,tmpe;
        switch( event.type ){
            /* Look for a keypress */
            case SDL_QUIT:
         (* gameover) = 1;
          break;
            case SDL_KEYDOWN:
                /* Check the SDLKey values and move change the coords */
                switch( event.key.keysym.sym ){
                   case SDLK_ESCAPE:
            case SDLK_q:
              (*gameover) = 1;
              break;
                        case SDLK_LEFT:
 if (allin->person.acceleration<0.25)
                       allin->person.acceleration+=0.005;
                        allin->person.postion.x -=(0.5*allin->person.acceleration)*(dt*dt)+allin->person.vitesse*dt;
                        allin->person.sens=-1;
                        break;
                        case SDLK_RIGHT:
if (allin->person.acceleration<0.25)
                        allin->person.acceleration+=0.005;
                        allin->person.postion.x +=(0.5*allin->person.acceleration)*(dt*dt)+allin->person.vitesse*dt;
                        allin->person.sens=1;
                        break;
                        case SDLK_SPACE:
                        if(allin->person.sens==-1)
                            {x=-8;
                               for(i=0;i<17;i++)
                                  {

                                 allin->person.postion.x-=10;

                                        if(i<7)
                                           allin->person.postion.y+=fnparabole(x);


                                        else

                                      allin->person.postion.y-=fnparabole(x);

                                    affichejump(allin,screen);
                                    SDL_Delay(10);
                                    x++;
                                   


                                   }
                            }
                        if(allin->person.sens==1)
                            {
                              x=-8;
                             for(i=0;i<17;i++)
                                {


                                allin->person.postion.x+=10;

                                     if(i<7)
                                      allin->person.postion.y+=fnparabole(x);

                                     else
                                      allin->person.postion.y-=fnparabole(x);

                                 affichejump(allin,screen);
                                 SDL_Delay(10);
                               x++;
                               

                            }



                        break;
                    default:
                        break;
                }

                break;
                }
  break;               
case SDL_KEYUP:
switch( event.key.keysym.sym ){
          case SDLK_LEFT:
            allin->person.acceleration=0.001;
          break;
          case SDLK_RIGHT:
            allin->person.acceleration=0.001;
          break;
                              }
break;

}
}

int main ( )
{ 
  ttimage allin;
  SDL_Surface *screen,*test;
  SDL_Event event;
  int  gameover;
  Uint32 t_prev,dt=1; 
Text txt;
  TTF_Font *police = NULL;
 

  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);

  /* set the title bar */
  SDL_WM_SetCaption("JUMP AND ACCELERATION", "JUMP AND ACCELERATION");

  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);


  /* load fn */

initialiser_image_position(&allin);

initText(&txt);
loadFont(&police);
  gameover = 0;
  /* loop game */
  while (!gameover)
  {
t_prev=SDL_GetTicks();
 SDL_PollEvent(&event); 
      

move(&allin ,event,screen ,&gameover,dt);


afficheall(&allin,screen);
displayText(police,&txt,screen,&allin,0);   
SDL_Flip(screen);
 dt=SDL_GetTicks()-t_prev; 
  if(1000/FPS > dt)
    SDL_Delay(1000/FPS-dt);
  }

  /* clean up */
	TTF_CloseFont(police);
  SDL_Quit();


  return 0;
}


