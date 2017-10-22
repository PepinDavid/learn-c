#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* PATH = "/home/david/dev/learn-c/hello-world/hanged-man/";
const char* FILE_NAME = "dico.txt";

int nomberRand(int nombreMax){
    srand(time(NULL));
    return (rand() % nombreMax);
}

void openFile(char *pathAndFile, int *cpt, char *w){
	FILE *dico = NULL;
	int charRead = 0;
    int sizeWord = 1;
	//int close = 0;
	int choosenWord = 0;
	
    //on ouvre le fichier
	dico = fopen(pathAndFile, "r");
	
	if(dico != NULL){
        //on compte le nombre de mot
		do{
			charRead = fgetc(dico);
			if(charRead == '\n')
				(*cpt)++;
		}while(charRead != EOF);
		
        
		printf("dico contains : %d words \n", (*cpt)+1);
		
        //choix d'un nombre au hazar
		choosenWord = nomberRand(*cpt);
		
		printf("myst num : %d\n", choosenWord);		
        //on recommence du debut du fichier
		rewind(dico);
        //tant que qu'on est pas a la ligne du mot choisi
		while(choosenWord > 0){
			charRead = fgetc(dico);
			if(charRead == '\n')			
				choosenWord--;
		}
        
        //faire un do while pour attraper le nombre de lettre du mot choisi
        do{
            charRead = fgetc(dico);
			if(charRead != '\n')
                sizeWord++;
        }while(charRead != '\n');
        
        //on se remet au debut du mot
        fseek(dico, -sizeWord, SEEK_CUR);
        printf("%p\n", w);
        //alloc dyn de la taille du mot +1
        w = realloc(w, sizeof(char)*sizeWord+1);
		fgets(w, sizeWord, dico);
        //ajout du caractere de fin de mot
        w[strlen(w)] = '\0';
        printf("%s\n", w);
        printf("%p\n", w);
		fclose(dico);
	}else{
		printf("Error lors de ouverture du Fichier %s \n", pathAndFile);
		exit(0);
	}
}

int main(int argc, char **argv)
{
	char *pathAndFile = NULL, *secretWord = NULL, *testWordPtr = NULL;
    char answer[50];
	int cpt = 0, i = 0;
	
	pathAndFile = malloc(strlen(PATH)+sizeof(FILE_NAME)); // make space for new string
	
	if(pathAndFile == NULL){
		printf("Error malloc pathAndFile\n");
		exit(0);
	}
	strcpy(pathAndFile, PATH); //copy the path
	strcat(pathAndFile, FILE_NAME); //add the name file
	
	printf("path file : %s\n", pathAndFile);
	secretWord = malloc(sizeof(char));
	openFile(pathAndFile, &cpt, secretWord);
	
    printf("test word : ");
    scanf("%s",&answer);
    
    testWordPtr = malloc(sizeof(char) * (strlen(answer)+1));
    for(; i < strlen(answer); i++){
        testWordPtr[i] = answer[i];
    }
    testWordPtr[strlen(testWordPtr) ] = '\0';
    
    printf("%d\n",(*testWordPtr == *secretWord));
    
	free(pathAndFile);
	pathAndFile = NULL;
	
	return 0;
}
