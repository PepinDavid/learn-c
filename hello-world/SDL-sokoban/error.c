#include "error.h"

void getErrorLoadSurface(SDL_Surface *e){
    if(e == NULL){
        fprintf(stderr, "Erreur intialisation SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

void getErrorLoadImg(SDL_Surface *e){
    if(e == NULL){
        fprintf(stderr, "Erreur intialisation SDL : %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
}