
#include <iostream>
#include <string>
#include <limits>
#include "Doublylist.h"

using namespace std;

void inputData(List &L) {
    infotype data;

    cout << "Masukkan nomor polisi: ";
    getline(cin, data.nopol);

    cout << "Masukkan warna kendaraan: ";
    getline(cin, data.warna);

    cout << "Masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (findElm(L, data.nopol) == Nil) {
        address P = alokasi(data);
        insertLast(L, P);
        cout << "Data berhasil ditambahkan.\n";
    } else {
        cout << "Nomor polisi sudah terdaftar.\n";
    }

    cout << endl;
}

int main() {
    List L;
    CreateList(L);

    address P;

    // Latihan 1: Input empat data kendaraan
    for (int i = 0; i < 4; i++) {
        cout << "Data kendaraan ke-" << i + 1 << endl;
        inputData(L);
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    // Latihan 2: Mencari data kendaraan
    string nopolCari;

    cout << "\nMasukkan nomor polisi yang dicari: ";
    getline(cin, nopolCari);

    P = findElm(L, nopolCari);

    if (P != Nil) {
        cout << "\nData kendaraan ditemukan." << endl;
        cout << "Nomor polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi "
             << nopolCari << " tidak ditemukan." << endl;
    }

    // Latihan 3: Menghapus data kendaraan
    string nopolHapus;
    bool hapusBerhasil;

    cout << "\nMasukkan nomor polisi yang akan dihapus: ";
    getline(cin, nopolHapus);

    deleteElm(L, nopolHapus, hapusBerhasil);

    if (hapusBerhasil) {
        cout << "Data dengan nomor polisi "
             << nopolHapus << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi "
             << nopolHapus << " tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST 1 SETELAH PENGHAPUSAN" << endl;
    printInfo(L);

    return 0;
}
