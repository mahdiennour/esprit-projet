   /**
* @file choixtouches.c
* @brief Testing Program.
* @author zribi moenes
* @version 0.1
* @date Apr 01, 2020
*
* Test changement touches
*
*/
   #include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
 #include <SDL/SDL_ttf.h>

int main(int argc, char *argv[])
 
{int i=1;
int b=1;
int j=0;
int bk2=0;
int bk3=0;
int play=1;
    int x=0,y=0,v=1, continuer=1;
   SDL_Surface *cont1 = NULL;
SDL_Surface *cont2 = NULL; 
SDL_Surface *cont3= NULL; 
SDL_Surface *back = NULL;
    SDL_Surface *ecran = NULL;
   
   
    SDL_Surface *settings1 = NULL;
    SDL_Surface *settings2 = NULL;
   
   SDL_Surface *prev=NULL ;



 SDL_Event event;
SDL_Rect positionback, positionsettings,position ;
SDL_Rect positionprev;
SDL_Rect positioncont1;
SDL_Rect positioncont2;
SDL_Rect positioncont3;
 
 positioncont1.x=400;
 positioncont1.y=350;
 positioncont2.x=200;
 positioncont2.y=200;
 positioncont3.x=400;
 positioncont3.y=200;

    positionback.x=0;
    positionback.y=0;
 
    positionsettings.x=220;
    positionsettings.y=250;
    positionprev.x=200;
    positionprev.y=500;
    SDL_Init( SDL_INIT_AUDIO|SDL_INIT_VIDEO );
    TTF_Init();
    
    SDL_WM_SetIcon(IMG_Load("icone.jpg"), NULL);
    ecran = SDL_SetVideoMode( 800,600, 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE );
    SDL_WM_SetCaption("VIDEOGAME", NULL);
     cont1=IMG_Load("cont1.png");
     cont2=IMG_Load("cont2.png");
     cont3=IMG_Load("cont3.png"); 
    back = IMG_Load("back.jpg");
    
   
    settings1 = IMG_Load("settings1.png");
    prev=IMG_Load("prev.png");
 

    SDL_BlitSurface( back, NULL, ecran, &positionback);
   
    SDL_BlitSurface(settings1, NULL, ecran,&positionsettings);
   
while (continuer)
{    SDL_BlitSurface( back, NULL, ecran, &positionback);
    
     SDL_BlitSurface(settings1, NULL, ecran,&positionsettings);
     SDL_WaitEvent(&event);
   SDL_Flip(ecran);
 x = event.motion.x;
        y = event.motion.y;
        
switch(event.type)
    { 
     case SDL_QUIT:
            continuer = 0;
            break;
    



case SDL_MOUSEBUTTONUP:



if (((x >=positionsettings.x)&&(x <=positionsettings.x +200))&&((y <=positionsettings.y+95)&&(y >= positionsettings.y)))



{
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(cont1,NULL,ecran,&positioncont1);

SDL_Flip(ecran);

bk2=1;int bk5=1;
int cont=0;
while (bk2)

{ SDL_WaitEvent(&event);


switch (event.type) 				
{case SDL_MOUSEBUTTONUP:

if (((event.button.x >=positioncont1.x)&&(event.button.x <=positioncont1.x+183))&&((event.button.y <=positioncont1.y+60 )&&(event.button.y >= positioncont1.y))){
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(cont2, NULL, ecran, &positioncont2);
SDL_BlitSurface(cont3, NULL, ecran, &positioncont3);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_Flip(ecran);
while (bk5)

{ SDL_PollEvent(&event);
////////////////////////////////////////////////////////////////////////////

switch (event.type) 				
{case SDL_MOUSEBUTTONUP:
if (((event.button.x >=positioncont2.x)&&(event.button.x <=positioncont2.x+125))&&((event.button.y <=positioncont2.y+125 )&&(event.button.y >= positioncont2.y)))
cont=2;
if (((event.button.x >=positioncont3.x)&&(event.button.x <=positioncont3.x+125))&&((event.button.y <=positioncont3.y+125 )&&(event.button.y >= positioncont3.y)))
cont=3;



else if (((event.button.x >=200)&&(event.button.x <=380))&&((event.button.y <= 550)&&(event.button.y >= 500)))
   bk5=0;



}
/////////////////////////////////////////////////////////////////////////////////
}

}

if (((event.button.x >=200)&&(event.button.x <=380))&&((event.button.y <= 550)&&(event.button.y >= 500)))
    bk2=0;
}

}

}
break;

}

}

    SDL_FreeSurface(back);
    SDL_FreeSurface(settings1);   
    SDL_Quit();
return 0;
}
