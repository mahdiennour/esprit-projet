#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


#include "affichage.h"
#include "constantes.h"


/* quadrille le terrain : fermeture de toutes les portes */
int quadrille(SDL_Surface *ecran)
{
    int i, j;
    SDL_Surface **portes = NULL;
    SDL_Rect pos;
 
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    if (! (portes = malloc(sizeof(SDL_Surface *) * nombreLignes())))
    {
        fprintf(stderr, "Erreur lors de l'allocation mémoire pour le\
                tableau *portes : SDL_Surface *\n");
        return -1;
    }
 
    // crée les lignes en mémoire et les affiches
    pos.x = 0;
    for (i = 0; i < NOMBRE_PORTE_HAUTEUR; i++)
    {
        pos.y = (i + 1) * TAILLE_BLOC + i * TAILLE_PORTE;
        portes[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_FENETRE,
                                         TAILLE_PORTE, 32, 0, 0, 0, 0);
        SDL_FillRect(portes[i], NULL, SDL_MapRGB(ecran->format, 0, 255, 0));
        SDL_BlitSurface(portes[i], NULL, ecran, &pos);
    }
    pos.y = 0;
    for (i = 0; i < NOMBRE_PORTE_LARGEUR; i++)
    {
        pos.x = (i + 1) * TAILLE_BLOC + i * TAILLE_PORTE;
        portes[NOMBRE_PORTE_HAUTEUR + i] = SDL_CreateRGBSurface(SDL_HWSURFACE,
                                                            TAILLE_PORTE,
                                                            HAUTEUR_FENETRE,
                                                            32, 0, 0, 0, 0);
        SDL_FillRect(portes[NOMBRE_PORTE_HAUTEUR + i], NULL,
                     SDL_MapRGB(ecran->format, 0, 255, 0));
        SDL_BlitSurface(portes[NOMBRE_PORTE_HAUTEUR + i], NULL, ecran, &pos);
    }
    SDL_Flip(ecran); // on affiche le résultat à l'écran
 
    for (i = 0; i < nombreLignes(); i++) // on libère les surfaces lignes
            SDL_FreeSurface(portes[i]);
 
    free(portes);
 
    return 1;
}
 
/* renvoie le nombre de lignes du labyrinthe quadrillé */
int nombreLignes()
{
    return NOMBRE_PORTE_HAUTEUR + NOMBRE_PORTE_LARGEUR;
}
 
/* enleve le mur d'une cellule selon sa direction */
void ouvrePorte(SDL_Surface *ecran, int x, int y, int direction)
{
    SDL_Surface *blanc = NULL;
    int w, h;
    SDL_Rect pos;
 
    // définit les dimensions du blanc en fonction de la direction
    w = (direction == NORD || direction == SUD) ? TAILLE_BLOC : TAILLE_PORTE;
    h = (direction == NORD || direction == SUD) ? TAILLE_PORTE : TAILLE_BLOC;
 
    // position du blanc
    switch (direction)
    {
        case SUD:
            y++;
        case NORD:
            pos.x = (TAILLE_PORTE + TAILLE_BLOC) * x;
            pos.y = y * TAILLE_BLOC + TAILLE_PORTE * y - 1;
            break;
        case EST:
            x++;
        case OUEST:
            pos.x = x * TAILLE_BLOC + TAILLE_PORTE * x - 1;
            pos.y = y * (TAILLE_PORTE + TAILLE_BLOC);
            break;
    }
 
    pos.w = w; pos.h = h;
SDL_FillRect(ecran, &pos, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_Flip(ecran);
}
