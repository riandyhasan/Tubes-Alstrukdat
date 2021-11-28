#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../adt.h"

int main(){

    State setet;
    int x;
    
    CreateRound(&setet);
    printf("ROUND TELAH TERCIPTA !!");
    printf("\n");

    printf("Masukkan jumlah pemain : ");
    scanf("%d", x);

    AddPlayerToGame(&setet, x);

    printf("\n");
    printf("Berikut semua player yang ada dalam permainan : \n");
    ShowPlayer(setet);

}