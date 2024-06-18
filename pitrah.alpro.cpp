#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int saldo = 200000;
const int PIN = 1234;


void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}
const int MAX_ATTEMPTS = 3;

int login() {
    int pin_input, attempts = 0;
    
    while (attempts < MAX_ATTEMPTS) {
        clearScreen();
        printf("Masukkan PIN atm anda : ");
        scanf("%d", &pin_input);
        if (pin_input == PIN) {
            return 1; // Login berhasil
        } else {
            printf("PIN salah. Silakan coba lagi.\n");
            attempts++;
        }
    }
    return 0; // Login gagal
}

void tarikTunai() {
    clearScreen();
    int jumlah;
    printf("Masukkan jumlah uang yang akan ditarik:\n");
    scanf("%d", &jumlah);
    
    if (jumlah <= saldo) {
        saldo -= jumlah;
        printf("Penarikan berhasil. Saldo Anda sekarang: %d\n", saldo);
    } else {
        printf("Saldo tidak mencukupi.\n");
    }
}

void transfer() {
    clearScreen();
    int jumlah;
    
    printf("Masukkan jumlah yang ingin anda transfer: ");
    scanf("%d", &jumlah);
    if (jumlah <= saldo) {
        saldo -= jumlah;
        printf("Transfer berhasil. Saldo Anda sekarang: %d\n", saldo);
    } else {
        printf("Saldo tidak mencukupi.\n");
    }
}

void setorTunai() {
    clearScreen();
    int jumlah;
    
    printf("Masukkan jumlah yang ingin anda setor: ");
    scanf("%d", &jumlah);
    saldo += jumlah;
    printf("Setoran berhasil. Saldo Anda sekarang: %d\n", saldo);
}

void cekSaldo() {
    clearScreen();
   
    printf("Saldo Anda saat ini: %d\n", saldo);
}

void topUp() {
    clearScreen();
    int pilihan, jumlah;
    printf("____ATM FITRAH___\n");
    printf("Pilih layanan Top Up:\n");
    printf("1. DANA\n");
    printf("2. SHOPEEPAY\n");
    printf("Pilihan Anda: ");
    scanf("%d", &pilihan);
    
    printf("Masukkan jumlah yang akan di-top up: ");
    scanf("%d", &jumlah);

    if (jumlah <= saldo) {
        saldo -= jumlah;
        switch (pilihan) {
            case 1:
                printf("Top up ke DANA berhasil. Sisa saldo anda : %d\n", saldo);
                break;
            case 2:
                printf("Top up ke SHOPEEPAY berhasil. Sisa saldo anda: %d\n", saldo);
                break;
            default:
                printf("Pilihan tidak valid. Top up gagal.\n");
                saldo += jumlah; // Kembalikan saldo
        }
    } else {
        printf("Maaf Saldo anda tidak mencukupi.\n");
    }
}

int main() {
    if (!login()) {
        printf("Kartu Anda tidak dapat digunakan.\n");
        exit(0);
    }

    int pilihan;
    while (1) {
        clearScreen();
        printf("___ATM FITRAH___\n");
        printf("Menu Transaksi:\n");
        printf("1. Tarik Tunai \n");
        printf("2. Transfer \n");
        printf("3. Cek Saldo \n");
        printf("Silakan pilih menu (Angka): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                if (login()) {
                    tarikTunai();
                }
                break;
            case 2:
                if (login()) {
                    transfer();
                }
                break;
            case 3:
                if (login()) {
                    cekSaldo();
                }
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
        printf("\n TEKAN ENTER JIKA UDAH SELESAI...");
        getchar(); // Menunggu input pengguna
        getchar();
    }

    return 0;
}

