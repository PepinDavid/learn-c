#include "event.h"
#include "contantes.h"

void pause(){
    int continuer = 1;
    SDL_Event event;
 
    while (continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                continuer = 0;
            break;
        }
    }
}

void MenuLoop(SDL_Surface *win, SDL_Event *e, SDLImage *menu){
    int loop = 1;
    
    printf("menuloop\n");
    while(loop){
        SDL_WaitEvent(e);
        switch(e->type){
            case SDL_QUIT:
                loop = 0;
                break;
            case SDL_KEYDOWN:
                printf("keydown\n");
                switch(e->key.keysym.sym){
                    case SDLK_1:
                        play(win, e);
                        break;
                    case SDLK_p:
                        play(win, e);
                        break;
                    case SDLK_2:
                        //editeur map
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
        SDL_FillRect(win, NULL, SDL_MapRGB(win->format, 0, 0, 0));
        SDL_BlitSurface(menu->picture, NULL, win, &(menu->position));
        SDL_Flip(win);
    }
}

void play(SDL_Surface *win, SDL_Event *e){
    int loop = 1, i = 0, deplacement = 0;
    Map map;
    SDLIMG wall, caisse, caisseOK, goal; 
    Player perso;
    //initialisation des images
    initSDLPlayer(&perso);
    
    initSDLIMG(&wall);
    initSDLIMG(&caisse);
    initSDLIMG(&caisseOK);
    initSDLIMG(&goal);
    
    //load pictures
    loadIMG(&wall, PATH_IMAGE, "mur.jpg");
    getErrorLoadImg(&wall);
    loadIMG(&caisse, PATH_IMAGE, "caisse.jpg");
    getErrorLoadImg(&caisse);
    loadIMG(&caisseOK, PATH_IMAGE, "caisse_ok.jpg");
    getErrorLoadImg(&caisseOK);
    loadIMG(&goal, PATH_IMAGE, "objectif.png");
    getErrorLoadImg(&goal);
    
    loadSprite(&perso, PATH_IMAGE, "mario_haut.gif", UP);
    getErrorLoadImg(&perso.sprites[UP]);
    loadSprite(&perso, PATH_IMAGE, "mario_bas.gif", DOWN);
    getErrorLoadImg(&perso.sprites[DOWN]);
    loadSprite(&perso, PATH_IMAGE, "mario_gauche.gif", LEFT);
    getErrorLoadImg(&perso.sprites[LEFT]);
    loadSprite(&perso, PATH_IMAGE, "mario_droite.gif", RIGHT);
    getErrorLoadImg(&perso.sprites[RIGHT]);
    
    //load map for store each case
    loadMap(&map, PATH_MAP, "map1.txt");
    
    SDL_EnableKeyRepeat(100, 100);
    while(loop){
        SDL_WaitEvent(e);
        switch(e->type){
            case SDL_QUIT:
                loop = 0;
                break;
            case SDL_KEYDOWN:
                switch(e->key.keysym.sym){
                    case SDLK_UP:
						deplacement = UP;
						if(perso.position.y - 1 > 0)
							perso.position.y -= SIZE_BLOCK;
                        break;
                    case SDLK_DOWN:
						deplacement = DOWN;
						if(perso.position.y + 1 < HEIGHT_WINDOW)
							perso.position.y += SIZE_BLOCK;
                        break;
                    case SDLK_LEFT:
						deplacement = LEFT;
						if(perso.position.x - 1 > 0)
							perso.position.x -= SIZE_BLOCK;
                        break;
                    case SDLK_RIGHT:
						deplacement = RIGHT;
						if(perso.position.x + 1  < WIDTH_WINDOW)
							perso.position.x += SIZE_BLOCK;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }        
        
        perso.picture = perso.sprites[deplacement];
        //refresh window
        SDL_FillRect(win, NULL, SDL_MapRGB(win->format, 0, 0, 0));
        SDL_BlitSurface(perso.picture, NULL, win, &(perso.position));
        SDL_Flip(win);
    }
    SDL_EnableKeyRepeat(0, 0);
    for(i = 0; i < 4; i++)
        SDL_FreeSurface(perso.sprites[i]);
}


