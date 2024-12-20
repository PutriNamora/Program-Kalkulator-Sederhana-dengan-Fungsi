/*
    Nama File      : MODUL6.c 
	Programmer     : Putri Namora
	Tgl. pembuatan : 9/11/24
	Deskripsi      : Menggabungkan Dua String
*/

#include <stdio.h>
#include <string.h>

// Deklarasi fungsi gabungkanString
void gabungkanString(char str1[], char str2[], char hasil[]);
void judul();
int main() {
    judul();
    char str1[50];  
    char str2[50];  
    char hasil[100]; 

    printf("Masukkan string pertama: ");
    scanf("%s", str1);

    printf("Masukkan string kedua  : ");
    scanf("%s", str2);

    // Menggabungkan string
    gabungkanString(str1, str2, hasil);

    // Menampilkan hasil penggabungan
    printf("Hasil penggabungan string: %s\n", hasil);

    return 0;
}
void judul(){
    printf("===============================================\n");
    printf("|         Menggabungkan 2 Buah String         |\n");
    printf("|---------------------------------------------|\n");
    printf("| PROGRAMMER : PUTRI NAMORA                   |\n");
    printf("| NIM        : 24343019                       |\n");
    printf("===============================================\n");
}
void gabungkanString(char str1[], char str2[], char hasil[]) {
 
    strcpy(hasil, str1);
 
    strcat(hasil, str2);
}