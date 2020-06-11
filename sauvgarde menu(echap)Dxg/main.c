#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int main(int argc, char *argv[]) 
{
    int x=0,y=0, continuer=1; 
    SDL_Surface *back = NULL;
    SDL_Surface *ecran = NULL;
    SDL_Surface *texte = NULL;
      SDL_Surface *oui = NULL;
      SDL_Surface *non=NULL; 
      SDL_Surface *retour=NULL; 
      
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};

    SDL_Rect positionback;SDL_Rect positionoui,position,positionnon,positionretour;
    positionback.x=0;
    positionback.y=0;

    SDL_Init( SDL_INIT_AUDIO|SDL_INIT_VIDEO );
    TTF_Init();
   
    SDL_WM_SetIcon(IMG_Load("icone.jpg"), NULL);
    ecran = SDL_SetVideoMode( 800,600, 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE );
    SDL_WM_SetCaption("VIDEOGAME", NULL);
   
     back = IMG_Load("fond.jpg");
     oui = IMG_Load("oui.jpg");
     non = IMG_Load("non.jpg");
     retour=IMG_Load("retour.jpg");
/* Chargement de la police */
    police = TTF_OpenFont("angelina.TTF", 66);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Voulez vous sauvgardez?", couleurNoire);
  SDL_Flip( ecran );
    //KEYBOARD EVENT

position.x   = 200;
position.y   = 50;
positionoui.x=100;
positionoui.y=200;
positionnon.x=400;
positionnon.y=200;
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_Delay(500); 
SDL_Flip(ecran); 
while (continuer)
{ 
    SDL_WaitEvent(&event);
   
  switch(event.type)
      {
       case SDL_QUIT:
            continuer =0;
            break;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
                { 
  
                     SDL_BlitSurface(back,NULL,ecran,&positionback);
                     SDL_BlitSurface(texte, NULL, ecran, &position);
                     SDL_BlitSurface(oui, NULL, ecran,&positionoui);
                     SDL_BlitSurface(non, NULL, ecran,&positionnon);
                     SDL_Flip(ecran);
    
              break;
}
}//switch ksym//
}//switch type//

}//while//
//SDL_BlitSurface(back,NULL,ecran,&positionback);
    //MOUSE EVENT
    SDL_FreeSurface(back);
     SDL_FreeSurface(oui);
     SDL_FreeSurface(non);
   TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Quit();
return 0;
}

   
