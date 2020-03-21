#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
  
typedef uint8_t**     maze_t;
typedef uint8_t*      mrow_t;
#define    MAKE_POS(x, y)   ((y << 16) | (x))
#define    BLOC_W           10
#define    BLOC_H           10
enum
{
    MZF_NORD  = 0x01,
    MZF_EST   = 0x02,
    MZF_SUD   = 0x04,
    MZF_OUEST = 0x08,
    MZF_NSOE  = 0x0f,
    MZF_VISIT = 0x10
};
void pause();
static int opposite[] = {0, MZF_SUD, MZF_OUEST, 0, MZF_NORD, 0, 0, 0, MZF_EST};
maze_t  alloc_maze(int w, int h)
{
    maze_t  maze = (maze_t ) calloc((w * h) +(h * ( sizeof *maze)), 1);
    mrow_t  mem  = (mrow_t) (maze + h);
    int    i;
    memset(mem, MZF_NSOE, w * h);
    for (i = 0; i < h; maze[i] = mem, mem += w, i ++);
    return maze;
}
void SDL_DrawLine(SDL_Surface * ecran, uint32_t color, int x, int y, int x2, int y2)
{
    SDL_Rect r = {x, y, x2 - x + 1, y2 - y + 1};
    SDL_FillRect(ecran, &r, color);
}
Uint32 SDL_PushTicks(Uint32 interval, void * unused)
{
    SDL_Event tick;
    memset(&tick, 0, sizeof tick);
    tick.type = SDL_USEREVENT;
    SDL_PushEvent(&tick);
    return interval;
}
int main(int argc,char *argv[])
{
    // Initialisation des nombres aléatoires
   // srand(time(NULL));
    //Définition des variables
    int w;                    // largeur du labyrinthe (verticale)
    int h;                    // Longeur du labyrinthe (horizontale)
    int t,i,j;                // Compteurs
    int xs, ys;               // Position de départ
    int xe, ye;               // Position de fin
    w = argc > 1 ? atoi(argv[1]) : 30;
    h = argc > 2 ? atoi(argv[2]) : 30;
    fprintf(stderr, "Generating maze %dx%d...\n", w, h);
    // Sélection d'un point d'entrée et de sortie
    switch (rand() % 2) {
    case 0: ys = 0; xs = rand() % w; ye = h - 1; xe = rand() % w; i = MZF_NORD;  break;
    case 1: xs = 0; ys = rand() % h; xe = w - 1; ye = rand() % h; i = MZF_OUEST; break;
    }
    //Création du labyrinthe : matrice de cases
    maze_t laby  = alloc_maze(w, h);
    int*  stack = (int*) calloc(sizeof *stack, w * h);
    laby[ys][xs] &= ~i;
    laby[ye][xe] &= ~opposite[i];
    stack[0] = MAKE_POS(xs, ys);
    //Génération des portes via algo de backtracking récursif.
    for (i = 0, j = 1; j > 0; i ++)
    {
        int x = stack[j - 1] & 0xffff;
        int y = stack[j - 1] >> 16;
        int f = 0;
        laby[y][x] |= MZF_VISIT;
        //On visite toutes les cellules avoisinantes de manière alélatoire
        while (f != MZF_NSOE)
        {
            int dir = 1 << (rand() % 4); //Choisi une direction parmi les 4 possibles
            int nx, ny;
            //Ajuste si on est déjà passé par là
            if (f & dir)
            {
                if ((f & (dir-1)) < dir-1) while (f & dir) dir >>= 1;
                else                       while (f & dir) dir <<= 1;
            }
            switch (dir) {
            case MZF_NORD:  nx = x; ny = y - 1; break;
            case MZF_EST:   ny = y; nx = x + 1; break;
            case MZF_SUD:   nx = x; ny = y + 1; break;
            case MZF_OUEST: ny = y; nx = x - 1; break;
            }
            //Dèjà visité ou visitable ?
            if (0 <= nx && nx < w && 0 <= ny && ny < h && ! (laby[ny][nx] & MZF_VISIT))
            {
                //Visite cette cellule, en créant un chemin de (x, y) à (nx, ny)
                laby[y][x] &= ~dir;
                laby[ny][nx] &= ~opposite[dir];
                stack[j++] = MAKE_POS(nx, ny);
                break;
            }
            else f |= dir;
        }
        //On a visité toutes les cellules avoisinante: backtrack
        if (f == MZF_NSOE) j --;
    }
    //===================Dessin=======================
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    SDL_Surface * ecran = SDL_SetVideoMode(BLOC_W * w + 20, BLOC_H * h + 20, 32, SDL_HWSURFACE);
    SDL_TimerID   timer;
    SDL_WM_SetCaption("Générateur de Labyrinthe", NULL);
    //++++++++++++++Coloriage du fond++++++++++++++++++++
    uint32_t back = SDL_MapRGB(ecran->format, 0, 0, 0);
    uint32_t vert = SDL_MapRGB(ecran->format, 0, 255, 0);
    uint32_t dead = SDL_MapRGB(ecran->format, 0, 128, 0);
    SDL_FillRect(ecran, NULL, back);
    //==================Affichage du labyrinthe=================
    for (j = 0; j < h; j++)
    {
  
        for (i = 0; i < w; i++)
        {
            int f  = laby[j][i];
            int x  = 10 + i * BLOC_W;
            int y  = 10 + j * BLOC_H;
            int x2 = x + BLOC_W - 1;
            int y2 = y + BLOC_H - 1;
            if (j > 0) f &= ~MZF_NORD;
            if (i > 0) f &= ~MZF_OUEST;
            laby[j][i] &= ~MZF_VISIT;
            // Placement de points aux angles des murs pour avoir un dessin continu
            if (f & MZF_NORD)  SDL_DrawLine(ecran, vert, x,  y,  x2, y);
            if (f & MZF_EST)   SDL_DrawLine(ecran, vert, x2, y,  x2, y2);
            if (f & MZF_SUD)   SDL_DrawLine(ecran, vert, x,  y2, x2, y2);
            if (f & MZF_OUEST) SDL_DrawLine(ecran, vert, x,  y,  x,  y2);
        }
    }
    SDL_UpdateRect(ecran, 0, 0, 0, 0);
    timer = SDL_AddTimer(100, SDL_PushTicks, NULL);
    //=====================Fin du dessin==============================
    //===================Parcours=====================================
    stack[0] = MAKE_POS(xs, ys);
    j = 1;
    while (! (xs == xe && ys == ye) && j > 0)
    {
        SDL_Event event;
        SDL_WaitEvent(&event);
        switch (event.type) {
        case SDL_KEYDOWN:
            if (event.key.state != SDL_PRESSED || event.key.keysym.sym != SDLK_ESCAPE)
                continue;
        case SDL_QUIT:
            j = -1; continue;
        case SDL_USEREVENT:
            break;
        default:
            continue;
        }
        int x = stack[j - 1] & 0xffff;
        int y = stack[j - 1] >> 16;
        int f = laby[y][x] & ~MZF_VISIT;
        SDL_Rect path = {10 + x * BLOC_W, 10 + y * BLOC_H, BLOC_W, BLOC_H};
        if (f & MZF_NORD)  path.y += 2, path.h -= 2;
        if (f & MZF_OUEST) path.x += 2, path.w -= 2;
        if (f & MZF_SUD)   path.h -= 2;
        if (f & MZF_EST)   path.w -= 2;
        SDL_FillRect(ecran, &path, vert);
        SDL_UpdateRect(ecran, 0, 0, 0, 0);
        laby[y][x] |= MZF_VISIT;
        xs = x; ys = y;
        //Avance dans le labyrinthe
        while (f != MZF_NSOE)
        {
            int dir = 1 << (rand() % 4); //Choisi une direction parmi les 4 possibles
            int nx, ny;
            //Ajuste si on est déjà passé par là
            if (f & dir)
            {
                if ((f & (dir-1)) < dir-1) while (f & dir) dir >>= 1;
                else                       while (f & dir) dir <<= 1;
            }
            switch (dir) {
            case MZF_NORD:  nx = x; ny = y - 1; break;
            case MZF_EST:   ny = y; nx = x + 1; break;
            case MZF_SUD:   nx = x; ny = y + 1; break;
            case MZF_OUEST: ny = y; nx = x - 1; break;
            }
            //Dèjà visité ou visitable ?
            if (0 <= nx && nx < w && 0 <= ny && ny < h && ! (laby[ny][nx] & MZF_VISIT))
            {
                stack[j++] = MAKE_POS(nx, ny);
                break;
            }
            else f |= dir; t ++;
        }
        if (f == MZF_NSOE)
        {
            SDL_FillRect(ecran, &path, dead);
            j --;
        }
    }
    SDL_RemoveTimer(timer);
    //====================Fin du programme============================
    if (j == 0)
    {
        fprintf(stderr, "Parcours terminé...\n" );
        pause();
    }
    SDL_FreeSurface(ecran);
    SDL_Quit();
    return 0;
}
void pause()
{
    int continuer = 1;
    SDL_Event event;
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type) {
        case SDL_KEYDOWN:
        case SDL_QUIT: continuer = 0;
        }
    }
}
