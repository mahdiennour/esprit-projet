typedef struct
{
int direction;
char score[5];
int vie;
SDL_Rect positionperso;
SDL_Surface *walk[8];
} caractere;
void Init_perso(caractere* hero);
void GestionVie(SDL_Surface *screen, caractere hero)
void deplacerPerso(caractere hero,screen *e);
void AnimerPerso(caractere *hero);
void AfficherPerso(caractere hero);
int Collision_perfect_pixel(SDL_Surface *screen, caractere *hero);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
