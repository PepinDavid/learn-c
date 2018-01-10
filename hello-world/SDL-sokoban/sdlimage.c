#include "sdlimage.h"
#include "error.h"

void initSDLImage(SDLImage *img){
	img->picture = NULL;
	img->path = NULL;
	img->position.x = 0;
	img->position.y = 0;
}

void initSDLPlayer(Player *player){
	int i = 0;
	
	for(; i < 4; i++){
		player->sprites[i] = NULL;
	}
	
	player->picture = NULL;
	player->path = NULL;
	player->position.x = 0;
	player->position.y = 0;
}

void initSDLIMG(SDLIMG *img){
    img->picture = NULL;
	img->path = NULL;
}

void loadMap(Map *m, char *constStr, char *str, int *nbGoal){
    FILE *carte = NULL;
    char fileLine[NB_BLOCKS_HEIGHT * NB_BLOCKS_WIDTH + 1];
    int i = 0, j = 0;
    printf("load map\n");
    m->pathFile = malloc(sizeof(char) * strlen(constStr) + (sizeof(char) * strlen(str)) + sizeof(char));
	strcpy(m->pathFile, constStr); //copy the path
	strcat(m->pathFile, str); //add the name file
    
    carte = fopen(m->pathFile, "r");
    
    if(carte != NULL){
        printf("carte != null\n");
        fgets(fileLine, NB_BLOCKS_HEIGHT * NB_BLOCKS_WIDTH + 1, carte);

        for(i = 0; i < NB_BLOCKS_WIDTH; i++){
            for(j = 0; j < NB_BLOCKS_HEIGHT; j++){
                switch(fileLine[(i * NB_BLOCKS_WIDTH) + j]){
                    case '0':
                        m->map[j][i] = EMPTY;
                        break;
                    case '1':
                        m->map[j][i] = WALL;
                        break;
                    case '2':
                        m->map[j][i] = CASE;
                        break;
                    case '3':
                        m->map[j][i] = GOAL;
                        (*nbGoal)++;
                        break;
                    case '4':
                        m->map[j][i] = MARIO;
                        break;
                    case '5':
                        m->map[j][i] = CASE_OK;
                        break;
                    default:
                        break;
                }
            }
        }
    }
      else
        exit(EXIT_FAILURE);
}

void loadIMG(SDLIMG *img, char *constStr, char *str ){
	img->path = malloc(sizeof(char) * strlen(constStr) + (sizeof(char) * strlen(str)) + sizeof(char));
	strcpy(img->path, constStr); //copy the path
	strcat(img->path, str); //add the name file
	img->picture = IMG_Load(img->path);
    getErrorLoadImg(img->picture);
}

void loadImage(SDLImage *img, char *constStr, char *str ){
	img->path = malloc(sizeof(char) * strlen(constStr) + (sizeof(char) * strlen(str)) + sizeof(char));
	strcpy(img->path, constStr); //copy the path
	strcat(img->path, str); //add the name file
	img->picture = IMG_Load(img->path);
    getErrorLoadImg(img->picture);
}

void loadSprite(Player *p, char *constStr, char *str, int direction ){
	p->path = malloc(sizeof(char) * strlen(constStr) + (sizeof(char) * strlen(str)) + sizeof(char));
	strcpy(p->path, constStr); //copy the path
	strcat(p->path, str); //add the name file
	p->sprites[direction] = IMG_Load(p->path);
    getErrorLoadImg(p->sprites[direction]);
}