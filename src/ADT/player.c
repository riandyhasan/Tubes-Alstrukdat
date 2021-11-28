#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

void CreatePlayer(Player *p, char *name, int id){
    List skill;
    CreateEmptyList(&skill);
    resetBuff(p);
    INFOPLAYER(*p) = id;
    strcpy(NAME(*p),name);
    INFOSKILL(*p) = skill;
}


boolean isSamePlayer(Player p1, Player p2){
    return INFOPLAYER(p1) == INFOPLAYER(p2);
}

void ResetPlayer(Player *P){
    CreateEmptyList(&INFOSKILL(*P));
    resetBuff(P);
}

/******************************* BUFF *******************************/


int countBuff (Player P){
    int count = 0;
    for (int i=0; i<4;i++){
        if (P.buff[i]) count++;
    }
    return count;
}


void printBuff (Player P) {
/* mengeluarkan list Buff yang dimiliki player */
    int pbuff = countBuff(P);
    printf("\n");
    if (pbuff == 0) printf("%s tidak memiliki buff!\n", NAME(P));
    else{
        printf ("%s memiliki buff:\n", NAME(P));

        int i = 1;
        while (i <= pbuff){
            for (int j = i-1;j < 4; j++){
                if (P.buff[j]){
                    if (j == 0){
                        printf("%d. ", i);
                        printf("Imunitas teleport. Anda tidak akan kemana-mana.\n");
                        break;
                    }
                    else if(j == 1){
                        printf("%d. ", i);
                        printf("Cermin pengganda. Anda bisa mendapatkan 2 skill baru!\n");
                        break;
                    }
                    else if (j == 2){
                        printf("%d. ", i);
                        printf("Senter pembesar hoki. Roll anda akan membesar!\n");
                        break;
                    }
                    else if (j == 3){
                        printf("%d. ", i);
                        printf("Senter pengecil hoki. Roll anda akan mengecil\n");
                        break;
                    }
                }
            }
            i ++;
        }
    }
}

void resetBuff (Player *P) {
/* me-reset seluruh buff kecuali imunitas teleport setiap ronde
(karena buff hanya berlaku sekali di suatu ronde) */
    for (int i = 0; i < 4; i++) {
        (*P).buff[i] = false;
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
    1 : Pintu Ga Ke Mana Mana 10%
    2 : Cermin Pengganda 6%
    3 : Senter Pembesar Hoki 15%
    4 : Senter Pengecil Hoki 15%
    5 : Mesin Penukar Posisi 4%
    6 : Teknologi Gagal 30%
    7 : Mesin Waktu 10%
    8 : Baling-Baling Jambu 10% */

    int TabSkill[100];
    int i, SkillDrop, SkillGet ;

    i = 0;

    while (i < 100){

        if ((i >= 0) && (i <= 9)){
            TabSkill[i] = 1 ;
        }
        else if ((i >= 10) && (i <= 15)){
            TabSkill[i] = 2 ;
        }
        else if ((i >= 16) && (i <= 30)){
            TabSkill[i] = 3 ;
        }
        else if ((i >= 31) && (i <= 45)){
            TabSkill[i] = 4 ;
        }
        else if ((i >= 46) && (i <= 49)){
            TabSkill[i] = 5 ;
        }
        else if ((i >= 50) && (i <= 79)){
            TabSkill[i] = 6 ;
        }
        else if ((i >= 80) && (i <= 89)){
            TabSkill[i] = 7 ;
        }
        else if ((i >= 90) && (i <= 99)){
            TabSkill[i] = 8 ;
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

    printf("\n");
    if (T == Nil){
        printf("Kamu gapunya skill apa apa, Kasian banget :(\n");
    }
    else{
        printf("%s memiliki skill:\n", NAME(P));
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
            else if (Info_Skill(T) == 7){
                printf("Mesin Waktu\n");
            }
            else if (Info_Skill(T) == 8){
                printf("Baling-Baling Jambu\n");
            }
            T = Next(T);
            i++ ;
        }
        printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n");
    }
    printf("\n");
}

void SalinSkill (Player *P1, Player P2){
    address skill;
    First(INFOSKILL(*P1)) = Nil;
    skill = First(INFOSKILL(P2));
    while (skill != Nil){
        InsVLast (&(INFOSKILL(*P1)), Info_Skill(skill));
        skill = Next(skill);
    }
}


void insPlayerSkill (Player *P){

    int X ;
    X = GetSkills() ;
    if (NbElmt(INFOSKILL(*P)) == 10) printf("Tidak mendapatkan skill karena sudah penuh! Jangan maruk ya :D\n");
    else{
        if (X == 6){
            /*DO NOTHING*/
            printf("Gacha kamu lagi ampas! %s tidak mendapat skill apa-apa :D\n", NAME(*P));
        }
        else{
            InsVLast (&INFOSKILL(*P), X);
            printf("%s mendapatkan skill!\n", NAME(*P));

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
            else if (X == 7){
                printf("Mesin Waktu berhasil dimasukkan ke dalam list!\n");
            }
            else if (X == 8){
                printf("Baling-Baling Jambu berhasil dimasukkan ke dalam list!\n");
            }
        }
    }
}


void DoubleMirror(Player *P){

    int i;

    if (NbElmt(INFOSKILL(*P)) < 9){
        for (i=0; i<2; i++){
            insPlayerSkill(P);
            usleep(500 * 1000);
        }
    }
    else{
        printf("Kamu tidak memiliki space cukup untuk skill ini. Skill terhapus dan kamu tidak mendapat apa apa !\n");
    }
}
