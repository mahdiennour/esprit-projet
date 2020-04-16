typedef struct 
{
int etat;
SDL_Surface *image;
SDL_Rect position;
Mix_chunk son;
} enemie; 
void Init_enemie(enemie* vilan);
void deplacerEnemie(enemie *vilan);
void AnimerPerso(enemie *vilan);
//void AfficherPerso(enemie vilan);
int Collision_enemie(enemie vilan, caractere hero);
//int Update_Etat(enemie vilan, caractere hero);
