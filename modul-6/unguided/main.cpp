
#include <iostream>
#include <string>
#include <limits>
#include "Buku.h"

using namespace std;

bool inputBuku(List &L) {
    infotype data;

    cout << "Masukkan kode buku: ";
    cin >> data.kodeBuku;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Masukkan judul buku: ";
    getline(cin, data.judul);

    cout << "Masukkan tahun terbit: ";
    cin >> data.thnTerbit;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (findElm(L, data.kodeBuku) != Nil) {
        cout << "Kode buku sudah terdaftar." << endl;
        return false;
    }

    insertLast(L, alokasi(data));
    cout << "Data buku berhasil ditambahkan." << endl;

    return true;
}

int main() {
    List L;
    CreateList(L);

    // Latihan 1: Memasukkan empat data buku
    for (int i = 0; i < 4; i++) {
        cout << "\nData buku ke-" << i + 1 << endl;
        inputBuku(L);
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    // Latihan 2: Mencari buku
    string kodeCari;

    cout << "\nMasukkan kode buku yang dicari: ";
    getline(cin, kodeCari);

    address hasil = findElm(L, kodeCari);

    if (hasil != Nil) {
        cout << "\nData buku ditemukan." << endl;
        cout << "Kode Buku    : " << hasil->info.kodeBuku << endl;
        cout << "Judul        : " << hasil->info.judul << endl;
        cout << "Tahun Terbit : " << hasil->info.thnTerbit << endl;
    } else {
        cout << "Data dengan kode buku " << kodeCari
             << " tidak ditemukan." << endl;
    }

    // Latihan 3: Menghapus buku
    string kodeHapus;
    bool hapusBerhasil;

    cout << "\nMasukkan kode buku yang akan dihapus: ";
    getline(cin, kodeHapus);

    deleteElm(L, kodeHapus, hapusBerhasil);

    if (hapusBerhasil) {
        cout << "Data dengan kode buku " << kodeHapus
             << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan kode buku " << kodeHapus
             << " tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST 1 SETELAH PENGHAPUSAN" << endl;
    printInfo(L);

    // Membebaskan seluruh node
    while (L.First != Nil) {
        address P = L.First;
        L.First = L.First->next;
        dealokasi(P);
    }

    L.Last = Nil;

    return 0;
}
