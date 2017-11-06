#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct SDLImage SDLImage;

struct SDLImage{
	SDL_Surface *img;
	SDL_Rect posImg;
};

void getErrorLoadSurface(SDL_Surface *e);
void getErrorLoadImg(SDL_Surface *e);

void checkEvent(SDL_Surface *win, SDLImage *pic, SDL_Event *event);
void redrawScreen(SDL_Surface *win, SDL_Surface *img, SDL_Rect *posImg);
void moveKeys(SDL_Event *event, SDL_Rect *posImg);
void moveMouseButton(SDL_Event *event, SDL_Rect *posImg, int *activeMouseMotion);

int main(int argc, char **argv)
{
	SDL_Surface *window = NULL;
	SDLImage picture;
    SDL_Event event;
    
	picture.img = NULL;
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Provide events with SDL", NULL);
    SDL_WM_SetIcon(SDL_LoadBMP("/home/david/Téléchargements/pack_images_sdz/sdl_icone.bmp"), NULL);
    
    window = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    getErrorLoadSurface(window);
    
    picture.img = IMG_Load("/home/david/Téléchargements/pack_images_sdz/zozor.bmp");
    getErrorLoadImg(picture.img);
    SDL_SetColorKey(picture.img, SDL_SRCCOLORKEY, SDL_MapRGB(picture.img->format, 0, 0, 255));
    picture.posImg.y = window->h / 2 - picture.img->h / 2;
    picture.posImg.x = window->w / 2 - picture.img->w / 2;
    
    
    checkEvent(window, &picture, &event);
    
    SDL_FreeSurface(picture.img);
    SDL_Quit();
    
	return 0;
}

void redrawScreen(SDL_Surface *win, SDL_Surface *img, SDL_Rect *posImg){
    
    SDL_FillRect(win, NULL, SDL_MapRGB(win->format, 255, 255, 255));
    SDL_BlitSurface(img, NULL, win, posImg);
    SDL_Flip(win); 
}

void checkEvent(SDL_Surface *win, SDLImage *pic, SDL_Event *event){
    int loopScene = 1;
	int activeMouseMotion = 1;
    SDL_EnableKeyRepeat(10, 10); 
    
    while (loopScene)
    {
        redrawScreen(win, pic->img, &(pic->posImg));
        
        SDL_WaitEvent(event);
        
        switch(event->type)
        {
            case SDL_QUIT:
                loopScene = 0;
                break;
            case SDL_KEYDOWN:
                moveKeys(event, &(pic->posImg));
                break;
			case SDL_MOUSEBUTTONUP:
				moveMouseButton(event, &(pic->posImg), &activeMouseMotion);
				break;
			case SDL_MOUSEMOTION:
				printf("move mouse\n %d\n", activeMouseMotion);
				if(activeMouseMotion == 1){
					pic->posImg.x = event->button.x - pic->posImg.w / 2;
					pic->posImg.y = event->button.y - pic->posImg.h / 2;
				}
				break;
        }
    }
}

void moveMouseButton(SDL_Event *event, SDL_Rect *posImg, int *activeMouseMotion){
	switch(event->button.button){
		case SDL_BUTTON_LEFT:
			*activeMouseMotion = 1;
			SDL_ShowCursor(SDL_DISABLE);
			posImg->x = event->button.x - posImg->w / 2;
			posImg->y = event->button.y - posImg->h / 2;
			printf("click button mouse left\n %d\n", *activeMouseMotion);
			break;
		case SDL_BUTTON_RIGHT:
			*activeMouseMotion = 0;
			SDL_ShowCursor(SDL_ENABLE);
			printf("click button mouse right\n %d\n", *activeMouseMotion);
			break;
	}
}

void moveKeys(SDL_Event *event, SDL_Rect *posImg){
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
		case SDLK_r:
			SDL_WarpMouse(posImg->x, posImg->y);
			break;
		case SDLK_UNKNOWN:
			break;
		default:
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