#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <perso.h>
SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;

	
	char* pPosition = ( char* ) surface->pixels ;

	
	pPosition += ( surface->pitch * y ) ;

	
	pPosition += ( surface->format->BytesPerPixel * x ) ;

	
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;

	
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}
int Collision_perfect_pixel(SDL_Surface *screen, caractere *hero)
{
int X,Y,W,H,i;
int collision=0;
SDL_Rect positionmasque;
SDL_Surface *image;
positionmasque.x=0;
positionmasque.y=0;
SDL_Color couleurNoire ={0,0,0};
SDL_Color col;
image = IMG_Load("backgrounds.jpg");
hero=IMG_Load("detective.png");
X=850;
Y=150;
W = 72;
H= 144;
SDL_SetColorKey(hero,SDL_SRCCOLORKEY,SDL_MapRGB(hero->format,255,255,255));
hero.positionperso[0].x=X;
hero.positionperso[0].y=Y;
hero.positionperso[1].x=X+(W/2);
hero.positionperso[1].y=Y;
hero.positionperso[2].x=X+W;
hero.positionperso[2].y=Y;
hero.positionperso[3].x=X;
hero.positionperso[3].y=Y+(H/2);
hero.positionperso[4].x=X;
hero.positionperso[4].y=Y+H;
hero.positionperso[5].x=X+(W/2);
hero.positionperso[5].y=Y+H;
hero.positionperso[6].x=X+W;
hero.positionperso[6].y=Y+H;
hero.positionperso[7].x=X+W;
hero.positionperso[7].y=Y+(H/2);
SDL_BlitSurface(image,NULL,screen, &positionmasque);
SDL_BlitSurface(hero,NULL,screen, &hero.positionperso[1]);
SDL_Flip(screen);
while((i<8)&&(collision==0))
{
col=GetPixel(screen,hero.positionperso[i].x,hero.positionperso[i].y);
if ((col.r==0)&&(col.b==0)&&(col.g==0))
{
collision=1;
}
else
{
i++;
}
}
return (collision);
}
