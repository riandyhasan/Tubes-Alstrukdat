#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../adt.h"

int main(){

    List driveSkill;
    int idDriveSkill, caridong, delSkill;
    char check, stillwant;
    address adrSkill, ADR;

    CreateEmptyList(&driveSkill);
    printf("\n");
    printf("List Skill kosong berhasil dibuat !\n");

    while (NbElmt(driveSkill) < 10){
        printf("\n");
        printf("Masukkan id yang ingin input ke list Skill : ");
        scanf("%d", &idDriveSkill);

        InsVLast (&driveSkill, idDriveSkill);
        printf("Skill dengan id %d berhasil dimasukkan ke list paling belakang.\n", idDriveSkill);
    }

    printf("\n");
    printf("Masukkan nomor id skill yang ingin dicari dalam list. (0 untuk stop mencari) : ");

    scanf("%d", &caridong);

    if (IsEmptyList(driveSkill)){
        printf("List skill kamu kosong ! Tidak dapat menampilkan apa apa.");
    }
    else{
        ADR = Search(driveSkill, caridong);
        printf ("Skill dengan id %d berada di address %d dari list skill\n", caridong, ADR);
    }

    while (caridong != 0){

        printf("Masukkan nomor id skill yang ingin dicari dalam list. (0 untuk stop mencari) : ");

        scanf("%d", &caridong);

        if (IsEmptyList(driveSkill)){
            printf("List skill kamu kosong ! Tidak dapat menampilkan apa apa.");
        }
        else{
            ADR = Search(driveSkill, caridong);
            printf ("Skill dengan id %d berada di address %d dari list skill\n", caridong, ADR);
        }
        printf("\n");
    }

    printf("Berikut daftar ID Skill yang kamu miliki :\n");
    PrintInfo(driveSkill);

    printf("\n");
    printf("apakah terdapat skill yang ingin kamu hapus ? (Y/N) : ");
    scanf("%c", &check);
    while (check != 'Y' && check != 'N'){
        scanf("%c", &check);
    }

    if (check == 'Y'){
        printf("\n");
        printf("Masukkan ID skill yang mau kamu hapus  : ");
        scanf("%d", &delSkill);

        DelP(&driveSkill, delSkill);

        while (check == 'Y'){
            printf("\n");
            printf("Apakah masih ada skill yang mau kamu hapus ? (Y/N) : ");
            getchar();
            scanf("%c", &check);

            if (check == 'Y'){
                printf("\n");
                printf("Masukkan ID skill yang mau kamu hapus  : ");
                scanf("%d", &delSkill);
                DelP(&driveSkill, delSkill);
            }
        }
        printf("\n");
        printf("Berikut list ID Skill yang kamu miliki sekarang : \n");
        PrintInfo(driveSkill);
    }
    else{
        printf("\n");
        printf("Baik, tidak ada skill yang terhapus");
        printf("\n");
        printf("Berikut list ID Skill yang kamu miliki sekarang : \n");
        PrintInfo(driveSkill);
    }
}