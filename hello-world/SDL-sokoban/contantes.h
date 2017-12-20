/*
constantes.h
------------

Rôle : défine constantes for all program
*/

#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

#define SIZE_BLOCK         34 // in pixels
#define NB_BLOCKS_WIDTH    12
#define NB_BLOCKS_HEIGHT   12
#define WIDTH_WINDOW     SIZE_BLOCK * NB_BLOCKS_WIDTH
#define HEIGHT_WINDOW    SIZE_BLOCK * NB_BLOCKS_HEIGHT
#define PATH_IMAGE "/home/david/perso/dev/learn-c/hello-world/SDL-sokoban/images/"
#define PATH_MAP "/home/david/perso/dev/learn-c/hello-world/SDL-sokoban/maps/"

enum {UP, DOWN, LEFT, RIGHT};
enum {EMPTY, WALL, CASE, GOAL, MARIO, CASE_OK};

#endif