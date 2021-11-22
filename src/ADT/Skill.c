#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "skill.h"
#include "state.h"
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
    address T;

    T = First(INFOSKILL(P));
    i = 1;

    while (T != Nil){
        printf("%d. ", i);

        if (Info_Skill(T) == 1){
            printf("Pintu Ga Ke Mana Mana");
        }
        else if (Info_Skill(T) == 2){
            printf("Cermin Pengganda");
        }
        else if (Info_Skill(T) == 3){
            printf("Senter Pembesar Hoki");
        }
        else if (Info_Skill(T) == 4){
            printf("Senter Pengecil Hoki");
        }
        else if (Info_Skill(T) == 5){
            printf("Mesin Penukar Posisi");
        }

        T = Next(T);
        i++ ;

        printf("\n");
    }

    printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.");
}


void CommandSkill (Player P, boolean *PintuGaKemanaMana, boolean *CerminPengganda, boolean *SenterPembesarHoki, boolean *SenterPengecilHoki, boolean *MesinPenukarPosisi ){
/* mengeluarkan command untuk meminta masukkan skill yang ingin dipakai */

    int idSkill ;

    printf("Masukkan skill : ");
    scanf("%d", idSkill);

    if (idSkill == 1){
        printf("%d memakai skill Pintu Ga Ke Mana Mana. Anda mendapatkan imunitas terhadap teleport!", INFOPLAYER(P));
        *PintuGaKemanaMana = true ;
    }
    else if (idSkill == 2){
        printf("%d memakai skill Cermin Pengganda. Skill ini akan dibuang digantikan dengan 2 skill baru.", INFOPLAYER(P));
        *CerminPengganda = true ;
    }
    else if (idSkill == 3){
        printf("%d memakai skill Senter Pembesar Hoki. Dadu hanya akan menghasilkan angka MaxRoll atau setengah dari MaxRoll", INFOPLAYER(P));
        *SenterPembesarHoki = true ;
    }
    else if (idSkill == 4){
        printf("%d memakai skill Senter Pengecil Hoki. Dadu hanya akan menghasilkan angka 0 atau setengah dari MaxRoll", INFOPLAYER(P));
        *SenterPengecilHoki = true ;
    }
    else if (idSkill == 5){
        printf("%d memakai skill Mesin Penukar Posisi.", INFOPLAYER(P));
        *MesinPenukarPosisi = true ;
    }

    DelP (&INFOSKILL(P), idSkill) ;

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

void DoubleMirror(){
    
}