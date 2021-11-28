/* Implementasi dari command */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "console.h"

Map M;
Stack S;
State turn;
State dummy;
int playerturn = 1;
int ronde = 1;
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
    const int trigger = 300; // ms
    const int numDots = 4;
    const char prompt[] = "Loading";

    for (int i= 0; i < 3; i++) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
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


void printLoadGame(){
    const int trigger = 400; // ms
    const int numDots = 5;
    const char prompt[] = "Loading Data Game";

    for (int i= 0; i < 3; i++) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
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

void printConLoad(){
    const int trigger = 300; // ms
    const int numDots = 3;
    const char prompt[] = "Memuat data player";

    for (int i= 0; i < 3; i++) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
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
    const int trigger = 300; // ms
    const int numDots = 6;
    const char prompt[] = "Roll";

    printf("\n");
    // Return and clear with spaces, then return and print prompt.
    printf("\r%s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
    fflush(stdout);

    // Print numDots number of dots, one every trigger milliseconds.
    for (int i = 0; i < numDots; i++) {
        usleep(trigger * 1000);
        fputc('.', stdout);
        fflush(stdout);
    }
    printf("\n");
}

void endGame(Player P){
    printf("\n==================== SELAMAT TELAH MENAMATKAN MOBITANGGA ====================\n");
    printf("==================== %s MENJADI JUARA PERMAINAN INI\n ====================", NAME(P));
    printf("Urutan pemain pada game ini: \n");
    addrPlayer AP = SearchPlayer(turn, P);
    int akhir = PLAYERPOS(AP);
    int i = 1;
    printf("%d. %s - Posisi Akhir: %d\n", i, NAME(P), akhir);
    while (i <= NPLAYER(turn)){
        addrPlayer AP = FIRSTPLAYER(turn);
        int temp = PLAYERPOS(AP);
        while (AP != Nil){
            if (temp != akhir && temp < PLAYERPOS(AP)) temp = PLAYERPOS(AP);
            AP = NextPlayer(AP);
        }
        addrPlayer print = FIRSTPLAYER(turn);
        while (print != Nil){
            if (PLAYERPOS(AP) == temp){
                i++;
                printf("%d. %s - Posisi Akhir: %d\n", i, NAME(AP -> pemain), PLAYERPOS(AP));
            }
            print = NextPlayer(print);
        }
        akhir = temp;
    }

}

void newGame() {
    int nPlayer;
    printf("\n");
	printf("Masukkan nama file konfigurasi permainan: ");
    scanf("%s", namefile);
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
        playerTurn(&turn);
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
            loadGame();
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
    if (playerturn == turn.nPlayer) {
        ResetAllPlayerBuff(&turn);
        Push(&S, turn);
        ronde ++;
        playerturn = 1;
    }
    else{
        printf("\n");
        playerturn ++;
    }
}

void undo(){
    // State pop;
    if (ronde > 2){
        if (playerturn == 1){
            Pop(&S, &turn);
            Pop(&S, &turn);
            Push(&S, turn);
        }else{
            Pop(&S, &turn);
            Push(&S, turn);
        }
        // ShowPlayer(pop);
        // PushState(&turn, pop);
        playerturn = 1;
        ronde --;
        playerTurn(&turn);
    }else{
        if (ronde == 2){
            if (playerturn == 1){
                Pop(&S, &turn);
                ResetStatePlayer(&turn);
            }else{
                Pop(&S, &turn);
                Push(&S, turn);
            }
            playerturn = 1;
            ronde = 1;
            playerTurn(&turn);
        }else{
            ResetStatePlayer(&turn);
            playerturn = 1;
            ronde = 1;
            playerTurn(&turn);
        }
        
    }
}

void save(){
    char savefile[100];
    char *dir = "../bin/";
    char savedir[150];
    Push(&S, turn);
    printf("Masukkan file name: ");
    scanf("%s", savefile);
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
    Stack dummy;
    CopyStack(&dummy, S);
    int nel = NElStack(dummy);
    State ss[nel];
    int i = 0;
    while (!IsEmptyStack(dummy)){
        ss[i] = InfoTop(dummy);
        State del;
        Pop(&dummy, &del);
        i++;
    }
    fprintf(f,"%d\n",nel);
    for (int j = 0;j <nel;j++){
        addrPlayer APS = FIRSTPLAYER(ss[j]);
        while(APS != Nil){
            fprintf(f,"%d ",INFOPLAYER(APS->pemain));
            
            for (int i = 0; i < 4; i++){
                if (APS->pemain.buff[i]) fprintf(f,"%d ",1);
                else fprintf(f,"%d ",0);
            }
            
            fprintf(f,"%d ",NbElmt(INFOSKILL(APS->pemain)));
            
            address skill;
            skill = First(INFOSKILL(APS->pemain));
            
            while (skill != Nil){
                fprintf(f,"%d ",Info_Skill(skill));
                skill = Next(skill);
            }
            fprintf(f,"%d",PLAYERPOS(APS));
            APS = NextPlayer(APS);
            fprintf(f, "\n");
        }

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
                if ((*P).buff[2] ||  (*P).buff[3]) printf("Punten, kamu udah punya buff roll! Jangan maruk ya :D\n");
                else{
                    printf("%s memakai skill Senter Pembesar Hoki. Dadu hanya akan menghasilkan angka setengah dari MaxRoll hingga\n", NAME(*P));
                    (*P).buff[2] = true;
                    DelP (&INFOSKILL(*P), 3);
                }
            }
            else if (Info_Skill(T) == 4){
                if ((*P).buff[2] ||  (*P).buff[3]) printf("Punten, kamu udah punya buff roll! Jangan maruk ya :D\n");
                else{
                    printf("%s memakai skill Senter Pengecil Hoki. Dadu hanya akan menghasilkan angka 1 hingga setengah dari MaxRoll\n", NAME(*P));
                    (*P).buff[3] = true;
                    DelP (&INFOSKILL(*P), 4) ;
                }
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

void printAllPos (){
    printf("Posisi player: \n");

    addrPlayer AP = FIRSTPLAYER(turn);
    while (AP != Nil){
        printf("%s : ", NAME(AP -> pemain));
        showPlayerPos(M, PLAYERPOS(AP));
        AP = NextPlayer(AP);
    }
}

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
        printf("%s mendapatkan angka %d\n", NAME(P), nRoll);
        int pos = PLAYERPOS(AP) + nRoll;
        if (pos > M.mapConfig.Neff) {
            pos = PLAYERPOS(AP) - nRoll;
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
            if(isForbidden(M, pos)){
                pos = PLAYERPOS(AP) - nRoll;
                if ( pos > 0 && !isForbidden(M, pos)){
                    printf("%s akan mundur.\n", NAME(P));
                    printf("%s mundur %d langkah.\n", NAME(P), nRoll);
                    ChangePlayerPosition(&AP, pos);
                    printf("%s berada di petak %d.\n", NAME(P), PLAYERPOS(AP));
                    teleportPlayer(P);
                    printf("\n");
                }else{
                    printf("%s tidak dapat bergerak! Sabar yaa:(\n", NAME(P));
                    printf("\n");
                    }
                }
            else{
                if ( pos == M.mapConfig.Neff &&(PLAYERPOS(AP) - nRoll > 0) && !isForbidden(M, PLAYERPOS(AP) - nRoll)){
                    printf("%s dapat maju dan mundur.\n", NAME(P));
                    printf("Ke mana %s mau bergerak:\n", NAME(P));
                    printf("%d. %d", 1, pos);
                    printf("%d. %d", 2, PLAYERPOS(AP) - nRoll);
                    int pil;
                    printf("Masukkan pilihan: ");
                    scanf("%d", &pil);
                    while(pil != 1 && pil != 2){
                        printf("Input tidak sesuai!\n");
                        printf("Masukkan pilihan: ");
                        scanf("%d", &pil);
                    }
                    if (pil == 1)  ChangePlayerPosition(&AP, pos);
                    else ChangePlayerPosition(&AP, PLAYERPOS(AP) - nRoll);
                    teleportPlayer(P);
                }
                printf("%s dapat maju.\n", NAME(P));
                printf("%s maju %d langkah.\n", NAME(P), nRoll);
                ChangePlayerPosition(&AP, pos);
                printf("%s berada di petak %d.\n", NAME(P), PLAYERPOS(AP));
                teleportPlayer(P);
                printf("\n");
            }
        }
        ROLLED(AP) = true;
        if (PLAYERPOS(AP) == M.mapConfig.Neff) {
            endgame = true;
            endGame(AP -> pemain);
        }
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
            printAllPos ();
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
            if (!ROLLED(AP)) printf("Punten a, roll dulu\n");
            else{
                save();
            }
        }
        else if (IsKataSama(CKata, ENDTURN)){
            endturn(turn);
            playerTurn(&turn);
        }
        else if (IsKataSama(CKata, UNDO)){
            undo();
        }
        else {
            printf("Punten, input tidak sesuai!\n");
            printf("Command yang bisa dipakai: SKILL, MAP, BUFF, INSPECT, ROLL, SAVE, ENDTURN, UNDO\n");
            printf("Silahkan input lagi!\n");
        }
    }
    printf("\n");
}

void playerTurn(State *St){
    Player P = SearchPlayerByPlayerNum(*St, playerturn);
    addrPlayer Pt = SearchPlayer(*St,P);
    ROLLED(Pt) = false;
    printf("\n");
    if (playerturn == 1)printf("=============== Ronde %d ===============\n", ronde);
    printf("\n");
    printf("========== Giliran %s bermain! ==========\n", NAME(P));
    printAllPos ();
    printf("\n");
    insPlayerSkill(&(Pt -> pemain));
    cmdPlayer();
}

void playerTurnLoad(State *St){
    Player P = SearchPlayerByPlayerNum(*St, playerturn);
    addrPlayer Pt = SearchPlayer(*St,P);
    ROLLED(Pt) = true;
    printf("\n");
    if (playerturn == 1)printf("=============== Ronde %d ===============\n", ronde);
    printf("\n");
    printf("========== Giliran %s bermain! ==========\n", NAME(P));
    printAllPos ();
    printf("\n");
    cmdPlayer();
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
        printf("Tidak dapat memundurkan diri sendiri!\n");
        printf("Silahkan masukkan no pemain yang ingin dimundurkan: ");
        scanf("%d", &X);
        P2 = SearchPlayerByPlayerNum(turn, X);
        addrPlayer AP = SearchPlayer(turn, P2);
    }

    printf("Hasil roll mendapatkan angka %d\n", rollresult);

    int pos = PLAYERPOS(AP) - rollresult;

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
                        printf("%s memiliki imunitas teleport.\n", NAME(P2));
                        printf("Apakah %s ingin teleport(Y/N)? ", NAME(P2));
                        scanf("%c", &check);
                        while (check != 'Y' && check != 'N') scanf("%c", &check);
                        if (check == 'Y'){
                            int tele = PetakOut(M.tele, PLAYERPOS(AP));
                            printf("%s teleport ke petak %d\n", NAME(P2), tele);
                            ChangePlayerPosition(&AP, PetakOut(M.tele,PLAYERPOS(AP)));
                        }else if (check == 'N'){
                            printf("%s tidak teleport.\n", NAME(P2));
                            printf("Buff imunitas teleport hilang.\n");
                            (AP -> pemain).buff[0] = false;
                        }
                    }else{
                        int tele = PetakOut(M.tele, PLAYERPOS(AP));
                        printf("%s teleport ke petak %d\n", NAME(P2), tele);
                        ChangePlayerPosition(&AP, PetakOut(M.tele,PLAYERPOS(AP)));
                    }
                    printf("\n");
                }
                if (PLAYERPOS(AP) == M.mapConfig.Neff) {
                    endgame = true;
                    endGame(AP -> pemain);
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
            
            if (pos == M.mapConfig.Neff && (PLAYERPOS(AP) - rollresult > 0) && !isForbidden(M, PLAYERPOS(AP) - rollresult)){
                printf("%s dapat maju dan mundur.\n", NAME(P2));
                printf("Ke mana %s mau bergerak:\n", NAME(P2));
                printf("%d. %d", 1, pos);
                printf("%d. %d", 2, PLAYERPOS(AP) - rollresult);
                
                int pil;
                printf("Masukkan pilihan: ");
                scanf("%d", &pil);
                
                while(pil != 1 && pil != 2){
                    printf("Input tidak sesuai!\n");
                    printf("Masukkan pilihan: ");
                    scanf("%d", &pil);
                }
                
                if (pil == 1){
                    ChangePlayerPosition(&AP, pos);
                }
                else{
                    ChangePlayerPosition(&AP, PLAYERPOS(AP) - rollresult);
                    teleportPlayer(P2);
                }
            }
            else{

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
                if (PLAYERPOS(AP) == M.mapConfig.Neff){
                    endgame = true;
                    endGame(AP -> pemain);
                }
            }
        }
        else{
            printf("%s Kamu tidak bergerak karena menemukan petak terlarang ! hohohooo\n", NAME(P2));
        }    
    }
}


void loadGame(){
    char loadfile[100];
    printf("Masukkan file name: ");
    scanf("%s", loadfile);
    STARTLOADFILE(loadfile);
    char copyy[LoadKata.Length];
    for (int i = 0; i < LoadKata.Length; i++){
        copyy[i] = LoadKata.TabKata[i+1];
    }
    printLoadGame();
    printf("\n");
    printf("Berhasil memuat data game. Permainan dimulai!\n\n");
    strcpy(namefile, copyy);
    inisialisasiMap(&(M));
    readMap(&M, namefile);
    if (pitaload != NULL){
        printLoading();
        printf("\n");
        printf("Berhasil memuat konfigurasi. Permainan dimulai!\n\n");
        printf("Konfigurasi player!\n");
        printConLoad();
        ADVKATALOAD();
        int nPlayer = KataToInt(LoadKata);
        printf("%d\n", nPlayer);
        CreateRound(&turn);
        LoadPlayerToGame(&turn, nPlayer);
        printf("\nPemain pada game ini adalah:\n");
        ShowPlayer(turn);
        printf("\n");
        ADVKATALOAD();
        ronde = KataToInt(LoadKata);
        ADVKATALOAD();
        playerturn = KataToInt(LoadKata);
        ADVKATALOAD();
        int n = KataToInt(LoadKata);
        CreateEmptyStack(&S);
        for (int i = 0; i < n; i++) {
            addrPlayer P;
            P = FIRSTPLAYER(turn);
            while(P != Nil){
                ADVKATALOAD();
                for (int j = 0; j < 4; j++) {
                    ADVKATALOAD();
                    (P -> pemain).buff[i] = KataToInt(LoadKata);
                }
                ADVKATALOAD();
                int nskill = KataToInt(LoadKata);
                CreateEmptyList(&INFOSKILL(P -> pemain));
                for (int k = 0; k < nskill; k++) {
                    ADVKATALOAD();
                    int info = KataToInt(LoadKata);
                    InsVLast(&INFOSKILL(P -> pemain), info);
                }
                ADVKATALOAD();
                int pos = KataToInt(LoadKata);
                PLAYERPOS(P) = pos;
                P = NextPlayer(P);
            }
            Push(&S, turn);
        }
        printf("Berhasil memuat game!\n");
        playerTurnLoad(&turn);
    }
}