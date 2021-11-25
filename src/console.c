// implementasi dari command
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "console.h"
Map M;
Stack S;
State turn;
int playerturn = 1;
boolean endgame = false;

char* banner[]={"                                                                                                                              ",
                "@@@                                                                                                                        @@@",    
                "@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@   @@@",  
                "@!@!@!@!@                                                                                                                  @!@!@!@!@",
                "!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!!   !!!",    
                ": :                                                                                                                        : :",   
                "@@@                                                                                                                         @@@",   
                "@@@          @@@@@@  @@@       @@@@@@ @@@@@@@ @@@@@@@  @@@  @@@ @@@  @@@ @@@@@@@  @@@@@@@@ @@@@@@  @@@@@@@                  @@@",   
                "@@!         @@!  @@@ @@!      !@@       @!!   @@!  @@@ @@!  @@@ @@!  !@@ @@!  @@@ @@!     @@!  @@@ @@!  @@@                 @@!",   
                "            @!@!@!@! @!!       !@@!!    @!!   @!@!!@!  @!@  !@! @!@@!@!  @!@  !@! @!!!:!  @!@!@!@! @!@  !@!                    ",   
                "!!!         !!:  !!! !!:          !:!   !!:   !!: :!!  !!:  !!! !!: :!!  !!:  !!! !!:     !!:  !!! !!:  !!!                 !!!",   
                ":!:          :   : : : ::.: : ::.: :     :     :   : :  :.:: :   :   ::: :: :  :  : :: ::  :   : : :: :  :                  :!:",   
                ": :                                                                                                                         : :",   
                "@@@                                                                                                                         @@@",   
                "@@@         @@@@@@@@@@   @@@@@@  @@@@@@@  @@@ @@@@@@@ @@@@@@  @@@  @@@  @@@@@@@   @@@@@@@   @@@@@@                          @@@",   
                "@@!         @@! @@! @@! @@!  @@@ @@!  @@@ @@!   @!!  @@!  @@@ @@!@!@@@ !@@       !@@       @@!  @@@                         @@!",   
                "            @!! !!@ @!@ @!@  !@! @!@!@!@  !!@   @!!  @!@!@!@! @!@@!!@! !@! @!@!@ !@! @!@!@ @!@!@!@!                            ",   
                "!!!         !!:     !!: !!:  !!! !!:  !!! !!:   !!:  !!:  !!! !!:  !!! :!!   !!: :!!   !!: !!:  !!!                         !!!",   
                ":!:          :      :    : :. :  :: : ::  :      :    :   : : ::    :   :: :: :   :: :: :   :   : :                         :!:",   
                ": :                                                                                                                         : :",   
                "@@@                                                                                                                        @@@ ",   
                "@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@   @@@ ",   
                "@!@!@!@!@                                                                                                                  @!@!@!@!@", 
                "!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!!   !!!",    
                ": :                                                                                                                        : :"};

void printBanner(){
    for (int i = 0; i< 25; i++){
        printf("%s\n", banner[i]);
    }
}

void printLoading(){
    const int trigger = 500; // ms
    const int numDots = 4;
    const char prompt[] = "Loading";

    for (int i= 0; i < 3; i++) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
        fflush(stdout);

        // Print numDots number of dots, one every trigger milliseconds.
        for (int i = 0; i < numDots; i++) {
            usleep(trigger * 1000);
            fputc('.', stdout);
            fflush(stdout);
        }
    }
    printf("\n");
}

void printRoll(){
    const int trigger = 500; // ms
    const int numDots = 6;
    const char prompt[] = "Roll";

    // Return and clear with spaces, then return and print prompt.
    printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
    fflush(stdout);

    // Print numDots number of dots, one every trigger milliseconds.
    for (int i = 0; i < numDots; i++) {
        usleep(trigger * 1000);
        fputc('.', stdout);
        fflush(stdout);
    }
    printf("\n");
}

void mainMenu(){
    int pil;
    printf("================== MAIN MENU ========================\n");
    printf("%d. NEW GAME\n", 1);
    printf("%d. LOAD GAME\n", 2);
    printf("Masukkan pilihan (1/2): ");
    scanf("%d", &pil);
    switch(pil){
        case 1:
            newGame();
            break;
        case 2:
            printf("Load game;\n");
            break;
        default:
            printf("Punten, inputnya masih gak sesuai!\n");
            printf("Masukkan pilihan (1/2): ");
            scanf("%d", &pil);
    }
}

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
    if ((playerturn + 1) > turn.nPlayer) playerturn = (playerturn + 1) % turn.nPlayer;
    else playerturn ++;
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

void CommandSkill (Player *P){
/* mengeluarkan command untuk meminta masukkan skill yang ingin dipakai */

    int UseSkill, i;
    address T;
    PrintSkill(*P);

    T = First(INFOSKILL(*P));
    if (T != Nil){
        printf("Masukkan skill : ");
        scanf("%d", &UseSkill);
        if ( UseSkill > 0){
            
            for (i=1; i<UseSkill; i++){
                T = Next(T);
            }

            if ( Info_Skill(T) == 1){
                printf("%s memakai skill Pintu Ga Ke Mana Mana. Anda mendapatkan imunitas terhadap teleport!\n", NAME(*P));
                (*P).buff[0] = true;
                DelP (&INFOSKILL(*P), 1) ;
            }
            else if (Info_Skill(T) == 2){
                printf("%s memakai skill Cermin Pengganda. Skill ini akan dibuang digantikan dengan 2 skill baru.\n", NAME(*P));
                (*P).buff[1] = true;
                DelP (&INFOSKILL(*P), 2) ;
                DoubleMirror(P);
            }
            else if (Info_Skill(T) == 3){
                printf("%s memakai skill Senter Pembesar Hoki. Dadu hanya akan menghasilkan angka MaxRoll atau setengah dari MaxRoll\n", NAME(*P));
                (*P).buff[2] = true;
                DelP (&INFOSKILL(*P), 3) ;
            }
            else if (Info_Skill(T) == 4){
                printf("%s memakai skill Senter Pengecil Hoki. Dadu hanya akan menghasilkan angka 0 atau setengah dari MaxRoll\n", NAME(*P));
                (*P).buff[3] = true;
                DelP (&INFOSKILL(*P), 4) ;
            }
            else if (Info_Skill(T) == 5){
                UseTukarPosisiPlayer(&turn, playerturn) ;
                DelP (&INFOSKILL(*P), 5) ;
            }
        }
        else if (UseSkill < 0){

            for (i=1; i<(UseSkill*-1); i++){
                T = Next(T);
            }

            if (Info_Skill(T) == 1){
                printf("%s membuang skill Pintu Ga Ke Mana Mana.\n", NAME(*P));
                DelP (&INFOSKILL(*P), 1) ;
            }
            else if (Info_Skill(T) == 2){
                printf("%s membuang skill Cermin Pengganda.\n", NAME(*P));
                DelP (&INFOSKILL(*P), 2) ;
            }
            else if (Info_Skill(T) == 3){
                printf("%s membuang skill Senter Pembesar Hoki.\n", NAME(*P));
                DelP (&INFOSKILL(*P), 3) ;
            }
            else if (Info_Skill(T) == 4){
                printf("%s membuang skill Senter Pengecil Hoki.\n", NAME(*P));
                DelP (&INFOSKILL(*P), 4) ;
            }
            else if (Info_Skill(T) == 5){
                printf("%s membuang skill Mesin Penukar Posisi.\n", NAME(*P));
                DelP (&INFOSKILL(*P), 5) ;
            }
        }
        else if (UseSkill == 0){
            return;
        }
    }
}

// void SwapPlayer (Player P1, Player P2, State *S){


// }

void playerRoll(){
    Player P = SearchPlayerByPlayerNum(turn, playerturn);
    addrPlayer AP = SearchPlayer(turn, P);
    if (ROLLED(AP)){
        printf("Punten, kamu udah ngeroll! jangan maruk ya :D\n");
    }else{
        printRoll();
        int nRoll;
        nRoll = roll();
        int pos = PLAYERPOS(AP) + nRoll;
        if (pos > M.mapConfig.Neff) pos = pos % M.mapConfig.Neff;
        printf("%s mendapatkan angka %d\n", NAME(P), nRoll);
        if (isForbidden(M, pos)){
            pos = PLAYERPOS(AP) - nRoll;
            if (pos < 0) pos = (PLAYERPOS(AP) + nRoll) % M.mapConfig.Neff;
            if(!isForbidden(M, pos)){
                printf("%s akan mundur.\n", NAME(P));
                printf("%s mundur %d langkah.\n", NAME(P), nRoll);
                ChangePlayerPosition(&AP, pos);
                printf("%s berada di petak %d.\n", NAME(P), PLAYERPOS(AP));
                if (IsTeleport(M.tele, PLAYERPOS(AP))){
                    printf("%s menemukan teleporter.\n", NAME(P));
                    printf("%s teleport ke petak %d\n", NAME(P), PetakOut(M.tele, PLAYERPOS(AP)));
                    ChangePlayerPosition(&AP, PetakOut(M.tele,PLAYERPOS(AP)));
                }
            }
            else{
                printf("%s tidak dapat bergerak! Sabar yaa:(\n", NAME(P));
            }
        }
        else{
            printf("%s dapat maju.\n", NAME(P));
            printf("%s maju %d langkah.\n", NAME(P), nRoll);
            ChangePlayerPosition(&AP, pos);
            printf("%s berada di petak %d.\n", NAME(P), PLAYERPOS(AP));
            if (IsTeleport(M.tele, PLAYERPOS(AP))){
                printf("%s menemukan teleporter.\n", NAME(P));
                printf("%s teleport ke petak %d\n", NAME(P), PetakOut(M.tele, PLAYERPOS(AP)));
                ChangePlayerPosition(&AP, PetakOut(M.tele,PLAYERPOS(AP)));
            }
        }

        ROLLED(AP) = true;
        if (PLAYERPOS(AP) == M.mapConfig.Neff) endgame = true;
    }
}


void cmdPlayer(){
    char MAP[] = "MAP";
    char SKILL[] = "SKILL";
    char BUFF[] = "BUFF";
    char INSPECT[] = "INSPECT";
    char ROLL[] = "ROLL";
    char SAVE[] = "SAVE";
    char ENDTURN[] = "ENDTURN";
    char UNDO[] = "UNDO";
    Player P = SearchPlayerByPlayerNum(turn, playerturn);
    addrPlayer AP = SearchPlayer(turn, P);
    while (!endgame){
    readInput();
    if (IsKataSama(CKata, SKILL)){
        CommandSkill(&P);
    }
    else if (IsKataSama(CKata, MAP)){
        printf("Posisi player: ");
        showPlayerPos(M, PLAYERPOS(AP));
    }
    else if (IsKataSama(CKata, BUFF)){
        printBuff(P);
    }
    else if (IsKataSama(CKata, INSPECT)){
        CmdInspect(M);
    }
    else if (IsKataSama(CKata, ROLL)){
        playerRoll();
    }
    else if (IsKataSama(CKata, SAVE)){
        printf("SAVE");
    }
    else if (IsKataSama(CKata, ENDTURN)){
        endturn(turn);
        playerTurn(&turn);
    }
    else if (IsKataSama(CKata, UNDO)){
        printf("UNDO");
    }
    else printf("Punten, input tidak sesuai! Silahkan input lagi\n");
    }
}


void playerTurn(State *St){
    Player P = SearchPlayerByPlayerNum(*St, playerturn);
    addrPlayer Pt = SearchPlayer(*St,P);
    ROLLED(Pt) = false;
    printf("Giliran %s bermain!\n", NAME(P));
    printf("Posisi player: ");
    showPlayerPos(M, PLAYERPOS(Pt));
    insPlayerSkill(&(Pt -> pemain));
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
        printLoading();
        printf("Berhasil memuat konfigurasi. Permainan dimulai!\n\n");
        printf("Konfigurasi player!\n");
        printf("Masukkan jumlah pemain: ");
        scanf("%d", &nPlayer);
        printf("Menambahkan player!\n");
        CreateRound(&turn);
        AddPlayerToGame(&turn, nPlayer);
        printf("%d Player telah ditambahkan!\n", nPlayer);
        playerturn = 1;
        printf("\nPemain pada game ini adalah:\n");
        ShowPlayer(turn);
        printf("\n");
    }
}

void startGame(){
    playerTurn(&turn);
}