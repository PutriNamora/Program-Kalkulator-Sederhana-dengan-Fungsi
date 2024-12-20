/*
    Nama File      : MODUL7.c 
	Programmer     : Putri Namora 
	Tgl. pembuatan : 10/11/24
	Deskripsi      : Menampilkan Elemen Array
*/

#include <stdio.h>

void judul(){
    printf("===============================================\n");
    printf("|            Menampilkan Elemen Array         |\n");
    printf("|---------------------------------------------|\n");
    printf("| PROGRAMMER : PUTRI NAMORA                   |\n");
    printf("| NIM        : 24343019                       |\n");
    printf("===============================================\n");
}
int main() {
    judul();
    int angka[5] = {10, 20, 30, 40, 50};
    for(int i = 0; i < 5; i++) {
        printf("Angka ke-%d: %d\n", i + 1, angka[i]);
    }
    return 0;
}