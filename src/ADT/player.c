#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

void CreatePlayer(Player *p, char *name, int id){
    List skill;
    boolean buff[4];
    CreateEmptyList(&skill);
    resetBuff(&buff);
    INFOPLAYER(*p) = id;
    strcpy(NAME(*p),name);
    printf("Nama pemain: %s\n", NAME(*p));
    INFOSKILL(*p) = skill;
}


boolean isSamePlayer(Player p1, Player p2){
    return INFOPLAYER(p1) == INFOPLAYER(p2) && NAME(p1) == NAME(p2);
}

/******************************* BUFF *******************************/

void printBuff (boolean b[4]) {
/* mengeluarkan list Buff yang dimiliki player */
    for (int i = 0; i < 4; i++) {
        if (b[0]) {
            printf("Anda mendapatkan buff imunitas teleport. Anda tidak akan kemana-mana.");
        }
        else if (b[1]) {
            printf("Anda mendapatkan buff cermin pengganda. Selamat, anda bisa mendapatkan 2 skill baru!");
        }
        else if (b[2]) {
            printf("Anda mendapatkan buff senter pembesar hoki. Selamat, hoki anda jadi besar!");
        }
        else if (b[3]) {
            printf("Anda mendapatkan buff senter pengecil hoki. Anda kurang beruntung, Player.");
        }
    }
}

void resetBuff (boolean (*b)[4]) {
/* me-reset seluruh buff kecuali imunitas teleport setiap ronde
(karena buff hanya berlaku sekali di suatu ronde) */
    for (int i = 0; i < 4; i++) {
        (*b)[i] = false;
    }
}

/****************** SKILL ******************/

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
