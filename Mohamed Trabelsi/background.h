typedef struct 
{
SDL_Surface *image;
Mix_Music *music;
Mix_chunk *son;
SDL_Rect positionback;
TTF_Font *texte;
} background;
background Init_back(background back);
void Affiche_back(background back,screen *ecran);
void Scrolling(background back,SDL_Surface *screen);

