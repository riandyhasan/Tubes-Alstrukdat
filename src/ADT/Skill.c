#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "Skill.h"


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (ListSkill L){
/* Mengirim true jika list kosong */

    return (First(L) == Nil && Last(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (ListSkill *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
idx Alokasi (infoSkill X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

    Skill *P = (Skill *)malloc(sizeof(Skill));

    if (P != Nil){
        infoSkill(P) = X;
        Next(P) = Nil;

        return P;
    }
    else{
        return Nil;
    }
}

void Dealokasi (idx *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

    free(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/

/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListSkill *L, infoSkill X){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

    idx P;

    P = Alokasi(X);

    if (IsEmpty(*L)){
        Last(*L) = P;
    }

    Next(P) = First(*L);
    First(*L) = P;

    neff(P)++ ;
}


void InsertLast (ListSkill *L, infoSkill X){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */


    if (IsEmpty(*L)){
        InsertFirst(L, X);
    }
    else{

        idx P;

        P = Alokasi(X);

        Next(Last(*L)) = P;
        Last(*L) = P;

        neff(P)++ ;
    }
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/

void DelAt (ListSkill *L, infoSkill X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

    idx P;
    
    P = Search(*L, X);
    
    if (P != Nil){
        
    }
}


/****************** PROSES GET SKILL ******************/

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


/****************** PROSES SEMUA ELEMEN ******************/

int NbElmt (ListSkill L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

    int count;
    idx P;

    count = 0;
    
    if (!IsEmpty(L)){
        P = First(L);

        while (Next(P) != Nil){
            count = count + 1 ;
            P = Next(P);
        }

        count = count + 1;
    }

    return count;
}


void PrintSkill (ListSkill L){
/* mengeluarkan list skill yang dimiliki player */

    int i;
    idx p;

    p = First(L);

    while (i < NbElmt(L)){
        if (p == 1){
            printf("Pintu Ga Ke Mana Mana");
        }
        else if (p == 2){
            printf("Cermin Pengganda");
        }
        else if (p == 3){
            printf("Senter Pembesar Hoki");
        }
        else if (p == 4){
            printf("Senter Pengecil Hoki");
        }
        else if (p == 5){
            printf("Mesin Penukar Posisi");
        }
        else if (p == 6){
            printf("Teknologi Gagal");
        }

        p = Next(p);
        i = i + 1;
    }

    printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.");
}


void CommandSkill (playerName){
/* mengeluarkan command untuk meminta masukkan skill yang ingin dipakai */

    int idSkill, player1, player2;

    printf("Masukkan skill : ");
    scanf("%d", idSkill);

    if (idSkill == 1){
        printf(playerName, "memakai skill Pintu Ga Ke Mana Mana. Anda mendapatkan imunitas terhadap teleport!");
    }
    else if (idSkill == 2){
        printf(playerName, "memakai skill Cermin Pengganda. Skill ini akan dibuang digantikan dengan 2 skill baru.");
    }
    else if (idSkill == 3){
        printf(playerName, "memakai skill Senter Pembesar Hoki. Dadu hanya akan menghasilkan angka MaxRoll atau setengah dari MaxRoll");
    }
    else if (idSkill == 4){
        printf(playerName, "memakai skill Senter Pengecil Hoki. Dadu hanya akan menghasilkan angka 0 atau setengah dari MaxRoll");
    }
    else if (idSkill == 5){
        printf(playerName, "memakai skill Mesin Penukar Posisi. Pilih pemain yang ingin ditukar posisinya : ");
    }
    else if (idSkill == 6){
        printf(playerName, "Teknologi Gagal. Anda tidak mendapatkan skill");
    }

    useSkill(idSkill);
}


void useSkill ();
/* menggunakan skill yang dimiliki oleh player */
