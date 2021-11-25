// implementasi dari command
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "adt.h"

Map M;
Stack S;
State turn;
int playerturn = 1;

int roll(){
    int maxN;
    Player p = SearchPlayerByPlayerNum(turn, playerturn);
    maxN = MAXROLL(M);
    if (p.buff[2] == true){
        srand (time(NULL));
        return (rand() % maxN) + (maxN/2);
    }
    else if (p.buff[3] == true){
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
    playerturn = (playerturn + 1) % turn.nPlayer;
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

void CommandSkill (){
/* mengeluarkan command untuk meminta masukkan skill yang ingin dipakai */

    int UseSkill, i;
    address T;
    Player P;

    P = SearchPlayerByPlayerNum(turn, playerturn);

    T = First(INFOSKILL(P));

    printf("Masukkan skill : ");
    scanf("%d", &UseSkill);

    if ( UseSkill > 0){
        
        for (i=1; i<UseSkill; i++){
            T = Next(T);
        }

        if ( Info_Skill(T) == 1){
            printf("%d memakai skill Pintu Ga Ke Mana Mana. Anda mendapatkan imunitas terhadap teleport!\n", INFOPLAYER(P));
            P.buff[0] = true;
            DelP (&INFOSKILL(P), 1) ;
        }
        else if (Info_Skill(T) == 2){
            printf("%d memakai skill Cermin Pengganda. Skill ini akan dibuang digantikan dengan 2 skill baru.\n", INFOPLAYER(P));
            P.buff[1] = true;
            DelP (&INFOSKILL(P), 2) ;
        }
        else if (Info_Skill(T) == 3){
            printf("%d memakai skill Senter Pembesar Hoki. Dadu hanya akan menghasilkan angka MaxRoll atau setengah dari MaxRoll\n", INFOPLAYER(P));
            P.buff[2] = true;
            DelP (&INFOSKILL(P), 3) ;
        }
        else if (Info_Skill(T) == 4){
            printf("%d memakai skill Senter Pengecil Hoki. Dadu hanya akan menghasilkan angka 0 atau setengah dari MaxRoll\n", INFOPLAYER(P));
            P.buff[3] = true;
            DelP (&INFOSKILL(P), 4) ;
        }
        else if (Info_Skill(T) == 5){
            UseTukarPosisiPlayer(&turn, playerturn) ;
            DelP (&INFOSKILL(P), 5) ;
        }
    }
    else if (UseSkill < 0){

        for (i=1; i<(UseSkill*-1); i++){
            T = Next(T);
        }

        if (Info_Skill(T) == 1){
            printf("%d membuang skill Pintu Ga Ke Mana Mana.\n", INFOPLAYER(P));
            DelP (&INFOSKILL(P), 1) ;
        }
        else if (Info_Skill(T) == 2){
            printf("%d membuang skill Cermin Pengganda.\n", INFOPLAYER(P));
            DelP (&INFOSKILL(P), 2) ;
        }
        else if (Info_Skill(T) == 3){
            printf("%d membuang skill Senter Pembesar Hoki.\n", INFOPLAYER(P));
            DelP (&INFOSKILL(P), 3) ;
        }
        else if (Info_Skill(T) == 4){
            printf("%d membuang skill Senter Pengecil Hoki.\n", INFOPLAYER(P));
            DelP (&INFOSKILL(P), 4) ;
        }
        else if (Info_Skill(T) == 5){
            printf("%d membuang skill Mesin Penukar Posisi.\n", INFOPLAYER(P));
            DelP (&INFOSKILL(P), 5) ;
        }
    }
    else if (UseSkill == 0){
        return;
    }
}

// void SwapPlayer (Player P1, Player P2, State *S){


// }




void cmdPlayer(){
    char MAP[] = "MAP";
    char SKILL[] = "SKILL";
    char BUFF[] = "BUFF";
    char INSPECT[] = "INSPECT";
    char ROLL[] = "ROLL";
    char SAVE[] = "SAVE";
    char ENDTURN[] = "ENDTURN";
    char UNDO[] = "UNDO";
    readInput();
    if (IsKataSama(CKata, SKILL)){
        CommandSkill();
    }
    else if (IsKataSama(CKata, MAP)){
        printf("MAP");
    }
    else if (IsKataSama(CKata, BUFF)){
        printf("BUFF");
    }
    else if (IsKataSama(CKata, INSPECT)){
        printf("INSPECT");
    }
    else if (IsKataSama(CKata, ROLL)){
        printf("ROLL");
    }
    else if (IsKataSama(CKata, SAVE)){
        printf("SAVE");
    }
    else if (IsKataSama(CKata, ENDTURN)){
        printf("ENDTURN");
    }
    else if (IsKataSama(CKata, UNDO)){
        printf("UNDO");
    }
}


void playerTurn(){

    printf("Saatnya turn player ke-%d\n", playerturn);
    Player P = SearchPlayerByPlayerNum(turn, playerturn);
    addrPlayer Pt = SearchPlayer(turn,P);
    printf("Posisi player: ");
    showPlayerPos(M, PLAYERPOS(Pt));
    insPlayerSkill(&turn, playerturn);
    cmdPlayer();
}


void newGame() {
	char name[100];
    int nPlayer;
	printf("Masukkan nama file konfigurasi permainan: ");
    scanf("%s", &name);
    inisialisasiMap(&(M));
    readMap(&M, name);
    CreateEmptyStack(&S);
    if (pita != NULL){
        printf("Berhasil memuat konfigurasi. Permainan dimulai!\n\n");
        printf("Konfigurasi player!\n");
        printf("Masukkan jumlah pemain: ");
        scanf("%d", &nPlayer);
        printf("\nMenambahkan player!");
        CreateRound(&turn);
        AddPlayerToGame(&turn, nPlayer);
        printf("\n%d Player telah ditambahkan!\n", nPlayer);
        playerturn = 1;
    }
}

void startGame(){
    printf("Pemain pada game ini adalah:\n");
    ShowPlayer(turn);
    playerTurn();
}