#include <stdio.h>
#include <stdlib.h>

#include "fonctions.h"

//-------------------------------------------------------------

int main(int argc, char **argv)
{
// withtout struct
//	int answer = 0,
//		difficulty = 0,
//	    nbMyst = 0,
//		luck = 10,
//	    replay = 1;
//	loopGame(&difficulty, &nbMyst, &answer, &luck, &replay);
    
//with struct
    Player p;
    Game g;
    InitPlayer(&p);
    InitGame(&g, &p);
	loopGameWithStruct(&g);
	return 0;
}


//-------------------------------------------------------------