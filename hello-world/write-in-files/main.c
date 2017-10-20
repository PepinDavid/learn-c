#include <stdio.h>
#include <stdlib.h>

const char* PATH = "/home/david/dev/learn-c/hello-world/write-in-files/";
const char* FILE_NAME = "test.txt";

int main(int argc, char **argv)
{
	FILE* fichier = NULL;
	char* pathAndFile = NULL;
	char* nom[100];
	int age = 0;
	int close = 0;
	int writeChar = 0; //for fputc
	int writeString = 0; //for fputs
	int writefString = 0; //for fprintf
	int readChar = 0; //for fgetc
	int readString = 0; //for fgets
	int nbChar = 14; //for size of string Hello World!\n 
	char* fGets[100];
	int readfString = 0; //for fscanf
	long positionCursor = 0;
    
    
	pathAndFile = malloc(strlen(PATH)+sizeof(FILE_NAME)); // make space for new string
	strcpy(pathAndFile, PATH); //copy the path
	strcat(pathAndFile, FILE_NAME); //add the name file
	
    
    //write in file
	fichier = fopen(pathAndFile, "r+");
	
	if(fichier != NULL){
		printf("Fichier %s ouvert\n", pathAndFile);
		printf("Ecriture dans le fichier\n");
		writeChar = fputc('A', fichier);
		(writeChar != EOF)?printf("%d 'fputc'\n",writeChar):printf("Erreur: %d\n", writeChar);
		
		writeString = fputs("\nHello World !\n", fichier);
		(writeString != EOF)?printf("%d 'fputs'\n",writeString):printf("Erreur: %d\n", writeString);
		
		writefString = fprintf(fichier, "Hello World !\n");
		(writefString != EOF)?printf("%d 'fprintf'\n",writefString):printf("Erreur: %d\n", writefString);

		printf("Quel est votre nom ?\n");
		scanf("%s", &nom);
		printf("Quel âge avez vous ?\n");
		scanf("%d", &age);
	
		writefString = fprintf(fichier, "Bonjour %s, vous avez %d ans", nom, age);
		(writefString != EOF)?printf("%d 'fprintf'\n",writefString):printf("Erreur: %d\n", writefString);
				
		(close == 0)?
			printf("Fichier fermé, return fclose = %d\n", close) : 
				printf("Erreur lors de la fermeture, return fclose = %d\n", close);
		
	}else{
		printf("Erreur lors de l'ouverture du fichier\n");
	}
	
    //read file
	fichier = fopen(pathAndFile, "r");
	if(fichier != NULL){		
		
		printf("read char in loop times\n");		
		do{
			readChar = fgetc(fichier); //cursor moving one char
			printf("%c", readChar);
		}while(readChar != EOF || readChar != -1);
		
		//return at begin of file
		rewind(fichier);
		printf("Rewind and read while not NULL\n");
		while(fgets(fGets, 100, fichier) != NULL){
			printf("%s", fGets);
		}
		
		//return at begin of file
		rewind(fichier);		
		printf("Rewind and read with fscanf\n");
		while(fscanf(fichier,"%s[^\n]",&fGets) != EOF){
			printf("%s", fGets);
		}
		
		close = fclose(fichier);
		
		(close == 0)?
			printf("Fichier fermé, return fclose = %d\n", close) : 
				printf("Erreur lors de la fermeture, return fclose = %d\n", close);
		
	}else{
		printf("Erreur lors de l'ouverture du fichier\n");
	}
	
	//reopen file read/play with cursor
    fichier = fopen(pathAndFile, "r");
	if(fichier != NULL){		
		
		printf("read first char\n");		
        readChar = fgetc(fichier); //cursor moving one char
        (readChar != EOF)? printf("%c\n", readChar) : printf("Error: %d",readChar);
				
        //get position cursor
        positionCursor = ftell(fichier);
        printf("position cursor: %ld\n", positionCursor);
		
        //move forward cursor of five char since position ftell
        fseek(fichier, 5, positionCursor);
        readChar = fgetc(fichier); //cursor moving one char
        (readChar != EOF)? printf("%c\n", readChar) : printf("Error: %d",readChar);
        
        
        //get position cursor
        positionCursor = ftell(fichier);
        printf("position cursor: %ld\n", positionCursor);
        
        //move backward curose of 3 since position ftell
        fseek(fichier, -3, positionCursor);
        readChar = fgetc(fichier); //cursor moving one char
        (readChar != EOF)? printf("%c\n", readChar) : printf("Error: %d",readChar);
                
        //or
        //move forward cursor of five char since actual position cursor
        //get position cursor
        positionCursor = ftell(fichier);
        printf("position cursor: %ld\n", positionCursor);

        fseek(fichier, 8, SEEK_CUR);
        readChar = fgetc(fichier); //cursor moving one char
        (readChar != EOF)? printf("%c\n", readChar) : printf("Error: %d",readChar);
        
        //move forward cursor of five char since begin file
        fseek(fichier, 8, SEEK_SET);
        readChar = fgetc(fichier); //cursor moving one char
        (readChar != EOF)? printf("%c\n", readChar) : printf("Error: %d",readChar);
        
        //move forward cursor of five char since end file
        fseek(fichier, -7, SEEK_END);
        readChar = fgetc(fichier); //cursor moving one char
        (readChar != EOF)? printf("%c\n", readChar) : printf("Error: %d",readChar);        
        
		close = fclose(fichier);
		
		(close == 0)?
			printf("Fichier fermé, return fclose = %d\n", close) : 
				printf("Erreur lors de la fermeture, return fclose = %d\n", close);
		
	}else{
		printf("Erreur lors de l'ouverture du fichier\n");
	}
    
    
    free(pathAndFile);
	return 0;
}
