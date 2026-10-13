# Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)

Shasa Olivia Rose - 109082500207

## Dasar Teori

Linked list atau senarai berantai adalah bentuk struktur data yang berisi kumpulan elemen data yang saling berkaitan lewat pointer. Elemen-elemennya memang terlihat berurutan secara logika, tapi di memori letaknya tidak harus bersebelahan\[3\]. Karena sifatnya yang dinamis, linked list jadi pilihan yang masuk akal kalau jumlah data sering berubah, sedangkan array lebih cocok kalau ukuran datanya sudah pasti dan butuh akses yang cepat\[2\]. Pada praktikum ini, list diimplementasikan dengan pointer, dan data yang disimpan berupa data majemuk (record) seperti data mahasiswa yang terdiri dari nama, NIM, dan umur\[5\].

### A. Konsep Singly Linked List

Singly linked list adalah model linked list yang hanya punya satu arah pointer, jadi penelusurannya cuma bisa maju dari depan ke belakang\[5\]. Setiap elemennya hanya dihubungkan oleh satu pointer tunggal ke elemen berikutnya\[2\].

#### 1. Node

Node (simpul/elemen) adalah tempat data disimpan. Isinya ada dua bagian: data itu sendiri dan penghubung (successor) ke node sesudahnya\[5\]. Di C++, node biasanya dibuat dengan `struct` yang di dalamnya ada field data dan field pointer ke `struct` yang sama.

#### 2. Pointer First dan Next

`first` (atau `head`) adalah pointer yang menunjuk ke elemen pertama list, sedangkan `next` adalah pointer di dalam tiap node yang menunjuk ke elemen di depannya\[5\]. Selama `first` masih dipegang, semua node di belakangnya masih bisa dijangkau satu per satu lewat `next`\[3\].

#### 3. Nil / NULL

Nil berarti pointer tidak menunjuk ke mana-mana. Node terakhir pada singly linked list selalu menunjuk ke Nil dan itu yang dipakai sebagai tanda berhenti saat menelusuri list\[3\]\[5\]. List yang kosong ditandai dengan `first` yang nilainya Nil.

### B. Operasi Dasar pada Singly Linked List

Secara umum operasi pada linked list mencakup pembuatan list, penyisipan, penghapusan, penelusuran, pencarian, dan pengubahan data\[5\]. Yang dibahas di modul ini baru sampai penyisipan, penghapusan, dan penelusuran.

#### 1. Insert (Penyisipan)

Ada tiga bentuk penyisipan: *insert first* (di awal list), *insert last* (di akhir list), dan *insert after* (setelah node tertentu). Menyisipkan di tengah list cukup dengan mengatur ulang pointer tanpa menggeser elemen lain, dan ini yang membuatnya lebih ringan dibanding array\[3\]\[5\].

#### 2. Delete (Penghapusan)

Penghapusan juga punya tiga bentuk: *delete first*, *delete last*, dan *delete after*. Setelah pointer disambung ulang, node yang dilepas harus dikembalikan memorinya ke sistem. Di C++ ini dilakukan dengan `delete`\[5\]. Untuk menghapus seluruh isi list, semua node dilepas satu per satu sampai `first` kembali bernilai Nil.

#### 3. View dan Hitung Node

View adalah penelusuran list dari node pertama sampai Nil sambil menampilkan data di tiap node\[5\]. Cara yang sama dipakai untuk menghitung jumlah node, yaitu dengan menambah counter setiap kali pindah ke node berikutnya.

## Guided

### 1. \[Header - list.h\]

```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedList {
    address first;
};

bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```

File ini isinya cuma deklarasi, jadi semua "kerangka" list ada di sini. `#ifndef` di awal dipakai supaya header tidak ke-include dua kali dan bikin error. `Nil` di-define jadi `NULL` biar penulisannya sama dengan yang ada di modul. Struct `mahasiswa` menampung nama, NIM, dan umur, lalu struct `node` membungkusnya bersama pointer `next`. Pointer `address` dibuat lewat `typedef` supaya tidak perlu nulis `node*` terus. Terakhir ada `linkedList` yang isinya cuma satu pointer `first`, dan di bawahnya daftar prototipe semua fungsi yang nanti ditulis isinya di `list.cpp`.

### 2. \[Implementasi - list.cpp\]

```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedList &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedList &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

Ini bagian yang isinya semua fungsi. `isEmpty` cuma ngecek apakah `first` masih Nil. `createList` bikin list kosong dengan mengisi `first` pakai Nil, sedangkan `alokasi` membuat node baru pakai `new`, mengisi datanya, dan membuat `next`-nya Nil dulu.

Untuk insert, `insertFirst` tinggal menyambungkan `next` node baru ke `first` lama, lalu `first` dipindah ke node baru. `insertLast` jalan menyusuri list sampai ketemu node yang `next`-nya Nil, baru node baru dipasang di situ (kalau list masih kosong ya langsung jadi `first`). `insertAfter` menyelipkan node baru setelah `Prev`, caranya node baru dulu diarahkan ke `Prev->next`, baru `Prev->next` diarahkan ke node baru. Urutan ini penting, kalau kebalik rantainya putus.

Untuk delete, `delFirst` menggeser `first` ke node kedua lalu node lama dibuang. `delLast` mencari node terakhir sambil nyimpen node sebelumnya di `nodePrev`, lalu `nodePrev->next` dikosongkan dan node terakhir dibuang, dengan satu kasus khusus kalau isi list cuma satu node. `delAfter` membuang node tepat setelah `nodePrev`. Satu catatan kecil, parameter `nodeHapus` di fungsi ini nilainya langsung ditimpa di dalam fungsi, jadi sebenarnya yang dipakai hanya `nodePrev`.

Sisanya, `printList` menelusuri list dari awal sambil mencetak nama, NIM, dan usia, `nbList` menghitung node dengan counter, dan `deleteList` membuang semua node satu per satu lalu mengembalikan `first` ke Nil.

### 3. \[Program Utama - main.cpp\]

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211100014", 21);
    nodeC = alokasi("Rizal", "2311100029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Di `main`, list dibuat kosong dulu, lalu lima node mahasiswa dialokasikan (Dhimas, Arvin, Rizal, Satrio, Joshua). Urutan insert-nya: Dhimas masuk di depan, Arvin di belakang, Rizal disisipkan setelah Dhimas, Satrio setelah Rizal, lalu Joshua di paling belakang. Jadi urutan list-nya Dhimas → Rizal → Satrio → Arvin → Joshua dengan jumlah 5 node.

Setelah itu tiga operasi delete dijalankan: `delFirst` membuang Dhimas, `delLast` membuang Joshua, dan `delAfter` membuang Satrio (node setelah Rizal). Sisanya Rizal dan Arvin, sehingga jumlah node jadi 2. Di akhir `deleteList` mengosongkan semuanya, jadi `printList` menampilkan "List kosong." dan jumlah node 0. Output yang keluar kira-kira seperti ini:

```
--- ISI LIST SETELAH DILAKUKAN INSERT ---
Nama : Dhimas, NIM : 2311102151, Usia : 20
Nama : Rizal, NIM : 2311100029, Usia : 20
Nama : Satrio, NIM : 2211102173, Usia : 21
Nama : Arvin, NIM : 2211100014, Usia : 21
Nama : Joshua, NIM : 2311102133, Usia : 21
jumlah node : 5

--- ISI LIST SETELAH DILAKUKAN DELETE ---
Nama : Rizal, NIM : 2311100029, Usia : 20
Nama : Arvin, NIM : 2211100014, Usia : 21
jumlah node : 2

List sudah terhapus!
--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---
List kosong.
jumlah node : 0
```

## Unguided

### 1. Membuat ADT Singly Linked List (`Singlylist.h`, `Singlylist.cpp`, `main.cpp`) lalu menampilkan isi list 9 12 8 0 2 dengan `insertFirst`

**\[Header - Singlylist.h\]**

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

**\[Implementasi - Singlylist.cpp\]**

```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```

**\[Program Utama - main.cpp\]**

```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1]()

Di soal pertama, ADT-nya dibuat dari nol dengan tipe data `int` biar lebih sederhana dari versi mahasiswa di Guided. `createList` mengisi `First` dengan Nil, `alokasi` membuat node baru dengan nilai `x`, dan `dealokasi` membuang node sekaligus mengembalikan pointernya jadi Nil supaya tidak jadi pointer gantung. `printInfo` menelusuri list dari `First` dan mencetak tiap nilai dipisah spasi.

Kunci dari soal ini ada di `insertFirst`. Karena tiap node baru selalu ditaruh di depan, urutan memasukkannya berlawanan dengan urutan tampilnya: nilai 2, 0, 8, 12, 9 dimasukkan berurutan, hasilnya list terbaca 9 → 12 → 8 → 0 → 2. Itu sama persis dengan output yang diminta soal. Satu penyesuaian kecil dari soal, di `main` saya menambahkan titik koma setelah `printInfo(L)` karena di soal aslinya terlewat.

### 2. Menghapus node 9 dengan `deleteFirst()`, node 2 dengan `deleteLast()`, dan node 8 dengan `deleteAfter()`, lalu menampilkan jumlah node dengan `nbList()` dan menghapus seluruh node dengan `deleteList()`

**\[Header - Singlylist.h\]**

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil nullptr

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif
```

**\[Implementasi - Singlylist.cpp\]**

```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L) {
    if (L.First != Nil) {
        address P = L.First;
        L.First = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.First != Nil) {
        if (L.First->next == Nil) {
            dealokasi(L.First);
        } else {
            address P = L.First;
            address Q = Nil;
            while (P->next != Nil) {
                Q = P;
                P = P->next;
            }
            Q->next = Nil;
            dealokasi(P);
        }
    }
}

void deleteAfter(List &L, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        address P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.First;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void deleteList(List &L) {
    address P = L.First;
    while (P != Nil) {
        address hapus = P;
        P = P->next;
        dealokasi(hapus);
    }
    L.First = Nil;
    cout << "- List Berhasil Terhapus -" << endl;
}
```

**\[Program Utama - main.cpp\]**

```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L);      // hapus node 9
    deleteLast(L);       // hapus node 2
    deleteAfter(L, P4);  // hapus node 8 (setelah node 12)

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1]()

Di versi ini `Nil` didefinisikan sebagai `nullptr` (bukan `NULL`), dan `alokasi` mengecek dulu apakah `new` berhasil sebelum mengisi node. Semua fungsi dari soal 1 ikut ditulis lagi di `Singlylist.cpp` supaya file-nya utuh dan bisa langsung dikompilasi.

Soal kedua melanjutkan list dari soal pertama (9 → 12 → 8 → 0 → 2). `deleteFirst` membuang node paling depan, yaitu 9, sehingga `First` pindah ke 12. `deleteLast` menelusuri list sampai ke node terakhir sambil mencatat node sebelumnya di `Q`, lalu `Q->next` dikosongkan dan node 2 dibuang. Kalau list isinya tinggal satu node, ada percabangan khusus supaya `First` ikut jadi Nil.

Untuk node 8, dipakai `deleteAfter` dengan node 12 (`P4`) sebagai `Prec`, karena 8 memang tepat berada setelah 12. Di fungsi ini `Prec->next` dilompatkan ke node sesudah 8 dulu, baru node 8 dibuang, jadi rantai list tetap tersambung. Setelah ketiganya jalan, sisa list tinggal 12 → 0 dengan jumlah node 2 dari hasil `nbList`, sesuai dengan output yang diminta.

Terakhir `deleteList` membuang semua node tersisa satu per satu. Pointer `hapus` dipakai supaya `P` bisa maju ke node berikutnya sebelum node sekarang dibuang. Setelah selesai, `First` dikembalikan ke Nil dan pesan "- List Berhasil Terhapus -" dicetak, sehingga `nbList` berikutnya menghasilkan 0.

## Kesimpulan

Dari praktikum ini saya jadi paham bahwa singly linked list itu pada dasarnya hanya rangkaian node yang diikat oleh pointer `next`, dengan `first` sebagai pegangan ke node pertama dan Nil sebagai penanda ujung list. Operasi insert dan delete di dalamnya sebenarnya cuma soal mengatur ulang pointer dengan urutan yang benar, misalnya pada `insertAfter` dan `delAfter` yang kalau urutannya terbalik bisa memutus rantai list. Memisah program ke `.h`, `.cpp`, dan `main.cpp` juga bikin kodenya lebih rapi karena deklarasi, isi fungsi, dan program utama punya tempat sendiri. Satu hal lain yang saya dapat, setiap node yang dibuat dengan `new` harus dikembalikan dengan `delete`, makanya fungsi seperti `dealokasi` dan `deleteList` penting supaya memori tidak bocor.

## Referensi

\[1\] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. \
\[2\] Mbejo, M. T., Nopa, L. A., Putri, J. S., & Risky, M. (2025). "Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa". Jurnal Sains Informatika Terapan, 4(2), 441-444. Diakses pada 13 Oktober 2026 melalui [https://doi.org/10.62357/jsit.v4i2.591](https://doi.org/10.62357/jsit.v4i2.591). \
\[3\] Selamet, R. (2016). "Implementasi Struktur Data List, Queue dan Stack dalam Java". Media Informatika, 15(3). Diakses pada 13 Oktober 2026 melalui [https://jurnal.likmi.ac.id/Jurnal/11_2016/112016_03_Rachmat.pdf](https://jurnal.likmi.ac.id/Jurnal/11_2016/112016_03_Rachmat.pdf). \
\[4\] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui [https://doi.org/10.21070/2020/978-623-6833-67-4](https://doi.org/10.21070/2020/978-623-6833-67-4). \
\[5\] Informatics Lab, Fakultas Informatika, Telkom University. (n.d.). Modul 4 Struktur Data: Singly Linked List (Bagian Pertama). Modul praktikum Struktur Data.