#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int main(int argc, char *argv[])
{
int i=1;
int bk2=0; 
int val=1;
    int x=0,y=0, continuer=1;
    SDL_Surface *back = NULL;
    SDL_Surface *ecran = NULL;
    SDL_Surface *newgame1 = NULL;
    SDL_Surface *newgame2 = NULL;
    SDL_Surface *continue1 = NULL;
    SDL_Surface *continue2 = NULL;
    SDL_Surface *quit1 = NULL;
    SDL_Surface *quit2 = NULL;
    SDL_Surface *texte = NULL;SDL_Surface *texte1 = NULL;
    SDL_Surface *retour=NULL ;
 SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurblanche = {255, 255, 255};
SDL_Rect positionback, positionnewgame, positioncontinue, positionquit,position,position1;
SDL_Rect positionretour;

    positionback.x=0;
    positionback.y=0;
    positionnewgame.x=220;
    positionnewgame.y=50;
    positioncontinue.x=220;
    positioncontinue.y=150;
    positionquit.x=220;
    positionquit.y=250;

    positionretour.x=200;
    positionretour.y=500;

    SDL_Init( SDL_INIT_AUDIO|SDL_INIT_VIDEO );
    TTF_Init();
    SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);
    ecran = SDL_SetVideoMode( 800,600, 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE );
    SDL_WM_SetCaption("VIDEOGAME", NULL);
   
    back = IMG_Load("fond.jpg");
    newgame1 = IMG_Load("newgame1.jpg");
    newgame2 = IMG_Load("newgame2.jpg");
    continue1 = IMG_Load("continue1.jpg");
    continue2= IMG_Load ("continue2.jpg");
    quit1 = IMG_Load("quit1.jpg");
    quit2 = IMG_Load("quit2.jpg");
    retour=IMG_Load("retour.jpg");

/* Chargement de la police */
    police = TTF_OpenFont("angelina.TTF", 60);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "      Commencer des le debut ", couleurblanche);
    texte1 = TTF_RenderText_Blended(police, "Toutes les informations sont enregistrees", couleurblanche);
   
 SDL_Flip( ecran );
    //KEYBOARD EVENT
    SDL_BlitSurface( back, NULL, ecran, &positionback);
    SDL_BlitSurface(newgame1, NULL, ecran, &positionnewgame);
    SDL_BlitSurface(continue1, NULL, ecran,&positioncontinue);
    SDL_BlitSurface(quit1, NULL, ecran, &positionquit);
while (continuer)
{   SDL_BlitSurface( back, NULL, ecran, &positionback);
    SDL_BlitSurface(newgame1, NULL, ecran, &positionnewgame);
    SDL_BlitSurface(continue1, NULL, ecran,&positioncontinue);
    SDL_BlitSurface(quit1, NULL, ecran, &positionquit);
    SDL_WaitEvent(&event);
   
switch(event.type)
    {
     case SDL_QUIT:
            continuer = 0;
            break;
     case SDL_KEYDOWN:
       switch(event.key.keysym.sym)
    {
 
   case SDLK_RETURN:

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(back, NULL, ecran, &positionback);
        position.x = 10;
        position.y = 300;
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
        SDL_Flip(ecran);

break;

   case SDLK_DOWN:
                switch(i)
{
 
case 1:

i=1;

SDL_BlitSurface(newgame1,NULL,ecran,&positionnewgame);
SDL_BlitSurface(continue1,NULL,ecran,&positioncontinue);
SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
SDL_BlitSurface(newgame2,NULL,ecran,&positionnewgame);
SDL_Flip(ecran);
i++;
break;
case 2:
//BOUTTON2,CLAVIER
i++;
//initialliser ecran
SDL_BlitSurface(newgame1,NULL,ecran,&positionnewgame);
SDL_BlitSurface(continue1,NULL,ecran,&positioncontinue);
SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
SDL_BlitSurface(continue2, NULL, ecran, &positioncontinue);
SDL_Flip(ecran);
break;
case 3:
//BOUTTON4,CLAVIERdn

//initialliser ecran
i=1;
SDL_BlitSurface(newgame1,NULL,ecran,&positionnewgame);
SDL_BlitSurface(continue1,NULL,ecran,&positioncontinue); 
SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
SDL_BlitSurface(quit2,NULL,ecran,&positionquit);
SDL_Flip(ecran);
break;

}

break;

                case SDLK_UP:
switch(i)
{
case 1:
i=3;
SDL_BlitSurface(newgame1,NULL,ecran,&positionnewgame);
SDL_BlitSurface(continue1,NULL,ecran,&positioncontinue);
SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
SDL_BlitSurface(newgame2,NULL,ecran,&positionnewgame);
SDL_Flip(ecran);
break;
case 2:
i--; SDL_BlitSurface(newgame1,NULL,ecran,&positionnewgame);
SDL_BlitSurface(continue1,NULL,ecran,&positioncontinue);
SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
SDL_BlitSurface(continue2, NULL, ecran, &positioncontinue);
SDL_Flip(ecran);
break;
case 3:
i--;
SDL_BlitSurface(newgame1,NULL,ecran,&positionnewgame);  SDL_BlitSurface(continue1,NULL,ecran,&positioncontinue); SDL_BlitSurface(quit1,NULL,ecran,&positionquit); SDL_BlitSurface(quit2,NULL,ecran,&positionquit);
SDL_Flip(ecran);
break;
}
break;
case SDLK_ESCAPE:
        continuer = 0;
        break;
}
case SDL_MOUSEMOTION:

        x = event.motion.x;
        y = event.motion.y;
        //If the mouse is over the button
        if( (( x >= positionnewgame.x )&&( x <= positionnewgame.x +200 )) && (( y >= positionnewgame.y )&& ( y <= positionnewgame.y+95  )))
            {SDL_BlitSurface(newgame1,NULL,ecran,&positionnewgame);
             SDL_BlitSurface(continue1,NULL,ecran,&positioncontinue);
             SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
             SDL_BlitSurface(newgame2, NULL, ecran, &positionnewgame);        
             SDL_Flip(ecran);
}

if( (( x >= positioncontinue.x )&&( x <= positioncontinue.x +200 )) && (( y >= positioncontinue.y )&& ( y <= positioncontinue.y+95  )))
            {SDL_BlitSurface(newgame1,NULL,ecran,&positionnewgame);
             SDL_BlitSurface(continue1,NULL,ecran,&positioncontinue);
             SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
             SDL_BlitSurface(continue2, NULL, ecran, &positioncontinue);        
             SDL_Flip(ecran);
}
if( (( x >= positionquit.x )&&( x <= positionquit.x +200 )) && (( y >= positionquit.y )&& ( y <= positionquit.y+95  )))
            {SDL_BlitSurface(newgame1,NULL,ecran,&positionnewgame);
             SDL_BlitSurface(continue1,NULL,ecran,&positioncontinue);
             SDL_BlitSurface(quit1,NULL,ecran,&positionquit);
             SDL_BlitSurface(quit2, NULL, ecran, &positionquit);        
             SDL_Flip(ecran);
}

break;

case SDL_MOUSEBUTTONUP:

if( (( x >= positionnewgame.x )&&( x <= positionnewgame.x +200 )) && (( y >= positionnewgame.y )&& ( y <= positionnewgame.y+95  )))

        { while (val)
       
          { SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
            SDL_BlitSurface(back, NULL, ecran, &positionback);
            SDL_BlitSurface(retour,NULL,ecran,&positionretour);
        position.x = 10;
        position.y = 100;  
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
        SDL_Flip(ecran);
SDL_WaitEvent(&event);

switch (event.type)
{case SDL_MOUSEBUTTONUP:

if(event.button.button == SDL_BUTTON_RIGHT)
val=0;
}
}
 SDL_BlitSurface( back, NULL, ecran, &positionback);
    SDL_BlitSurface(newgame1, NULL, ecran, &positionnewgame);
    SDL_BlitSurface(continue1, NULL, ecran,&positioncontinue);
    SDL_BlitSurface(quit1, NULL, ecran, &positionquit);
SDL_Flip(ecran);
val=1;
}


if (((x >=positionquit.x)&&(x <=positionquit.x +200))&&((y <=positionquit.y+95)&&(y >= positionquit.y)))
{
    continuer=0;
}

if (((x >=positioncontinue.x)&&(x <=positioncontinue.x +200))&&((y <=positioncontinue.y+95)&&(y >= positioncontinue.y)))
{SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(retour,NULL,ecran,&positionretour);
        position1.x = 10;
        position1.y = 100;
SDL_BlitSurface(texte1, NULL, ecran, &position1); /* Blit du texte */
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
    SDL_FreeSurface(newgame1);
    SDL_FreeSurface(continue1);
    SDL_FreeSurface(quit1);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Quit();
return 0;
}

   
	
