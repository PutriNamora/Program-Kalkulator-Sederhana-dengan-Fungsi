#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menampilkan identitas program
void judul() {
    printf("===============================================\n");
    printf("|               KALKULATOR SEDERHANA          |\n");
    printf("|---------------------------------------------|\n");
    printf("| PROGRAMMER : PUTRI NAMORA                   |\n");
    printf("| NIM        : 24343019                       |\n");
    printf("===============================================\n");
}

// Fungsi untuk menghitung penjumlahan
float tambahkan(float a, float b) {
    return a + b;
}

// Fungsi untuk menghitung pengurangan
float kurangkan(float a, float b) {
    return a - b;
}

// Fungsi untuk menghitung perkalian
float kalikan(float a, float b) {
    return a * b;
}

// Fungsi untuk menghitung pembagian
float bagikan(float a, float b) {
    if (b == 0) {
        printf("Kesalahan: Pembagian dengan nol tidak diperbolehkan.\n");
        return 0;
    }
    return a / b;
}

// Fungsi untuk operasi kalkulator menggunakan file
void kalkulatorFile() {
    FILE *inputFile, *outputFile;
    char operator;
    float a, b, hasil;

    // Membuka file input_7.txt untuk membaca
    inputFile = fopen("C:\\Users\\user\\.vscode\\YA ALLAH\\input_7.txt", "r");
    if (inputFile == NULL) {
        printf("File input_7.txt tidak dapat dibuka!\n");
        return;
    }

    // Membuka atau membuat file output_7.txt untuk menulis
    outputFile = fopen("C:\\Users\\user\\.vscode\\YA ALLAH\\output_7.txt", "w");
    if (outputFile == NULL) {
        printf("File output_7.txt tidak dapat dibuat!\n");
        fclose(inputFile);
        return;
    }

    // Membaca setiap baris dari file input dan memproses operasinya
    while (fscanf(inputFile, "%f %c %f", &a, &operator, &b) != EOF) {
        switch (operator) {
            case '+':
                hasil = tambahkan(a, b);
                break;
            case '-':
                hasil = kurangkan(a, b);
                break;
            case '*':
                hasil = kalikan(a, b);
                break;
            case '/':
                hasil = bagikan(a, b);
                break;
            default:
                fprintf(outputFile, "%.2f %c %.2f = Error: Operator tidak valid\n", a, operator, b);
                continue;
        }

        // Menulis hasil ke file output
        if (operator == '/' && b == 0) {
            fprintf(outputFile, "%.2f %c %.2f = Error: Pembagian dengan nol\n", a, operator, b);
        } else {
            fprintf(outputFile, "%.2f %c %.2f = %.4f\n", a, operator, b, hasil);
        }
    }

    printf("Hasil operasi dari file telah disimpan ke file output_7.txt\n");

    // Menutup file
    fclose(inputFile);
    fclose(outputFile);
}

// Fungsi untuk operasi kalkulator secara langsung (manual)
void kalkulatorManual() {
    char operator;
    float a, b, hasil;

    // Input ekspresi
    printf("Masukkan ekspresi (contoh: 5 * 5): ");
    scanf("%f %c %f", &a, &operator, &b);

    // Memproses operasi
    switch (operator) {
        case '+':
            hasil = tambahkan(a, b);
            printf("Hasil: %.4f\n", hasil);
            break;
        case '-':
            hasil = kurangkan(a, b);
            printf("Hasil: %.4f\n", hasil);
            break;
        case '*':
            hasil = kalikan(a, b);
            printf("Hasil: %.4f\n", hasil);
            break;
        case '/':
            hasil = bagikan(a, b);
            if (b != 0) {
                printf("Hasil: %.4f\n", hasil);
            }
            break;
        default:
            printf("Operator tidak valid!\n");
    }
}

int main() {
    int pilihan;
    char lagi;

    judul();

    do {
        // Menampilkan menu
        printf("\n=== Menu Kalkulator ===\n");
        printf("1. Kalkulator Manual (Input dari Terminal)\n");
        printf("2. Kalkulator dari File (input_7.txt)\n");
        printf("3. Keluar\n");
        printf("Pilih opsi (1-3): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                kalkulatorManual();
                break;
            case 2:
                kalkulatorFile();
                break;
            case 3:
                printf("Terima kasih telah menggunakan kalkulator sederhana!\n");
                exit(0);
            default:
                printf("Pilihan tidak valid! Silakan pilih opsi 1-3.\n");
        }

        // Menanyakan apakah pengguna ingin menggunakan program lagi
        printf("\nApakah Anda ingin menggunakan kalkulator lagi? (y/n): ");
        scanf(" %c", &lagi);
    } while (lagi == 'y' || lagi == 'Y');

    printf("Terima kasih telah menggunakan kalkulator sederhana!\n");
    return 0;
}