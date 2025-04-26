#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list/linked_list.h"
#include <string.h>
#include "kota.h"


int main()
{
  int jml_kota = 5;
  KotaArr myKotaArr;
  // printf("Masukkan jumlah kota: ");
  // scanf("%d", &jml_kota);

  init_arr(&myKotaArr);

  // print_kota(myKotaArr);
  // insert_kt(&myKotaArr, "Bandung");
  // insert_kt(&myKotaArr, "Cimahi"); 
  // print_kota(myKotaArr);
  // insert_kt(&myKotaArr, "Karawang"); 
  // print_kota(myKotaArr);
  // delete_kt(&myKotaArr, "Bandung");
  // print_kota(myKotaArr);

  while (true)
  {
    system("cls");
    // Interaktif Mode
    printf("============== Operasi Kota ===============\n");
    printf("1. Insert Kota\n");
    printf("2. Delete Kota\n");
    printf("3. Print All\n");
    printf("=============== Operasi Warga =============\n");
    printf("4. Insert Warga\n");
    printf("5. Delete Warga\n");
    printf("6. Print Warga\n");
    printf("=============== Exit ======================\n");
    printf("7. Exit\n");
    printf("Pilih(1-7): ");
    int option;
    scanf("%d", &option);
    printf("\n");
    char kota[50], warga[50], *temp = NULL;
    switch (option)
    {
      case 1:
        printf("Masukkan nama kota: ");
        scanf("%s", kota);
        insert_kt(&myKotaArr, kota);
        break;
      case 2:
        printf("Masukkan nama kota untuk dihapus: ");
        scanf("%s", kota);
        delete_kt(&myKotaArr, kota);
        break;
      case 3:
        print_kota(myKotaArr);
        break;
      case 4:
        printf("Masukkan nama kota: ");
        scanf("%s", kota);
        printf("Masukkan nama warga: ");
        scanf("%s", warga);
        insert_warga(&myKotaArr, kota, warga);
        break;
      case 5:
        printf("Masukkan nama kota asal: ");
        scanf("%s", kota);
        printf("Masukkan nama warga: ");
        scanf("%s", warga);
        delete_warga(&myKotaArr, kota, warga, &temp);
        printf("\n");
        if (temp != NULL) {
          printf("Warga Dihapus: %s\n", temp);
          free(temp);
        }
        break;
      case 6:
        printf("Masukkan nama kota: ");
        scanf("%s", kota); 
        printf("\n");
        print_warga(myKotaArr, kota);
        break;
      case 7:
        return 0;

      }

      printf("Tekkan enter untuk melanjutkan...\n");
      getchar();
      getchar();

  }
}

// int main()
// {

//   ListKt* arrKota;
//   int jml = 0;
//   scanf("%d", &jml);
//   arrKota=(ListKt*) malloc(sizeof(ListKt) * jml);
//   init_arr(arrKota);

//   insert_kota(arrKota, "Cimahi");
//   insert_kota(arrKota, "Bandung");

//   insert_nama(arrKota, "Bandung", "Maulana");
//   insert_nama(arrKota, "Bandung", "Andi");
//   insert_nama(arrKota, "Cimahi", "Bayu");
//   insert_nama(arrKota, "Cimahi", "Nandhi");

//   print_all(arrKota);
//   // print_kt(arrKota, "Cimahi");
//   delete_kota(arrKota, "Cimahi");
//   printf("\n");
//   print_all(arrKota);
  
//   printf("\n");
//   insert_kota(arrKota, "Garut");
//   print_all(arrKota);
  
//   return 0;
// }