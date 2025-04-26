
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"
#include "linked_list/linked_list.h"

// #define MAX_KOTA 10

void init_kt(Kota *kota){
  kota->kt = "";
  kota->pWarga = NULL;
}

void init_arr(KotaArr *kotaArr){
  // Ukuran minimal array
  kotaArr->size = 5;
  kotaArr->kota =(Kota*) malloc (sizeof(Kota)*kotaArr->size);

  for (int i = 0; i < kotaArr->size; i++)
  {
    init_kt(kotaArr->kota+i);
    // printf("Kota ke-%d berhasil di inisialisasi\n", i+1);
  }
  

}
void insert_kt(KotaArr *kotaArr, char* kt){
  // Perbesar array jika penuh
  if(isArrayFull(*kotaArr)){
    kotaArr->size += 1;
    kotaArr->kota = realloc(kotaArr->kota, sizeof(Kota)*kotaArr->size);
    init_kt(kotaArr->kota + kotaArr->size-1);
  }

  
  for (int i = 0; i < kotaArr->size; i++)
  {
    if(strcmp(kotaArr->kota[i].kt, "") == 0){
      kotaArr->kota[i].kt = strdup(kt);
      return;
    }
  }
  
}

void delete_kt(KotaArr *kotaArr,char* kt){
  for (int i = 0; i < kotaArr->size; i++)
  {
    if(strcmp(kotaArr->kota[i].kt, kt) == 0){
      free(kotaArr->kota[i].kt);
      init_kt(kotaArr->kota + i);
      return;
    }
  }
  printf("Kota %s tidak ada di list\n", kt);
}

void print_kota(KotaArr kotaArr){
  for (int i = 0; i < kotaArr.size; i++)
  {
    printf("[%s]", kotaArr.kota[i].kt);
    print_nm(kotaArr.kota[i].pWarga);
  }
  printf("\n");
  
}

bool isArrayFull(KotaArr kotaArr){
  for (int i = 0; i < kotaArr.size; i++)
  {
    if(kotaArr.kota[i].kt == ""){
      return false;
    }
  }
  return true;
}

void insert_warga(KotaArr *kotaArr, char* kt, char* nm){
  for (int i = 0; i < kotaArr->size; i++)
  {
    if(strcmp(kotaArr->kota[i].kt, kt) == 0){
      insert_nm(&(kotaArr->kota[i].pWarga), nm);
      return;
    }
  }
  printf("Kota %s tidak ada di list\n", kt);
}

void delete_warga(KotaArr *kotaArr, char* kt, char* nm, char** temp){
  for (int i = 0; i < kotaArr->size; i++)
  {
    if(strcmp(kotaArr->kota[i].kt, kt) == 0){
      delete_nm(&(kotaArr->kota[i].pWarga), nm, temp);
      return;
    }
  }
  printf("Kota %s tidak ada di list\n", kt);
}
void print_warga(KotaArr kotaArr, char* kt){
  for (int i = 0; i < kotaArr.size; i++)
  {
    if(strcmp(kotaArr.kota[i].kt, kt) == 0){
      print_nm(kotaArr.kota[i].pWarga);
      return;
    }
  }
  printf("kota %s tidak ada di list.\n", kt);
}

void destroy_warga(KotaArr *kotaArr, char* kt){
  for (int i = 0; i < kotaArr->size; i++)
  {
    if(strcmp(kotaArr->kota[i].kt, kt) == 0){
      destroy_nm(&(kotaArr->kota[i].pWarga));
      return;
    }
  }
}

void destroy_all_warga(KotaArr *kotaArr){
  for (int i = 0; i < kotaArr->size; i++)
  {
    destroy_nm(&(kotaArr->kota[i].pWarga));
  }
}

int get_jumlah_kota(KotaArr kotaArr){
  int count = 0;
  for (int i = 0; i < kotaArr.size; i++)
  {
    if(strcmp(kotaArr.kota[i].kt, "") != 0){
      count++;
    }
  }
  return count;
}
int get_jumlah_warga(KotaArr kotaArr, char* kt){
  for (int i = 0; i < kotaArr.size; i++)
  {
    if(strcmp(kotaArr.kota[i].kt, kt) == 0){
      LinkedList wargaList;
      wargaList.head = kotaArr.kota[i].pWarga;
      return get_length(wargaList);
    }
  }
  return -1;
}

int get_jumlah_warga_all(KotaArr kotaArr){
  int count = 0;
  for (int i = 0; i < kotaArr.size; i++)
  {
    if(strcmp(kotaArr.kota[i].kt, "") != 0){
      count += get_jumlah_warga(kotaArr, kotaArr.kota[i].kt);
    }
  }
  return count;
}








// void init_arr(ListKt *arrKota, int size){
//   arrKota = malloc(sizeof(ListKt)*size);
//   for (int i = 0; i < size; i++)
//   {
//    create_list(&(*arrKota) + i);
//   }
// }

// void insert_kota(ListKt arrKota[], char* kotaNama){
//   for (int i = 0; i < MAX_KOTA; i++)
//   {
//     if (arrKota[i].head == NULL) {
//       insert_first(&arrKota[i], kotaNama);
//       // printf("Kota %s berhasil ditambahkan.\n", kotaNama);
//       return;
//     }
//   }
//   printf("Overflow, tidak ada ruang untuk membuat kota baru");
  
// }

// void insert_nama(ListKt arrKota[], char* kt, char* nama){
//   bool isExist = false;
//   int i;
//   for (i = 0; i < MAX_KOTA; i++)
//   {
//     if(arrKota[i].head != NULL && strcmp(arrKota[i].head->nm, kt) == 0){
//       isExist = true;
//       break;
//     }
//   }
//   if(isExist){
//     insert_last(&arrKota[i], nama);
//   }else{
//     printf("Kota %s tidak ada di list.\n", kt);
//   }
// }

// void delete_kota(ListKt arrKota[], char* kotaNama){
//   for (int i = 0; i < MAX_KOTA; i++)
//   {
//     if(arrKota[i].head != NULL && strcmp(arrKota[i].head->nm, kotaNama) == 0){
//       destroy_list(&arrKota[i]);
//       return;
//     }
//   }
//   printf("Kota %s tidak ada di list.\n", kotaNama);
// }


// void delete_nama(ListKt arrKota[], char* kt, char* nama, char** temp){
//   bool isExist = false;
//   int i;
//   for (i = 0; i < MAX_KOTA; i++)
//   {
//     if(arrKota[i].head != NULL && strcmp(arrKota[i].head->nm, kt) == 0){
//       isExist = true;
//       break;
//     }
//   }
//   if(isExist){
//     delete_val(&arrKota[i], nama, temp);
//   }else{
//     printf("Kota %s tidak ada di list.\n", kt);
//   }
// }

// void print_all(ListKt arrKota[]){
//   for (int i = 0; i < MAX_KOTA; i++)
//   {
//     if(arrKota[i].head != NULL){
//       print_list(arrKota[i]);
//     }
//   }
// }


// void print_kt(ListKt arrKota[], char* kt){
//   bool isExist = false;
//   int i;
//   for (i = 0; i < MAX_KOTA; i++)
//   {
//     if(arrKota[i].head != NULL && strcmp(arrKota[i].head->nm, kt) == 0){
//       isExist = true;
//       break;
//     }
//   }

//   if(isExist){
//     print_list(arrKota[i]);
//   }else{
//     printf("Kota %s tidak ditemukan.\n", kt);
//   }
// }