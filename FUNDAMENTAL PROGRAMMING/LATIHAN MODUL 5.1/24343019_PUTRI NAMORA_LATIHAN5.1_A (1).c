#include<stdio.h>

//fungsi untuk menghitung luas persegi panajang 
int hitungLuasPP(int panjang, int lebar){
    return panjang * lebar;
}

int main(){

    printf(" \t Luas Persegi Panjang\n");
    printf("\t=======================\n");
    printf("Nama    : Putri Namora\n");
    printf("NIM     : 24343019\n");
   

    int panjang, lebar;

    printf("Masukkan panjang: ");
    scanf("%d", &panjang);
    printf("Masukkan lebar: ");
    scanf("%d", &lebar);

    //memangggil fungsi dan menampilkan hasil
    int luas = hitungLuasPP(panjang, lebar);
    printf("Luas persegi panjang adalah: %d\n", luas);

    return 0;
}
