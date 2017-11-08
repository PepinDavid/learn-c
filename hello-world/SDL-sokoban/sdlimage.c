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

void loadImage(SDLImage *img, char *constStr, char *str ){
	img->path = malloc(sizeof(char) * strlen(constStr) + (sizeof(char) * strlen(str)) + sizeof(char));
	strcpy(img->path, constStr); //copy the path
	strcat(img->path, str); //add the name file
	img->picture = IMG_Load(img->path);
}