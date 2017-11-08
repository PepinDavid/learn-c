#ifndef DEF_SDLIMAGE
#define DEF_SDLIMAGE

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
typedef struct SDLImage SDLImage;
typedef struct Player Player;

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
void loadImage(SDLImage *img, char *constStr, char *str);

#endif