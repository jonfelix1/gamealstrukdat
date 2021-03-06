/* Nama file: stackt.h */
/* Copyright: Kelompok 11 K-1 IF2110 2019/2020 */

#ifndef stackt_H
#define stackt_H

#include "../boolean.h"
#include "../bangunan/bangunan.h"

#define MaxElStack 100
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef struct {
  BANGUNAN bangunan;  // bangunan sebelum di lakukan suatu aksi
  int idBangunan;   // no id bangunan
  int jenis;
  /* penanda jenis elemen stack untuk suatu command
    -1 : ATTACK yang tidak berpindah kepemilikan atau MOVE (dapat dijadikan sama)
    0 : LEVEL_UP
    >0 : ATTACK yang berpindah kepemilikan (merepresentasikan posisi dalam list) */ 
  boolean CH; // Critical Hit
} infoStack;

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  infoStack T[MaxElStack+1]; /* tabel penyimpan elemen */
  int TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxElStack] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 1.. MaxElStack+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

infoStack MakeInfoStack(BANGUNAN B, int id, int jenis, boolean CH);
/* Membuat infoStack */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infoStack X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infoStack* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif