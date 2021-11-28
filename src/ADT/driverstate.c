#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./adt.h"

int main(){

    List driveSkill;
    int idDriveSkill, caridong, delSkill;
    char check;
    address adrSkill, ADR;

    CreateEmptyList(&driveSkill);
    printf("List Skill kosong berhasil dibuat !\n");
    printf("\n");

    while (NbElmt(driveSkill) < 10){
        printf("Masukkan id yang ingin input ke list Skill : ");
        scanf("%d", &idDriveSkill);

        InsVLast (&driveSkill, idDriveSkill);
        printf("Skill dengan id %d berhasil dimasukkan ke list paling belakang.", idDriveSkill);
    }

    printf("\n");
    printf("Masukkan nomor id skill yang ingin dicari dalam list : ");

    scanf("%d", &caridong);

    if (isEmpty(driveSkill)){
        printf("List skill kamu kosong ! Tidak dapat menampilkan apa apa.");
    }
    else{
        ADR = Search(driveSkill, &caridong);
        printf ("Skill dengan id %d berada di address %d dari list skill", caridong, ADR);
    }

    printf("\n");
    printf("apakah terdapat skill yang ingin kamu hapus ? (Y/N)");
    scanf("%c", &check);
        while (check != 'Y' && check != 'N'){
            scanf("%c", &check);
        }

        if (check == 'Y'){
            printf("\n");
            printf("Masukkan ID skill yang mau kamu hapus  :");
            scanf("%d", &delSkill);

            DelP(&driveSkill, delSkill);
        }
        else{
            printf("\n");
            printf("Baik, tidak ada skill yang terhapus");
        }
}