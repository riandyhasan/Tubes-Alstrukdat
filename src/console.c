/* Implementasi dari command */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "console.h"

Map M;
Stack S;
Queue Q;
State turn;
State dummy;
int playerturn = 1;
int ronde;
boolean endgame = false;
char namefile[100];

char* banner[]={"                                                                                                                               ",
                "@@@                                                                                                                         @@@",    
                "@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@  @@@@@",  
                "@!@!@!@!@                                                                                                             @!@!@!@!@",
                "!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!!  !!!!!",    
                ": :                                                                                                                         : :",   
                "@@@                                                                                                                         @@@",   
                "@@@                @@@@@@  @@@       @@@@@@ @@@@@@@ @@@@@@@  @@@  @@@ @@@  @@@ @@@@@@@  @@@@@@@@ @@@@@@  @@@@@@@            @@@",   
                "@@!               @@!  @@@ @@!      !@@       @!!   @@!  @@@ @@!  @@@ @@!  !@@ @@!  @@@ @@!     @@!  @@@ @@!  @@@           @@!",   
                "                  @!@!@!@! @!!       !@@!!    @!!   @!@!!@!  @!@  !@! @!@@!@!  @!@  !@! @!!!:!  @!@!@!@! @!@  !@!              ",   
                "!!!               !!:  !!! !!:          !:!   !!:   !!: :!!  !!:  !!! !!: :!!  !!:  !!! !!:     !!:  !!! !!:  !!!           !!!",   
                ":!:                :   : : : ::.: : ::.: :     :     :   : :  :.:: :   :   ::: :: :  :  : :: ::  :   : : :: :  :            :!:",   
                ": :                                                                                                                         : :",   
                "@@@                                                                                                                         @@@",   
                "@@@                  @@@@@@@@@@   @@@@@@  @@@@@@@  @@@ @@@@@@@ @@@@@@  @@@  @@@  @@@@@@@   @@@@@@@   @@@@@@                 @@@",   
                "@@!                  @@! @@! @@! @@!  @@@ @@!  @@@ @@!   @!!  @@!  @@@ @@!@!@@@ !@@       !@@       @@!  @@@                @@!",   
                "                     @!! !!@ @!@ @!@  !@! @!@!@!@  !!@   @!!  @!@!@!@! @!@@!!@! !@! @!@!@ !@! @!@!@ @!@!@!@!                   ",   
                "!!!                  !!:     !!: !!:  !!! !!:  !!! !!:   !!:  !!:  !!! !!:  !!! :!!   !!: :!!   !!: !!:  !!!                !!!",   
                ":!:                  :      :    : :. :  :: : ::  :      :    :   : : ::    :   :: :: :   :: :: :   :   : :                 :!:",   
                ": :                                                                                                                         : :",   
                "@@@                                                                                                                        @@@@",   
                "@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@ @@@!@@@@   @@@@",   
                "@!@!@!@!@                                                                                                             @!@!@!@!@", 
                "!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!! !!!:!!!!  !!!!!",    
                ": :                                                                                                                         : :"};

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

    printf("\n");
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

void newGame() {
    int nPlayer;
    printf("\n");
	printf("Masukkan nama file konfigurasi permainan: ");
    scanf("%s", &namefile);
    inisialisasiMap(&(M));
    readMap(&M, namefile);
    CreateEmptyStack(&S);
    if (pita != NULL){
        printLoading();
        printf("\n");
        printf("Berhasil memuat konfigurasi. Permainan dimulai!\n\n");
        printf("Konfigurasi player!\n");
        printf("Masukkan jumlah pemain: ");
        scanf("%d", &nPlayer);
        printf("\n");
        while (nPlayer < 1){
            printf("Masukkan jumlah pemain: ");
            scanf("%d", &nPlayer);
        }
        printf("Menambahkan player!\n");
        CreateRound(&turn);
        AddPlayerToGame(&turn, nPlayer);
        printf("%d Player telah ditambahkan!\n", nPlayer);
        printf("\n");
        playerturn = 1;
        ronde = 1;
        printf("\nPemain pada game ini adalah:\n");
        ShowPlayer(turn);
        printf("\n");
    }
}

void mainMenu(){
    int pil;
    printf("\n========================================================= MAIN MENU =========================================================\n");
    printf("\n");
    printf("                                                        %d. NEW GAME\n", 1);
    printf("                                                        %d. LOAD GAME\n", 2);
    printf("                                                  Masukkan pilihan (1/2): ");
    scanf("%d", &pil);
    while (pil != 1 && pil != 2){
        printf("Punten, inputnya masih gak sesuai!\n");
        printf("Masukkan pilihan (1/2): ");
        scanf("%d", &pil);
    }
    switch(pil){
        case 1:
            newGame();
            break;
        case 2:
            printf("Load game;\n");
            break;
    }
}

int roll(Player p){
    int maxN;
    maxN = MAXROLL(M);
    
    printf("\n");
    if (p.buff[2]){
        printf("Hoki kamu besar, roll akan menjadi lebih besar\n");
        printf("\n");
        srand (time(NULL));
        return (rand() % (maxN + 1 - (maxN/2))) + maxN/2;
    }
    else if (p.buff[3]){
        printf("Hoki kamu kecil, roll akan jadi lebih kecil\n");
        printf("\n");
        srand (time(NULL));
        return (rand() % (maxN/2)) + 1;
    }
    else if (!p.buff[2] && !p.buff[3]){
        srand (time(NULL));
        return (rand() % maxN) + 1;
    }
}


void endturn(State turn){
    Push(&S, turn);
    if ((playerturn + 1) > turn.nPlayer) {
        playerturn = (playerturn + 1) % turn.nPlayer;
        ronde ++;
    }
    else{
        printf("\n");
        playerturn ++;
    }
}

void undo(){
    State pop;
    if (ronde > 1){
        if (playerturn == 1){
            for (int i = 0; i < NPLAYER(InfoTop(S)); i++){
                Pop(&S, &turn);
            }
            ronde --;
        }
        else{
            for (int i = 0; i < playerturn; i++){
                Pop(&S, &turn);
            }
        }
        playerturn = 1;
        playerTurn(&turn);
    }else{
        if(playerturn > 1){
            for (int i = 0; i < playerturn; i++){
                Pop(&S, &turn);
            }
        }
        ResetStatePlayer(&turn);
        playerturn = 1;
        playerTurn(&turn);
        ronde = 1;
    }
}

void save(){
    char savefile[100];
    char *dir = "../bin/";
    char savedir[150];
    printf("Masukkan file name: ");
    scanf("%s", &savefile);
    strcpy(savedir, dir);
    strcat(savedir, savefile);
    FILE *f = fopen(savedir, "w");
    fprintf(f,"%s\n",namefile);
    fprintf(f,"%d\n",NPLAYER(turn));
    addrPlayer AP = FIRSTPLAYER(turn);
    for (int i = 0; i < NPLAYER(turn); i++){
        fprintf(f,"%d ",INFOPLAYER(AP->pemain));
        fprintf(f,"%s\n",NAME(AP->pemain));
        AP = NextPlayer(AP);
    }
    fprintf(f,"%d\n",ronde);
    fprintf(f,"%d\n",playerturn);
    // QueueSave();
    while(!IsEmptyQ(Q)){
        Del(&Q, &dummy);
        addrPlayer APS = FIRSTPLAYER(dummy);
        while(APS != Nil){
            fprintf(f,"%d ",INFOPLAYER(APS->pemain));
            for (int i = 0; i < 4; i++){
                fprintf(f,"%d ",(APS->pemain.buff[i]));
            }
            fprintf(f,"%d ",NbElmt(INFOSKILL(APS->pemain)));
            address skill;
            skill = First(INFOSKILL(APS->pemain));
            while (skill != Nil){
                fprintf(f,"%d ",Info_Skill(skill));
                skill = Next(skill);
            }
            APS = NextPlayer(APS);
        }
        fprintf(f, "\n");
    }    
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

            printf("\n");

            if ( Info_Skill(T) == 1){
                printf("%s memakai skill Pintu Ga Ke Mana Mana. Anda mendapatkan imunitas terhadap teleport!\n", NAME(*P));
                (*P).buff[0] = true;
                DelP (&INFOSKILL(*P), 1) ;
            }
            else if (Info_Skill(T) == 2){
                if ((*P).buff[1]) printf("Punten, %s telah memakai Cermin Pengganda sebelumnya! Jangan maruk ya :D\n", NAME(*P));
                else{
                    printf("%s memakai skill Cermin Pengganda. Skill ini akan dibuang digantikan dengan 2 skill baru.\n", NAME(*P));
                    (*P).buff[1] = true;
                    DelP (&INFOSKILL(*P), 2) ;
                    DoubleMirror(P);
                }
            }
            else if (Info_Skill(T) == 3){
                printf("%s memakai skill Senter Pembesar Hoki. Dadu hanya akan menghasilkan angka setengah dari MaxRoll hingga\n", NAME(*P));
                (*P).buff[2] = true;
                DelP (&INFOSKILL(*P), 3) ;
            }
            else if (Info_Skill(T) == 4){
                printf("%s memakai skill Senter Pengecil Hoki. Dadu hanya akan menghasilkan angka 1 hingga setengah dari MaxRoll\n", NAME(*P));
                (*P).buff[3] = true;
                DelP (&INFOSKILL(*P), 4) ;
            }
            else if (Info_Skill(T) == 5){
                UseTukarPosisiPlayer(&turn, playerturn) ;
                DelP (&INFOSKILL(*P), 5) ;
            }
            else if (Info_Skill(T) == 7){
                printf("%s memakai skill Mesin Waktu. Membuat player lain mundur :D\n", NAME(*P));
                UseMesinWaktu (P);
                DelP (&INFOSKILL(*P), 7) ;
            }
            else if (Info_Skill(T) == 8){
                printf("%s memakai skill Baling-Baling Jambu. Membuat player lain maju :D\n", NAME(*P));
                UseBalingBalingJambu (P);
                DelP (&INFOSKILL(*P), 8) ;
            }
            printf("\n");
        }
        else if (UseSkill < 0){

            for (i=1; i<(UseSkill*-1); i++){
                T = Next(T);
            }

            printf("\n");
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
            else if (Info_Skill(T) == 7){
                printf("%s membuang skill Mesin Waktu\n", NAME(*P));
                DelP (&INFOSKILL(*P), 7) ;
            }
            else if (Info_Skill(T) == 8){
                printf("%s membuang skill Baling-Baling Jambu.\n", NAME(*P));
                DelP (&INFOSKILL(*P), 8) ;
            }
        }
        else if (UseSkill == 0){
            return;
        }

        printf("\n");
    }
}

// void SwapPlayer (Player P1, Player P2, State *S){


// }

void teleportPlayer(Player P){
    addrPlayer AP = SearchPlayer(turn, P);
    if (IsTeleport(M.tele, PLAYERPOS(AP))){
        printf("%s menemukan teleporter.\n", NAME(P));
        if (P.buff[0]){
            char check;
            printf("Apakah %s ingin teleport(Y/N)? ", NAME(P));
            scanf("%c", &check);
            while (check != 'Y' && check != 'N') scanf("%c", &check);
            if (check == 'Y'){
                int tele = PetakOut(M.tele, PLAYERPOS(AP));
                printf("%s teleport ke petak %d\n", NAME(P), tele);
                ChangePlayerPosition(&AP, PetakOut(M.tele,PLAYERPOS(AP)));
            }
        }else{
            int tele = PetakOut(M.tele, PLAYERPOS(AP));
            printf("%s teleport ke petak %d\n", NAME(P), tele);
            ChangePlayerPosition(&AP, PetakOut(M.tele,PLAYERPOS(AP)));
        }
        printf("\n");
    }
}

void playerRoll(Player P){
    addrPlayer AP = SearchPlayer(turn, P);
    if (ROLLED(AP)){
        printf("Punten, kamu udah ngeroll! jangan maruk ya :D\n");
    }else{
        printRoll();
        int nRoll;
        nRoll = roll(P);
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
                teleportPlayer(P);
                printf("\n");
            }
            else{
                printf("%s tidak dapat bergerak! Sabar yaa:(\n", NAME(P));
                printf("\n");
            }
        }
        else{
            printf("%s dapat maju.\n", NAME(P));
            printf("%s maju %d langkah.\n", NAME(P), nRoll);
            ChangePlayerPosition(&AP, pos);
            printf("%s berada di petak %d.\n", NAME(P), PLAYERPOS(AP));
            teleportPlayer(P);
            printf("\n");
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
    printf("\n");
    while (!endgame){
        readInput();
        if (IsKataSama(CKata, SKILL)){
            CommandSkill(&P);
        }
        else if (IsKataSama(CKata, MAP)){
            printAllPos (M, turn);
        }
        else if (IsKataSama(CKata, BUFF)){
            printBuff(P);
        }
        else if (IsKataSama(CKata, INSPECT)){
            CmdInspect(M);
        }
        else if (IsKataSama(CKata, ROLL)){
            playerRoll(P);
        }
        else if (IsKataSama(CKata, SAVE)){
            save();
        }
        else if (IsKataSama(CKata, ENDTURN)){
            endturn(turn);
            playerTurn(&turn);
        }
        else if (IsKataSama(CKata, UNDO)){
            undo();
        }
        else {
            printf("Punten, input tidak sesuai! Silahkan input lagi\n");
        }
    }
    printf("\n");
}

void playerTurn(State *St){
    Player P = SearchPlayerByPlayerNum(*St, playerturn);
    addrPlayer Pt = SearchPlayer(*St,P);
    ROLLED(Pt) = false;
    printf("\n");
    printf("============ Ronde %d ============\n", ronde);
    printf("\n");
    printf("Giliran %s bermain!\n", NAME(P));
    printAllPos (M, turn);
    printf("\n");
    insPlayerSkill(&(Pt -> pemain));
    cmdPlayer();
}

void startGame(){
    playerTurn(&turn);
}



void UseMesinWaktu (Player *T){

    int maxN = MAXROLL(M);
    int rollresult;

    srand (time(NULL));
    rollresult = (rand() % maxN) + 1;
    
    // Player P;
    int X;

    // P = *T ;
    ShowPlayer(turn);
    printf("Pemain yang ingin dimundurkan : ");
    scanf("%d", &X);

    Player P2; 
    P2 = SearchPlayerByPlayerNum(turn, X);
    addrPlayer AP;
    AP = SearchPlayer(turn, P2);
    boolean same;

    while (isSamePlayer(*T, P2)){
        printf("Tidak dapat memajukan diri sendiri!\n");
        printf("Silahkan masukkan no pemain yang ingin dimajukan: ");
        scanf("%d", &X);
        P2 = SearchPlayerByPlayerNum(turn, X);
        addrPlayer AP = SearchPlayer(turn, P2);
    }

    printf("Hasil roll mendapatkan angka %d\n", rollresult);

    int pos = PLAYERPOS(AP) - rollresult;

    if (pos > M.mapConfig.Neff){
        pos = PLAYERPOS(AP) - rollresult;

        if (isForbidden(M, pos)){
            printf("%s Kamu tidak bergerak karena menemukan petak terlarang ! hohohooo\n", NAME(P2));
        }
        else{
            printf("%s akan mundur.\n", NAME(P2));
            printf("%s mundur %d langkah.\n", NAME(P2), rollresult);
            ChangePlayerPosition(&AP, pos);
            printf("%s berada di petak %d.\n", NAME(P2), PLAYERPOS(AP));

        }
    }
    else{ 
        if (pos <= 0){
            printf("Gerakan tidak sah ! kamu akan diam di tempat.\n") ;
        }
        else{
            if (isForbidden(M, pos)){
                printf("%s Kamu tidak bergerak karena menemukan petak terlarang ! hohohooo\n", NAME(P2));
            }
            else if(!isForbidden(M, pos)){
                
                printf("%s akan mundur.\n", NAME(P2));
                printf("%s mundur %d langkah.\n", NAME(P2), rollresult);
                ChangePlayerPosition(&AP, pos);
                printf("%s berada di petak %d.\n", NAME(P2), PLAYERPOS(AP));


                if (IsTeleport(M.tele, PLAYERPOS(AP))){
                    printf("%s menemukan teleporter.\n", NAME(P2));
                    if (P2.buff[0]){
                        char check;
                        printf("Apakah %s ingin teleport(Y/N)? ", NAME(P2));
                        scanf("%c", &check);
                        while (check != 'Y' && check != 'N') scanf("%c", &check);
                        if (check == 'Y'){
                            int tele = PetakOut(M.tele, PLAYERPOS(AP));
                            printf("%s teleport ke petak %d\n", NAME(P2), tele);
                            ChangePlayerPosition(&AP, PetakOut(M.tele,PLAYERPOS(AP)));
                        }
                    }else{
                        int tele = PetakOut(M.tele, PLAYERPOS(AP));
                        printf("%s teleport ke petak %d\n", NAME(P2), tele);
                        ChangePlayerPosition(&AP, PetakOut(M.tele,PLAYERPOS(AP)));
                    }
                    printf("\n");
                }

                ROLLED(AP) = true;
                if (PLAYERPOS(AP) == M.mapConfig.Neff) endgame = true;
            }
            else{
                printf("%s Kamu tidak bergerak karena menemukan petak terlarang ! hohohooo\n", NAME(P2));
            }
        }
    }
}


void UseBalingBalingJambu (Player *T){
    
    int maxN = MAXROLL(M);
    int rollresult;

    srand (time(NULL));
    rollresult = (rand() % maxN) + 1;
    
    // Player P;
    int X;

    // P = *T ;
    ShowPlayer(turn);
    printf("Pemain yang ingin dimajukan : ");
    scanf("%d", &X);

    Player P2; 
    P2 = SearchPlayerByPlayerNum(turn, X);
    addrPlayer AP;
    AP = SearchPlayer(turn, P2);
    boolean same;

    while (isSamePlayer(*T, P2)){
        printf("Tidak dapat memajukan diri sendiri!\n");
        printf("Silahkan masukkan no pemain yang ingin dimajukan: ");
        scanf("%d", &X);
        P2 = SearchPlayerByPlayerNum(turn, X);
        addrPlayer AP = SearchPlayer(turn, P2);
    }

    printf("Hasil roll mendapatkan angka %d\n", rollresult);

    int pos = PLAYERPOS(AP) + rollresult;

    if (pos > M.mapConfig.Neff){
        pos = PLAYERPOS(AP) - rollresult;

        if (isForbidden(M, pos)){
            printf("%s Kamu tidak bergerak karena menemukan petak terlarang ! hohohooo\n", NAME(P2));
        }
        else{
            printf("%s akan mundur.\n", NAME(P2));
            printf("%s mundur %d langkah.\n", NAME(P2), rollresult);
            ChangePlayerPosition(&AP, pos);
            printf("%s berada di petak %d.\n", NAME(P2), PLAYERPOS(AP));

        }
    }
    else{ 
        if (isForbidden(M, pos)){
            printf("%s Kamu tidak bergerak karena menemukan petak terlarang ! hohohooo\n", NAME(P2));
        }
        else if(!isForbidden(M, pos)){
            printf("%d\n", pos);
            
            printf("%s akan maju.\n", NAME(P2));
            printf("%s maju %d langkah.\n", NAME(P2), rollresult);
            ChangePlayerPosition(&AP, pos);
            printf("%s berada di petak %d.\n", NAME(P2), PLAYERPOS(AP));


            if (IsTeleport(M.tele, PLAYERPOS(AP))){
                printf("%s menemukan teleporter.\n", NAME(P2));
                if (P2.buff[0]){
                    char check;
                    printf("Apakah %s ingin teleport(Y/N)? ", NAME(P2));
                    scanf("%c", &check);
                    while (check != 'Y' && check != 'N') scanf("%c", &check);
                    if (check == 'Y'){
                        int tele = PetakOut(M.tele, PLAYERPOS(AP));
                        printf("%s teleport ke petak %d\n", NAME(P2), tele);
                        ChangePlayerPosition(&AP, PetakOut(M.tele,PLAYERPOS(AP)));
                    }
                }else{
                    int tele = PetakOut(M.tele, PLAYERPOS(AP));
                    printf("%s teleport ke petak %d\n", NAME(P2), tele);
                    ChangePlayerPosition(&AP, PetakOut(M.tele,PLAYERPOS(AP)));
                }
                printf("\n");
            }

            ROLLED(AP) = true;
            if (PLAYERPOS(AP) == M.mapConfig.Neff) endgame = true;
        }
        else{
            printf("%s Kamu tidak bergerak karena menemukan petak terlarang ! hohohooo\n", NAME(P2));
        }
    }
}


// void QueueSave(){
//     Stack dummyS;
//     CopyStack(&dummyS,S);
//     CreateEmptyQ(&Q, NElStack(S));
//     while(!IsEmptyStack(dummyS)){
//         Pop(&dummyS, &dummy);
//         Add(&Q, dummy);
//     }
// }