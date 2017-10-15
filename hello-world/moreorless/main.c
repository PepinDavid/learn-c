#include <stdio.h>
#include <stdlib.h>

#include "fonctions.h"

//-------------------------------------------------------------

int main(int argc, char **argv)
{
    Player p = { 0, 10};
    Game g = {&p, 1, 0, 0};
//	int answer = 0,
//		difficulty = 0,
//	    nbMyst = 0,
//		luck = 10,
//	    replay = 1;
	printf("%d\n",&g);
    printf("%d\n",g.nbMyst);
    printf("%d\n",(&g)->nbMyst);
	//loopGame(&difficulty, &nbMyst, &answer, &luck, &replay);
	loopGameWithStruct(&g);
	return 0;
}


//-------------------------------------------------------------