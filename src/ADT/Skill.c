#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listlinier.h"
#include "skill.h"
#include "state.h"
#include "player.h"

/****************** PROSES GET SKILL MELALUI RANDOMIZER ******************/

int printRandoms(int lower, int upper, int count)
{
    int i, num;

    srand(time(0));

    for (i = 0; i < count; i++) {
        num = (rand() % (upper - lower + 1)) + lower;
    }

    return num ;
}


int GetSkills (){

    /* 
    1 : Pintu Ga Ke Mana Mana
    2 : Cermin Pengganda
    3 : Senter Pembesar Hoki
    4 : Senter Pengecil Hoki
    5 : Mesin Penukar Posisi
    6 : Teknologi Gagal*/

    int TabSkill[100];
    int i, SkillDrop, SkillGet ;

    i = 0;

    while (i < 100){

        if ((i >= 0) && (i <= 15)){
            TabSkill[i] = 1 ;
        }
        else if ((i >= 16) && (i <= 23)){
            TabSkill[i] = 2 ;
        }
        else if ((i >= 24) && (i <= 43)){
            TabSkill[i] = 3 ;
        }
        else if ((i >= 44) && (i <= 63)){
            TabSkill[i] = 4 ;
        }
        else if ((i >= 64) && (i <= 68)){
            TabSkill[i] = 5 ;
        }
        else if ((i >= 69) && (i <= 99)){
            TabSkill[i] = 6 ;
        }

        i++ ;
    }

    SkillDrop = printRandoms(0, 100, 1);
    SkillGet = TabSkill[SkillDrop];

    return SkillGet;
}

void insPlayerSkill (Player *P){

    int X ;

    X = GetSkills() ;

    if (X == 6){
        /*DO NOTHING*/
        printf("Maaf, anda kurang beruntung :D\n");
    }
    else{
        InsVLast (&INFOSKILL(*P), X);

        if (X == 1){
            printf("Pintu Ga Ke Mana Mana berhasil dimasukkan ke dalam list!\n");
        }
        else if (X == 2){
            printf("Cermin Pengganda berhasil dimasukkan ke dalam list!\n");
        }
        else if (X == 3){
            printf("Senter Pembesar Hoki berhasil dimasukkan ke dalam list!\n");
        }
        else if (X == 4){
            printf("Senter Pengecil Hoki berhasil dimasukkan ke dalam list!\n");
        }
        else if (X == 5){
            printf("Mesin Penukar Posisi berhasil dimasukkan ke dalam list!\n");
        }
    }
}


/****************** PROSES SKILL ******************/

void PrintSkill (Player P){
/* mengeluarkan list skill yang dimiliki player */

    int i;
    address T;

    T = First(INFOSKILL(P));
    i = 1;

    if (T == Nil){
        printf("Kamu gapunya skill apa apa, Kasian banget :(\n");
    }
    else{

        while (T != Nil){
            printf("%d. ", i);

            if (Info_Skill(T) == 1){
                printf("Pintu Ga Ke Mana Mana\n");
            }
            else if (Info_Skill(T) == 2){
                printf("Cermin Pengganda\n");
            }
            else if (Info_Skill(T) == 3){
                printf("Senter Pembesar Hoki\n");
            }
            else if (Info_Skill(T) == 4){
                printf("Senter Pengecil Hoki\n");
            }
            else if (Info_Skill(T) == 5){
                printf("Mesin Penukar Posisi\n");
            }

            T = Next(T);
            i++ ;

            printf("\n");
        }
    }

    printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.");
}


void CommandSkill (Player *P){
/* mengeluarkan command untuk meminta masukkan skill yang ingin dipakai */

    int UseSkill, i;
    address T;

    T = First(INFOSKILL(*P));

    printf("Masukkan skill : ");
    scanf("%d", &UseSkill);

    if ( UseSkill > 0){
        
        for (i=1; i<UseSkill; i++){
            T = Next(T);
        }

        if ( Info_Skill(T) == 1){
            printf("%d memakai skill Pintu Ga Ke Mana Mana. Anda mendapatkan imunitas terhadap teleport!\n", INFOPLAYER(*P));
            BUFF(INFOBUFF(*P))[0] = true;
            DelP (&INFOSKILL(*P), 1) ;
        }
        else if (Info_Skill(T) == 2){
            printf("%d memakai skill Cermin Pengganda. Skill ini akan dibuang digantikan dengan 2 skill baru.\n", INFOPLAYER(*P));
            BUFF(INFOBUFF(*P))[1] = true;
            DelP (&INFOSKILL(*P), 2) ;
        }
        else if (Info_Skill(T) == 3){
            printf("%d memakai skill Senter Pembesar Hoki. Dadu hanya akan menghasilkan angka MaxRoll atau setengah dari MaxRoll\n", INFOPLAYER(*P));
            BUFF(INFOBUFF(*P))[2] = true;
            DelP (&INFOSKILL(*P), 3) ;
        }
        else if (Info_Skill(T) == 4){
            printf("%d memakai skill Senter Pengecil Hoki. Dadu hanya akan menghasilkan angka 0 atau setengah dari MaxRoll\n", INFOPLAYER(*P));
            BUFF(INFOBUFF(*P))[3] = true;
            DelP (&INFOSKILL(*P), 4) ;
        }
        else if (Info_Skill(T) == 5){
            printf("%d memakai skill Mesin Penukar Posisi.\n", INFOPLAYER(*P));
            // Tukar Posisi
            DelP (&INFOSKILL(*P), 5) ;
        }
    }
    else if (UseSkill < 0){

        for (i=1; i<(UseSkill*-1); i++){
            T = Next(T);
        }

        if (Info_Skill(T) == 1){
            printf("%d membuang skill Pintu Ga Ke Mana Mana.\n", INFOPLAYER(*P));
            DelP (&INFOSKILL(*P), 1) ;
        }
        else if (Info_Skill(T) == 2){
            printf("%d membuang skill Cermin Pengganda.\n", INFOPLAYER(*P));
            DelP (&INFOSKILL(*P), 2) ;
        }
        else if (Info_Skill(T) == 3){
            printf("%d membuang skill Senter Pembesar Hoki.\n", INFOPLAYER(*P));
            DelP (&INFOSKILL(*P), 3) ;
        }
        else if (Info_Skill(T) == 4){
            printf("%d membuang skill Senter Pengecil Hoki.\n", INFOPLAYER(*P));
            DelP (&INFOSKILL(*P), 4) ;
        }
        else if (Info_Skill(T) == 5){
            printf("%d membuang skill Mesin Penukar Posisi.\n", INFOPLAYER(*P));
            DelP (&INFOSKILL(*P), 5) ;
        }
    }
    else if (UseSkill == 0){
        return;
    }
}

void TukarPosisiPlayer (Player P1, Player P2, State *S){

    int temp;
    addrPlayer Plyr1, Plyr2;

    Plyr1 = SearchPlayer(*S, P1);
    temp = PLAYERPOS(Plyr1);

    Plyr2 = SearchPlayer(*S, P2);

    ChangePlayerPosition (S, P1, PLAYERPOS(Plyr2));
    ChangePlayerPosition (S, P2, temp);

}

void DoubleMirror(Player *P){
    
    List X;
    int i;

    X = INFOSKILL(*P);

    if (NbElmt(X) < 9){
        DelP(&X, 2);

        for (i=0; i=1; i++){
            insPlayerSkill(P);
        }
    }
    else{
        printf("Kamu tidak memiliki space cukup untuk skill ini. Skill terhapus dan kamu tidak mendapat apa apa !\n");
    }
}