#ifndef ARAAY_TO_SLL_H
#define ARAAY_TO_SLL_H

#include "linked_list/linked_list.h"
#include "warga.h"

// typedef LinkedList ListKt;

typedef struct Kota{
  char* kt;
  Kota* next;
  Warga pWarga;
} Kota;

void insert_kota(Kota** head, char* kt);
void delete_kota(Kota** head, char* kt, char** temp);
void print_kota(Kota* head);
void destroy_kota(Kota** head);

void insert_warga(Kota** head, char* kt, char* nm);
void delete_warga(Kota** head, char* kt, char* nm, char** temp);
void print_warga(Kota* head, char* kt);
void destroy_warga(Kota** head, char* kt);

#endif // ARAAY_TO_SLL_H