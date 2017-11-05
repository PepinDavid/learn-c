#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
 
void pause();
void getErrorLoadSurface(SDL_Surface *e);

int main(int argc, char **argv)
{
	SDL_Surface *window = NULL;
    SDL_Event event;
    
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Provide events with SDL", NULL);
    SDL_WM_SetIcon(SDL_LoadBMP("/home/david/Téléchargements/pack_images_sdz/sdl_icone.bmp"), NULL);
    
    window = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    getErrorLoadSurface(window);
    
    pause(&event);
    
    SDL_Quit();
    
	return 0;
}

void pause(SDL_Event *event)
{
    int continuer = 1;
 
    while (continuer)
    {
        
        SDL_WaitEvent(event);
        
        switch(event->type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

void getErrorLoadSurface(SDL_Surface *e){
    if(e == NULL){
        fprintf(stderr, "Erreur intialisation SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}