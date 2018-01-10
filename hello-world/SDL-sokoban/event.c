#include "event.h"
#include "contantes.h"
#include "sdlttf.h"

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
                switch(e->key.keysym.sym){
                    case SDLK_KP1:
                    case SDLK_p:
                        play(win, e);
                        break;
                    case SDLK_KP2:
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

    int loop = 1, i = 0, j = 0, deplacement = 0, winner = 0;
    Map carte;
    SDLIMG wall, caisse, caisseOK, goal; 
	SDL_Rect position;
    SDL_Surface *text = NULL;
    Player perso;
    //initialisation player
    initSDLPlayer(&perso);
    
    initSDLIMG(&wall);
    initSDLIMG(&caisse);
    initSDLIMG(&caisseOK);
    initSDLIMG(&goal);
    
    //load pictures
    loadIMG(&wall, PATH_IMAGE, "mur.jpg");
    loadIMG(&caisse, PATH_IMAGE, "caisse.jpg");
    loadIMG(&caisseOK, PATH_IMAGE, "caisse_ok.jpg");
    loadIMG(&goal, PATH_IMAGE, "objectif.png");
    
    //load sprite player
    loadSprite(&perso, PATH_IMAGE, "mario_haut.gif", UP);
    loadSprite(&perso, PATH_IMAGE, "mario_bas.gif", DOWN);
    loadSprite(&perso, PATH_IMAGE, "mario_gauche.gif", LEFT);
    loadSprite(&perso, PATH_IMAGE, "mario_droite.gif", RIGHT);
    
    //load map for store each case
    loadMap(&carte, PATH_MAP, "map1.txt");
	//get position player on map
	for (i = 0 ; i < NB_BLOCKS_WIDTH ; i++)
	{
		for (j = 0 ; j < NB_BLOCKS_HEIGHT ; j++)
		{
			if(carte.map[i][j] == MARIO){
				perso.position.x = i * SIZE_BLOCK;
				perso.position.y = j * SIZE_BLOCK;
				break;
			}
		}
	}
    SDL_EnableKeyRepeat(100, 100);
    while(loop){
        winner = 0;
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
							movePlayer(&perso, &carte, &deplacement);
                        break;
                    case SDLK_DOWN:
						deplacement = DOWN;
						if(perso.position.y + SIZE_BLOCK < HEIGHT_WINDOW)
							movePlayer(&perso, &carte, &deplacement);
                        break;
                    case SDLK_LEFT:
						deplacement = LEFT;
						if(perso.position.x - 1 > 0)
							movePlayer(&perso, &carte, &deplacement);
                        break;
                    case SDLK_RIGHT:
						deplacement = RIGHT;
						if(perso.position.x + SIZE_BLOCK < WIDTH_WINDOW)
							movePlayer(&perso, &carte, &deplacement);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }        
        
		//picture pointer points to the corresponding sprinte pointer
        perso.picture = perso.sprites[deplacement];
        //refresh window with good orientation picture player
        SDL_FillRect(win, NULL, SDL_MapRGB(win->format, 0, 0, 0));
		//add picture after fillRect
		for (i = 0 ; i < NB_BLOCKS_WIDTH ; i++)
        {
			for (j = 0 ; j < NB_BLOCKS_HEIGHT ; j++)
			{
				position.x = i * SIZE_BLOCK;
				position.y = j * SIZE_BLOCK;
				
				switch(carte.map[i][j]){
					case WALL:
						SDL_BlitSurface(wall.picture, NULL, win, &position);
						break;
					case CASE:
						SDL_BlitSurface(caisse.picture, NULL, win, &position);
						break;
					case MARIO:
						SDL_BlitSurface(perso.picture, NULL, win, &(perso.position));
						break;
					case CASE_OK:
                        winner++;
						SDL_BlitSurface(caisseOK.picture, NULL, win, &position);
						break;
					case GOAL:
						SDL_BlitSurface(goal.picture, NULL, win, &position);
						break;
					default:
						break;
				}
			}
		}		
        SDL_Flip(win);
        if(winner > 2){
            loop = 0;
            //free
            for(i = 0; i < 4; i++)
                SDL_FreeSurface(perso.sprites[i]);
            SDL_FreeSurface(wall.picture);
            SDL_FreeSurface(caisse.picture);
            SDL_FreeSurface(caisseOK.picture);
            SDL_FreeSurface(goal.picture);
        }
    }
    
    loop = 1;
    initTTF();
    text = textTTF("You win !!!");
    position.x = WIDTH_WINDOW / 4;
    position.y = HEIGHT_WINDOW / 2;
    while(loop){
        SDL_BlitSurface(text, NULL, win, &position);
        SDL_Flip(win);
        SDL_WaitEvent(e);
        switch(e->type){
            case SDL_QUIT:
                loop = 0;
                break;
            default:
                break;
        }
        test
    }
    //free
    SDL_FreeSurface(text);
    
    closeTTF();
    SDL_EnableKeyRepeat(0, 0);
	//quit game
}


void movePlayer(Player *perso, Map *map, int *deplacement){
    int x = perso->position.x / SIZE_BLOCK;
    int y = perso->position.y / SIZE_BLOCK;
    int positionFutur = 0;
    switch(*deplacement){
        case UP:
            y -= 1;
            if(map->map[x][y] != WALL && map->map[x][y] != CASE_OK){
                if(map->map[x][y] == CASE){
                    positionFutur = map->map[x][y-1];
                    if(positionFutur != WALL && positionFutur != CASE && positionFutur != CASE_OK){
                        map->map[x][y] = EMPTY;
                        map->map[x][y-1] = (positionFutur == GOAL) ?
                             CASE_OK : 
                             CASE;
                        perso->position.y -= SIZE_BLOCK;
                    }
                }
                else
                    perso->position.y -= SIZE_BLOCK;
            }
            break;
        case DOWN:
            y += 1;
            if(map->map[x][y] != WALL && map->map[x][y] != CASE_OK){
                if(map->map[x][y] == CASE){
                    positionFutur = map->map[x][y+1];
                    if(positionFutur != WALL && positionFutur != CASE && positionFutur != CASE_OK){
                        map->map[x][y] = EMPTY;
                        map->map[x][y+1] = (positionFutur == GOAL) ?
                             CASE_OK : 
                             CASE;
                        
                        perso->position.y += SIZE_BLOCK;                        
                    }
                }
                else
                    perso->position.y += SIZE_BLOCK;
            }
            break;
        case LEFT:
            x -= 1;
            if(map->map[x][y] != WALL && map->map[x][y] != CASE_OK){
                if(map->map[x][y] == CASE){
                    positionFutur = map->map[x-1][y];
                    if(positionFutur != WALL && positionFutur != CASE && positionFutur != CASE_OK){
                        map->map[x][y] = EMPTY;
                        map->map[x-1][y] = (positionFutur == GOAL) ?
                             CASE_OK : 
                             CASE;
                        perso->position.x -= SIZE_BLOCK;                        
                    }
                }
                else
                    perso->position.x -= SIZE_BLOCK;
            }
            break;
        case RIGHT:
            x += 1;
            if(map->map[x][y] != WALL && map->map[x][y] != CASE_OK){
                if(map->map[x][y] == CASE){
                    positionFutur = map->map[x+1][y];
                    if(positionFutur != WALL && positionFutur != CASE && positionFutur != CASE_OK){
                        map->map[x][y] = EMPTY;
                        map->map[x+1][y] = (positionFutur == GOAL) ?
                             CASE_OK : 
                             CASE;
                        perso->position.x += SIZE_BLOCK;      
                    }
                }
                else
                    perso->position.x += SIZE_BLOCK;
            }
            break;
        default:
            break;
    }
}