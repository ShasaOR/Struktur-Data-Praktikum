#include "mahasiswa.h"
#include <iostream>

void createList(ListMahasiswa &L) {
    L.n = 0;
}

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void inputDataMahasiswa(ListMahasiswa &L) {
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> L.n;
    if (L.n > MAX_MHS) L.n = MAX_MHS;
    
    for (int i = 0; i < L.n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin >> L.tab[i].nama;
        cout << "NIM   : ";
        cin >> L.tab[i].nim;
        cout << "UTS   : ";
        cin >> L.tab[i].uts;
        cout << "UAS   : ";
        cin >> L.tab[i].uas;
        cout << "Tugas : ";
        cin >> L.tab[i].tugas;
        
        L.tab[i].nilaiAkhir = hitungNilaiAkhir(L.tab[i].uts, L.tab[i].uas, L.tab[i].tugas);
    }
}

void tampilkanDataMahasiswa(ListMahasiswa L) {
    cout << "\n================ DAFTAR NILAI MAHASISWA ================\n";
    for (int i = 0; i < L.n; i++) {
        cout << i + 1 << ". Nama: " << L.tab[i].nama 
             << " | NIM: " << L.tab[i].nim 
             << " | Nilai Akhir: " << L.tab[i].nilaiAkhir << endl;
    }
    cout << "========================================================\n";
}