// Implementasi mesin_kata.h 

#include "mesin_kata.h"
#include <stdio.h>
#include <stdlib.h>
boolean EndKata;
boolean EndKataLoad;
Kata CKata;
Kata LoadKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while(CC == BLANK || CC == ENTER){
        ADV();
    }
}

void IgnoreBlankLoad()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while(CL == BLANK || CL == ENTER){
        ADVLOAD();
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
    int i = 1;
    CKata.Length = 0;
    while(CC != BLANK && CC != ENTER ){
        IgnoreBlank();
        CKata.TabKata[i] = CC;
        i++;
        ADV();
    }
    CKata.Length = i-1;
}
          
void STARTKATA(char *filename)
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START(filename);
    IgnoreBlank();
    if (CC == EOF) EndKata = true;
    else /* CC != MARK */
    {
        EndKata = false;
        SalinKata();
    }
}

void STARTLOADFILE(char *filename)
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    STARTLOAD(filename);
    IgnoreBlankLoad();
    if (CL == EOF) EndKataLoad = true;
    else /* CC != MARK */
    {
        EndKataLoad = false;
        SalinLKata();
    }
}

void SalinLKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 1;
    LoadKata.Length = 0;
    while(CL != BLANK && CL != ENTER ){
        IgnoreBlankLoad();
        LoadKata.TabKata[i] = CL;
        i++;
        ADVLOAD();
    }
    LoadKata.Length = i-1;
}

void ADVKATALOAD()
    /* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlankLoad();
    if (CL == EOF) 
    {
        EndKataLoad = true;
    }
    else /* CC != MARK */
    {
        SalinLKata();
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
    if (CC == EOF) 
    {
        EndKata = true;
    }
    else /* CC != MARK */
    {
        SalinKata();
    }
}

int KataToInt(Kata CKata){
    char kata[CKata.Length];
    if (CKata.Length == 1) {
        char kata[2];
        kata[0] = CKata.TabKata[1];
        char temp[2] = { kata[0], '\0'} ;
        return atoi(temp);
    }
    else{
        for (int i = 0; i < CKata.Length; i++){
            kata[i] = CKata.TabKata[i+1];
        }
        return atoi(kata);
    }
}

void printKata(Kata kata){
  for(int i = 1; i <= kata.Length; i++){
    printf("%c", kata.TabKata[i]);
  }
  printf("\n");
}

void readInput(){
    printf("Masukkan command: ");
    STARTCOMMAND();
}

boolean IsKataSama(Kata k1, char *k2){
    boolean sama = true;
    for(int i=0; i < k1.Length; i++){
        if (k2[i] != k1.TabKata[i+1]) sama = false;
    }
    return sama;
}