#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
 
void pause();
void CreateNewSurface(SDL_Surface *surface[]);
void PosAndBlit(SDL_Surface *ecran, SDL_Surface *surface[], SDL_Rect *pos);
void FreeSurfaceDegrade(SDL_Surface *surface[]);

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    SDL_Surface *rect = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 200, 32, 0, 0, 0, 0);
    SDL_Surface *degrade[255] = {NULL};
    SDL_Rect pos;
    //pour un rectangle dans un rectangle principal dans la window
    pos.x = (800-200)/2;
    pos.y = (600-200)/2;
    //faire un degradé
    CreateNewSurface(degrade);
    
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
    //SDL_FULLSCREEN pleine ecran
    //SDL_HWSURFACE utilisation carte 3D
    //SDL_RESIZABLE rend la fenetre extensible
    //SDL_DOUBLEBUF evite le scintillement, utile en 2D pour rendre deplacement joueur plus fluide
    if( ecran == NULL ){ // Ouverture de la fenêtre et verification erreur ouverture
        fprintf(stderr, "Erreur intialisation SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("test SDL", NULL); //change nom fenetre
    //pour un rectangle dans un rectangle principal dans la window
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 0, 0));//dessiner un carré de couleur rouge
    SDL_FillRect(rect, NULL, SDL_MapRGB(ecran->format, 0, 255, 177));//dessiner un carré de couleur plus ou moins vert
    SDL_BlitSurface(rect, NULL, ecran, &pos);
    
    //PosAndBlit(ecran, degrade, &pos);
    
    SDL_Flip(ecran);//maj ecran
    
    pause(); // Mise en pause du programme
    
    FreeSurfaceDegrade(degrade);
    SDL_FreeSurface(rect);
    SDL_Quit(); // Arrêt de la SDL
 
    return EXIT_SUCCESS; // Fermeture du programme
}

void CreateNewSurface(SDL_Surface *surface[]){
    int i = 0;
    for(; i < 256; i++){
        surface[i] = SDL_CreateRGBSurface( SDL_HWSURFACE, 800, 600, 32, 0, 0, 0, 0);
    }
}

void PosAndBlit(SDL_Surface *ecran, SDL_Surface *surface[], SDL_Rect *pos){
    int i = 0;
    for(; i < 256; i++){
        if( i%2 == 0 )
            pos->x = i,
                pos->y = i;
        else
            pos->x = 800 - i,
                pos->y = 600 - i;
        
        if( i/2 == 0 )
            SDL_FillRect(surface[i], NULL, SDL_MapRGB(ecran->format, i, i, i));
        else if( i%3 == 0 )
            SDL_FillRect(surface[i], NULL, SDL_MapRGB(ecran->format, i*2, 0, i*2));
        else
            SDL_FillRect(surface[i], NULL, SDL_MapRGB(ecran->format, 0, i*4, 0));
        SDL_BlitSurface(surface[i], NULL, ecran, pos);
    }
}

void FreeSurfaceDegrade(SDL_Surface *surface[]){
    int i = 0;
    for(; i < 256; i++){
        SDL_FreeSurface(surface[i]);
    }
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
        }
    }
}