#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED


typedef struct enigme
{
SDL_Surface *texte;
SDL_Surface *answer[4];
SDL_Rect postxt;
SDL_Rect posans1;
SDL_Rect posans2;
}enigme;

typedef struct enigmes
{
int nbenigmes;
enigme E[30];
}enigmes;

typedef struct chrono
{
SDL_Surface *texte;
SDL_Rect poschrono;
}chrono;


void initialiser_enigmes(enigmes *ES);
int  afficher_enigmes(enigmes *ES,SDL_Surface *fenetre);
int ResolutionEniges(enigmes ES,int IndiceEnigme,char an[]);
void enigmi ();
int main(int argc, char** argv);
#endif // ENIGME_H_INCLUDED
