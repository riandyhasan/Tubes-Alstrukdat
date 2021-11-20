// Nama: Riandy Hasan
// NIM : 18220058
// Tanggal: Kamis, 28 Oktober 2021 
// Topik: Praktikum 5 - ADT List Linier
// Deskripsi: Implementasi dari listlinier.h

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "player.h"

boolean IsEmpty (List L){
    /* Mengirim true jika list kosong */
    return First(L) == Nil;
}

void CreateEmpty (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

address Alokasi (infoSkill X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

    address P;
	
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){
        InfoSkill(P) = X;
        Next(P) = Nil;
        return P;
    }
    else{
        return Nil;
    }
}

void Dealokasi (address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(*P);
}

address Search (List L, infoSkill X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P;

    P = First(L);
    if (IsEmpty(L)) return Nil;
    else{
        while (P != Nil && Info(P) != X){
            P = Next(P);
        }
        return P;
    }
}

void InsVFirst (List *L, infoSkill X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P;

    P = Alokasi(X);

    if (P != Nil){
    Next(P) = First(*L);
	First(*L) = P;
    }
}

void InsVLast (List *L, infoSkill X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P, last;

        if(IsEmpty(*L)) InsVFirst(L, X);
        else {
            P = Alokasi(X);
            if (P != Nil){
                last = First(*L);
                while(Next(last) != Nil){
                    last = Next(last);
                }
            Next(last) = P;
        }
    }
}

void DelVFirst (List *L, infoSkill *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;

    P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infoSkill *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;

    P = First(*L);
    if(Next(P) != Nil){
        while(Next(Next(P)) != Nil){
            P = Next(P);
        }
        *X = Info(Next(P));
        Dealokasi(&Next(P));
        Next(P) = Nil;
    }else{
        DelVFirst(L, X);
    }
}


void DelP (List *L, infoSkill X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address P, loc;

    if(!IsEmpty(*L)){
        P = First(*L);
        if(Info(P) == X){
            DelFirst(L, &loc);
        }else{
            while(Next(P) != Nil && Info(Next(P)) != X){
                P = Next(P);
            }
            if(Next(P) != Nil){
                DelAfter(L, &loc, P);
            }
        }
    }
}


void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    address loc;

    loc = First(*L);
    if(Next(loc) == Nil){
        DelFirst(L, P);
    }else{
        while(Next(Next(loc)) != Nil){
            loc = Next(loc);
        }
        DelAfter(L, P, loc);
    }
}


void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}


void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P;
    if(IsEmpty(L)) printf("[]");
    else{
        printf("[");
        P = First(L);
        while (P != Nil){
            printf("%d", Info(P));
            P = Next(P);
            if (P != Nil)
                printf(",");
        }
        printf("]");
    }
}


int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int count;
    address P;

    if (IsEmpty(L)) return 0;
    else{
        count = 0;
        P = First(L);
        while (P != Nil){
            count ++;
            P = Next(P);
        }
        return count;
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

void PrintSkill (Player P){
/* mengeluarkan list skill yang dimiliki player */

    int i;
    address p;

    p = First(LSPlayer(P));

    while (i < NbElmt(LSPlayer(P))){
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


void CommandSkill (Player P){
/* mengeluarkan command untuk meminta masukkan skill yang ingin dipakai */

    int idSkill, player1, player2;

    printf("Masukkan skill : ");
    scanf("%d", idSkill);

    if (idSkill == 1){
        printf(INFOPLAYER(P), "memakai skill Pintu Ga Ke Mana Mana. Anda mendapatkan imunitas terhadap teleport!");
    }
    else if (idSkill == 2){
        printf(INFOPLAYER(P), "memakai skill Cermin Pengganda. Skill ini akan dibuang digantikan dengan 2 skill baru.");
    }
    else if (idSkill == 3){
        printf(INFOPLAYER(P), "memakai skill Senter Pembesar Hoki. Dadu hanya akan menghasilkan angka MaxRoll atau setengah dari MaxRoll");
    }
    else if (idSkill == 4){
        printf(INFOPLAYER(P), "memakai skill Senter Pengecil Hoki. Dadu hanya akan menghasilkan angka 0 atau setengah dari MaxRoll");
    }
    else if (idSkill == 5){
        printf(INFOPLAYER(P), "memakai skill Mesin Penukar Posisi. Pilih pemain yang ingin ditukar posisinya : ");
    }
    else if (idSkill == 6){
        printf(INFOPLAYER(P), "Teknologi Gagal. Anda tidak mendapatkan skill");
    }

    useSkill(idSkill);
}


void useSkill ();
/* menggunakan skill yang dimiliki oleh player */
