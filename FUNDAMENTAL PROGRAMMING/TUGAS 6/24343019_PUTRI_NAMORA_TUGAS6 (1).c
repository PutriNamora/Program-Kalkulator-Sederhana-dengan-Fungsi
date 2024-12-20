/* 
   Nama File          : Tugas6.c
   Programmer         : Putri Namora / 24343019
   Tanggal Pengkodean : Jumat, 22 November 2024
   Deskripsi          : Program ini menampilkan input teks
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

// Untuk mengukur waktu eksekusi
#define MAX_BUFFER 1000 // Ukuran buffer untuk membaca file

// Fungsi untuk menghitung kata dalam file
int hitungKata(FILE *file) {
    char buffer[MAX_BUFFER];
    int jumlahKata = 0;
    char *kata;

    // Baca file baris per baris dan hitung jumlah kata
    while (fgets(buffer, MAX_BUFFER, file) != NULL) {
        kata = strtok(buffer, " \t\n"); // Tokenisasi string dengan delimiter spasi, tab, atau newline
        while (kata != NULL) {
            jumlahKata++; // Tambahkan jumlah kata
            kata = strtok(NULL, " \t\n"); // Ambil kata berikutnya
        }
    }

    return jumlahKata;
}

int main() {
    FILE *file;
    char namaFile[100];
    int jumlahKata;
    clock_t start, end; // Untuk mengukur waktu
    double waktuEksekusi;
	printf("________________________________________________________________________________________________________________________\n");
    printf("\t\t\t\t Nama                : Putri Namora\n");
    printf("\t\t\t\t NIM                 : 24343019\n");
    printf("\t\t\t\t Prodi               : Informatika\n");
    printf("\t\t\t\t Tugas               : Tugas 6\n");
    printf("\t\t\t\t Mata Kuliah         : Fundamental Pemograman\n");
    printf("\t\t\t\t Deskripsi           : Program ini menampilkan input teks\n");
    printf("________________________________________________________________________________________________________________________\n\n");
    
    // Meminta pengguna memasukkan nama file
    printf("Masukkan nama file: ");
    scanf("%s", namaFile);

    // Membuka file
    file = fopen(namaFile, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s.\n", namaFile);
        return 1;
    }

    // Mengukur waktu mulai
    start = clock();

    // Menghitung jumlah kata dalam file
    jumlahKata = hitungKata(file);

    // Mengukur waktu selesai
    end = clock();

    // Menghitung waktu eksekusi dalam detik
    waktuEksekusi = (double)(end - start) / CLOCKS_PER_SEC;

    // Menutup file
    fclose(file);

    // Menampilkan hasil
    printf("Jumlah kata dalam file: %d\n", jumlahKata);
    printf("Waktu eksekusi: %.5f detik\n", waktuEksekusi);

    return 0;
}
