// Nama: Riandy Hasan
// NIM : 18220058
// Tanggal: Kamis, 28 Oktober 2021 
// Topik: Praktikum 5 - ADT List Linier
// Deskripsi: Implementasi dari listlinier.h

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmpty (List L){
    /* Mengirim true jika list kosong */
    return First(L) == Nil;
}

void CreateEmpty (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

    address P;
	
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
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

address Search (List L, infotype X){
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

void InsVFirst (List *L, infotype X){
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

void InsVLast (List *L, infotype X){
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

void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;

    P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X){
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

void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    if (P != Nil){
        Next(P) = First(*L);
        First(*L) = P;
    }
}
void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    address loc;
    if (P != Nil){
    if(IsEmpty(*L)) InsertFirst(L, P);
    else{
        loc = First(*L);
        while (Next(loc) != Nil){
            loc = Next(loc);
        }
        Next(loc) = P;
        Next(P) = Nil;
        }
    }
}

void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P= First(*L);
    First(*L) = Next(*P);
}

void DelP (List *L, infotype X){
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

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
/* Mengirimkan nilai Info(P) yang maksimum */
    int max;
    address P;
    P = First(L);
    max = Info(P);
    while (P != Nil){
        if (Info(P) > max) max = Info(P);
        P = Next(P);
    }
    return max;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    address P;
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    First(*L1) = Nil;
    if (IsEmpty(*L3)){
        First(*L3) = First(*L2);
    } else {
        P = First(*L3);
        while (Next(P) != Nil){
            P = Next(P);
        }
        Next(P) = First(*L2);
    }
    First(*L2) = Nil;
}

address AdrMax (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    address P;
    int max;

    P = First(L);
    max = Max(L);
    while (P != Nil && Info(P) != max){
        P = Next(P);
    }
    return P;
}

infotype Min (List L){
/* Mengirimkan nilai info(P) yang minimum */
    int min;
    address P;
    P = First(L);
    min = Info(P);
    while (P != Nil){
        if (Info(P) < min) min = Info(P);
        P = Next(P);
    }
    return min;
}

address AdrMin (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    address P;
    int min;

    P = First(L);
    min = Min(L);
    while (P != Nil && Info(P) != min){
        P = Next(P);
    }
    return P;
}

float Average (List L){
/* Mengirimkan nilai rata-rata info(P) */
    address P;
    float avg;
    int count;
    P = First(L);

    if (IsEmpty(L)) return 0;
    else{
    avg = 0;
    count = 0;
    while (P != Nil){
        avg += Info(P);
        count++;
        P = Next(P);
    }
    return avg/count;
    }
}

void InversList (List *L){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    address P, last, Prec;


    if (!IsEmpty(*L)){
        address P = First(*L);
        while (Next(P) != Nil){
            P = Next(P);
        }
        last = P;
        while (P != First(*L)){
            Prec = First(*L);
            while (Next(Prec) != P){
                Prec = Next(Prec);
            }
            Next(P) = Prec;
            P = Next(P);
        }
        Next(P) = Nil;
        First(*L) = last;
    }
}