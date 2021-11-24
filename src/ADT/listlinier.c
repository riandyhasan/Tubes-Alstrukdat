#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmptyList (List L){
    /* Mengirim true jika list kosong */
    return First(L) == Nil;
}

void CreateEmptyList (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

address Alokasi (skill_info X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

    address P;
	
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){
        Info_Skill(P) = X;
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

address Search (List L, skill_info X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P;

    P = First(L);
    if (IsEmptyList(L)) return Nil;
    else{
        while (P != Nil && Info_Skill(P) != X){
            P = Next(P);
        }
        return P;
    }
}

void InsVFirst (List *L, skill_info X){
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

void InsVLast (List *L, skill_info X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P, last;

        if(IsEmptyList(*L)) InsVFirst(L, X);
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

void DelVFirst (List *L, skill_info *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;

    P = First(*L);
    *X = Info_Skill(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast (List *L, skill_info *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;

    P = First(*L);
    if(Next(P) != Nil){
        while(Next(Next(P)) != Nil){
            P = Next(P);
        }
        *X = Info_Skill(Next(P));
        Dealokasi(&Next(P));
        Next(P) = Nil;
    }else{
        DelVFirst(L, X);
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


void DelP (List *L, skill_info X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address P, loc;

    if(!IsEmptyList(*L)){
        P = First(*L);
        if(Info_Skill(P) == X){
            DelFirst(L, &loc);
        }else{
            while(Next(P) != Nil && Info_Skill(Next(P)) != X){
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
    if(IsEmptyList(L)) printf("[]");
    else{
        printf("[");
        P = First(L);
        while (P != Nil){
            printf("%d", Info_Skill(P));
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

    if (IsEmptyList(L)) return 0;
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
