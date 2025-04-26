#ifndef WARGA_H
#define WARGA_H
#include "linked_list\linked_list.h"

typedef Node* Warga;

void insert_nm(Warga* head, char* nm);
void delete_nm(Warga* head, char* nm, char** temp);
void print_nm(Warga head);
void destroy_nm(Warga* head);


#endif // !WARGA_H
