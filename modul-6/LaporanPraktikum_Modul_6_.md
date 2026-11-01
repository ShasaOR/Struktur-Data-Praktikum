# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List</h1>
<p align="center">Shasa Olivia Rose - 109082500207</p>

## Dasar Teori

Doubly Linked List adalah struktur data berantai yang setiap node-nya menyimpan data dan dua pointer, yaitu `next` untuk menunjuk node berikutnya dan `prev` untuk menunjuk node sebelumnya. Struktur ini memungkinkan penelusuran dua arah.

### A. Konsep Doubly Linked List<br/>

#### 1. Struktur Node
Node terdiri dari `info`, `next`, dan `prev`. Pada list kosong, `First` dan `Last` bernilai `Nil`. Node pertama memiliki `prev = Nil`, sedangkan node terakhir memiliki `next = Nil`.

#### 2. Pointer First dan Last
`First` menunjuk node pertama dan `Last` menunjuk node terakhir. Dengan adanya `Last`, node baru dapat ditambahkan ke akhir list tanpa harus menelusuri semua node dari awal.

#### 3. Pengelolaan Memori
Node dibuat menggunakan `new` dan memori dikembalikan menggunakan `delete`. Sebelum node dihapus, pointer node di sekitarnya harus diperbarui agar list tetap terhubung.

### B. Operasi Dasar Doubly Linked List<br/>

#### 1. Create List, Alokasi, dan Dealokasi
`CreateList()` mengatur `First` dan `Last` menjadi `Nil`. `alokasi()` membuat node baru, sedangkan `dealokasi()` membebaskan memori node yang sudah dilepas dari list.

#### 2. Insert Last
Jika list kosong, node baru menjadi `First` dan `Last`. Jika list tidak kosong, `prev` node baru menunjuk `Last` lama, `next` node terakhir lama menunjuk node baru, kemudian `Last` diperbarui.

#### 3. Searching dan Delete
Searching menelusuri node dan membandingkan data yang dicari. Penghapusan dapat dilakukan pada awal, akhir, atau setelah node tertentu. Pointer tetangga perlu diperbarui sebelum node di-dealokasi.

## Guided

File Guided yang diberikan menggunakan data kendaraan (`nopol`, `warna`, `thnBuat`), sedangkan soal Unguided meminta data buku. Keduanya dipisahkan agar nama tipe dan field mengikuti instruksi masing-masing.

### 1. Header — `Doublylist.h`

```cpp
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

#define Nil NULL

// Latihan 1
struct infotype
{
    std::string nopol;
    std::string warna;
    int thnBuat;
};
typedef struct elmlist *address;
struct elmlist
{
    infotype info;
    address next;
    address prev;
};
struct List
{
    address First;
    address Last;
};

// Latihan 1
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Latihan 2

address findElm(List L, std::string nopol);

// Latihan 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string nopol, bool &status);

#endif
```

**Penjelasan:** Header mendefinisikan data kendaraan, node dengan pointer `next` dan `prev`, serta list dengan `First` dan `Last`. Deklarasi fungsi mencakup operasi dasar, pencarian, dan penghapusan.

### 2. Implementasi — `Doublylist.cpp`

```cpp
#include "Doublylist.h"

// Latihan 1
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil; 
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.Last;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    while (P != Nil) {
        std::cout << "no polisi : " << P->info.nopol << std::endl;   
        std::cout << "warna     : " << P->info.warna << std::endl;   
        std::cout << "tahun     : " << P->info.thnBuat << std::endl; 
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) { 
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;         
        (L.Last)->next = P;     
        L.Last = P;               
    }
}

// Latihan 2
address findElm(List L, std::string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Latihan 3
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.First; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;     
        (L.First)->prev = Nil; 
        P->next = Nil;         
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.Last; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;      
        (L.Last)->next = Nil; 
        P->prev = Nil;         
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;     
        (P->next)->prev = Prec; 
        P->next = Nil;            
        P->prev = Nil;           
    }
}

void deleteElm(List &L, std::string nopol, bool &status) {
    address P = findElm(L, nopol);
    status = false;

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P); 
        status = true;
    }
}
```

**Penjelasan:** `insertLast()` menyisipkan node di akhir list. `findElm()` menelusuri list dari `First` dan mengembalikan alamat node yang nomor polisinya cocok. Prosedur delete memperbarui pointer `First`, `Last`, `next`, dan `prev` sebelum node dibebaskan.

### 3. Program utama — `main.cpp`

```cpp
#include <iostream>
#include "Doublylist.h"
using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan nomor polisi: "; cin >> data.nopol;
    cout << "masukkan warna kendaraan: "; cin >> data.warna;
    cout << "masukkan tahun kendaraan: "; cin >> data.thnBuat;
    if (findElm(L, data.nopol) == Nil) {
        P = alokasi(data); 
        insertLast(L, P);  
    } else {
        cout << "nomor polisi sudah terdaftar" << endl; 
    }
}

int main() {
    List L;
    CreateList(L); 
    address P;

    // Latihan 1
    inputData(L); 
    inputData(L); 
    inputData(L); 
    inputData(L); 

    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    // Latihan 2
    string nopolCari;
    cout << "\nMasukkan Nomor Polisi yang dicari : "; 
    cin >> nopolCari; 
    
    P = findElm(L, nopolCari); 
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl; 
        cout << "Warna        : " << P->info.warna << endl; 
        cout << "Tahun        : " << P->info.thnBuat << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }

    // Latihan 3
    string nopolHapus;
    bool hapusBerhasil;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;

    deleteElm(L, nopolHapus, hapusBerhasil); 

    if (hapusBerhasil) {
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
    }
    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    return 0;
}
```

**Penjelasan:** Program memasukkan empat data kendaraan, menolak nomor polisi yang duplikat, mencari kendaraan berdasarkan nomor polisi, kemudian menghapus data yang dipilih dan menampilkan list setelah penghapusan.

### Output Guided 1 :
![Screenshot Output Unguided 1]()


## Unguided

Berdasarkan *Latihan Praktikum Modul 6 Doubly Linked List*, bagian Unguided terdiri dari tiga soal yang saling berkaitan. Ketiganya menggunakan file yang sama, yaitu `Buku.h`, `Buku.cpp`, dan `main.cpp`.

### 1. Pembuatan ADT, Insert Data, Searching, dan Delete

Program akhir mengimplementasikan seluruh kebutuhan pada tiga soal:

1. Membuat ADT Doubly Linked List dengan data buku yang terdiri dari `kodeBuku`, `judul`, dan `thnTerbit`.
2. Memasukkan data di akhir list serta memeriksa duplikasi `kodeBuku`.
3. Mencari buku berdasarkan `kodeBuku` menggunakan `findElm()`.
4. Menghapus buku berdasarkan `kodeBuku` menggunakan `deleteFirst()`, `deleteLast()`, dan `deleteAfter()` melalui fungsi `deleteElm()`.

#### 1.1 Source Code — `Buku.h`

```cpp
#ifndef BUKU_H
#define BUKU_H
#include <iostream>
#include <string>
#define Nil NULL

struct buku
{
    std::string kodeBuku;
    std::string judul;
    int thnTerbit;
};

typedef buku infotype;

typedef struct ElmList *address;

struct ElmList
{
    infotype info;
    address next;
    address prev;
};

struct List
{
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, std::string kodeBuku);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string kodeBuku, bool &status);

#endif
```

**Penjelasan:** File header mendefinisikan tipe data buku, node yang memiliki pointer `next` dan `prev`, struktur list dengan pointer `First` dan `Last`, serta deklarasi seluruh fungsi yang digunakan pada program.

#### 1.2 Source Code — `Buku.cpp`

```cpp
#include "Buku.h"

void CreateList(List &L) { L.First = Nil; L.Last = Nil; }

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x; P->next = Nil; P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) { delete P; P = Nil; }
}

void printInfo(List L) {
    address P = L.First;
    if (P == Nil) { std::cout << "List kosong." << std::endl; return; }
    while (P != Nil) {
        std::cout << "Kode Buku    : " << P->info.kodeBuku << std::endl;
        std::cout << "Judul        : " << P->info.judul << std::endl;
        std::cout << "Tahun Terbit : " << P->info.thnTerbit << std::endl;
        P = P->next;
    }
}

void insertLast(List &L, address P) {
    if (P == Nil) return;
    if (L.First == Nil) { L.First = P; L.Last = P; }
    else { P->prev = L.Last; L.Last->next = P; L.Last = P; }
}

address findElm(List L, std::string kodeBuku) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.kodeBuku == kodeBuku) return P;
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    if (L.First == Nil) { P = Nil; return; }
    P = L.First;
    if (L.First == L.Last) { L.First = Nil; L.Last = Nil; }
    else { L.First = P->next; L.First->prev = Nil; P->next = Nil; }
}

void deleteLast(List &L, address &P) {
    if (L.Last == Nil) { P = Nil; return; }
    P = L.Last;
    if (L.First == L.Last) { L.First = Nil; L.Last = Nil; }
    else { L.Last = P->prev; L.Last->next = Nil; P->prev = Nil; }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) { P = Nil; return; }
    P = Prec->next;
    if (P == L.Last) deleteLast(L, P);
    else {
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteElm(List &L, std::string kodeBuku, bool &status) {
    address P = findElm(L, kodeBuku);
    status = false;
    if (P != Nil) {
        if (P == L.First) deleteFirst(L, P);
        else if (P == L.Last) deleteLast(L, P);
        else deleteAfter(L, P->prev, P);
        dealokasi(P);
        status = true;
    }
}
```

**Penjelasan:** File implementasi berisi fungsi pembuatan list, alokasi dan dealokasi node, penampilan data, penyisipan di akhir list, pencarian berdasarkan kode buku, serta prosedur penghapusan node pada posisi pertama, terakhir, atau setelah node tertentu.

#### 1.3 Source Code — `main.cpp`

```cpp
#include <iostream>
#include "Buku.h"
using namespace std;

bool inputBuku(List &L) {
    infotype data;

    cout << endl;
    cout << "masukkan kode buku: ";
    cin >> data.kodeBuku;

    cout << "masukkan judul buku: ";
    cin >> data.judul;

    cout << "masukkan tahun terbit: ";
    cin >> data.thnTerbit;

    if (findElm(L, data.kodeBuku) != Nil) {
        cout << "kode buku sudah terdaftar" << endl;
        return false;
    }

    insertLast(L, alokasi(data));
    return true;
}

int main() {
    List L;
    CreateList(L);

    inputBuku(L);
    inputBuku(L);
    inputBuku(L);
    inputBuku(L);

    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);

    string kodeCari;
    cout << endl << "Masukkan Kode Buku yang dicari : ";
    cin >> kodeCari;

    address hasil = findElm(L, kodeCari);

    if (hasil != Nil) {
        cout << endl;
        cout << "Kode Buku    : " << hasil->info.kodeBuku << endl;
        cout << "Judul        : " << hasil->info.judul << endl;
        cout << "Tahun Terbit : " << hasil->info.thnTerbit << endl;
    } else {
        cout << "Data dengan kode buku " << kodeCari
             << " tidak ditemukan." << endl;
    }

    string kodeHapus;
    bool hapusBerhasil;

    cout << endl << "Masukkan Kode Buku yang akan dihapus : ";
    cin >> kodeHapus;

    deleteElm(L, kodeHapus, hapusBerhasil);

    if (hapusBerhasil) {
        cout << "Data dengan kode buku " << kodeHapus
             << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan kode buku " << kodeHapus
             << " tidak ditemukan." << endl;
    }

    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);

    while (L.First != Nil) {
        address P = L.First;
        L.First = L.First->next;
        dealokasi(P);
    }
    L.Last = Nil;

    return 0;
}
```

**Penjelasan:** Program utama menerima empat input buku. Kode buku diperiksa terlebih dahulu agar tidak ada duplikasi. Setelah data dimasukkan, program menampilkan isi list, mencari buku berdasarkan kode yang dimasukkan, menghapus buku berdasarkan kode yang dipilih, lalu menampilkan kembali isi list setelah penghapusan.

### Output Unguided 1 :
![Screenshot Output Unguided 1]()


Contoh pengujian mengikuti data pada modul:

- `B001`, `Algoritma`, `2020`
- `B003`, `Struktur_Data`, `2018`
- `B001`, `Basis_Data`, `2021` — ditolak karena kode buku sudah terdaftar
- `B004`, `Jaringan_Komputer`, `2022`

Selanjutnya, masukkan `B001` pada proses pencarian dan `B003` pada proses penghapusan. Setelah penghapusan, list seharusnya hanya berisi buku `B001` dan `B004`.

**Catatan:** Pada contoh di halaman 2–3 modul, data akhir ditampilkan dengan urutan `B004` lalu `B001`. Implementasi `printInfo()` pada kode akhir di atas menelusuri dari `First` ke `Last`, sehingga urutan tampilnya `B001` lalu `B004`. Isi list tetap sama; perbedaannya hanya arah penelusuran saat menampilkan data.

## Kesimpulan

Doubly Linked List menggunakan pointer `next` dan `prev` sehingga node dapat ditelusuri dua arah. Pointer `First` dan `Last` menandai batas list. Praktikum ini menerapkan pembuatan list, alokasi memori, penyisipan di akhir, pencegahan data duplikat, pencarian berdasarkan kode, serta penghapusan node pada posisi berbeda. Pointer harus diperbarui sebelum dealokasi agar struktur list tetap valid.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

[2] Indahyati, U., & Rahmawati, Y. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4
