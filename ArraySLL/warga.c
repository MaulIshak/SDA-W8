#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"
#include "linked_list/linked_list.h"
#include "warga.h"

void insert_nm(Warga* head, char* nm) {
  LinkedList wargaList;
  wargaList.head = *head;
  insert_last(&wargaList, nm);
  *head = wargaList.head;
}

void delete_nm(Warga* head, char* nm, char** temp){
  LinkedList wargaList;
  wargaList.head = *head;
  delete_val(&wargaList, nm, temp);
  *head = wargaList.head;
}

void print_nm(Warga head){
  LinkedList wargaList;
  wargaList.head = head;
  if(is_list_empty(wargaList)){
    printf("\n");
    return;
  }else{
    print_list(wargaList);
  }

}
void destroy_nm(Warga* head){
  LinkedList wargaList;
  wargaList.head = *head;
  destroy_list(&wargaList);
  *head = NULL;
}