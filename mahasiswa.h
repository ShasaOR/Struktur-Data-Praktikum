#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

const int MAX_MHS = 10;

struct ListMahasiswa {
    Mahasiswa tab[MAX_MHS];
    int n;
};

void createList(ListMahasiswa &L);
float hitungNilaiAkhir(float uts, float uas, float tugas);
void inputDataMahasiswa(ListMahasiswa &L);
void tampilkanDataMahasiswa(ListMahasiswa L);

#endif