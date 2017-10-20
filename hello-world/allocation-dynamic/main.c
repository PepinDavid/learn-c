#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
void triple(int *c){
    *c *= 3;
}

int main(int argc, char **argv)
{
	//for sizeof and see address ptr
    char arrChar[10];
    int arrInt[3];
    int cpt = 0;
    int* ptrInt = NULL;
    char* ptrChar = NULL;
    Player p = {"Pepin", NULL, 10, 0};
    Game g = {NULL};
    g.p = &p;
    int a = 10;
    int *b = &a;
	int *c = NULL;
	
	int i = 0, nbAmis = 0;
	int *arrAmis = NULL;
	
	
	
	c = malloc(sizeof(a));
	*c = a;    
    
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
	printf("Player name[0] : %ld octets\n", sizeof(p.name[0]));
    printf("Player surname : %ld octets\n", sizeof(p.surname));
	printf("Player answer : %ld octets\n", sizeof(p.answer));
	printf("Player ptr answer : %ld octets\n", sizeof((void *)p.answer));
	printf("Player luck : %ld octets\n", sizeof(p.luck));
    printf("Game edited : %ld octets\n\n", sizeof(g));
	printf("Game ptr edited : %ld octets\n\n", sizeof(&g));
    
	
	printf("testing with ptr\n");
	printf("ptr int a : %p\n", &a);
    printf("ptr int b : %p\n", b);
	printf("ptr int c : %p\n", c);
    
    triple(b);
    
    printf("int a : %d\n",a);
    printf("int b : %d\n",*b);
	printf("int c : %d\n\n",*c);
	
	printf("see address pointer\n");
    printf("address g : %p\n", &g);
    printf("address g.p : %p\n", &g.p);
    printf("address g.nbMyst : %p\n", &g.nbMyst);
	printf("address g.difficulty : %p\n\n", &g.difficulty);
	
	//in hex
	printf("in HEX\n");
    printf("address p : %p\n", &p);
    printf("address p in g = g.p : %p\n", g.p);
    printf("address p in g = (void *)(g.p) : %p\n", (void *)(g.p));
	
	printf("address p.name = &(p.name) : %p\n", &(p.name));//pointer of first case of player p, pointer of pointer of first case of name in player p
	//same thing
	printf("address name in p = p.name : %p\n", p.name);//pointer of first case of player p
	printf("address name in p = (void *)(p.name) : %p\n", (void *)p.name);//pointer of first case of name in player p
	
	printf("address p.surname = &p.surname : %p\n", &p.surname);//pointer of second case of player p
	printf("address p.answer = &p.answer : %p\n", &p.answer);//pointer of third case of player p
	printf("address p.luck = &p.luck : %p\n", &p.luck);//pointer of third case of player p
    printf("address surname in p before malloc = (void *)p.surname : %p\n\n", (void *)p.surname);
    
	//in dec
	printf("in DEC\n");
    printf("address p : %d\n", abs(&p));
    printf("address p in g = (void *)(g.p) : %d\n", abs((void *)(g.p)));
	
	printf("address p.name : %d\n", abs(&(p.name)));//pointer of first case of player p, pointer of pointer of first case of name in player p
	//same thing
	printf("address p.name : %d\n", abs(p.name));//pointer of first case of player p
	printf("address name in p : %d\n", abs((void *)(p.name)));//pointer of first case of name in player p
	
	printf("address p.surname : %d\n", abs(&(p.surname)));//pointer of second case of player p
	printf("address p.answer : %d\n", abs(&p.answer));//pointer of third case of player p
	printf("address p.luck : %d\n", abs(&p.luck));//pointer of fourth case of player p
    printf("address p in g = g.p : %d\n", abs(g.p));
    printf("address surname in p before malloc: %d\n\n", abs((void *)(p.surname)));
	
    printf("%s\n", p.name);
    printf("Votre prénom : ");
    scanf("%s", arrChar);
	
    for(; i < strlen(arrChar); i++){
        if(arrChar[i] != '\0')
            cpt++;
    }
    
    printf("cpt : %d\n", cpt);    
    printf("prenom sizeof : %ld\n", sizeof(char)*cpt+1);
    
	(p.surname) = malloc(sizeof(char)*cpt+1);
	
	if((void *)p.surname == NULL){		
		printf("Error malloc on p.surname");
	}else{
		i = 0;
		for(; i < strlen(arrChar); i++){
			if(arrChar[i] != '\0')
				p.surname[i] = arrChar[i];
		}
		printf("address surname in p after malloc : %p\n", (void *)(p.surname));
		printf("Player surname after malloc: %ld octets\n\n", sizeof(p.surname));
		printf("Bonjour %s\n", p.surname);
	}
	
    arrChar[0] = 'B';
    arrChar[1] = 'l';
    arrChar[2] = 'a';
    arrChar[3] = 'b';
    arrChar[4] = 'L';
    arrChar[5] = 'A';
    
    printf("%s\n\n",arrChar);
	
	printf("%p\n", &arrChar);
	printf("%p\n", &arrChar[0]);
	printf("%p\n\n", &arrChar[1]);

    printf("Petit exemple d'allocation-dynamique\n");
	printf("Combien d'amis avez vous ?\n");
	scanf("%d", &nbAmis);
	
	
	if(nbAmis > 0){
	
		arrAmis = malloc(sizeof(int)*nbAmis);
		
		if(arrAmis == NULL){
			printf("Error malloc arrAmis\n");
		}else{
			
			for(i = 0; i < nbAmis; i++){
				printf("Quel age a l'ami numéro %d : ", i+1);
				scanf("%d", &arrAmis[i]);
				printf("\n");
			}
			
			for(i = 0; i < nbAmis; i++){
				printf("Votre ami numero %d a %d\n", i+1, arrAmis[i]);
			}
		}
	}
	
	return 0;
}
