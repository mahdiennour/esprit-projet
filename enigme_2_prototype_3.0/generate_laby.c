#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algorithme.h"
#include "constantes.h"
#include "affichage.h"
 
/* crée le labyrinthe, renvoie un pointeur sur le labyrinthe créé,
   NULL si erreur */
p_labyrinthe creeLabyrinthe(SDL_Surface *ecran)
{
    p_labyrinthe lab = NULL;
 
    srand(time(NULL));
 
    lab = (p_labyrinthe) malloc(sizeof(_labyrinthe)); // allocation mémoire du labyrinthe
    if (!lab)
        return NULL;
 
    lab->largeur = LARGEUR;
    lab->hauteur = HAUTEUR;
 
    // allocation mémoire tableau
    if (!(lab->tableau = malloc(lab->largeur * lab->hauteur)))
        return NULL;
    // remplissage du tableau à la valeur 0
    memset(lab->tableau, 0, lab->largeur * lab->hauteur);
 
    lab->entree = donneCelluleBordAleatoire(lab);
    while ((lab->sortie = donneCelluleBordAleatoire(lab)) == lab->entree);
 
    celluleSuivante(lab, lab->entree, ecran); // génération du labyrinthe
 
    return lab;
}
 
/* détruit le labyrinthe */
void detruitLabyrinthe(p_labyrinthe lab)
{
    if (lab)
    {
        if (lab->tableau)
            free(lab->tableau);
        free(lab);
    }
}
 
/* retourne la cellule correspondante aux coordonnées (x ; y) */
char* donneCelluleXY(p_labyrinthe lab, int x, int y)
{
    // on vérifie si les coordonnées sont bien comprises dans le labyrinthe
    if (x < 0 || x >= lab->largeur)
        return NULL;
    if (y < 0 || y >= lab->hauteur)
        return NULL;
 
    return lab->tableau + (lab->largeur * y + x);
}
 
/* retourne une cellule aléatoire se trouvant sur les bords du labyrinthe */
char* donneCelluleBordAleatoire(p_labyrinthe lab)
{
    int i, j;
 
    i = donneAleatoire(4); // choisit la position cardinale de la cellule
    switch (i) // change positions en fonction de la position cardinale choisie
    {
            case NORD:
            j = 0;
            i = donneAleatoire(lab->largeur);
                    break;
        case SUD:
            j = lab->hauteur - 1;
            i = donneAleatoire(lab->largeur);
            break;
        case EST:
            j = donneAleatoire(lab->hauteur);
            i = 0;
            break;
            case OUEST:
            j = donneAleatoire(lab->hauteur);
            i = lab->largeur - 1;
                    break;
        default:
            break;
    }
    return donneCelluleXY(lab, i, j);
}
 
/* retourne la prochaine cellule selon la direction */
char* donneCelluleDirection(p_labyrinthe lab, char *cellule, int direction)
{
    int x, y;
 
    // prend les coordonnées x ; y de la prochaine cellule
    if (((x = celluleX(lab, cellule)) < 0) || (y = celluleY(lab, cellule)) < 0)
        return NULL;
 
    if (direction == NORD)
        y--;
    else if (direction == EST)
        x++;
    else if (direction == OUEST)
        x--;
    else if (direction == SUD)
        y++;
 
    return donneCelluleXY(lab, x, y);
}
 
/* renvoie la coordonnée x de la cellule reçue en paramètre */
int celluleX(p_labyrinthe lab, char *cellule)
{
    // on vérifie si la cellule est bien dans le labyrinthe
    if (cellule < lab->tableau)
        return -1;
    if (cellule >= lab->tableau + lab->hauteur * lab->largeur)
        return -1;
 
    return (cellule - lab->tableau) % lab->largeur;
}
 
/* renvoie la coordonnée y de la cellule reçue en paramètre */
int celluleY(p_labyrinthe lab, char *cellule)
{
    // on vérifie si la cellule est bien dans le labyrinthe
    if (cellule < lab->tableau)
        return -1;
    if (cellule >= lab->tableau + lab->hauteur * lab->largeur)
        return -1;
 
    return (cellule - lab->tableau) / lab->largeur;
}
 
/* boucle de génération du labyrinthe */
void celluleSuivante(p_labyrinthe lab, char *cellule, SDL_Surface *ecran)
{
    _annuaire annuaire[4];
    int i, h, n;
    char *celluleSuivante;
    char **historique;
 
    // on alloue la mémoire pour l'historique
    historique = (char **) malloc(lab->largeur * lab->hauteur * sizeof(char *));
    h = 0;
    historique[h++] = cellule;
 
    for (; ; )
    {
        for (; ; )
        {
            *cellule |= CELL_ETAT; // la cellule est visitée
            n = 0; // nombre de portes pouvant être ouvertes autour de la cellule
 
            // vérifie quelles portes peuvent être ouvertes
            for (i = NORD; i <= OUEST; i++)
            {
                if ((celluleSuivante = donneCelluleDirection(lab, cellule, i)))
                    // si la cellule suivante n'est pas déjà visitée
                    if (!(*celluleSuivante & CELL_ETAT))
                    {
                        // on enregistre la direction et la prochaine cellule
                        annuaire[n].direction = i;
                        annuaire[n++].cellule = celluleSuivante;
                    }
            }
 
            if (!n) // si aucune porte ne peut être ouverte
                break; // on quitte la boucle
 
            if (n == 1) // si seulement une porte peut être ouverte
                i = 0;
            else // sinon on choisit une direction sur une prochaine
                i = donneAleatoire(n); // cellule tirée aléatoirement
 
            celluleSuivante = annuaire[i].cellule;
            i = annuaire[i].direction;
 
            // on ouvre la porte (graphiquement)
            ouvrePorte(ecran, celluleX(lab, cellule), celluleY(lab, cellule),
                       i);
            SDL_Delay(1);
 
            // lie les deux cellules
            *cellule |= 1 << i;
            *celluleSuivante |= 1 << ((i + 2) % 4);
 
            historique[h++] = cellule = celluleSuivante;
        }
        if (h == 0) // si l'historique est vide
            break; // on quitte la boucle : fin de la génération
        cellule = historique[--h]; // on descend dans l'historique
    }
    free(historique);
}
 
/* retourne un nombre aléatoire compris entre 0 et n */
int donneAleatoire(int n)
{
    return rand() % n;
}
