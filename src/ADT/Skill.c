#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "skill.h"
#include "player.h"

/****************** PROSES GET SKILL MELALUI RANDOMIZER ******************/

void printRandoms (int lower, int upper, int count){

    int i;

    for (i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower ;
        printf("%d ", num);
    }
}

int DrivePrintRandoms (int lower, int upper, int count){

    srand(time(0));
  
    printRandoms(lower, upper, count);
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

    for (i=0; i<100; i++){
        if (0 <= i <= 15){
            TabSkill[i] = 1 ;
        }
        else if (16 <= i <= 23){
            TabSkill[i] = 2 ;
        }
        else if (24 <= i <= 43){
            TabSkill[i] = 3 ;
        }
        else if (44 <= i <= 63){
            TabSkill[i] = 4 ;
        }
        else if (64 <= i <= 68){
            TabSkill[i] = 5 ;
        }
        else if (69 <= i <= 99){
            TabSkill[i] = 6 ;
        }
    }

    srand(time(0));
    SkillDrop = DrivePrintRandoms(0, 100, 1);
    SkillGet = TabSkill[SkillDrop];

    return SkillGet;
}

void insPlayerSkill (Player P){

    int X ;

    X = GetSkills() ;

    if (X == 6){
        /*DO NOTHING*/
    }
    else{
        InsVLast (&INFOSKILL(P), X);
    }
}


/****************** PROSES SKILL ******************/

void PrintSkill (Player P){
/* mengeluarkan list skill yang dimiliki player */

    int i;
    address p;

    p = First(INFOSKILL(P));

    while (i < NbElmt(INFOSKILL(P))){
        if (idSkill(p) == 1){
            printf("Pintu Ga Ke Mana Mana");
        }
        else if (idSkill(p) == 2){
            printf("Cermin Pengganda");
        }
        else if (idSkill(p) == 3){
            printf("Senter Pembesar Hoki");
        }
        else if (idSkill(p) == 4){
            printf("Senter Pengecil Hoki");
        }
        else if (idSkill(p) == 5){
            printf("Mesin Penukar Posisi");
        }

        p = Next(p);
        i = i + 1;
    }

    printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.");
}


int CommandSkill (Player P){
/* mengeluarkan command untuk meminta masukkan skill yang ingin dipakai */

    int idSkill ;

    printf("Masukkan skill : ");
    scanf("%d", idSkill);

    if (idSkill == 1){
        printf(INFOPLAYER(P), "memakai skill Pintu Ga Ke Mana Mana. Anda mendapatkan imunitas terhadap teleport!");
        PintuGaKemanaMana = true ;
    }
    else if (idSkill == 2){
        printf(INFOPLAYER(P), "memakai skill Cermin Pengganda. Skill ini akan dibuang digantikan dengan 2 skill baru.");
        CerminPengganda = true ;
    }
    else if (idSkill == 3){
        printf(INFOPLAYER(P), "memakai skill Senter Pembesar Hoki. Dadu hanya akan menghasilkan angka MaxRoll atau setengah dari MaxRoll");
        SenterPembesarHoki = true ;
    }
    else if (idSkill == 4){
        printf(INFOPLAYER(P), "memakai skill Senter Pengecil Hoki. Dadu hanya akan menghasilkan angka 0 atau setengah dari MaxRoll");
        SenterPengecilHoki = true ;
    }
    else if (idSkill == 5){
        printf(INFOPLAYER(P), "memakai skill Mesin Penukar Posisi. Pilih pemain yang ingin ditukar posisinya : ");
        MesinPenukarPosisi = true ;
    }

    DelP (&INFOSKILL(P), idSkill) ;

    return idSkill;
}


 