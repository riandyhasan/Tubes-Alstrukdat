#include "mesin_kar.c"
#include "mesin_kata.c"
#include <string.h>
#include <stdio.h>

int main() {
  char *filename;
  char *dir = "../../data";
  char openfile[100];  
  printf("Masukkan filename untuk dibuka\n");
  readInput();
  strcpy(openfile, dir);
  strcpy(openfile, CKata.TabKata);
  STARTKATA(openfile);
  STARTLOADFILE(openfile);
  return 0;
}