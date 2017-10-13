//
// fonctions.h
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ChoiceDifficulty(int* diff, int* nbM);

void Answers(int* ans, const int* nbM, int* chance);

int YouWin(int* chance);

void Replay(int *replay);

void loopGame(int *diff, int *nbM, int *ans, int *chance, int *replay);