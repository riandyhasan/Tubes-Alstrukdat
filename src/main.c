// Ini buat manggil semua fungsi di game
#include <stdio.h>
#include <stdlib.h>
#include "console.c"

int main(){
    printBanner();
    mainMenu();
    startGame();
    return 0;
}