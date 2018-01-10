#include "sdlttf.h"
#include "contantes.h"

void initTTF(){  
    if(TTF_Init() == -1){
        fprintf(stderr, "Erreur initTTF %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
}

void closeTTF(){
    TTF_Quit();
}

SDL_Surface* textTTF(char* txt){
    SDL_Surface *textIMG = NULL;
    SDL_Color fontColor = { 255, 255, 255};
    TTF_Font *police = NULL;
    police = TTF_OpenFont(PATH_POLICE, 65);
    textIMG = TTF_RenderText_Blended(police, txt, fontColor);
    printf("in func %p\n", textIMG);
    return textIMG;
}