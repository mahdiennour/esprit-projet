#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int main(int argc, char *argv[])
{
int bk2=0;
    int x=0,y=0, continuer=1;
    SDL_Surface *back = NULL;
    SDL_Surface *ecran = NULL;
    SDL_Surface *quit1 = NULL;
    SDL_Surface *quit2 = NULL;
    SDL_Surface *texte = NULL;
    SDL_Surface *oui1 = NULL;
    SDL_Surface *non1 = NULL;
    SDL_Surface *retour=NULL ;
 SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurblanche = {255, 255, 255};
    SDL_Rect positionback,positionquit,position;
    SDL_Rect positionretour;
    SDL_Rect positionoui,positionnon;

    positionback.x=0;
    positionback.y=0;
    positionquit.x=500;
    positionquit.y=500;
    positionretour.x=200;
    positionretour.y=500;

    SDL_Init( SDL_INIT_AUDIO|SDL_INIT_VIDEO );
    TTF_Init();
    SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);
    ecran = SDL_SetVideoMode( 800,600, 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE );
    SDL_WM_SetCaption("VIDEOGAME", NULL);

    back = IMG_Load("fond.jpg");
    quit1 = IMG_Load("quit1.png");
    quit2= IMG_Load ("quit2.png");
    retour=IMG_Load("retour.jpg");
    oui1= IMG_Load("non.jpg");
    non1=IMG_Load("oui.jpg");
/* Chargement de la police */
    police = TTF_OpenFont("angelina.TTF", 60);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "VOULEZ VOUS SAUVGARDER?", couleurblanche);
    SDL_Flip( ecran );
    SDL_BlitSurface( back, NULL, ecran, &positionback);
    SDL_BlitSurface(quit1, NULL, ecran,&positionquit);
    SDL_BlitSurface(oui1, NULL, ecran, &positionoui);
    SDL_BlitSurface(non1, NULL, ecran, &positionnon);
while (continuer)
{   SDL_BlitSurface( back, NULL, ecran, &positionback);
    SDL_BlitSurface(quit1, NULL, ecran,&positionquit);
    SDL_WaitEvent(&event);

switch(event.type)
    {
     case SDL_QUIT:
            continuer = 0;
            break;
case SDL_MOUSEMOTION:

        x = event.motion.x;
        y = event.motion.y;
        //If the mouse is over the button
if( (( x >= positionquit.x )&&( x <= positionquit.x +200 )) && (( y >= positionquit.y )&& ( y <= positionquit.y+95  )))
            {
             SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
             SDL_BlitSurface(quit2, NULL, ecran, &positionquit);
             SDL_Flip(ecran);
            }
break;

case SDL_MOUSEBUTTONUP:

if (((x >=positionquit.x)&&(x <=positionquit.x +200))&&((y <=positionquit.y+95)&&(y >= positionquit.y)))
{SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(retour,NULL,ecran,&positionretour);
            position.x    = 10;
            position.y    = 100;
            positionoui.x = 100;
            positionoui.y =200;
            positionnon.x =400;
            positionnon.y =200;

      SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
      SDL_BlitSurface(oui1, NULL, ecran, &positionoui);
      SDL_BlitSurface(non1, NULL, ecran, &positionnon);
      SDL_Flip(ecran);
SDL_WaitEvent(&event);
SDL_Flip(ecran);

bk2=1;
while (bk2)
{ SDL_WaitEvent(&event);
switch (event.type)
{case SDL_MOUSEBUTTONUP:
   bk2=0;
}
}
}
break;
}
}
    //MOUSE EVENT
    SDL_FreeSurface(back);
    SDL_FreeSurface(quit1);
    TTF_CloseFont(police);
    SDL_FreeSurface(oui1);
    SDL_FreeSurface(non1);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Quit();
return 0;
}






