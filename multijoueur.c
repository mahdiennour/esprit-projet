#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "background.h"
#include"perso.h"
#include "enemie.h"
void main()
{
SDL_Surface *ecran =NULL;
hero hero ;
Mix_Music *music;
background back;
SDL_Event event;
int done=1;
int c=0;
int c2;
int stat;
int stat1;
int d1;
int d2;
Enemy e,e1;
hero.num=0;
initialiser_evan(&hero);
initialiser_evan1(&hero) ;
e=InitEnemy(e,1000,150);
e1=InitEnemy(e1,1000,600);
initialiser_background(&back);
SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
hero.num=0;
ecran = SDL_SetVideoMode(1600, 900, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
 SDL_EnableKeyRepeat(10, 10);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    printf("Error : %s",Mix_GetError());
  music = Mix_LoadMUS("music.mp3");
  Mix_PlayMusic(music,-1);
while (done)
{
Affiche_back(back,ecran);
afficher_hero(hero,ecran);
d1=deplacement1(&hero,&event);
d2=deplacement2(&hero,&event);
//e=MoveEnemy(e,hero.pos_hero2,&stat,hero.heromoved);
//e1=MoveEnemy1(e1,hero.pos_hero,&stat1,hero.heromoved);
//e=AnimateEnemy(e,stat);
//e1=AnimateEnemy1(e1,stat);
//AfficherEnemy(e,ecran);
//AfficherEnemy1(e1,ecran);
SDL_Flip(ecran);
scrolling1 (&hero,&back,d1,c);
scrolling2 (&hero,&back,d2,c2);
//c=collision_Parfaite(back.calque,hero.image_hero[hero.num],hero.pos_hero2,back.positionback2);
c2=collision_Parfaite2(back.calque2,hero.image_hero2[hero.num],hero.pos_hero,back.poscam1);
}
SDL_Quit();
}
