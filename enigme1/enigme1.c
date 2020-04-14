#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "enigmes.h"
#include <string.h>

int afficher_enigmes(enigmes* ES,SDL_Surface *fenetre)
{int i=0;srand(time(NULL));
i=rand()%(ES->nbenigmes);
SDL_BlitSurface(ES->E[i].answer[1],NULL,fenetre,&ES->E[0].posans1);
SDL_BlitSurface(ES->E[i].answer[2],NULL,fenetre,&ES->E[0].posans2);
SDL_BlitSurface(ES->E[i].texte,NULL,fenetre,&ES->E[0].postxt);
return i;
}


void initialiser_enigmes(enigmes *ES)
{
TTF_Init();
TTF_Font *police ;
int i,j;
police = TTF_OpenFont("Indy Women.ttf",40 );
char txt[400],an1[20],an2[20];
SDL_Color couleurBlanc = {29, 156, 4 };
SDL_WM_SetCaption("Enigme quizz", NULL);
///////saisire nombre enigme /////
ES->nbenigmes=50;


for(i=0;i<ES->nbenigmes;i++)
{
ES->E[i].postxt.x=120;
ES->E[i].postxt.y=80;
ES->E[i].posans1.x=172;
ES->E[i].posans1.y=204;
ES->E[i].posans2.x=172;
ES->E[i].posans2.y=297;
}

FILE *FICHIER;
FICHIER = fopen("e.txt", "r+");
  if (!FICHIER)
     {
      printf("\aERREUR: Impossible d'ouvrir "
             "le fichier: \n");
      exit(-1);
     }

for(i=0;i<ES->nbenigmes;i++)
{
fscanf (FICHIER, "%s %s %s\n", txt, an1, an2);

for(j=0;j<strlen(txt);j++)
{
  if (txt[j]=='_')
  {
txt[j]=' ';
  }
}



ES->E[i].texte     = TTF_RenderText_Blended(police,txt, couleurBlanc);
ES->E[i].answer[1] = TTF_RenderText_Blended(police,an1, couleurBlanc);
ES->E[i].answer[2] = TTF_RenderText_Blended(police,an2, couleurBlanc);
}
fclose(FICHIER);
}

int ResolutionEniges(enigmes ES,int IndiceEnigme,char an[])
{int reponse=0;int i;
char rep[400];
FILE *FICHIER;


FICHIER = fopen("FichierReponse.txt", "r+");
  if (!FICHIER)
     {
      printf("\aERREUR: Impossible d'ouvrir "
             "le fichier: \n");
      exit(-1);
     }
for (i=0;i<=IndiceEnigme;i++)
{
    fscanf (FICHIER, "%s \n", rep);
}
fclose(FICHIER);


if (strcmp(an,rep)==0)
{
    reponse=1;
}


return reponse ;
}
/* int afficher_chrono(chrono *c, int done)
{  
 SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurBlanc = {29, 156, 4 };
char temps[20] = ""; / Tableau de char suffisamment grand /
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0;


    TTF_Init();
    SDL_WM_SetCaption("TIME LIMIT 2000MS!!!!!!!!!!!", NULL);

     Chargement de la police 
    police = TTF_OpenFont("LionCub-Regular-2.ttf", 65);

    Initialisation du temps et du texte 
    tempsActuel = SDL_GetTicks();
    sprintf(temps, "Temps : %d", compteur);
    c->texte = TTF_RenderText_Blended(police, temps, couleurBlanc);

    while (done)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                done = 0;
                break;
        }
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 100) /*Si 100 ms au moins se sont écoulées 
        {
            compteur += 100; /* On rajoute 100 ms au compteur */
           // sprintf(temps, "Temps : %d", compteur); /* On écrit dans la chaîne "temps" le nouveau temps */
     /* On supprime la surface précédente       
 c->texte = TTF_RenderText_Blended(police, temps, couleurBlanc); 
SDL_BlitSurface(c->texte, NULL,fenetre, &c->poschrono);
 On écrit la chaîne temps dans la SDL_Surface 
            tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent 
        }
        c->poschrono.x = 300;
        c->poschrono.y = 100;
 
        
    
    }

   return compteur;
}*/
void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

void enigmi()

{TTF_Font *police = NULL;
    SDL_Color couleurBlanc = {29, 156, 4 };
char temps[20] = ""; 
chrono *c;
SDL_Init (SDL_INIT_VIDEO);
int continuer=1,reponse=-1,IndiceEnigme,j,i;
TTF_Font *shine ;
TTF_Font *not ;
int compteur=0,done=1;
char txt[400],an1[20],an2[20];
   SDL_Surface *fenetre;
   SDL_Surface *background;
SDL_Surface *nice;
SDL_Surface *bad;
    SDL_Color fontblack={0,0,0};
    SDL_Color fontred={ 255, 0, 0 };
    
    SDL_Color fontbleu={0,0,255};
   SDL_Event event;
enigmes ES;

   fenetre=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE);
   SDL_Rect positionbg;
   positionbg.x=0;
   positionbg.y=0;

          if (SDL_Init(SDL_INIT_VIDEO))
   {
       fprintf (stderr,"ERROR %s",SDL_GetError());
   }

   background=IMG_Load ("images.jpg");
 nice=IMG_Load ("nice.jpg");
 bad=IMG_Load ("bad.jpg");
   SDL_BlitSurface(background,NULL,fenetre,&positionbg);
   SDL_Flip(fenetre);
  initialiser_enigmes(&ES);
IndiceEnigme=afficher_enigmes(&ES,fenetre);

///////////////////////////////////////////////

FILE *FICHIER;
FICHIER = fopen("e.txt", "r+");
  if (!FICHIER)
     {
      printf("\aERREUR: Impossible d'ouvrir "
             "le fichier: \n");
      exit(-1);
     }

for(i=0;i<=IndiceEnigme;i++)
{
fscanf (FICHIER, "%s %s %s \n", txt, an1,an2);
}

fclose(FICHIER);
//while(done)
//{//compteur=afficher_chrono(c,done);
//if (compteur>=2000)
//done=0;}
//&&done==1
  while (continuer!=0&&reponse==-1)
{


 SDL_WaitEvent(&event);
       switch(event.type)
       {

          case SDL_QUIT:

               continuer = 0;

          break;

         case SDL_KEYDOWN:
         switch (event.key.keysym.sym)
         {
          case SDLK_ESCAPE:
            continuer=0;
          break;

          case SDLK_UP:
          if (continuer==1)
          {
       not=TTF_OpenFont("Indy Women.ttf",54);
    shine=TTF_OpenFont("Indy Women.ttf",60);
    ES.E[IndiceEnigme].answer[1]=TTF_RenderText_Solid(shine,an1,fontbleu);
    ES.E[IndiceEnigme].answer[2]=TTF_RenderText_Solid(not,an2,fontred);
     SDL_BlitSurface(background,NULL,fenetre,&positionbg);
     SDL_BlitSurface(ES.E[IndiceEnigme].texte,NULL,fenetre,&ES.E[0].postxt);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[1],NULL,fenetre,&ES.E[0].posans1);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[2],NULL,fenetre,&ES.E[0].posans2);
// SDL_FreeSurface(c->texte); 
            //c->texte = TTF_RenderText_Blended(police, temps, couleurBlanc); 
//SDL_BlitSurface(c->texte, NULL,fenetre, &c->poschrono);
     SDL_Flip (fenetre);
     i=1;
     continuer=2;
          }
     else if (continuer==2)
          {
         not=TTF_OpenFont("Indy Women.ttf",54);
    shine=TTF_OpenFont("Indy Women.ttf",60);
     SDL_BlitSurface(background,NULL,fenetre,&positionbg);
    ES.E[IndiceEnigme].answer[1]=TTF_RenderText_Solid(not,an1,fontred);
    ES.E[IndiceEnigme].answer[2]=TTF_RenderText_Solid(shine,an2,fontbleu);
    SDL_BlitSurface(ES.E[IndiceEnigme].texte,NULL,fenetre,&ES.E[0].postxt);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[1],NULL,fenetre,&ES.E[0].posans1);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[2],NULL,fenetre,&ES.E[0].posans2);
 //SDL_FreeSurface(c->texte); 
        // c->texte = TTF_RenderText_Blended(police, temps, couleurBlanc); 
//SDL_BlitSurface(c->texte, NULL,fenetre, &c->poschrono);
     SDL_Flip (fenetre);
     i=2;
     continuer=1;
          }

          break;

          case SDLK_DOWN:
          if (continuer==1)
          {
        not=TTF_OpenFont("Indy Women.ttf",54);
    shine=TTF_OpenFont("Indy Women.ttf",60);
    ES.E[IndiceEnigme].answer[1]=TTF_RenderText_Solid(shine,an1,fontbleu);
    ES.E[IndiceEnigme].answer[2]=TTF_RenderText_Solid(not,an2,fontred);
     SDL_BlitSurface(background,NULL,fenetre,&positionbg);
     SDL_BlitSurface(ES.E[IndiceEnigme].texte,NULL,fenetre,&ES.E[0].postxt);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[1],NULL,fenetre,&ES.E[0].posans1);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[2],NULL,fenetre,&ES.E[0].posans2);
 //SDL_FreeSurface(c->texte); 
           // c->texte = TTF_RenderText_Blended(police, temps, couleurBlanc); 
//SDL_BlitSurface(c->texte, NULL,fenetre, &c->poschrono);
     SDL_Flip (fenetre);
     i=1;
     continuer=2;
          }
     else if (continuer==2)
          {
         not=TTF_OpenFont("Indy Women.ttf",54);
    shine=TTF_OpenFont("Indy Women.ttf",60);
     SDL_BlitSurface(background,NULL,fenetre,&positionbg);
    ES.E[IndiceEnigme].answer[1]=TTF_RenderText_Solid(not,an1,fontred);
    ES.E[IndiceEnigme].answer[2]=TTF_RenderText_Solid(shine,an2,fontbleu);
    SDL_BlitSurface(ES.E[IndiceEnigme].texte,NULL,fenetre,&ES.E[0].postxt);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[1],NULL,fenetre,&ES.E[0].posans1);
     SDL_BlitSurface(ES.E[IndiceEnigme].answer[2],NULL,fenetre,&ES.E[0].posans2);
 //SDL_FreeSurface(c->texte); 
          //  c->texte = TTF_RenderText_Blended(police, temps, couleurBlanc); 
//SDL_BlitSurface(c->texte, NULL,fenetre, &c->poschrono);
     SDL_Flip (fenetre);
     i=2;
     continuer=1;
          }
            break;

     case SDLK_RETURN :
          switch (i)
          {
              case 1 :
reponse=ResolutionEniges(ES,IndiceEnigme,an1);

              break;
              case 2:
reponse=ResolutionEniges(ES,IndiceEnigme,an2);

              break;
          }
          break;
         }
       
}

}
if (reponse==1)
{   SDL_BlitSurface(nice,NULL,fenetre,&positionbg);
   SDL_Flip(fenetre);
pause();

}
else
{
   SDL_BlitSurface(bad,NULL,fenetre,&positionbg);
   SDL_Flip(fenetre);
pause();

}

TTF_CloseFont(not);
TTF_CloseFont(shine);
	TTF_Quit();
SDL_FreeSurface(ES.E[IndiceEnigme].texte);
SDL_FreeSurface(ES.E[IndiceEnigme].answer[1]);
SDL_FreeSurface(ES.E[IndiceEnigme].answer[2]);
SDL_Quit ();
}
int main(int argc, char** argv)
{
enigmi();
return 1;

}
