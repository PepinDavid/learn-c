//ne pas oublie de rajouter dans le linker du projet le
//path d'acces aux libs

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
 
void pause();
void getErrorLoadImg(SDL_Surface *e);
int main(int argc, char **argv)
{
	SDL_Surface *win = NULL, *img = NULL, *oImg = NULL, *png = NULL;
    SDL_Rect pos, pos2, posPng;
    
    pos.x = 0;
    pos.y = 0;
    pos2.x = 600;
    pos2.y = 400;
    posPng.x = 100;
    posPng.y = 100;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    win = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    if(win == NULL){
        fprintf(stderr, "Erreur intialisation SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    SDL_WM_SetCaption("Load IMG in window", NULL);
    SDL_WM_SetIcon(SDL_LoadBMP("/home/david/Téléchargements/pack_images_sdz/sdl_icone.bmp"), NULL);
    //chargement d'une image
    img = SDL_LoadBMP("/home/david/Téléchargements/pack_images_sdz/lac_en_montagne.bmp");
    getErrorLoadImg(img);
    
    oImg = SDL_LoadBMP("/home/david/Téléchargements/pack_images_sdz/zozor.bmp");   
    getErrorLoadImg(oImg);
    
    //fonction dans sdl image
    png = IMG_Load("/home/david/Téléchargements/pack_images_sdz/sapin.png");
    getErrorLoadImg(png);
    
    //preparation de l'image pour indiqué quel couleur doit etre transparente
    SDL_SetColorKey(oImg, SDL_SRCCOLORKEY, SDL_MapRGB(oImg->format, 0, 0, 255));
    //ajoute de la transparence sur l'image en parametre (O = total transparence)
    SDL_SetAlpha(oImg, SDL_SRCALPHA, 128);
    
    //ajoute de la transparence sur l'image en parametre (O = total transparence)
    SDL_SetAlpha(png, SDL_SRCALPHA, 100);
    
    SDL_BlitSurface(img, NULL, win, &pos);
    SDL_BlitSurface(oImg, NULL, win, &pos2);
    SDL_BlitSurface(png, NULL, win, &posPng);
    SDL_Flip(win);
    
    pause();
    
    SDL_FreeSurface(img);
    SDL_FreeSurface(oImg);
    SDL_FreeSurface(png);
    SDL_Quit();
	return 0;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
    }
}

void getErrorLoadImg(SDL_Surface *e){
    if(e == NULL){
        fprintf(stderr, "Erreur intialisation SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}