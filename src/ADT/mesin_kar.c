/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesin_kar.h"
#include <stdio.h>
#include <string.h>

char CC;
boolean EOP;

static FILE *pita;
static int retval;


void START(char filename[50]) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    char *dir = "../../data/";
    char file[100];
    strcpy(file, dir);
    strcat(file, filename);
    pita = fopen(file, "r");
    if (pita == NULL) {
		printf("Punten, file gak bisa dibuka!\n");
	} else {
      printf("Loading.....");
		printf("Memuat konfigurasi dari file %s...\n", filename);
	}
    ADV();
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
    retval = fscanf(pita,"%c",&CC);
    printf("%c", CC);
    EOP = (CC == MARK);
    if (EOP) {
       fclose(pita);
    }
}
