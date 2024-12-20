/*
    Nama File      : TUGAS4.c 
	Programmer     : Putri Namora 
	Tgl. pembuatan : 10/11/24
	Deskripsi      : Program Kepustakaan Sederhana
*/

#include <stdio.h>
#include <string.h>

#define MAX_BUKU 135 
#define MAX_STRING 135 

// Definisi struct Buku
struct Buku {
    char judul[MAX_STRING];
    char pengarang[MAX_STRING];
    int tahun;
};

void tambahBuku(struct Buku *perpustakaan, int *jumlahBuku);
void tampilkanBuku(struct Buku *perpustakaan, int jumlahBuku);
void cariBuku(struct Buku *perpustakaan, int jumlahBuku, char *judulCari);

int main() {
	printf("=====================================================================\n");
    printf("\t Nama                : PUTRI NAMORA\n");
    printf("\t NIM                 : 24343019\n");
    printf("\t Prodi               : Informatika\n");
    printf("\t Tugas               : Tugas 4\n");
    printf("\t Mata Kuliah         : Fundamental Pemograman\n");
    printf("\t Deskripsi           : Program Kepustakaan Sederhana\n");
    printf("=====================================================================\n");
    struct Buku perpustakaan[MAX_BUKU]; // Array untuk menyimpan buku
    int jumlahBuku = 0; // Jumlah buku saat ini
    int pilihan;
    char judulCari[MAX_STRING];

    do {
        // Menu utama
        printf("=====================================================================\n");
        printf("\t1. Menambahkan Buku Baru ke Daftar\n");
        printf("\t2. Menampilkan Buku yang Tersedia di Daftar\n");
        printf("\t3. Mencari Judul Buku yang Tersedia di Daftar\n");
        printf("\t4. Keluar\n");
        printf("=====================================================================\n");
        printf("Masukkan Menu yang Ingin Anda Pilih (1/2/3/4): ");
        scanf("%d", &pilihan);
        getchar(); // Membersihkan karakter newline dari buffer input

        switch (pilihan) {
            case 1:
                tambahBuku(perpustakaan, &jumlahBuku);
                break;
            case 2:
                tampilkanBuku(perpustakaan, jumlahBuku);
                break;
            case 3:
                printf("Masukkan judul buku yang ingin dicari: ");
                fgets(judulCari, MAX_STRING, stdin);
                judulCari[strcspn(judulCari, "\n")] = 0; // Menghapus karakter newline
                cariBuku(perpustakaan, jumlahBuku, judulCari);
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 4);

    return 0;
}

// Fungsi untuk menambah buku
void tambahBuku(struct Buku *perpustakaan, int *jumlahBuku) {
    if (*jumlahBuku < MAX_BUKU) {
        printf("\nMasukkan judul buku: ");
        fgets(perpustakaan[*jumlahBuku].judul, MAX_STRING, stdin);
        perpustakaan[*jumlahBuku].judul[strcspn(perpustakaan[*jumlahBuku].judul, "\n")] = 0;

        printf("Masukkan pengarang buku: ");
        fgets(perpustakaan[*jumlahBuku].pengarang, MAX_STRING, stdin);
        perpustakaan[*jumlahBuku].pengarang[strcspn(perpustakaan[*jumlahBuku].pengarang, "\n")] = 0;

        printf("Masukkan tahun terbit: ");
        scanf("%d", &perpustakaan[*jumlahBuku].tahun);
        getchar(); // Membersihkan newline dari input

        (*jumlahBuku)++;
        printf("\nBuku berhasil ditambahkan!\n");
    } else {
        printf("Perpustakaan penuh, tidak bisa menambah buku lagi!\n");
    }
}

// Fungsi untuk menampilkan semua buku
void tampilkanBuku(struct Buku *perpustakaan, int jumlahBuku) {
    if (jumlahBuku == 0) {
        printf("Tidak ada buku di perpustakaan.\n");
    } else {
        printf("================================================================\n");
        printf("Daftar Buku\n");
        printf("================================================================\n");
        for (int i = 0; i < jumlahBuku; i++) {
            printf("\nBuku %d:\n", i + 1);
            printf("Judul    : %s\n", perpustakaan[i].judul);
            printf("Pengarang: %s\n", perpustakaan[i].pengarang);
            printf("Tahun    : %d\n", perpustakaan[i].tahun);
            printf("\n");
        }
    }
}

// Fungsi untuk mencari buku berdasarkan judul
void cariBuku(struct Buku *perpustakaan, int jumlahBuku, char *judulCari) {
    int ditemukan = 0;
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(perpustakaan[i].judul, judulCari) == 0) {
            printf("\nBuku ditemukan:\n");
            printf("Judul    : %s\n", perpustakaan[i].judul);
            printf("Pengarang: %s\n", perpustakaan[i].pengarang);
            printf("Tahun    : %d\n", perpustakaan[i].tahun);
            ditemukan = 1;
            break;
        }
    }

    if (!ditemukan) {
        printf("\nBuku '%s' tidak ditemukan. Mungkin buku '%s' belum terdaftar atau terdapat kesalahan ejaan pada ketikan anda.\n", judulCari);
    }
}
