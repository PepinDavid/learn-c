#include "sdlimage.h"

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

void loadMap(Map *m, char *constStr, char *str){
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
                printf("%c", fileLine[(i * NB_BLOCKS_WIDTH) + j]);
                switch(fileLine[(i * NB_BLOCKS_WIDTH) + j]){
                    case '0':
                        m->map[j][i] = 0;
                        break;
                    case '1':
                        m->map[j][i] = 1;
                        break;
                    case '2':
                        m->map[j][i] = 2;
                        break;
                    case '3':
                        m->map[j][i] = 3;
                        break;
                    case '4':
                        m->map[j][i] = 4;
                        break;
                    case '5':
                        m->map[j][i] = 5;
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
}

void loadImage(SDLImage *img, char *constStr, char *str ){
	img->path = malloc(sizeof(char) * strlen(constStr) + (sizeof(char) * strlen(str)) + sizeof(char));
	strcpy(img->path, constStr); //copy the path
	strcat(img->path, str); //add the name file
	img->picture = IMG_Load(img->path);
}

void loadSprite(Player *p, char *constStr, char *str, int direction ){
	p->path = malloc(sizeof(char) * strlen(constStr) + (sizeof(char) * strlen(str)) + sizeof(char));
	strcpy(p->path, constStr); //copy the path
	strcat(p->path, str); //add the name file
	p->sprites[direction] = IMG_Load(p->path);
}