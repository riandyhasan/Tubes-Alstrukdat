// implementasi dari command
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const int maxN = 20;

int roll(){
    srand (time(NULL));
    return (rand() % maxN) + 1;
}

void endturn(){

}

int main(){
    int dc = roll();
    printf("%d", dc);
    return 0;
}