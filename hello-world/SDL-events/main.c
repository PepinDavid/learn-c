#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
 
void getErrorLoadSurface(SDL_Surface *e);
void getErrorLoadImg(SDL_Surface *e);

void checkEvent(SDL_Surface *win, SDL_Surface *img, SDL_Rect *posImg, SDL_Event *event);
void redrawScreen(SDL_Surface *win, SDL_Surface *img, SDL_Rect *posImg);
void move(SDL_Event *event, SDL_Rect *posImg);

int main(int argc, char **argv)
{
	SDL_Surface *window = NULL, *img = NULL;
    SDL_Rect posImg;
    SDL_Event event;
    
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Provide events with SDL", NULL);
    SDL_WM_SetIcon(SDL_LoadBMP("/home/david/Téléchargements/pack_images_sdz/sdl_icone.bmp"), NULL);
    
    window = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    getErrorLoadSurface(window);
    
    img = IMG_Load("/home/david/Téléchargements/pack_images_sdz/zozor.bmp");
    getErrorLoadImg(img);
    SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 0, 255));
    posImg.y = window->h / 2 - img->h / 2;
    posImg.x = window->w / 2 - img->w / 2;
    
    
    checkEvent(window, img, &posImg, &event);
    
    SDL_FreeSurface(img);
    SDL_Quit();
    
	return 0;
}

void redrawScreen(SDL_Surface *win, SDL_Surface *img, SDL_Rect *posImg){
    
    SDL_FillRect(win, NULL, SDL_MapRGB(win->format, 255, 255, 255));
    SDL_BlitSurface(img, NULL, win, posImg);
    SDL_Flip(win); 
}

void checkEvent(SDL_Surface *win, SDL_Surface *img, SDL_Rect *posImg, SDL_Event *event)
{
    int loopScene = 1;
    SDL_EnableKeyRepeat(10, 10); 
    
    while (loopScene)
    {
        redrawScreen(win, img, posImg);        
        
        SDL_WaitEvent(event);
        
        switch(event->type)
        {
            case SDL_QUIT:
                loopScene = 0;
                break;
            case SDL_KEYDOWN:
                move(event, posImg);
                break;
        }
    }
}


void move(SDL_Event *event, SDL_Rect *posImg){
    switch(event->key.keysym.sym)
    {
        case SDLK_UP:
            posImg->y -= 5;
            printf("up\n");
            break;
        case SDLK_DOWN:
            posImg->y += 5;
            printf("down\n");
            break;
        case SDLK_RIGHT:
            posImg->x += 5;
            printf("right\n");
            break;
        case SDLK_LEFT:
            posImg->x -= 5;
            printf("left\n");
            break;
    }
}

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