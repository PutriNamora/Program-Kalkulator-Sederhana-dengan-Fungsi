#include <stdio.h>
int main() {
    // Deklarasi variabel 
    float nilaiTugas, nilaiUTS, nilaiUAS, nilaiAkhir;
    int lulus;

    // Input nilai dari pengguna 
    printf("Masukkan nilai tugas (0-100):");
    scanf("%f", &nilaiTugas); 
    printf("Masukkan nilai UTS (0-100):");
    scanf("%f", &nilaiUTS); 
    printf("Masukkan nilai UAS(0-100):");
    scanf("%f", &nilaiUAS); 

    // Hitung nilai akhir 
    nilaiAkhir = (0.3 * nilaiTugas) + (0.3 * nilaiUTS) + (0.4 * nilaiUAS);

    // Penentuan kelulusan 
    lulus = (nilaiAkhir >= 60) && (nilaiUAS >= 50);

    // output 
    printf("\n Nilai Akhir Anda Adalah : %.2f\n" , nilaiAkhir);

    if (lulus) {
        printf("Selamat Anda Lulus");
    } else {
        printf("Maaf, Anda Tidak Lulus");
    }
    
    return 0;
}
