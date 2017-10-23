#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* PATH = "/home/david/perso/dev/learn-c/hello-world/hanged-man/";
const char* FILE_NAME = "dico.txt";
/*
----
|  |
|  O
| \|/
|  |
| / \
|
------
 */

int nomberRand(int nombreMax){
    srand(time(NULL));
    return (rand() % nombreMax);
}

void pointerFall(char *c){
	if(c == NULL){
		printf("Error malloc %s\n", c);
		exit(0);
	}
}

//read character answer
char readChar(){
	char letter = 0;
	
	letter = getchar(); //read first character
	letter = toupper(letter); //put letter in upper case
	
	while(getchar() != '\n'); //read all character in memory one by one thru \n for erase them
		
	//return letter in upper case
	return letter;
}

//create word hide with same longer of wordDico
void createWordHide(char *wordDico, char *wordHide){
	int i = 0;
	
	wordHide = realloc(wordHide, sizeof(char)*strlen(wordDico)+1);	
	for(; i < strlen(wordDico); i++)
		wordHide[i] = '*';
	
	wordHide[strlen(wordHide)] = '\0';
}

//compare char between wordDico and letter and change char in wordHide
//in good place if letter is in dico
int compareWord(char *wordDico, char *wordHide, char letter){
	int i = 0, findLetter = 0;
	for(; wordDico[i] != '\0'; i++){		
		if(wordDico[i] == letter ){
			wordHide[i] = letter;
			findLetter = 1;
		}
	}
	return findLetter;
}

void openFile(char *pathAndFile, char *w){
	FILE *dico = NULL;
	int cpt = 0,
		charRead = 0,
		sizeWord = 1,
		choosenWord = 0;
	
    //open file
	dico = fopen(pathAndFile, "r");
	
	if(dico != NULL){
        //count number of words
		do{
			charRead = fgetc(dico);
			if(charRead == '\n')
				cpt++;
		}while(charRead != EOF);
        
		printf("dico contains : %d words \n", (cpt)+1);
		
        //choose word
		choosenWord = nomberRand(cpt);
		
		printf("myst num : %d\n", choosenWord);		
		
        //return to the begin of the file
		rewind(dico);
		
        //while we don't to the good line
		while(choosenWord > 0){
			charRead = fgetc(dico);
			if(charRead == '\n')			
				choosenWord--;
		}
        
        //count letters of the choosen word
        do{
            charRead = fgetc(dico);
			if(charRead != '\n')
                sizeWord++;
        }while(charRead != '\n');
        
        //return the cursor to the beginning of the word
        fseek(dico, -sizeWord, SEEK_CUR);

        //alloc dyn size word +1
        w = realloc(w, sizeof(char)*sizeWord+1);
		fgets(w, sizeWord, dico);
		
        //add end charater after the word
        w[strlen(w)] = '\0';
		
		fclose(dico);
	}else{
		printf("Error lors de ouverture du Fichier %s \n", pathAndFile);
		exit(0);
	}
}

int main(int argc, char **argv)
{
	char *pathAndFile = NULL, 
		 *secretWord = NULL, 
		 *wordHide = NULL,
		 answer = 0;
	int findLetter = 0, win = 10, replay = 0;
	
	
	do{		
		pathAndFile = malloc(strlen(PATH)+sizeof(FILE_NAME)); // make space for new string
		secretWord = malloc(sizeof(char));
		wordHide = malloc(sizeof(char));
		pointerFall(pathAndFile);
		pointerFall(secretWord);
		pointerFall(wordHide);
		strcpy(pathAndFile, PATH); //copy the path
		strcat(pathAndFile, FILE_NAME); //add the name file
		
		printf("path file : %s\n", pathAndFile);
		
		openFile(pathAndFile, secretWord);
		free(pathAndFile);
		pathAndFile = NULL;
		
		createWordHide(secretWord, wordHide);
		do{
			printf("Il vous %d coups\n", win);
			printf("%s\n", wordHide);
			printf("Taper une lettre : \n");
			answer = readChar();
			findLetter = compareWord(secretWord, wordHide, answer);
			if(findLetter == 0){
				win--;
				printf("Mauvaise réponse !\n");
			}
		}while(strcmp(secretWord, wordHide) && win > 0);   
		
		(win > 0)?
			printf("You Win\n"):
			printf("You Lose, le mot était : %s\n", secretWord);
		
		free(secretWord);
		free(wordHide);
		secretWord = NULL;
		wordHide = NULL;

		do{
			printf("Rejouez ?\n\t1 - Oui\n\t0 - Non\n");
			scanf("%d", &replay);		
			if(replay < 0 || replay > 1)
				printf("La réponse %d n'est pas accepter\n", replay);
		}while(replay < 0 || replay > 1);
	}while(replay == 1);
	
	printf("Bye\n");
	return 0;
}
