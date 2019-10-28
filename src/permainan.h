/* Nama file: permainan.h */
/* Copyright: Kelompok 11 K-1 IF2110 2019/2020 */

#ifndef __PERMAINAN_H__
#define __PERMAINAN_H__

#include "tabbangunan.h"
#include "matriks.h"
#include "listbangunan.h"

typedef struct{
    int N,M; // Menyimpan ukuran peta
    int B; // Menyimpan banyak bangunan
    TabBANGUNAN DaftarBangunan; // Menyimpan daftar bangunan
    MATRIKS Peta;
    List ListBangunanPlayer1;
    List ListBangunanPlayer2;
} Permainan;

/* ********** SELEKTOR ********** */
#define TinggiPeta(P) (P).N
#define LebarPeta(P) (P).M
#define JumlahBangunan(P) (P).B
#define DaftarBangunan(P) (P).DaftarBangunan
#define Peta(P) (P).Peta
#define ListBangunanP1(P) (P).ListBangunanPlayer1
#define ListBangunanP2(P) (P).ListBangunanPlayer2

void BacaKonfigurasi(char NamaFile[],Permainan *Perm);
/*  Membaca konfigurasi file dari 'NamaFile'
    I.S. = 'NamaFile' terdefinisi dan ada
    F.S. = Variabel Perm terinisialisasi */

void TulisPetaPermainan (Permainan Perm);
/* Prosedur yang serupa seperti TulisMATRIKS namun mengganti memberikan output */
/* berupa character sesuai integer yang ada pada konvensi sebagai berikut */
/* Elmt(Peta(Perm),i,j) = -1 maka cetak '*' */
/* Elmt(Peta(Perm),i,j = 0 maka cetak ' ' */
/* else maka TulisBANGUNAN(Elmt(Peta(Perm), i, j)) */

void TulisBangunanPlayer(List L,TabBANGUNAN tabBangunan);
/* Menuliskan daftar bangunan dari suatu player */

#endif