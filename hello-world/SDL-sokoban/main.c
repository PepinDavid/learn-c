//ne pas oublie de rajouter dans le linker du projet le
//path d'acces aux libs

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "error.h"
#include "contantes.h"
#include "event.h"
#include "sdlimage.h"
#include "sdlttf.h"

const char *caisse = "caisse.jpg";

int main(int argc, char **argv)
{
	
	SDL_Surface *window = NULL;
	SDLImage menu;
    SDL_Event event;
	initSDLImage(&menu);
	
    //SDL_Event event;
	char *pathAndFile = NULL;
	
	pathAndFile = malloc(sizeof(char) * strlen(PATH_IMAGE) + (sizeof(char) * strlen(caisse)) + sizeof(char)); // make space for new string
	strcpy(pathAndFile, PATH_IMAGE); //copy the path
	strcat(pathAndFile, caisse); //add the name file
	
	window = SDL_SetVideoMode(WIDTH_WINDOW, HEIGHT_WINDOW, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
	getErrorLoadSurface(window);
	
	loadImage(&menu, PATH_IMAGE, "menu.jpg");
	getErrorLoadSurface(menu.picture);
	
    SDL_Init(SDL_INIT_VIDEO);
	
	SDL_WM_SetIcon(IMG_Load(pathAndFile), NULL);
	
	MenuLoop(window, &event, &menu);
	
	free(pathAndFile);
	SDL_FreeSurface(menu.picture);
	SDL_FreeSurface(window);
    SDL_Quit();
	
	return 0;
}
