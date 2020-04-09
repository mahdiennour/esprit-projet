#ifndef ALGORITHME_H
#define ALGORITHME_H
 
#include <SDL/SDL.h>
 
/* masque de bit */
#define CELL_ETAT   16
 
/* structure de données du labyrinthe */
typedef struct {
    int largeur, hauteur;
    char *entree, *sortie;
    char *tableau;
} _labyrinthe, *p_labyrinthe;
 
/* structure d'un annuaire pour y stocker cellule et direction */
typedef struct {
    int direction;
    char* cellule;
} _annuaire;
 
p_labyrinthe creeLabyrinthe(SDL_Surface *ecran);
void detruitLabyrinthe(p_labyrinthe lab);
char* donneCelluleXY(p_labyrinthe lab, int x, int y);
char* donneCelluleBordAleatoire(p_labyrinthe lab);
char* donneCelluleDirection(p_labyrinthe lab, char *cellule, int direction);
int celluleX(p_labyrinthe lab, char *cellule);
int celluleY(p_labyrinthe lab, char *cellule);
void celluleSuivante(p_labyrinthe lab, char *cellule, SDL_Surface *ecran);
int donneAleatoire(int n);
 
#endif
