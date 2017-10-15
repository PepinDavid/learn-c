//
// fonctions.h
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Game Game;
typedef struct Player Player;

struct Player{
    int answer;
    int luck;
};

struct Game{
    Player* p;
    int replay;
    int nbMyst;
    int difficulty;
};

void ChoiceDifficulty(int* diff, int* nbM);

void Answers(int* ans, const int* nbM, int* chance);

int YouWin(int* chance);

void Replay(int *replay);

void loopGame(int *diff, int *nbM, int *ans, int *chance, int *replay);

//with struct
void loopGameWithStruct(Game* g);

void ChoiceDifficultyWithStruct(Game* g);

void AnswersWithStruct(Game* g);

int YouWinWithStruct(Game* g);

void ReplayWithStruct(Game* g);