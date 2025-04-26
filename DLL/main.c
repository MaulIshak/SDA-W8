#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list/linked_list.h"
#include <string.h>
#include "kota.h"

int main()
{
  Kota* head = NULL; // Head dari linked list kota
  char kota[50], warga[50], *temp = NULL;

  while (true) {
      // system("cls");
      // Interactive mode with options
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

      switch (option) {
          case 1:
              printf("Masukkan nama kota: ");
              scanf("%s", kota);
              insert_kota(&head, kota);
              break;
          case 2:
              printf("Masukkan nama kota untuk dihapus: ");
              scanf("%s", kota);
              delete_kota(&head, kota, &temp);
              if (temp != NULL) {
                  printf("Kota Dihapus: %s\n", temp);
                  free(temp); // Free the allocated memory for the deleted Kota
              }
              break;
          case 3:
              print_kota(head);
              break;
          case 4:
              printf("Masukkan nama kota: ");
              scanf("%s", kota);
              printf("Masukkan nama warga: ");
              scanf("%s", warga);
              insert_warga(&head, kota, warga);
              break;
          case 5:
              printf("Masukkan nama kota asal: ");
              scanf("%s", kota);
              printf("Masukkan nama warga: ");
              scanf("%s", warga);
              delete_warga(&head, kota, warga, &temp);
              if (temp != NULL) {
                  printf("Warga Dihapus: %s\n", temp);
                  free(temp); // Free the allocated memory for the deleted Warga
              }
              break;
          case 6:
              printf("Masukkan nama kota: ");
              scanf("%s", kota);
              printf("\n");
              print_warga(head, kota);
              break;
          case 7:
              destroy_kota(&head);
              return 0;
      }

      printf("Tekan enter untuk melanjutkan...\n");
      getchar();
      getchar();
  }
}
