/* Nama file: bangunan.h */
/* Copyright: Kelompok 11 K-1 IF2110 2019/2020 */

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "boolean.h"

#define Nil NULL

/* 
    FirstGraph -> [Info] -> [Info] -> [Info] -> [/]
                    |          |         |
                    V          V         V   
                  [Info]      [/]     [Info]
                    |                    |
                    V                    V
                   [/]                  [/]
*/

typedef int infotype;
// Alamat sebuah elemen untuk vertice pada graph
typedef struct tVERTICE *adrver; 
// Alamat sebuah elemen untuk adjacent dari sebuah vertice
typedef struct tADJ *adradj;

typedef struct tVERTICE {
    infotype InfoVer; // ID Bangunan
    adradj FirstAdj;
    adrver NextVer; 
} VERTICE;

typedef struct tADJ {
    infotype InfoAdj; // ID Bangunan
    adradj NextAdj;
} ADJ; 

typedef struct {
    adrver FirstVer ; 
} GraphBANGUNAN;

/* Selektor untuk address vertice */
#define InfoVer(V) (V)->InfoVer
#define FirstAdj(V) (V)->FirstAdj
#define NextVer(V) (V)->NextVer
/* Selektor untuk addres adjacent*/
#define NextAdj(A) (A)->NextAdj
#define InfoAdj(A) (A)->InfoAdj
/* Selektor untuk adress vertice pertama pada graph */
#define FirstVer(G) (G).FirstVer

/* Definisi GraphBANGUNAN : */
/* GraphBANGUNAN kosong : Semua FirstAdjacent(V) = Nil */
/* Setiap vertice dengan adrvertice P dapat diacu InfoVer(P), NextVer(P), FirstAdj(P) */
/* Setiap adjacent dengan adradj P dapat diacu dengan InfoAdj(P), NextAdj(P) */
/* Elemen terakhir vertice : jika addressnya Last, maka NextVer(Last)=Nil */
/* Elemen terakhir adjacent : jika addressnya Last, maka NextAdj(Last)=Nil */

adrver AlokasiVer (infotype X);
/* Melakukan alokasi sebesar infotype */
/* Jika berhasil, maka dihasilkan P yaitu adrver */
/* dengan InfoVer(P) = X, NextVer = Nil, NextAdj = Nil */

adradj AlokasiAdj (infotype X);
/* Melakukan alokasi sebesar infotype */
/* Jika berhasil, maka dihasilkan P yaitu adradj */
/* dengan InfoAdj(P) = X, NextAdj = Nil */

void DealokasiVer (adrver *P);

void DealokasiAdj (adradj *P);

void CreateGraph(GraphBANGUNAN *G, int V);
/* Membuat graph kosong sesuai definisi diatas */
/* Jumlah vertice pada G adalah V */

void MakeTerhubung(GraphBANGUNAN *G, int V1, int V2);
/* Menambahkan V2 sebagai adjacent dari V1, dan V1 sebagai adjacent dari V2 */

adrver SearchVer (GraphBANGUNAN G, infotype X);

adradj SearchAdj (adrver V, infotype X);

void InsVLastVer (GraphBANGUNAN *G, infotype X);
/* Melakukan alokasi P, jika berhasil maka */
/* menambahkan elemen alamat P, dengan InfoVer(P) = X, diakhir list vertice */

void InsVLastAdj (GraphBANGUNAN *G, infotype X);
/* Melakukan alokasi P, jika berhasil maka */
/* menambahkan elemen alamat P, dengan InfoAdj(P) = X, diakhir list adjacent */

void PrintKeterhubungan(GraphBANGUNAN G);
/* Mencetak ke layar semua vertice dan adjacentnya */
/* Format penulisan: vi -> adj1 -> adj2 -> ... -> adjn */

#endif