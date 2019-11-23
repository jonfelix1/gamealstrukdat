/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define NMaxStr 255
#define BLANK ' '
#define ENTER '\n'

typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
  int Length;
} Kata;

/* State Mesin Kata */
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK */

void STARTKATA(char NamaFile[], boolean file);
/* I.S. : CC sembarang, 'NamaFile' terdefinisi dan ada filenya
   F.S. : CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau EndPita = true;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

/* Operasi Mesinkata */
int CKatatoInt();
/*  Mengembalikan integer dari CKata */

Kata StringtoKata(char s[]);
/* Mengubah string menjadi Kata */

boolean IsSamaKata(Kata kata1,Kata kata2);
/* Mengembalikan true jika kata1=kata2 */

#endif
