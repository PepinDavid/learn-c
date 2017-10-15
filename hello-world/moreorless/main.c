#include <stdio.h>
#include <stdlib.h>

#include "fonctions.h"

//-------------------------------------------------------------

int main(int argc, char **argv)
{
    Player p;
    Game g;
//	int answer = 0,
//		difficulty = 0,
//	    nbMyst = 0,
//		luck = 10,
//	    replay = 1;
//	printf("%d\n",&g);
//    printf("%d\n",g.nbMyst);
//    printf("%d\n",(&g)->nbMyst);
	//loopGame(&difficulty, &nbMyst, &answer, &luck, &replay);
    
    InitPlayer(&p);
    InitGame(&g, &p);
	loopGameWithStruct(&g);
	return 0;
}


//-------------------------------------------------------------