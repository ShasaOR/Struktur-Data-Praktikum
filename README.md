# <h1 align="center">Laporan Praktikum Modul 2 - Array, Pointer & Reference</h1>
<p align="center">Shasa Olivia Rose - 23111021xx</p>

## Dasar Teori
Struktur data dasar dalam bahasa C++ mencakup penggunaan array, pointer, reference, serta operasi matriks. 

### A. Matriks dan Array
Array adalah kumpulan elemen data yang bertipe sama yang disimpan di dalam alamat memori yang berdekatan. Array satu dimensi merepresentasikan daftar sekuensial, sedangkan array dua dimensi (seperti matriks $3 \times 3$) merepresentasikan tabel baris dan kolom yang dapat dioperasikan secara matematis seperti penjumlahan, pengurangan, dan perkalian matriks [1].

### B. Pointer dan Reference
Pointer adalah variabel khusus yang menyimpan alamat memori dari variabel lain. Dengan menggunakan pointer atau *reference* (`&`), kita dapat mengakses dan memodifikasi nilai variabel secara langsung melalui referensi memorinya tanpa harus menduplikasi nilai tersebut [2].

## Guided

### 1. Guided 1 (Contoh Pointer)
```C++
#include <iostream>
#include <iomanip>

using namespace std;

void inputMatriks(int M[3][3], string nama) {
    cout << "Masukkan elemen matriks " << nama << " (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nama << "[" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }
}

void cetakMatriks(int M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(5) << M[i][j];
        }
        cout << endl;
    }
}

int main() {
    int A[3][3], B[3][3], C[3][3];

    cout << "========================================\n";
    cout << "  PROGRAM OPERASI MATRIKS 3X3           \n";
    cout << "========================================\n";

    inputMatriks(A, "A");
    cout << endl;
    inputMatriks(B, "B");

    cout << "\nMatriks A:\n";
    cetakMatriks(A);

    cout << "\nMatriks B:\n";
    cetakMatriks(B);

    // 1. Penjumlahan
    cout << "\n--- HASIL PENJUMLAHAN (A + B) ---\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    cetakMatriks(C);

    // 2. Pengurangan
    cout << "\n--- HASIL PENGURANGAN (A - B) ---\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    cetakMatriks(C);

    // 3. Perkalian Matriks
    cout << "\n--- HASIL PERKALIAN (A * B) ---\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cetakMatriks(C);

    return 0;
}

```

Penjelasan singkat mengenai konsep guided 1.

### 2. Guided 2 (Contoh Array)

```C++
#include <iostream>

using namespace std;

// Menukar 3 variabel menggunakan Pointer
void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

// Menukar 3 variabel menggunakan Reference
void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 10, y = 20, z = 30;

    cout << "========================================\n";
    cout << "  SWAP 3 VARIABEL (POINTER & REFERENCE) \n";
    cout << "========================================\n";

    cout << "NILAI AWAL:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    // Menukar dengan Pointer (a -> b, b -> c, c -> a)
    tukarPointer(&x, &y, &z);
    cout << "\nSETELAH TUKAR DENGAN POINTER:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    // Menukar kembali dengan Reference (kembali ke susunan sebelum tukar reference)
    tukarReference(x, y, z);
    cout << "\nSETELAH TUKAR DENGAN REFERENCE:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}

```


## Unguided

### 1. Program Operasi Matriks 3x3 (Penjumlahan, Pengurangan, Perkalian)

```C++
#include <iostream>
#include <iomanip>

using namespace std;

void inputMatriks(int M[3][3], string nama) {
    cout << "Masukkan elemen matriks " << nama << " (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nama << "[" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }
}

void cetakMatriks(int M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(5) << M[i][j];
        }
        cout << endl;
    }
}

int main() {
    int A[3][3], B[3][3], C[3][3];

    cout << "========================================\n";
    cout << "  PROGRAM OPERASI MATRIKS 3X3           \n";
    cout << "========================================\n";

    inputMatriks(A, "A");
    cout << endl;
    inputMatriks(B, "B");

    cout << "\nMatriks A:\n";
    cetakMatriks(A);

    cout << "\nMatriks B:\n";
    cetakMatriks(B);

    // 1. Penjumlahan
    cout << "\n--- HASIL PENJUMLAHAN (A + B) ---\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    cetakMatriks(C);

    // 2. Pengurangan
    cout << "\n--- HASIL PENGURANGAN (A - B) ---\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    cetakMatriks(C);

    // 3. Perkalian Matriks
    cout << "\n--- HASIL PERKALIAN (A * B) ---\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cetakMatriks(C);

    return 0;
}

```

### Output Unguided 1 :

##### Output 1

**Penjelasan Unguided 1:**
Program di atas mendeklarasikan dua buah matriks berukuran $3 \times 3$ (`A` dan `B`) serta satu matriks penampung hasil (`C`). Fungsi `inputMatriks` digunakan untuk mengisi elemen matriks melalui input pengguna secara dinamis, sedangkan fungsi `cetakMatriks` digunakan untuk menampilkan bentuk matriks dengan format kolom yang rapi menggunakan library `<iomanip>`. Operasi penjumlahan dan pengurangan dilakukan dengan menjumlahkan/mengurangkan indeks elemen yang bersesuaian, sementara perkalian matriks menggunakan 3 perulangan bersarang (*nested loop*) untuk menghitung dot product baris kali kolom.

---

### 2. Program Menukar Nilai 3 Variabel Menggunakan Pointer & Reference

```C++
#include <iostream>

using namespace std;

// Menukar 3 variabel menggunakan Pointer
void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

// Menukar 3 variabel menggunakan Reference
void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 10, y = 20, z = 30;

    cout << "========================================\n";
    cout << "  SWAP 3 VARIABEL (POINTER & REFERENCE) \n";
    cout << "========================================\n";

    cout << "NILAI AWAL:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    // Menukar dengan Pointer
    tukarPointer(&x, &y, &z);
    cout << "\nSETELAH TUKAR DENGAN POINTER:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    // Menukar kembali dengan Reference
    tukarReference(x, y, z);
    cout << "\nSETELAH TUKAR DENGAN REFERENCE:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}

```

### Output Unguided 2 :

##### Output 1

**Penjelasan Unguided 2:**
Program ini mendemonstrasikan manipulasi memori secara langsung melalui dua metode, yaitu pointer dan *reference*. Fungsi `tukarPointer` menerima parameter berupa alamat memori (`*a`, `*b`, `*c`) dan melakukan pergeseran nilai secara siklikal. Di sisi lain, fungsi `tukarReference` menerima variabel asli melalui alias memori (`&a`, `&b`, `&c`) tanpa perlu operator address-of (`&`) saat pemanggilan fungsinya di `main`. Keduanya menghasilkan perubahan nilai variabel `x`, `y`, dan `z` secara permanen di dalam fungsi pemanggil.

---

### 3. Program Menu Array 1D (Cari Min, Max, dan Rata-rata)

```C++
#include <iostream>

using namespace std;

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

```

### Output Unguided 3 :

##### Output 1

**Penjelasan Unguided 3:**
Program ini mengelola array satu dimensi statis berukuran 10 elemen menggunakan perulangan menu *switch-case* interaktif. Terdapat pemisahan modular yang jelas antara fungsi pengembalian nilai (*function*) seperti `cariMaksimum()` dan `cariMinimum()` yang menggunakan tipe data `int`, serta prosedur (*void*) `hitungRataRata()` untuk mencetak hasil kalkulasi rata-rata desimal. Menu terus berulang menggunakan struktur kontrol `do-while` hingga pengguna memilih opsi keluar.

## Kesimpulan

Praktikum Modul 2 ini memberikan pemahaman mendalam mengenai pengoperasian array dua dimensi untuk matriks, manajemen memori tingkat lanjut menggunakan *pointer* dan *reference*, serta modularisasi program menggunakan fungsi dan prosedur terpisah. Penerapan menu interaktif berbasis *switch-case* juga melatih logika kontrol alur program secara terstruktur.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi : STRUKTUR DATA*. Medan: UNIVERSITAS ISLAM NEGERI SUMATERA UTARA MEDAN.

[2] Indahyati, Uce., Rahmawati Yunianita. (2020). *"BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++"*. Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
