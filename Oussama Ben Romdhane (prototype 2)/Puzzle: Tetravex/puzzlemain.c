#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>




SDL_Surface* fenetre;


SDL_Event event;


void attendre(float temps);
void intialisation();
void cleanup();
void afficher_texte( int x, int y, int taille, char *ch, int R, int G,int B);
void cas1 ();
void cas2 ();
void cas3 ();
void cas4 ();
void cas5 ();
void cas6 ();
void game();







int main(int argc,char** argv)
{

    SDL_Init( SDL_INIT_VIDEO );
    fenetre = SDL_SetVideoMode(1024, 668, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF);
    TTF_Init();
  
    game();
    return 0;
}

void temps(time_t t1)
{
    int seconde=0;
    int minute=0;
    int heure=0;
    int diff=0;
    char temps[10];
    char lose[]="YOU LOSE!";
    char quit1[]="press q to quit";
    char timelimit[]="Time Limit";
    char timelimit_1[]="5 mins";
    time_t t2;

    t2 = time(NULL);
    diff=difftime(t2, t1);


    while(diff>=3600)
    {
        diff=diff-3600;
        heure++;
    }
    while(diff>=60)
    {
        diff=diff-60;
        minute++;

}
   
 seconde=diff;

while (minute>=5)
{
SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 0, 0, 0));
afficher_texte(300,200,70,lose,255,0,0);
afficher_texte(200,300,70,quit1,255,0,0);
SDL_Flip(fenetre);

if (SDL_WaitEvent(&event)) {
if(event.type == SDL_KEYDOWN) 
  {
    if (event.key.keysym.sym == SDLK_q)
     {
SDL_Quit();
     }
  }
}
}



    if (heure<10)
        sprintf(temps,"0%d:",heure);
    else
        sprintf(temps,"%d:",heure);
    if (minute<10)
        sprintf(temps,"%s0%d:",temps,minute);
    else
        sprintf(temps,"%s%d:",temps,minute);
    if (seconde<10)
        sprintf(temps,"%s0%d",temps,seconde);
    else
        sprintf(temps,"%s%d",temps,seconde);
    printf("%s\n",temps);
    afficher_texte(165,39,45,temps,255,255,255);
    afficher_texte(429,35,30,timelimit,255,255,255);
    afficher_texte(463,70,30,timelimit_1,255,255,255);
    FILE *fp=fopen("Fichiers/time/time.txt","w");
    fprintf(fp,"%s\n",temps);
    fclose(fp);

}


void cleanup()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


void afficher_texte( int x, int y, int taille, char *ch, int R, int G,int B)
{
    TTF_Font* Font = TTF_OpenFont("Fichiers/Fonts/font.ttf",taille);
    SDL_Color color = {R, G, B};
    SDL_Surface* surface = TTF_RenderText_Solid(Font,ch,color);
    SDL_Rect texteDestination;
    texteDestination.x = x;
    texteDestination.y = y;
    SDL_BlitSurface(surface,NULL,fenetre,&texteDestination);
    SDL_FreeSurface(surface);
    TTF_CloseFont(Font);
}



void cas1()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;
   




    

    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 205;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);



    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);

   

    

    SDL_Surface* carre1 = IMG_Load("Fichiers/cas1/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas1/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas1/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas1/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas1/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas1/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas1/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas1/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas1/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
SDL_Flip(fenetre);




  

    while(!(((imaged1.x==imagegd1.x)&&(imaged1.y==imagegd1.y))&&((imaged2.x==imagegd2.x)&&(imaged2.y==imagegd2.y))&&((imaged3.x==imagegd3.x)&&(imaged3.y==imagegd3.y))&&((imaged4.x==imagegd4.x)&&(imaged4.y==imagegd4.y))&&((imaged5.x==imagegd5.x)&&(imaged5.y==imagegd5.y))&&((imaged6.x==imagegd6.x)&&(imaged6.y==imagegd6.y))&&((imaged7.x==imagegd7.x)&&(imaged7.y==imagegd7.y))&&((imaged8.x==imagegd8.x)&&(imaged8.y==imagegd8.y))&&((imaged9.x==imagegd9.x)&&(imaged9.y==imagegd9.y))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
                  
                }
            }
 if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


















                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
           
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        temps(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }
int continuer=1;
while (continuer)
{
SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 0, 0, 0));
char end[]="YOU WIN!";
char quit2[]="press q to quit";
afficher_texte(300,200,70,end,0,255,0);
afficher_texte(200,300,70,quit2,0,255,0);
SDL_Flip(fenetre);

if (SDL_WaitEvent(&event)) {
if(event.type == SDL_KEYDOWN) 
  {
    if (event.key.keysym.sym == SDLK_q)
     {
continuer=0;
     }
  }
}
}
    cleanup();

}


void cas2()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;




   

    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 205;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);



    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);

   

    SDL_Surface* carre1 = IMG_Load("Fichiers/cas3/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas3/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas3/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas3/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas3/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas3/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas3/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas3/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas3/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
    SDL_Flip(fenetre);





    while(!(((imaged1.x==imagegd1.x)&&(imaged1.y==imagegd1.y))&&((imaged2.x==imagegd2.x)&&(imaged2.y==imagegd2.y))&&((imaged3.x==imagegd3.x)&&(imaged3.y==imagegd3.y))&&((imaged4.x==imagegd4.x)&&(imaged4.y==imagegd4.y))&&((imaged5.x==imagegd5.x)&&(imaged5.y==imagegd5.y))&&((imaged6.x==imagegd6.x)&&(imaged6.y==imagegd6.y))&&((imaged7.x==imagegd7.x)&&(imaged7.y==imagegd7.y))&&((imaged8.x==imagegd8.x)&&(imaged8.y==imagegd8.y))&&((imaged9.x==imagegd9.x)&&(imaged9.y==imagegd9.y))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
                
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        temps(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }
int continuer=1;
while (continuer)
{
SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 0, 0, 0));
char end[]="YOU WIN!";
char quit2[]="press q to quit";
afficher_texte(300,200,70,end,0,255,0);
afficher_texte(200,300,70,quit2,0,255,0);
SDL_Flip(fenetre);

if (SDL_WaitEvent(&event)) {
if(event.type == SDL_KEYDOWN) 
  {
    if (event.key.keysym.sym == SDLK_q)
     {
continuer=0;
     }
  }
}
}
    cleanup();

}




void cas3()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;
   





    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 205;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);




    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);

   

    SDL_Surface* carre1 = IMG_Load("Fichiers/cas2/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas2/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas2/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas2/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas2/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas2/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas2/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas2/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas2/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
    SDL_Flip(fenetre);




    

    while(!(((imaged1.x==imagegd1.x)&&(imaged1.y==imagegd1.y))&&((imaged2.x==imagegd2.x)&&(imaged2.y==imagegd2.y))&&((imaged3.x==imagegd3.x)&&(imaged3.y==imagegd3.y))&&((imaged4.x==imagegd4.x)&&(imaged4.y==imagegd4.y))&&((imaged5.x==imagegd5.x)&&(imaged5.y==imagegd5.y))&&((imaged6.x==imagegd6.x)&&(imaged6.y==imagegd6.y))&&((imaged7.x==imagegd7.x)&&(imaged7.y==imagegd7.y))&&((imaged8.x==imagegd8.x)&&(imaged8.y==imagegd8.y))&&((imaged9.x==imagegd9.x)&&(imaged9.y==imagegd9.y))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
             
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        temps(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }

  int continuer=1;
while (continuer)
{
SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 0, 0, 0));
char end[]="YOU WIN!";
char quit2[]="press q to quit";
afficher_texte(300,200,70,end,0,255,0);
afficher_texte(200,300,70,quit2,0,255,0);
SDL_Flip(fenetre);

if (SDL_WaitEvent(&event)) {
if(event.type == SDL_KEYDOWN) 
  {
    if (event.key.keysym.sym == SDLK_q)
     {
continuer=0;
     }
  }
}
}  
    cleanup();

}



void cas4()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;
   



 

    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 205;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);




    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);

 

    SDL_Surface* carre1 = IMG_Load("Fichiers/cas4/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas4/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas4/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas4/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas4/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas4/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas4/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas4/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas4/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
    SDL_Flip(fenetre);





    while(!(((imaged1.x==imagegd1.x)&&(imaged1.y==imagegd1.y))&&((imaged2.x==imagegd2.x)&&(imaged2.y==imagegd2.y))&&((imaged3.x==imagegd3.x)&&(imaged3.y==imagegd3.y))&&((imaged4.x==imagegd4.x)&&(imaged4.y==imagegd4.y))&&((imaged5.x==imagegd5.x)&&(imaged5.y==imagegd5.y))&&((imaged6.x==imagegd6.x)&&(imaged6.y==imagegd6.y))&&((imaged7.x==imagegd7.x)&&(imaged7.y==imagegd7.y))&&((imaged8.x==imagegd8.x)&&(imaged8.y==imagegd8.y))&&((imaged9.x==imagegd9.x)&&(imaged9.y==imagegd9.y))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
              
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        temps(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }

int continuer=1;
while (continuer)
{
SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 0, 0, 0));
char end[]="YOU WIN!";
char quit2[]="press q to quit";
afficher_texte(300,200,70,end,0,255,0);
afficher_texte(200,300,70,quit2,0,255,0);
SDL_Flip(fenetre);

if (SDL_WaitEvent(&event)) {
if(event.type == SDL_KEYDOWN) 
  {
    if (event.key.keysym.sym == SDLK_q)
     {
continuer=0;
     }
  }
}
}    
    cleanup();

}



void cas5()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;
    



 

    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 205;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);



    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);



    SDL_Surface* carre1 = IMG_Load("Fichiers/cas5/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas5/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas5/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas5/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas5/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas5/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas5/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas5/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas5/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
    SDL_Flip(fenetre);






   while(!(((imaged1.x==imagegd1.x)&&(imaged1.y==imagegd1.y))&&((imaged2.x==imagegd2.x)&&(imaged2.y==imagegd2.y))&&((imaged3.x==imagegd3.x)&&(imaged3.y==imagegd3.y))&&((imaged4.x==imagegd4.x)&&(imaged4.y==imagegd4.y))&&((imaged5.x==imagegd5.x)&&(imaged5.y==imagegd5.y))&&((imaged6.x==imagegd6.x)&&(imaged6.y==imagegd6.y))&&((imaged7.x==imagegd7.x)&&(imaged7.y==imagegd7.y))&&((imaged8.x==imagegd8.x)&&(imaged8.y==imagegd8.y))&&((imaged9.x==imagegd9.x)&&(imaged9.y==imagegd9.y))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
               
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        temps(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }

 int continuer=1;
while (continuer)
{
SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 0, 0, 0));
char end[]="YOU WIN!";
char quit2[]="press q to quit";
afficher_texte(300,200,70,end,0,255,0);
afficher_texte(200,300,70,quit2,0,255,0);
SDL_Flip(fenetre);

if (SDL_WaitEvent(&event)) {
if(event.type == SDL_KEYDOWN) 
  {
    if (event.key.keysym.sym == SDLK_q)
     {
continuer=0;
     }
  }
}
}  
    cleanup();

}




void cas6()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;
    


   

    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 205;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);




    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);



    SDL_Surface* carre1 = IMG_Load("Fichiers/cas6/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas6/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas6/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas6/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas6/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas6/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas6/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas6/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas6/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
    SDL_Flip(fenetre);





    while(!(((imaged1.x==imagegd1.x)&&(imaged1.y==imagegd1.y))&&((imaged2.x==imagegd2.x)&&(imaged2.y==imagegd2.y))&&((imaged3.x==imagegd3.x)&&(imaged3.y==imagegd3.y))&&((imaged4.x==imagegd4.x)&&(imaged4.y==imagegd4.y))&&((imaged5.x==imagegd5.x)&&(imaged5.y==imagegd5.y))&&((imaged6.x==imagegd6.x)&&(imaged6.y==imagegd6.y))&&((imaged7.x==imagegd7.x)&&(imaged7.y==imagegd7.y))&&((imaged8.x==imagegd8.x)&&(imaged8.y==imagegd8.y))&&((imaged9.x==imagegd9.x)&&(imaged9.y==imagegd9.y))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
             
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        temps(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }

 int continuer=1;
while (continuer)
{
SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 0, 0, 0));
char end[]="YOU WIN!";
char quit2[]="press q to quit";
afficher_texte(300,200,70,end,0,255,0);
afficher_texte(200,300,70,quit2,0,255,0);
SDL_Flip(fenetre);

if (SDL_WaitEvent(&event)) {
if(event.type == SDL_KEYDOWN) 
  {
    if (event.key.keysym.sym == SDLK_q)
     {
continuer=0;
     }
  }
}
}  
    cleanup();

}





void game()
{
    while(1)
    {
        srand(time(NULL));
        int g = (rand()%(5-0+1));
       
        switch(g)
        {
        case 0:
            cas1();
            break;
        case 1:
            cas2();
            break;
        case 2:
            cas3();
            break;
        case 3:
            cas4();
            break;
        case 4:
            cas5();
            break;
        case 5:
            cas6();
            break;
        }
    }
     
}
