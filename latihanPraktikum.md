```markdown
# Laporan Praktikum Modul 3 - Abstract Data Type (ADT) & Pointer

* **Mata Kuliah:** Struktur Data
* **Nama:** Shasa Olivia Rose
* **NIM:** 109082500207
* **Program Studi:** S1 Teknik Informatika
* **Universitas:** Telkom University Purwokerto

---

## I. Tujuan Praktikum
1. Memahami konsep Abstract Data Type (ADT) dan penggunaannya dalam pemrograman modular C++.
2. Mampu mendeklarasikan dan mengimplementasikan struktur data, fungsi, serta prosedur (primitif) ke dalam file terpisah (`.h` dan `.cpp`).
3. Menerapkan penggunaan array, pointer, serta manipulasi data pada struktur data kompleks.

---

## II. Dasar Teori
Abstract Data Type (ADT) adalah model matematika dari struktur data yang mendefinisikan tipe data secara statik beserta sekumpulan operasi dasar (primitif) yang berlaku pada tipe tersebut tanpa mengungkap detail implementasinya. ADT umumnya diimplementasikan dengan membagi program ke dalam beberapa modul:
1. **Header File (`.h`)**: Berisi definisi tipe data (`struct`), konstanta, dan prototipe fungsi/prosedur (primitif).
2. **Implementation File (`.cpp`)**: Berisi realisasi atau body dari fungsi dan prosedur yang telah dideklarasikan.
3. **Driver / Main Program (`main.cpp`)**: Berisi fungsi `main()` untuk menjalankan program utama dan memanggil primitif yang tersedia.

Selain ADT, pemahaman mengenai **pointer** (variabel yang menyimpan alamat memori variabel lain) serta **array 2 dimensi** sangat krusial dalam pengelolaan memori dan struktur data tingkat lanjut.

---

## III. Pembahasan Latihan (Latsol) Modul 3

### 1. Latihan 1: Program Data Mahasiswa Menggunakan Array & ADT
Program ini dirancang untuk menyimpan data mahasiswa maksimal 10 orang menggunakan array dalam ADT. Setiap elemen mahasiswa memiliki field nama, NIM, nilai UTS, nilai UAS, nilai tugas, dan nilai akhir yang dihitung secara otomatis melalui fungsi dengan rumus: 
$$\text{Nilai Akhir} = (0.3 \times \text{UTS}) + (0.4 \times \text{UAS}) + (0.3 \times \text{Tugas})$$

#### Kode Program:
* **`mahasiswa.h`**
```cpp
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

```

* **`mahasiswa.cpp`**

```cpp
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

```

* **`main.cpp` (Latihan 1)**

```cpp
#include "mahasiswa.h"

int main() {
    ListMahasiswa listMhs;
    createList(listMhs);
    inputDataMahasiswa(listMhs);
    tampilkanDataMahasiswa(listMhs);
    return 0;
}

```

---

### 2. Latihan 2: ADT Pelajaran

Latihan ini mengimplementasikan ADT sederhana untuk data pelajaran yang terdiri dari field `namamapel` dan `kodepel`, lengkap dengan fungsi `create_pelajaran` dan prosedur `tampil_pelajaran`.

#### Kode Program:

* **`pelajaran.h`**

```cpp
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct Pelajaran {
    string namamapel;
    string kodepel;
};

Pelajaran create_pelajaran(string namamapel, string kodepel);
void tampil_pelajaran(Pelajaran pel);

#endif

```

* **`pelajaran.cpp`**

```cpp
#include "pelajaran.h"
#include <iostream>

Pelajaran create_pelajaran(string namamapel, string kodepel) {
    Pelajaran pel;
    pel.namamapel = namamapel;
    pel.kodepel = kodepel;
    return pel;
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "nama pelajaran: " << pel.namamapel << endl;
    cout << "nilai: " << pel.kodepel << endl;
}

```

* **`main.cpp` (Latihan 2)**

```cpp
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    Pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}

```

---

### 3. Latihan 3: Manipulasi Array 2D (3x3) & Pointer Integer

Program ini mendemonstrasikan pengoperasian array 2 dimensi berukuran 3x3 dan pointer integer. Program mencakup fungsi/prosedur untuk menampilkan isi array 2D, menukar isi elemen dari dua array 2D pada posisi tertentu, serta menukar nilai yang ditunjuk oleh dua buah pointer.

#### Kode Program:

* **`main.cpp` (Latihan 3)**

```cpp
#include <iostream>

using namespace std;

// Prosedur menampilkan isi array 2D 3x3
void tampilkanArray2D(int arr[3][3], string namaArray) {
    cout << "Isi " << namaArray << ":" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Prosedur menukar isi dari 2 array integer 2D pada posisi tertentu
void tukarElemenArray2D(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        int temp = arr1[baris][kolom];
        arr1[baris][kolom] = arr2[baris][kolom];
        arr2[baris][kolom] = temp;
    } else {
        cout << "Indeks posisi di luar batas (0-2)!" << endl;
    }
}

// Prosedur menukar isi dari variabel yang ditunjuk oleh 2 buah pointer
void tukarNilaiPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int val1 = 10;
    int val2 = 20;
    int *ptr1 = &val1;
    int *ptr2 = &val2;

    cout << "--- KONDISI AWAL ---" << endl;
    tampilkanArray2D(A, "Array A");
    tampilkanArray2D(B, "Array B");
    cout << "Pointer 1 (*ptr1): " << *ptr1 << ", Pointer 2 (*ptr2): " << *ptr2 << endl << endl;

    // Menukar elemen array 2D pada posisi [1][1]
    tukarElemenArray2D(A, B, 1, 1);
    cout << "--- SETELAH TUKAR ELEMEN ARRAY 2D (Posisi [1][1]) ---" << endl;
    tampilkanArray2D(A, "Array A");
    tampilkanArray2D(B, "Array B");
    cout << endl;

    // Menukar nilai variabel yang ditunjuk pointer
    tukarNilaiPointer(ptr1, ptr2);
    cout << "--- SETELAH TUKAR NILAI POINTER ---" << endl;
    cout << "Pointer 1 (*ptr1): " << *ptr1 << ", Pointer 2 (*ptr2): " << *ptr2 << endl;

    return 0;
}

```

---

## IV. Kesimpulan

Melalui praktikum Modul 3 ini, konsep Abstract Data Type (ADT) berhasil diterapkan dengan memisahkan spesifikasi tipe serta primitif ke dalam file header (`.h`) dan file implementasi (`.cpp`). Pemisahan ini membuat kode program lebih terstruktur, mudah dibaca, serta mempermudah maintenance program modular. Selain itu, pemahaman terhadap array, struct, dan pointer terbukti sangat penting dalam menyusun operasi data yang kompleks seperti manipulasi array 2 dimensi.

```

```