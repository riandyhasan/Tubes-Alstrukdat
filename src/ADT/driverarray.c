#include <stdio.h>
#include <stdlib.h>
#include "array.c"

int main(){
    TabChar T;
    MakeEmptyArr(&T);
    if (IsEmptyArr(T)) printf("Array kosong\n");
    if (IsFullArr(T)) printf("Array full\n");
    printf("Banyaknya maximum elemen adalah %d\n", MaxNbElArr(T));
    int nArr;
    printf("Masukkan banyak el array: ");
    scanf("%d", &nArr);
    SetNeff(&T, nArr);
    printf("Banyak elemen array: %d\n", NbElmtArr(T));
    printf("Masukkan el array: ");
    char cc[nArr];
    scanf("%s", &cc);
    for (int i = 1; i <= NbElmtArr(T); i++){
        SetEl(&T, i, cc[i-1]);
    }
    printf("First Idx: %d\n", GetFirstIdx(T));
    printf("Last Idx: %d\n", GetLastIdx(T));
    printf("el array: ");
    for (int i = 1; i <= NbElmtArr(T); i++){
        printf("%c", GetElmtArr(T, i));
    }
    printf("\n");
    TabChar T2;
    MakeEmptyArr(&T2);
    SetTab(T, &T2);
    int idx;
    printf("Masukkan idx: ");
    scanf("%d", &idx);
    if (IsIdxValid(T, idx)) {
        if (IsIdxEff(T, idx))  printf("Idx valid dan merupakan Neff\n");
        else printf("Idx valid!\n");
    }
    return 0;
}