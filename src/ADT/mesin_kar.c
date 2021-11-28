/* File: mesinkar.c */
/* Implementasi Mesin Karakter */
#include <stdio.h>
#include <string.h>
#include "mesin_kar.h"

char CC;
char CL;
boolean EOP;
boolean EOPL;

static FILE *pita;
static FILE *pitaload;

void START(char *filename) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    char *dir = "../data/";
    char file[100];
    strcpy(file, dir);
    strcat(file, filename);
    printf("Membuka file %s\n", filename);
    pita = fopen(file, "r");
    if (pita == NULL) {
		printf("Punten, file gak bisa dibuka!\n");
	} else {
		printf("Memuat konfigurasi dari file %s\n", filename);
      printf("\n");
	}
   ADV();
}

void STARTLOAD(char *filename) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    char *dir = "../bin/";
    char file[100];
    strcpy(file, dir);
    strcat(file, filename);
    printf("Membuka file %s\n", filename);
    pitaload = fopen(file, "r");
    if (pitaload == NULL) {
		printf("Punten, file gak bisa dibuka!\n");
	} else {
		printf("Memuat konfigurasi dari file %s\n", filename);
      printf("\n");
	}
   ADVLOAD();
}

void ADVLOAD() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    CL = getc(pitaload);
    EOPL = (CL == EOF);
    if (EOPL) {
       fclose(pitaload);
    }
}

void STARTINPUT(){
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pita = stdin;
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    CC = getc(pita);
    EOP = (CC == EOF);
    if (EOP) {
       fclose(pita);
    }
}