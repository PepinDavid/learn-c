#ifndef DEF_EVENT
#define DEF_EVENT

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "sdlimage.h"


void pause();
void MenuLoop(SDL_Surface *win, SDL_Event *e, SDLImage *menu);
void play(SDL_Surface *win, SDL_Event *e);
#endif