/* 	Nama File		: Latihan9.c
	Programmer		: Putri Namora 24343019
	Tgl. pembuatan	: 22/11/2024
	Deskripsi		: Pengolahan FILE
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    char nama[50];
    char nim[15];
    char jurusan[30];
};

int main() {
    struct Mahasiswa mahasiswa[100];
    int jumlahMahasiswa = 0;

    // Membaca file input.txt
    FILE *inputFile = fopen("C:\\Users\\user\\.vscode\\input.txt", "r");
    if (inputFile == NULL) {
        printf("File input.txt tidak dapat dibuka!\n");
        return 1;
    }

    // Membaca data dari file dan menyimpannya dalam array of struct
    while (fscanf(inputFile, "%s %s %s", mahasiswa[jumlahMahasiswa].nama, 
           mahasiswa[jumlahMahasiswa].nim, 
           mahasiswa[jumlahMahasiswa].jurusan) != EOF) {
        jumlahMahasiswa++;
    }
    fclose(inputFile);

    // Menampilkan data yang telah dibaca
    printf("Data Mahasiswa dari File:\n");
    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("Nama: %s, NIM: %s, Jurusan: %s\n", 
               mahasiswa[i].nama, mahasiswa[i].nim, mahasiswa[i].jurusan);
    }

    // Meminta input data mahasiswa baru
    printf("Masukkan data mahasiswa baru:\n");
    printf("Nama: ");
    scanf("%s", mahasiswa[jumlahMahasiswa].nama);
    printf("NIM: ");
    scanf("%s", mahasiswa[jumlahMahasiswa].nim);
    printf("Jurusan: ");
    scanf("%s", mahasiswa[jumlahMahasiswa].jurusan);
    jumlahMahasiswa++;

    // Menulis seluruh data ke file output.txt
    FILE *outputFile = fopen("C:\\Users\\user\\.vscode\\output.txt", "w");
    if (outputFile == NULL) {
        printf("File output.txt tidak dapat dibuat!\n");
        return 1;
    }
    for (int i = 0; i < jumlahMahasiswa; i++) {
        fprintf(outputFile, "%s %s %s\n", 
                mahasiswa[i].nama, mahasiswa[i].nim, mahasiswa[i].jurusan);
    }
    fclose(outputFile);

    printf("Data berhasil disimpan ke output.txt!\n");

    return 0;
}
