#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "sdlimage.h"

#ifndef DEF_EVENT
#define DEF_EVENT

void pause();
void MenuLoop(SDL_Surface *win, SDL_Event *e, SDLImage *menu);
void play(SDL_Surface *win, SDL_Event *e);
void movePlayer(Player *perso, Map *map, int *deplacement);
#endif