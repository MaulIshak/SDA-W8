
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"
#include "linked_list/linked_list.h"

void insert_kota(Kota** head, char* kt){
    Kota* new_kota = (Kota*)malloc(sizeof(Kota));
    new_kota->kt = strdup(kt);
    new_kota->next = NULL;
    new_kota->pWarga = NULL;

    if (*head == NULL) {
        *head = new_kota;
    } else {
        Kota* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_kota;
    }
}

void delete_kota(Kota** head, char* kt, char** temp){
    Kota* current = *head;
    Kota* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->kt, kt) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            *temp = current->kt;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Kota %s tidak ada di list.\n", kt);
}

void print_kota(Kota* head){
    if(head == NULL){
        printf("Tidak ada kota\n");
    }
    while (head != NULL) {
        printf("[%s] ", head->kt);
        print_warga(head, head->kt);
        head = head->next;
    }
}

void destroy_kota(Kota** head){
    Kota* current = *head;
    while (current != NULL) {
        Kota* next = current->next;
        destroy_nm(&(current->pWarga));
        free(current->kt);
        free(current);
        current = next;
    }
    *head = NULL;
}

void insert_warga(Kota** head, char* kt, char* nm){
    Kota* current = *head;
    while (current != NULL) {
        if (strcmp(current->kt, kt) == 0) {
            insert_nm(&current->pWarga, nm);
            return;
        }
        current = current->next;
    }
    printf("Kota %s tidak ada di list.\n", kt);
}

void delete_warga(Kota** head, char* kt, char* nm, char** temp){
    Kota* current = *head;
    while (current != NULL) {
        if (strcmp(current->kt, kt) == 0) {
            delete_nm(&current->pWarga, nm, temp);
            return;
        }
        current = current->next;
    }
    printf("Kota %s tidak ada di list.\n", kt);
}

void print_warga(Kota* head, char* kt){
  Kota* current = head;
  while (current != NULL) {
      if (strcmp(current->kt, kt) == 0) {
          print_nm(current->pWarga);
          return;
      }
      current = current->next;
    }
}

void destroy_warga(Kota** head, char* kt){
    Kota* current = *head;
    while (current != NULL) {
        if (strcmp(current->kt, kt) == 0) {
            destroy_nm(&(current->pWarga));
            return;
        }
        current = current->next;
    }
}
