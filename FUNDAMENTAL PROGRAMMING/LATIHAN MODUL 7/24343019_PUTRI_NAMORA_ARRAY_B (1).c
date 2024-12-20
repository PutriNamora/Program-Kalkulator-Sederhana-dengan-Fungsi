/*
    Nama File      : MODUL7.c 
	Programmer     : Putri Namora
	Tgl. pembuatan : 10/11/24
	Deskripsi      : Menjumlahkan Elemen Array
*/

#include <stdio.h>

void judul(){
    printf("===============================================\n");
    printf("|            Menjumlahkan Elemen Array        |\n");
    printf("|---------------------------------------------|\n");
    printf("| PROGRAMMER : PUTRI NAMORA                   |\n");
    printf("| NIM        : 24343019                       |\n");
    printf("===============================================\n");
}

int main() {
    judul();
    int angka[5] = {10, 20, 30, 40, 50};
    int jumlah = 0;
    for(int i = 0; i < 5; i++) {
        printf("Angka ke-%d: %d\n", i + 1, angka[i]);
    }
    for(int i = 0; i < 5; i++) {
        jumlah += angka[i];
    }
    printf("Jumlah semua elemen array: %d\n", jumlah);
    return 0;
}