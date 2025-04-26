#ifndef ARAAY_TO_SLL_H
#define ARAAY_TO_SLL_H

#include "linked_list/linked_list.h"
#include "warga.h"

// typedef LinkedList ListKt;

typedef struct Kota{
  char* kt;
  Warga pWarga;
} Kota;

typedef struct KotaArr{
  // Array dinamis dari kota
  Kota *kota;
  // Ukuran array
  int size;
} KotaArr;

void init_arr(KotaArr *kotaArr);
void init_kt(Kota *kota);
void insert_kt(KotaArr *kotaArr, char* kt);
void delete_kt(KotaArr *kotaArr, char* kt);
void print_kota(KotaArr kotaArr);
bool isArrayFull(KotaArr kotaArr);

void delete_warga(KotaArr *kotaArr, char* kt, char* nm, char** temp);
void insert_warga(KotaArr *kotaArr, char* kt, char* nm);
void print_warga(KotaArr kotaArr, char* kt);
void destroy_warga(KotaArr *kotaArr, char* kt);
void destroy_all_warga(KotaArr *kotaArr);


int get_jumlah_kota(KotaArr kotaArr);
int get_jumlah_warga(KotaArr kotaArr, char* kt);
int get_jumlah_warga_all(KotaArr kotaArr);







// // Inisialisasi Array kota dengan list kosong
// void init_arr(ListKt *arrKota, int size);
// // insert kota ke dalam array
// void insert_kota(ListKt arrKota[], char* kotaNama);
// // insert nama orang ke kota tertentu
// void insert_nama(ListKt arrKota[], char* kt, char* nama);
// // Hapus kota tertentu, index akan berubah menjadi list kosong
// void delete_kota(ListKt arrKota[], char* kotaNama);
// // Hapus orang tertentu di kota tertentu
// void delete_nama(ListKt arrKota[], char* kt, char* nama, char** temp);
// // Tampilkan pendudukan di semua kota
// void print_all(ListKt arrKota[]);
// // Tampilkan kota tertentu saja
// void print_kt(ListKt arrKota[], char* kt);

#endif // ARAAY_TO_SLL_H