//
// fonctions.h
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct Game Game;
typedef struct Player Player;

struct Player{
    char name[100];
    char surname[100];
    char answerChar[64];
    int answer;
    int luck;
};

struct Game{
    Player* p;
    int replay;
    int nbMyst;
    int difficulty;
    char numChar[4];
};

void EraseBuffer();

int Read(char *str, int length);

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

void InitPlayer(Player* p);

void InitGame(Game* g, Player* p);