#ifndef DEF_SDLIMAGE
#define DEF_SDLIMAGE

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "contantes.h"
typedef struct SDLImage SDLImage;
typedef struct Player Player;
typedef struct SDLIMG SDLIMG;
typedef struct Map Map;

struct SDLIMG{
	SDL_Surface *picture;
	char *path;
};

struct Map{
	int map[NB_BLOCKS_WIDTH][NB_BLOCKS_HEIGHT];
	char *pathFile;
};

struct SDLImage{
	SDL_Surface *picture;
	SDL_Rect position;
	char *path;
};

struct Player{
	SDL_Surface *sprites[4];
	SDL_Surface *picture;
	SDL_Rect position;
	char *path;
};


void initSDLImage(SDLImage *img);
void initSDLPlayer(Player *player);
void initSDLIMG(SDLIMG *img);
void loadMap(Map *m, char *constStr, char *str);
void loadIMG(SDLIMG *img, char *constStr, char *str);
void loadImage(SDLImage *img, char *constStr, char *str);
void loadSprite(Player *p, char *constStr, char *str, int direction );

#endif