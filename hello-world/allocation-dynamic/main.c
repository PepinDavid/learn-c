#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Coords Coords;
typedef struct Game Game;
typedef struct Player Player;

struct Coords{
    int x;
    int y;
};

struct Player{
    char* name;
    char* surname;
    int answer;
    int luck;
};

struct Game{
    Player* p;
    int replay;
    int nbMyst;
    int difficulty;
};


int main(int argc, char **argv)
{
    char arrChar[10];
    int arrInt[3];
    int cpt = 0;
    int* ptrInt = NULL;
    char* ptrChar = NULL;
    Player p = {"Pepin", NULL, 10, 0};
    Game g = {&p};
    
    
	printf("sizeof \n");
    printf("char : %ld octets\n", sizeof(char));
    printf("int : %ld octets\n", sizeof(int));
    printf("long : %ld octets\n", sizeof(long));
    printf("float : %ld octets\n", sizeof(float));
    printf("double : %ld octets\n", sizeof(double));
    
    printf("array char [10] : %ld octets\n", sizeof(arrChar));
    printf("array int [3] : %ld octets\n", sizeof(arrInt));
    printf("ptr int : %ld octets\n", sizeof(ptrInt));
    printf("ptr char : %ld octets\n", sizeof(ptrChar));
    
    printf("Coordonnees : %ld octets\n", sizeof(Coords));
    printf("Player : %ld octets\n", sizeof(Player));
    printf("Game : %ld octets\n", sizeof(Game));
    printf("Player edited : %ld octets\n", sizeof(p));
    printf("Player name : %ld octets\n", sizeof(p.name));
    printf("Player surname before malloc  : %ld octets\n", sizeof(p.surname));
    printf("Game edited : %ld octets\n", sizeof(g));
    
    printf("address g : %p\n", &g);
    printf("address g : %p\n", &(g.p));
    printf("address p : %p\n", &p);
    printf("address p in g : %p\n", (void *)(g.p));
    printf("address p.surname : %p\n", (void *)(p.surname));
    //???? printf("address g.p : %p\n", *(g.p));
    printf("%d\n",(p.surname == NULL));
    
    printf("%s\n", p.name);
    printf("Votre prénom : ");
    scanf("%s", arrChar);
    
    for(int i = 0; i < strlen(arrChar); i++){
        if(arrChar[i] != '\0')
            cpt++;
    }
    
    printf("%d\n", cpt);    
    printf("prenom sizeof : %ld\n", sizeof(char)*cpt+1);
    (p.surname) = malloc(sizeof(char)*cpt+1);
    printf("address p.surname : %p\n", (void *)(p.surname));
    p.surname = arrChar;
    printf("address p.surname : %p\n", (void *)(p.surname));
    printf("%s\n", p.surname);
    printf("Player surname after : %ld octets\n", sizeof(p.surname));
    
    //same things
    printf("address p.surname : %p\n", *p.surname);
    printf("address p.surname : %p\n", &p.surname);
    
    printf("address p.surname : %p\n", (void *)(p.surname));
    
	return 0;
}
