// implementasi dari command
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "./ADT/stack.c"
#include "skill.h"

int roll(int maxN){

    if (SenterPembesarHoki == true){
        srand (time(NULL));
        return (rand() % maxN) + (maxN/2);
    }
    else if (SenterPengecilHoki == true){
        srand (time(NULL));
        return (rand() % (maxN/2)) + 1;
    }
    else{
        srand (time(NULL));
        return (rand() % maxN) + 1;
    }
}

void endturn(Stack *S, State turn){
    Push(&S, turn);
    // next turn
}

void turn(Stack *S){

}

void undo(Stack *S, int NPlayer){
    for (int i = 0; i < NPlayer; i++){
        State pop;
        Pop(S, &pop);
   }
}

void save(char filename[50]){
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Punten, file gak bisa dibuka!\n");
        exit(1);
    }

    //Write something
    fclose(f);
}