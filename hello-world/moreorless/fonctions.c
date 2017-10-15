#include "fonctions.h"

const int MAX_EASY = 100, 
		  MAX_MEDIUM = 1000, 
		  MAX_HARD = 10000, 
		  MIN = 1;


void ChoiceDifficulty(int *diff, int *nbM){
	srand(time(NULL)); 

	char* choiceDifficult = "Choix de la difficulté : \n\t1. facile (0 à 100)\n\t2. moyenne (0 à 1000)\n\t3. Difficile (0 à 10000)\n";
	
	printf("%c\n",choiceDifficult[0]);
	printf("Devinez le nombre mystères !!!\n");
	printf("%s",choiceDifficult);
	
	do{
		scanf("%d", diff);
		
		switch(*diff){
			case 1:
				*nbM = (rand() % (MAX_EASY - MIN +1)) + MIN;
				break;
			case 2:
				*nbM = (rand() % (MAX_MEDIUM - MIN +1)) + MIN;
				break;
			case 3:
				*nbM = (rand() % (MAX_HARD - MIN +1)) + MIN;
				break;
			default:
				printf("Le choix %d n'est pas un choix valide\n ", *diff);
				printf("%s",choiceDifficult);
				break;
				
		}
	}while(*diff < 1 || *diff > 3);
	
	switch(*diff){
		case 1:
			printf("Niveau Facile 0 à 100\n");
			break;
		case 2:
			printf("Niveau Moyen 0 à 1000\n");
			break;
		case 3:
			printf("Niveau Difficile 0 à 10000\n");
			break;
		default:
			break;
			
	}
}

void Answers(int *ans,const int *nbM, int *chance){
	do{
		printf("Vous avez %d chance. Votre reponse : ", *chance);
		scanf("%d", ans);
		
		if(*ans > *nbM)
			printf("Plus petit !\n"), (*chance)--;
		else if(*ans < *nbM)
			printf("Plus grand !\n"), (*chance)--;
		
	}while(*ans != *nbM && *chance > 0);
}

int YouWin(int *chance){
	printf("Félicitations !!!\n");
	if(*chance == 10)
		printf("Champion : %d", *chance);
	else if(*chance < 10 && *chance > 5)
		printf("Intermediaire : %d", *chance);
	else if(*chance <= 5 && *chance >= 3)
		printf("Pas mal : %d", *chance);
	else
		printf("Ca, c'est de la chance : %d", *chance);
		
	printf("\n");
	
	return 1;
}

void Replay(int *replay){
	int answer = 1;
	printf("Rejouer ? \n\t 1.Oui \n\t 2.Non \nReponse : ");
	scanf("%d", &answer);
	do{
		switch(answer){
			case 1:
				*replay = 1;
				break;
			case 2:
				*replay = 0;
				break;
			default:
				printf("\nChoix en 1 et 2, recommencez \n");
				break;
		}
	}while(answer < 1 || answer > 2);
}

void loopGame(int *diff, int *nbM, int *ans, int *chance, int *replay){
	do{
		
		ChoiceDifficulty(diff, nbM);
	
		Answers(ans, nbM, chance);
		
		(*chance > 0)?YouWin(chance):printf("Perdu le nombre était : %d\n",*nbM);
			
		Replay(replay);
		*chance = 10;
		
		printf("\n");
		if(*replay == 0)
			printf("Bye\n");
	}while(*replay > 0);
}


// with strcuture

void loopGameWithStruct(Game* g){
	do{
		ChoiceDifficultyWithStruct(g);
	
		AnswersWithStruct(g);
		
		(g->p->luck > 0)?YouWinWithStruct(g):printf("Perdu le nombre était : %d\n",g->nbMyst);
			
        ReplayWithStruct(g);
		g->p->luck = 10;
		
		printf("\n");
		if(g->replay == 0)
			printf("Bye\n");
	}while(g->replay > 0);
}

void ChoiceDifficultyWithStruct(Game* g){
	srand(time(NULL)); 

	char* choiceDifficult = "Choix de la difficulté : \n\t1. facile (0 à 100)\n\t2. moyenne (0 à 1000)\n\t3. Difficile (0 à 10000)\n";
	
	printf("%c\n",choiceDifficult[0]);
	printf("Devinez le nombre mystères !!!\n");
	printf("%s",choiceDifficult);
	
	do{
		scanf("%d", (&g->difficulty));
		switch(g->difficulty){
			case 1:
				g->nbMyst = (rand() % (MAX_EASY - MIN +1)) + MIN;
				break;
			case 2:
				g->nbMyst = (rand() % (MAX_MEDIUM - MIN +1)) + MIN;
				break;
			case 3:
				g->nbMyst = (rand() % (MAX_HARD - MIN +1)) + MIN;
				break;
			default:
				printf("Le choix %d n'est pas un choix valide\n ", g->difficulty);
				printf("%s",choiceDifficult);
				break;
				
		}
	}while(g->difficulty < 1 || g->difficulty > 3);
	
	switch(g->difficulty){
		case 1:
			printf("Niveau Facile 0 à 100\n");
			break;
		case 2:
			printf("Niveau Moyen 0 à 1000\n");
			break;
		case 3:
			printf("Niveau Difficile 0 à 10000\n");
			break;
		default:
			break;
			
	}
}

void AnswersWithStruct(Game* g){
	do{
		printf("Vous avez %d chance. Votre reponse : ", g->p->luck);
		scanf("%d", (&g->p->answer));
		
		if(g->p->answer > g->nbMyst)
			printf("Plus petit !\n"), g->p->luck--;
		else if(g->p->answer < g->nbMyst)
			printf("Plus grand !\n"), g->p->luck--;
		
	}while(g->p->answer != g->nbMyst && g->p->luck > 0);
}

int YouWinWithStruct(Game* g){
	printf("Félicitations !!!\n");
	if(g->p->luck == 10)
		printf("Champion : %d", g->p->luck);
	else if(g->p->luck < 10 && g->p->luck > 5)
		printf("Intermediaire : %d", g->p->luck);
	else if(g->p->luck <= 5 && g->p->luck >= 3)
		printf("Pas mal : %d", g->p->luck);
	else
		printf("Ca, c'est de la chance : %d", g->p->luck);
		
	printf("\n");
	
	return 1;
}

void ReplayWithStruct(Game* g){
	int answer = 1;
	printf("Rejouer ? \n\t 1.Oui \n\t 2.Non \nReponse : ");
	scanf("%d", &answer);
	do{
		switch(answer){
			case 1:
				g->replay = 1;
				break;
			case 2:
				g->replay = 0;
				break;
			default:
				printf("\nChoix en 1 et 2, recommencez \n");
				break;
		}
	}while(answer < 1 || answer > 2);
}