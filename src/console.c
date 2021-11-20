// implementasi dari command
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "./ADT/stack.c"

int roll(int maxN){
    srand (time(NULL));
    return (rand() % maxN) + 1;
}

void endturn(){

}

void turn(Stack *S){

}

void undo(Stack *S){
   State pop;
   Pop(S, &pop);
}

void save(char filename){
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Punten, file gak bisa dibuka!\n");
        exit(1);
    }

    //Write something
    fclose(f);
}