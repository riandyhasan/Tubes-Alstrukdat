// implementasi dari command
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "./ADT/stack.c"
#include "./ADT/map.c"

extern Map M;
extern Stack S;

int roll(Map M, State S, int Pnum){
    int maxN;
    Player p = SearchPlayerByPlayerNum(S, Pnum);
    maxN = MAXROLL(M);
    if (BUFF(INFOBUFF(p))[2] == true){
        srand (time(NULL));
        return (rand() % maxN) + (maxN/2);
    }
    else if (BUFF(INFOBUFF(p))[3] == true){
        srand (time(NULL));
        return (rand() % (maxN/2)) + 1;
    }
    else{
        srand (time(NULL));
        return (rand() % maxN) + 1;
    }
}

void endturn(State turn){
    Push(&S, turn);
    // next turn
}

void turn(Stack *S){

}

void undo(){
    State pop;
    for (int i = 0; i < NPLAYER(InfoTop(S)); i++){
        Pop(&S, &pop);
   }
}

void save(char filename[50]){
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Punten, file gak bisa dibuka!\n");
    }

    //Write something
    fclose(f);
}

void newGame() {
	char name[50];
    int nPlayer;
	printf("Masukkan nama file konfigurasi permainan: ");
    scanf("%s", &name);
    inisialisasiMap(&M);
    readMap(&M, name);
    CreateEmptyStack(&S);
    printf("Berhasil memuat level. Permainan dimulai!\n\n");
    printf("Konfigurasi player!\n");
    printf("Masukkan jumlah pemain: ");
    scanf("%d", &nPlayer);
    printf("\nMenambahkan player!\n");
    AddPlayerToGame(nPlayer);
    printf("\n%d Player telah ditambahkan!", nPlayer);
}