#include <iostream>

using namespace std;

// Array Global / Konstanta
const int SIZE = 10;
int arrA[SIZE] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};

void tampilkanArray() {
    cout << "Isi Array A: [ ";
    for (int i = 0; i < SIZE; i++) {
        cout << arrA[i] << (i == SIZE - 1 ? "" : ", ");
    }
    cout << " ]\n";
}

int cariMaksimum() {
    int maxVal = arrA[0];
    for (int i = 1; i < SIZE; i++) {
        if (arrA[i] > maxVal) {
            maxVal = arrA[i];
        }
    }
    return maxVal;
}

int cariMinimum() {
    int minVal = arrA[0];
    for (int i = 1; i < SIZE; i++) {
        if (arrA[i] < minVal) {
            minVal = arrA[i];
        }
    }
    return minVal;
}

void hitungRataRata() {
    double total = 0;
    for (int i = 0; i < SIZE; i++) {
        total += arrA[i];
    }
    double avg = total / SIZE;
    cout << "Nilai Rata-rata Array: " << avg << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata - rata\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanArray();
                break;
            case 2:
                cout << "Nilai Maksimum: " << cariMaksimum() << endl;
                break;
            case 3:
                cout << "Nilai Minimum: " << cariMinimum() << endl;
                break;
            case 4:
                hitungRataRata();
                break;
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}