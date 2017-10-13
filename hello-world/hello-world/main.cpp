#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	int nb1 = 5; 
	int age = 0;
	float weight = 0.0;
	float size = 0;
	printf("hello world\n");
	printf("bonjour\n");
		
	printf("Il vous reste %d vies \n", nb1);
	
	printf("Quel age avez vous ? \n");
	scanf("%d",&age);
	printf("Votre poids : ");
	scanf("%f",&weight);
	printf("\nEt votre taille : ");
	scanf("%f",&size);
	
	printf("\nVous faites %f et vous pesez %f votre IMC est de : %f \n", size, weight, weight/pow(size, 2));
	
	
	return 0;
}
