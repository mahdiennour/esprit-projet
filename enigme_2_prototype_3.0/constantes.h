#ifndef CONSTANTES_H
#define CONSTANTES_H
 
/* dimensions du labyrinthe */
#define LARGEUR                 25
#define HAUTEUR                 25
#define NOMBRE_PORTE_HAUTEUR    HAUTEUR - 1
#define NOMBRE_PORTE_LARGEUR    LARGEUR - 1
 
/* directions */
enum {
    NORD, SUD, EST, OUEST
};
 
#endif
