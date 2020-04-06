#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ennemi.h"
#include "background.h"
int load_enemie(enemie* E)
{
	A->image = IMG_Load("../images/Ennemi.png");

	if(A->image == NULL) {
		printf("Unable to load Ennemi jpg:%s\n", SDL_GetError());
		return (-1);
	}

	SDL_SetColorKey( A->image, SDL_SRCCOLORKEY, SDL_MapRGB(A->image->format, 255, 255, 255) );

	return (0);
}


void Init_enemie(enemie* E)
{
	E->positionAbsolue.x = 1000;
	E->positionAbsolue.y = 250;
	E->positionAbsolue.w = Ennemi_WIDTH;
	E->positionAbsolue.h = Ennemi_HEIGHT;
	E->positionAnimation.x = 0;
	E->positionAnimation.y = 0;
	E->positionAnimation.w = Ennemi_WIDTH;
	E->positionAnimation.h = Ennemi_HEIGHT;
}
void blitEnnemi(Ennemi E, SDL_Surface* screen)
{
	SDL_BlitSurface(E.image, &E.positionAnimation, screen, &E.positionAbsolue);
}
void freeEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
}
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "fonctions.h"


SDL_Surface * initEcran(char * titre, char * icone, int largeur, int hauteur)
{
    SDL_Surface *ecran = NULL;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_Load(icone), NULL);
    ecran = SDL_SetVideoMode(largeur, hauteur, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption(titre, NULL);

    return ecran;
}

int attendreAvantDeQuitter(Uint8 typeEvenement)
{
    int continuer = 1 ;
    switch(typeEvenement)
    {
        case SDL_QUIT:
            continuer = 0;break;
        default : break;
    }
    return continuer;
}

void backgroundColorSurface(SDL_Surface * surface, Uint8 rouge, Uint8 vert, Uint8 bleu)
{
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, rouge, vert, bleu));
}

void afficheMessage(SDL_Surface * surfaceBlit, char * texte, int tailleText, char * fontFile, SDL_Color textColor, SDL_Rect position)
{
    SDL_Surface *message = NULL;
    TTF_Font *police=NULL;

    TTF_Init();
    police = TTF_OpenFont(fontFile, tailleText);
    message = TTF_RenderText_Solid(police, texte, textColor);
    SDL_BlitSurface(message, NULL, surfaceBlit, &position);

    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(message);
}

int verifEtatToucheClavier()
{
    Uint8 *keystates = SDL_GetKeyState(NULL);

    if( keystates[SDLK_UP] )
        return SDLK_UP;

    if( keystates[ SDLK_DOWN ] )
        return SDLK_DOWN;

    if( keystates[ SDLK_LEFT ] )
         return SDLK_LEFT;

    if( keystates[ SDLK_RIGHT ] )
        return SDLK_RIGHT;

    return RIEN;
}

void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect *position)
{
    SDL_Surface* loadedImage = NULL;
    loadedImage = IMG_Load(fileImage);
    position->h = loadedImage->h;
    position->w = loadedImage->w;
    SDL_BlitSurface(loadedImage, NULL, surfaceBlit, position);
    SDL_FreeSurface(loadedImage);
}

SDL_Rect * decoupeSprite(char * fileSprite, int nbCaseCol, int nbCaseLigne )
{
    SDL_Surface * feuilleDeSprite = NULL;
    SDL_Rect * tabSprite;
    SDL_Rect coupe;
    int i,j;
    int nbCase=0;

    tabSprite = malloc((nbCaseCol*nbCaseLigne)*sizeof(SDL_Rect));
    feuilleDeSprite = IMG_Load(fileSprite);
    coupe.h = feuilleDeSprite->h/nbCaseCol;
    coupe.w =feuilleDeSprite->w/nbCaseLigne;

    for(i=0; i < nbCaseLigne; i++)
    {
        coupe.y = coupe.h*i;
        for(j=0;j<nbCaseCol; j++)
        {
            coupe.x = coupe.w*j;
            tabSprite[nbCase] = coupe;
            nbCase++;
        }
    }
    SDL_FreeSurface(feuilleDeSprite);
    return tabSprite;
}

void blitSpriteSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect position, SDL_Rect * clip)
{
    SDL_Surface* loadedImage = NULL;
    loadedImage = IMG_Load(fileImage);
    SDL_BlitSurface(loadedImage, clip, surfaceBlit, &position);
    SDL_FreeSurface(loadedImage);
}

Mix_Music* jouerSon(char *fichierSon)
{
    Mix_Music *music = NULL;
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096);

    music = Mix_LoadMUS(fichierSon);
    Mix_PlayMusic( music, -1 );

    return music;
}

void attendreTemps(int millisecondes)
{
    int startTicks = SDL_GetTicks();

    while((SDL_GetTicks() - startTicks) < millisecondes)
    {
        SDL_Delay(1);
    }
}

void deplacement(SDL_Rect * pos, SDL_Event event, int vitesse_x, int vitesse_y)
{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP: pos->y -= vitesse_y / 2; break;
            case SDLK_DOWN: pos->y += vitesse_y / 2; break;
            case SDLK_LEFT: pos->x -= vitesse_x / 2; break;
            case SDLK_RIGHT: pos->x += vitesse_x / 2; break;
            default: break;
        }
    }
}

int testCollision(SDL_Rect obj1, SDL_Rect obj2, int * typeCollision)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = obj1.x;
    rightA = obj1.x + obj1.w;
    topA = obj1.y;
    bottomA = obj1.y + obj1.h;

    leftB = obj2.x;
    rightB = obj2.x + obj2.w;
    topB = obj2.y;
    bottomB = obj2.y + obj2.h;

    if( bottomA <= topB )
    {
        *typeCollision = BOTTOM;return 1;
    }


    if( topA >= bottomB )
    {
        *typeCollision = TOP;return 1;
    }

    if( rightA <= leftB )
    {
        *typeCollision = RIGHT;return 1;
    }

    if( leftA >= rightB )
    {
        *typeCollision = LEFT;return 1;
    }
    return 0;
}

void deplacementAutorise(int typeCol, SDL_Rect * pos1, SDL_Event event, int vit_x, int vit_y)
{
    switch(typeCol)
    {
        case BOTTOM :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_UP : case SDLK_RIGHT : case SDLK_LEFT : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        case TOP :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_DOWN : case SDLK_RIGHT : case SDLK_LEFT : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        case RIGHT :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_UP : case SDLK_DOWN : case SDLK_LEFT : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        case LEFT :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_UP : case SDLK_RIGHT : case SDLK_DOWN : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        default : break;
    }
}

