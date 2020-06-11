/**
* @file choixperso.c
* @brief Testing Program.
* @author zribi moenes
* @version 0.1
* @date Apr 01, 2020
*
* Test choix perso
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
int bk4=1;
int test=0;
int play=1;
    int x=0,y=0,v=1, continuer=1;
   SDL_Surface *personnage =NULL; 
SDL_Surface *personnage1 =NULL;
SDL_Surface *personnage2 =NULL;
SDL_Surface *personnage3 =NULL;
SDL_Surface *personnage4 =NULL;
SDL_Surface *personnage5 =NULL;
SDL_Surface *back = NULL;
    SDL_Surface *ecran = NULL;
    SDL_Surface *play1 = NULL;
   
   
    SDL_Surface *settings1 = NULL;
  
   
   SDL_Surface *prev=NULL ;



 SDL_Event event;
SDL_Rect positionback, positionplay,  positionsettings,position ;
SDL_Rect positionprev;
SDL_Rect positionpersonnage;
  SDL_Rect positionpersonnage1;
SDL_Rect positionpersonnage2;
SDL_Rect positionpersonnage3;
SDL_Rect positionpersonnage4;
SDL_Rect positionpersonnage5;
  positionpersonnage.x=200;
    positionpersonnage.y=150;
   positionpersonnage1.x=10;
    positionpersonnage1.y=50;
positionpersonnage2.x=110;
    positionpersonnage2.y=50;
positionpersonnage3.x=210;
    positionpersonnage3.y=50;
positionpersonnage4.x=310;
    positionpersonnage4.y=50;
positionpersonnage5.x=410;
 positionpersonnage5.y=300;
 positionback.x=0;
    positionback.y=0;
    positionplay.x=220;
    positionplay.y=50;
    positionsettings.x=220;
    positionsettings.y=250;
    positionprev.x=200;
    positionprev.y=500;
    SDL_Init( SDL_INIT_AUDIO|SDL_INIT_VIDEO );
    TTF_Init();
    
    SDL_WM_SetIcon(IMG_Load("icone.jpg"), NULL);
    ecran = SDL_SetVideoMode( 800,600, 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE );
    SDL_WM_SetCaption("VIDEOGAME", NULL);
    personnage=IMG_Load("personnage.png");
    back = IMG_Load("back.jpg");
    play1 = IMG_Load("play1.png");

   personnage1=IMG_Load("1.jpg");
personnage2=IMG_Load("2.png");
personnage3=IMG_Load("3.png");
personnage4=IMG_Load("4.jpg");
personnage5=IMG_Load("5.png");
    settings1 = IMG_Load("settings1.png");
   
    prev=IMG_Load("prev.png");


    SDL_BlitSurface( back, NULL, ecran, &positionback);
    SDL_BlitSurface(play1, NULL, ecran, &positionplay);
    SDL_BlitSurface(settings1, NULL, ecran,&positionsettings);
   
while (continuer)
{    SDL_BlitSurface( back, NULL, ecran, &positionback);
     SDL_BlitSurface(play1, NULL, ecran, &positionplay);
     SDL_BlitSurface(settings1, NULL, ecran,&positionsettings);
     SDL_WaitEvent(&event);
     x = event.motion.x;
        y = event.motion.y;
SDL_Flip(ecran);
switch(event.type)
    { 
     case SDL_QUIT:
            continuer = 0;

            break;
   



case SDL_MOUSEBUTTONUP:

if (((x >=positionplay.x)&&(x <=positionplay.x +200))&&((y <=positionplay.y+95)&&(y >= position.y)))



{
SDL_BlitSurface(back,NULL,ecran,&positionback);


 if (test==1)
SDL_BlitSurface(personnage1, NULL, ecran, &positionpersonnage1);
else if (test==2)
SDL_BlitSurface(personnage2, NULL, ecran, &positionpersonnage2);
else if (test==3)
SDL_BlitSurface(personnage3, NULL, ecran, &positionpersonnage3);
else if (test==4)
SDL_BlitSurface(personnage4, NULL, ecran, &positionpersonnage4);
else if (test==5)
SDL_BlitSurface(personnage5, NULL, ecran, &positionpersonnage5);

SDL_Flip(ecran);

bk2=1;
while (bk2)

{ SDL_WaitEvent(&event);


switch (event.type) 
{ case SDL_QUIT:
            continuer = 0;
            bk2=0;
break;
    				

}

}

}

if (((x >=positionsettings.x)&&(x <=positionsettings.x +200))&&((y <=positionsettings.y+95)&&(y >= positionsettings.y)))



{
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);

 SDL_BlitSurface(personnage, NULL, ecran, &positionpersonnage);

SDL_Flip(ecran);

bk2=1;
while (bk2)

{ SDL_WaitEvent(&event);


switch (event.type) 				
{case SDL_MOUSEBUTTONUP:
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (((event.button.x >=positionpersonnage.x)&&(event.button.x <=positionpersonnage.x+78))&&((event.button.y <=positionpersonnage.y+129 )&&(event.button.y >= positionpersonnage.y))){
SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(prev,NULL,ecran,&positionprev);
SDL_BlitSurface(personnage1, NULL, ecran, &positionpersonnage1);
SDL_BlitSurface(personnage2, NULL, ecran, &positionpersonnage2);
SDL_BlitSurface(personnage3, NULL, ecran, &positionpersonnage3);
SDL_BlitSurface(personnage4, NULL, ecran, &positionpersonnage4);
SDL_BlitSurface(personnage5, NULL, ecran, &positionpersonnage5);
SDL_Flip(ecran);
while (bk4)

{ SDL_PollEvent(&event);


switch (event.type) 				
{case SDL_MOUSEBUTTONUP:
if (((event.button.x >=positionpersonnage1.x)&&(event.button.x <=positionpersonnage1.x+40))&&((event.button.y <=positionpersonnage1.y+38 )&&(event.button.y >= positionpersonnage1.y)))
test=1;
if (((event.button.x >=positionpersonnage2.x)&&(event.button.x <=positionpersonnage2.x+90))&&((event.button.y <=positionpersonnage2.y+120 )&&(event.button.y >= positionpersonnage2.y)))
test=2;
if (((event.button.x >=positionpersonnage3.x)&&(event.button.x <=positionpersonnage3.x+90))&&((event.button.y <=positionpersonnage3.y+120 )&&(event.button.y >= positionpersonnage3.y)))
test=3;
if (((event.button.x >=positionpersonnage4.x)&&(event.button.x <=positionpersonnage4.x+268))&&((event.button.y <=positionpersonnage4.y+188 )&&(event.button.y >= positionpersonnage4.y)))
test=4;
if (((event.button.x >=positionpersonnage5.x)&&(event.button.x <=positionpersonnage5.x+72))&&((event.button.y <=positionpersonnage5.y+144 )&&(event.button.y >= positionpersonnage5.y)))
test=5;


else if (((event.button.x >=200)&&(event.button.x <=380))&&((event.button.y <= 550)&&(event.button.y >= 500)))
   bk4=0;



}

}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
