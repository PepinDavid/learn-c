#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* PATH = "/home/david/perso/dev/learn-c/hello-world/hanged-man/";
const char* FILE_NAME = "dico.txt";

void openFile(char *pathAndFile, int *cpt, char *w){
	srand(time(NULL)); 
	FILE *dico = NULL;
	int charRead = 0;
	int close = 0;
	int choosenWord = 0;
	
	dico = fopen(pathAndFile, "r");
	
	if(dico != NULL){
		
		do{
			charRead = fgetc(dico);
			if(charRead == '\n')
				(*cpt)++;
		}while(charRead != EOF);
		
		printf("dico contains : %d words \n", (*cpt)+1);
		
		choosenWord = (rand() % *cpt);
		
		printf("myst num : %d\n", choosenWord);
		
		rewind(dico);
		
		while(choosenWord > 0){
			charRead = fgetc(dico);
			if(charRead == "\n")			
				choosenWord--;
		}
		
		printf("%d", choosenWord);
		fgets(w, 100, dico);

		fclose(dico);
	}else{
		printf("Error lors de ouverture du Fichier %s \n", pathAndFile);
		exit(0);
	}
}

int main(int argc, char **argv)
{
	char *pathAndFile = NULL, secretWord[100];
	int cpt = 0;
	
	pathAndFile = malloc(strlen(PATH)+sizeof(FILE_NAME)); // make space for new string
	
	if(pathAndFile == NULL){
		printf("Error malloc pathAndFile\n");
		exit(0);
	}
	strcpy(pathAndFile, PATH); //copy the path
	strcat(pathAndFile, FILE_NAME); //add the name file
	
	printf("path file : %s\n", pathAndFile);
	
	openFile(pathAndFile, &cpt, &secretWord);
	
	printf("%s\n", secretWord);
	free(pathAndFile);
	pathAndFile = NULL;
	
	return 0;
}
