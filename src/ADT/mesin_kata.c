// Implementasi mesin_kata.h 

#include "mesin_kata.h"
#include "mesin_kar.c"

#include <stdio.h>
#include <stdlib.h>
boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while(CC == BLANK || CC == ENTER){
        ADV();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    CKata.Length = 0;
    while(CC != BLANK && CC != ENTER){
        IgnoreBlank();
        CKata.TabKata[i] = CC;
        i++;
        ADV();
    }
    CKata.Length = i;
}
          
void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlank();
    if (CC == MARK) EndKata = true;
    else /* CC != MARK */
    {
        EndKata = false;
        SalinKata();
    }
}

void STARTCOMMAND()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    STARTINPUT();
    IgnoreBlank();
    if (CC == MARK) EndKata = true;
    else /* CC != MARK */
    {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC == MARK) 
    {
        EndKata = true;
    }
    else /* CC != MARK */
    {
        SalinKata();
    }
}

int KataToInt(Kata CKata){
    return atoi(CKata.TabKata);
}

void printKata(Kata kata){
  for(int i = 0; i < kata.Length; i++){
    printf("%c", kata.TabKata[i]);
  }
  printf("\n");
}

void readConfig(){
    int mapLen, nTel, maxRoll, telSucc, telPred;
    STARTKATA();
    mapLen = KataToInt(CKata);
    // panjang map = mapLen
    // SalinMap
    ADVKATA();
    ADVKATA();
    maxRoll = KataToInt(CKata);
    ADVKATA();
    nTel = KataToInt(CKata);
    for (int i = 0; i < nTel-1; i++){
    //     isi map dengan teleporter
    ADVKATA();
    ADVKATA();
    }
    EndKata = true;
    printf("mapLen: %d\n", mapLen);
    printf("nTel: %d\n", nTel);
    printf("maxRoll: %d\n", maxRoll);
}

void readInput(){
    STARTCOMMAND();
    printKata(CKata);
}