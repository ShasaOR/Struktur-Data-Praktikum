# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Shasa Olivia Rose - 109082500207</p>

## Dasar Teori
Queue atau antrian adalah struktur data linear yang aturan mainnya First In First Out (FIFO): elemen yang masuk paling awal akan keluar paling awal juga [1]. Gambaran gampangnya seperti antrean di loket tiket kereta api, orang yang datang pertama dilayani pertama dan yang datang terakhir dilayani paling akhir [5]. Prinsip yang sama dipakai di sistem antrian sungguhan, misalnya pendaftaran pasien di puskesmas yang melayani pasien sesuai urutan kedatangannya [2].

### A. Konsep Dasar Queue<br/>
Setiap queue punya dua penunjuk. `head` menunjuk elemen paling depan, yaitu tempat elemen diambil, dan `tail` menunjuk elemen paling belakang, yaitu tempat elemen baru disisipkan. Queue dianggap kosong kalau head bernilai Nil [5]. Dari dua penunjuk ini muncul dua operasi utama, yaitu enqueue untuk memasukkan elemen dan dequeue untuk mengeluarkan elemen [1].

#### 1. Enqueue (Insert)
Enqueue selalu dilakukan di bagian tail [5]. Pada versi linked list, elemen baru dibuat dulu lewat `alokasi` dan `next`-nya diisi Nil. Setelah itu elemen tail yang lama disambungkan ke elemen baru, baru tail dipindah ke elemen baru tersebut. Kalau queue masih kosong, head dan tail langsung sama-sama menunjuk elemen baru. Contoh memasukkan angka 9 ke queue yang isinya 5, 2, 7:

```
Sebelum :  HEAD                         TAIL
             |                            |
             v                            v
           [ 5 | o-]--->[ 2 | o-]--->[ 7 | Nil ]

Langkah 1 :  P = alokasi(9);      ->   P --> [ 9 | Nil ]
Langkah 2 :  (Q.tail)->next = P;  ->   [ 7 | o-]---> [ 9 | Nil ]
Langkah 3 :  Q.tail = P;          ->   TAIL pindah ke elemen 9

Sesudah :  HEAD                                      TAIL
             |                                         |
             v                                         v
           [ 5 | o-]--->[ 2 | o-]--->[ 7 | o-]--->[ 9 | Nil ]
```

#### 2. Dequeue (Delete)
Dequeue dilakukan di bagian head [5]. Alamat head disimpan dulu ke P, lalu head digeser ke elemen berikutnya, kemudian `next` milik P diputus (Nil) supaya elemen itu benar-benar lepas dari antrian. Kalau elemen yang diambil ternyata elemen terakhir, head dan tail dikembalikan ke Nil sehingga queue kosong lagi.

```
Sebelum :  HEAD                         TAIL
             |                            |
             v                            v
           [ 5 | o-]--->[ 2 | o-]--->[ 7 | Nil ]

Langkah 1 :  P = Q.head;           ->   P menunjuk elemen 5
Langkah 2 :  Q.head = P->next;     ->   HEAD pindah ke elemen 2
Langkah 3 :  P->next = Nil;        ->   elemen 5 lepas dari antrian

Sesudah :  HEAD              TAIL         P --> [ 5 | Nil ]
             |                 |
             v                 v
           [ 2 | o-]--->[ 7 | Nil ]
```

### B. Queue Representasi Linked List<br/>
Di modul, queue bisa dibuat dengan dua cara, yaitu pointer (linked list) dan tabel (array) [5]. Dengan linked list jumlah elemen tidak dibatasi dan memorinya diatur sendiri lewat alokasi dan dealokasi [5]. Linked list memang fleksibel dan hemat memori, tapi punya kelemahan di waktu akses [3]. Untuk queue hal ini jarang jadi masalah karena operasinya cuma menyentuh ujung depan dan ujung belakang.

#### 1. Struktur dan primitif ADT
ADT queue dipecah ke tiga file: `queue.h` untuk tipe data dan prototipe, `queue.cpp` untuk isi fungsinya, dan `main.cpp` untuk menjalankan program. Satu elemen (`elmQ`) berisi `info` dan pointer `next`, sedangkan queue sendiri hanya menyimpan `head` dan `tail`. Primitif yang disediakan modul antara lain `isEmpty`, `CreateQueue`, `alokasi`, `dealokasi`, `findElm`, `fFindElm`, `insert`, `delete`, `printInfo`, `nbList`, dan `delAll` [5].

#### 2. Kondisi queue
Ada tiga keadaan yang perlu diperhatikan. Queue kosong kalau head dan tail sama-sama Nil, queue satu elemen kalau head dan tail menunjuk elemen yang sama, dan selebihnya queue berisi banyak elemen dengan head di depan dan tail di belakang [5].

### C. Queue Representasi Array<br/>
Pada representasi array jumlah antrean terbatas dan tidak ada manajemen memori [5]. Queue dengan array bisa dibuat dalam bentuk linear array maupun circular array [1]. Modul membahas tiga alternatif yang bedanya ada di cara head dan tail bergerak.

#### 1. Alternatif 1 (head diam, tail bergerak)
Head selalu berada di posisi pertama selama queue tidak kosong. Waktu enqueue, tail tinggal dimajukan. Waktu dequeue, elemen di head diambil lalu semua elemen sesudahnya digeser ke depan dan tail mundur satu. Cara ini mirip orang yang maju satu langkah tiap ada yang selesai dilayani, tapi tidak efisien karena ada pergeseran di setiap dequeue [5].

#### 2. Alternatif 2 (head bergerak, tail bergerak)
Di sini dequeue cukup memajukan head tanpa menggeser elemen lain, jadi lebih efisien. Konsekuensinya bisa terjadi keadaan penuh semu, yaitu tail sudah di index paling akhir padahal bagian depan array masih kosong. Kalau itu terjadi elemen harus digeser dulu untuk membuat ruang, dan pergeseran hanya dilakukan kalau tail sudah mencapai index maksimum [5].

#### 3. Alternatif 3 (head dan tail berputar)
Head dan tail bergerak mengelilingi array. Kalau tail sampai di index terakhir, posisi berikutnya adalah index awal lagi, dan hal yang sama berlaku untuk head. Karena itu tidak ada lagi pergeseran elemen, dan strategi ini sering disebut circular buffer [5]. Pada circular queue, tempat yang ditinggalkan data lama bisa langsung dipakai data baru tanpa menggeser elemen lain [4].

| Alternatif | Head | Tail | Dequeue | Kekurangan |
|---|---|---|---|---|
| 1 | tetap di index 0 | maju | elemen digeser ke depan | banyak pergeseran |
| 2 | maju | maju | head maju | penuh semu, perlu digeser saat tail di ujung |
| 3 | berputar | berputar | head maju (balik ke awal) | logika penuh dan kosong lebih rumit |

## Guided 

### 1. Queue dengan Linked List

Guided pertama membuat queue dari linked list satu arah, dengan satu elemen berisi angka (`int`) dan dua penunjuk di queue-nya, yaitu head dan tail. Programnya terdiri dari tiga file yang saling terhubung.

**[Header - queue.h]**

```C++
#ifndef QUEUE_H_INCLUDE
#define QUEUE_H_INCLUDE

#include <iostream>
using namespace std;

#define Nil NULL

typedef bool boolean;
typedef int infotype;
typedef struct elmQ *address;

struct elmQ {
    infotype info;
    address next;
};

struct queue {
    address head, tail;
};

boolean isEmpty(queue Q);
void CreateQueue(queue &Q);
address alokasi(infotype X);
void dealokasi(address P);
address findElm(queue Q, infotype X);
boolean fFindElm(queue Q, address P);
void insert(queue &Q, address P);
void deleteQueue(queue &Q, address &P);
void printInfo(queue Q);
int nbList(queue Q);
void delAll(queue &Q);

#endif
```
File ini isinya deklarasi saja, belum ada logika yang jalan. Baris `#ifndef` sampai `#endif` dipakai supaya header tidak ke-include dua kali, lalu `Nil` didefinisikan sebagai `NULL` untuk penanda pointer kosong. `boolean` dan `infotype` cuma nama lain dari `bool` dan `int`. Struct `elmQ` adalah satu elemen queue yang menyimpan `info` (datanya) dan `next` (alamat elemen sesudahnya), sedangkan struct `queue` hanya berisi dua pointer, `head` untuk elemen paling depan dan `tail` untuk paling belakang. Sisanya adalah prototipe fungsi yang isinya ditulis di `queue.cpp`.

**[Source - queue.cpp]**

```C++
#include "queue.h"

boolean isEmpty(queue Q) {
    return (Q.head == Nil);
}

void CreateQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

address alokasi(infotype X) {
    address P = new (nothrow) elmQ;
    if (P != Nil) {
        P->info = X;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

address findElm(queue Q, infotype X) {
    address P = Q.head;
    while (P != Nil) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

boolean fFindElm(queue Q, address P) {
    address R = Q.head;
    while (R != Nil) {
        if (R == P) {
            return true;
        }
        R = R->next;
    }
    return false;
}

void insert(queue &Q, address P) {
    if (isEmpty(Q)) {
        Q.head = P;
        Q.tail = P;
    } else {
        (Q.tail)->next = P;
        Q.tail = P;
    }
}

void deleteQueue(queue &Q, address &P) {
    P = Q.head;
    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head = P->next;
    }
    P->next = Nil;
}

void printInfo(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
    } else {
        address P = Q.head;
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

int nbList(queue Q) {
    int jumlah = 0;
    address P = Q.head;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void delAll(queue &Q) {
    address P;
    while (!isEmpty(Q)) {
        deleteQueue(Q, P);
        dealokasi(P);
    }
}
```
`isEmpty` mengecek apakah `head` masih Nil, dan `CreateQueue` mengisi head dan tail dengan Nil supaya queue mulai dalam keadaan kosong. `alokasi` membuat elemen baru dengan `new (nothrow)`, jadi kalau memori habis hasilnya Nil dan program tidak langsung error. Kalau berhasil, `info` diisi X dan `next` diisi Nil. `dealokasi` tinggal `delete` elemen yang tidak dipakai lagi.

`findElm` menelusuri queue dari head sampai ketemu elemen yang `info`-nya sama dengan X lalu mengembalikan alamatnya, atau Nil kalau tidak ada. `fFindElm` mirip, hanya saja yang dicocokkan adalah alamatnya, hasilnya true atau false.

Untuk `insert`, kalau queue kosong maka head dan tail sama-sama diarahkan ke P. Kalau sudah ada isinya, `next` milik tail dihubungkan ke P lalu tail dipindah ke P, persis seperti langkah di Gambar 8-2 sampai 8-4 pada modul. `deleteQueue` kebalikannya: P menyimpan elemen head, kalau head dan tail sama (elemen tinggal satu) keduanya dikembalikan ke Nil, kalau tidak head dimajukan ke `next`. Terakhir `next` milik P dikosongkan. Elemennya belum dihapus dari memori, hanya dilepas dan dikirim balik lewat parameter P, jadi harus di-`dealokasi` sendiri setelahnya. Di modul fungsi ini bernama `delete`, tapi karena itu sudah kata kunci C++, di sini namanya diganti `deleteQueue`.

`printInfo` mencetak isi queue dari head sampai Nil, dan kalau kosong menampilkan "Queue kosong". `nbList` menghitung banyaknya elemen dengan cara yang sama, yaitu menelusuri dari head sambil menambah counter. `delAll` mengulang `deleteQueue` dan `dealokasi` selama queue belum kosong, sampai semua elemen terhapus.

**[Main - main.cpp]**

```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    queue Q;
    address P;

    CreateQueue(Q);
    cout << "isEmpty: " << isEmpty(Q) << endl;
    printInfo(Q);

    insert(Q, alokasi(5));
    insert(Q, alokasi(2));
    insert(Q, alokasi(7));
    cout << "Setelah insert 5, 2, 7" << endl;
    printInfo(Q);
    cout << "nbList : " << nbList(Q) << endl;

    P = findElm(Q, 2);
    if (P != Nil) {
        cout << "findElm(2) ketemu, info = " << P->info << endl;
        cout << "fFindElm : " << fFindElm(Q, P) << endl;
    }
    if (findElm(Q, 9) == Nil) {
        cout << "findElm(9) tidak ketemu" << endl;
    }

    deleteQueue(Q, P);
    cout << "Setelah delete, elemen yang keluar = " << P->info << endl;
    dealokasi(P);
    printInfo(Q);

    delAll(Q);
    cout << "Setelah delAll" << endl;
    printInfo(Q);
    cout << "isEmpty: " << isEmpty(Q) << endl;

    return 0;
}
```
Di `main`, queue dibuat dulu dengan `CreateQueue` lalu dicek kosong atau tidaknya (hasilnya 1 karena true). Setelah itu angka 5, 2, dan 7 dimasukkan berurutan memakai `insert(Q, alokasi(...))` dan isi queue tampil sebagai `5 2 7`, dengan `nbList` bernilai 3. `findElm(Q, 2)` ketemu sehingga info-nya bisa dicetak dan `fFindElm` mengembalikan 1, sedangkan pencarian angka 9 tidak ketemu karena memang tidak pernah dimasukkan.

Bagian yang menarik ada di `deleteQueue(Q, P)`. Sebelumnya P menunjuk elemen 2 hasil `findElm`, tapi setelah dipanggil P ditimpa dengan elemen head, jadi yang keluar adalah angka 5, bukan 2. Ini menunjukkan sifat FIFO, yang pertama masuk yang pertama keluar. Elemen itu lalu di-`dealokasi` dan queue tersisa `2 7`. Di akhir `delAll` menghapus semuanya dan queue kembali kosong.

### 2. (Guided 2)

> **[BELUM DIISI]** File untuk Guided 2 belum ada, tinggal ditambahkan dengan format yang sama seperti Guided 1: [Header - ...], [Source - ...], [Main - ...], masing-masing diikuti kode dan penjelasannya.

## Unguided 

### 1. Buatlah ADT Queue menggunakan array dengan mekanisme Alternatif 1 (head diam, tail bergerak)

**[Header - queue.h]**

```C++
#ifndef QUEUE_ALT1_H
#define QUEUE_ALT1_H
#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5]; // Ukuran maksimal 5 sesuai soal
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

**[Source - queue.cpp]**

```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        return -999; // Tanda error
    } else {
        infotype temp = Q.info[Q.head];
        if (Q.head == Q.tail) { // Kalau sisa 1 elemen
            createQueue(Q);
        } else {
            // Geser semua elemen ke kiri (Head tetap diam)
            for (int i = 0; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
        return temp;
    }
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << Q.head << " - " << Q.tail << " : empty queue" << endl;
    } else {
        cout << Q.head << " - " << Q.tail << " : ";
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

**[Main - main.cpp]**

```C++
#include "queue.h"

int main() {
    cout << "Hello world!" << endl;
    cout << "------------------------" << endl;
    cout << "H - T   : Queue Info" << endl;
    cout << "------------------------" << endl;
    
    Queue Q;
    createQueue(Q);
    printInfo(Q);
    
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](assets/output%201.png)

Di `queue.h`, queue dibuat dari array `info` berukuran 5 sesuai soal. Ukurannya disimpan di konstanta `MAKS` supaya tidak menulis angka 5 berulang kali. `head` dan `tail` bertipe int dan menyimpan index array, bukan pointer seperti di guided. Fungsi `dequeue` mengembalikan `infotype`, yaitu elemen yang diambil. Nama fungsi `createQueue` ditulis dengan huruf kecil di depan supaya cocok dengan pemanggilan di `main` pada soal.

Di `queue.cpp`, queue kosong ditandai head dan tail yang sama-sama -1. Karena di Alternatif 1 head selalu diam di index 0, queue dianggap penuh kalau tail sudah di index terakhir (`MAKS - 1`). Pada `enqueue`, kalau queue kosong head dan tail diisi 0, kalau tidak tail cukup dimajukan satu lalu datanya ditaruh di `info[tail]`. Bagian yang paling berbeda ada di `dequeue`: elemen di `info[head]` diambil dulu, lalu semua elemen sesudahnya digeser satu langkah ke kiri dengan perulangan `for` dan tail dikurangi satu, jadi head tidak perlu pindah. Kalau yang diambil adalah elemen terakhir, head dan tail dikembalikan ke -1. Kalau queue kosong, `dequeue` hanya menampilkan pesan dan mengembalikan -1. `printInfo` mencetak nilai head dan tail dulu, lalu isi queue dari head sampai tail, atau tulisan `empty queue` kalau kosong.

`main.cpp` mengikuti contoh di soal: queue dibuat, dicetak dalam keadaan kosong, lalu enqueue 5, 2, 7, dequeue, enqueue 4, dan dequeue dua kali, dengan `printInfo` di setiap langkah. Di bawahnya ditambahkan uji kecil yang mengisi queue sampai penuh dan mencoba memasukkan satu elemen lagi, karena bagian inilah yang nanti membedakan ketiga alternatif.

Output 1 sesuai dengan cara kerja Alternatif 1. Awalnya `-1 - -1` dengan tulisan empty queue, lalu setelah enqueue 5, 2, 7 head tetap 0 sementara tail naik sampai 2. Pada dequeue pertama angka 5 keluar dan angka 2 dan 7 bergeser ke index 0 dan 1, makanya tail turun jadi 1 (`0 - 1 | 2 7`). Pola ini berlanjut sampai tersisa angka 4 di `0 - 0`. Pada Output 2, queue terisi penuh di `0 - 4`, enqueue angka 3 ditolak dengan pesan Queue penuh, dan setelah satu dequeue elemen bergeser sehingga angka 3 bisa masuk di enqueue berikutnya.

### 2. Buatlah implementasi ADT Queue pada file queue.cpp dengan mekanisme Alternatif 2 (head bergerak, tail bergerak)

`queue.h` dan `main.cpp` sama dengan Unguided 1, jadi tidak ditulis ulang. Yang berubah hanya `queue.cpp`.

**[Source - queue.cpp]**

```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    // Penuh beneran kalau head di 0 dan tail di batas maksimal
    return (Q.head == 0 && Q.tail == 4); 
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            // Kalau tail mentok di ujung tapi depan kosong (penuh semu)
            if (Q.tail == 4 && Q.head > 0) {
                // Geser ke depan untuk bersihin ruang
                int geser = Q.head;
                for (int i = Q.head; i <= Q.tail; i++) {
                    Q.info[i - geser] = Q.info[i];
                }
                Q.tail = Q.tail - geser;
                Q.head = 0;
            }
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        return -999;
    } else {
        infotype temp = Q.info[Q.head];
        if (Q.head == Q.tail) {
            createQueue(Q); // Reset kalau datanya habis
        } else {
            Q.head++; // Head-nya maju, tanpa geser data
        }
        return temp;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

**[Source - queue.h]**

```C++
#ifndef QUEUE_ALT1_H
#define QUEUE_ALT1_H
#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5]; 
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

**[Source - main.cpp]**

```C++
#include "queue.h"

int main() {
    cout << "Hello world!" << endl;
    cout << "------------------------" << endl;
    cout << "H - T   : Queue Info" << endl;
    cout << "------------------------" << endl;
    
    Queue Q;
    createQueue(Q);
    printInfo(Q);
    
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    
    return 0;
}
```
### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2](assets/output%202.png)

Pada Alternatif 2 `dequeue` jauh lebih ringan: setelah elemen di head diambil, head cukup dimajukan (`Q.head++`) dan tidak ada elemen yang digeser. Kalau elemen terakhir diambil, head dan tail kembali ke -1 seperti sebelumnya. Akibatnya, head tidak lagi selalu 0, sehingga `isFullQueue` tidak bisa cuma mengecek tail. Queue baru dianggap benar-benar penuh kalau head di index 0 dan tail di index terakhir. Kalau tail sudah di index terakhir tapi head masih di depan 0, itu penuh semu, dan `enqueue` menanganinya dengan menggeser semua elemen ke awal array dulu (head jadi 0, tail menyesuaikan), baru tail dimajukan untuk elemen yang baru. Penggeserannya hanya dilakukan di saat itu saja, sesuai penjelasan modul.

Di Output 1 kelihatan bedanya dengan Alternatif 1: setelah dequeue pertama nilainya `1 - 2 | 2 7`, head sudah pindah ke index 1 dan elemennya tidak bergeser. Setelah dua dequeue berikutnya tersisa angka 4 di `3 - 3`. Output 2 menunjukkan penuh semu: enqueue 8 membuat tail sampai index 4 (`3 - 4`), jadi saat angka 1 masuk, elemen digeser dulu ke awal dan hasilnya `0 - 2`. Setelah penuh di `0 - 4` dan satu dequeue (`1 - 4`), enqueue angka 3 memicu pergeseran lagi sehingga kembali ke `0 - 4`.

### 3. Buatlah implementasi ADT Queue pada file queue.cpp dengan mekanisme Alternatif 3 (head dan tail berputar)

`queue.h` dan `main.cpp` juga sama dengan Unguided 1. Hanya `queue.cpp` yang berbeda.

**[Source - queue.cpp]**

```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    // penuh kalau posisi setelah tail (muter) ketemu head
    return ((Q.tail + 1) % MAKS == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh, " << x << " tidak bisa dimasukkan" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKS;   // kalau di ujung balik ke 0
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;   // -1 kalau queue kosong
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
    } else {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKS;   // sama, kalau di ujung balik ke 0
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (i != Q.tail) {
            cout << Q.info[i] << " ";
            i = (i + 1) % MAKS;
        }
        cout << Q.info[Q.tail] << " ";
    }
    cout << endl;
}
```

**[Source - queue.h]**

```C++
#ifndef QUEUE_ALT1_H
#define QUEUE_ALT1_H
#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5]; 
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

**[Source - main.cpp]**

```C++

#include "queue.h"

int main() {
    cout << "Hello world!" << endl;
    cout << "------------------------" << endl;
    cout << "H - T   : Queue Info" << endl;
    cout << "------------------------" << endl;

    Queue Q;
    createQueue(Q);
    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);

    enqueue(Q, 2);
    printInfo(Q);

    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 4);
    printInfo(Q);

    enqueue(Q, 9);
    printInfo(Q);

    enqueue(Q, 1);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    return 0;
}

```
### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 3](assets/output%203.png)

Di Alternatif 3 head dan tail dimajukan dengan rumus `(posisi + 1) % MAKS`, jadi kalau sudah di index 4 langkah berikutnya kembali ke index 0. Dengan begitu tidak ada lagi pergeseran elemen dan tidak ada penuh semu, karena ruang kosong di depan langsung terpakai. Konsekuensinya, kondisi penuh tidak bisa dicek lewat `tail == MAKS - 1`. Queue penuh kalau posisi setelah tail (yang sudah dimodulo) bertemu head. `printInfo` juga harus ikut berputar, yaitu berjalan dari head dengan `% MAKS` sampai bertemu tail, karena urutan index bisa saja loncat dari 4 ke 0.

Output 1 sama dengan Alternatif 2 karena selama tail belum melewati index terakhir, cara kerjanya memang mirip. Perbedaannya muncul di Output 2. Setelah `3 - 4`, enqueue angka 1 tidak menggeser apa pun, tail cuma balik ke index 0 (`3 - 0`), lalu lanjut `3 - 1` dan `3 - 2`. Di titik ini queue penuh karena `(2 + 1) % 5` sama dengan head, yaitu 3, jadi enqueue angka 3 ditolak. Setelah satu dequeue head pindah ke 4 (`4 - 2`), dan enqueue angka 3 langsung masuk di index 3 tanpa pergeseran (`4 - 3`).

## Kesimpulan
Dari praktikum ini kelihatan bahwa queue sebenarnya sederhana: elemen masuk lewat tail dan keluar lewat head. Yang membuat tiap implementasi berbeda adalah cara mengatur head dan tail-nya. Pada versi linked list jumlah elemen tidak dibatasi dan memorinya dikelola lewat alokasi dan dealokasi, tapi pointer harus dijaga dengan hati-hati, terutama saat queue kosong atau tinggal satu elemen.

Pada versi array, ketiga alternatif menghasilkan urutan data yang sama, tapi nilai head dan tail-nya berbeda. Alternatif 1 paling mudah dipahami namun boros karena tiap dequeue menggeser elemen. Alternatif 2 menghilangkan pergeseran itu, tapi memunculkan masalah penuh semu. Alternatif 3 (circular) menyelesaikan masalah tersebut karena posisi kosong di depan dipakai lagi tanpa menggeser data [4], dengan konsekuensi pengecekan penuh dan perulangan pada `printInfo` harus memakai modulo.

## Referensi
[1] A. Zulfahrizan, M. A. S. HSB, F. br. Hutagalung, dan F. Ramadhani. (2025). "Implementasi Library Python Dequeue pada Antrian Bank Menggunakan Logika First In First Out". JATI (Jurnal Mahasiswa Teknik Informatika), Vol. 9, No. 1, hlm. 224-228. Diakses melalui https://ejournal.itn.ac.id/jati/article/download/12260/6856.
<br>[2] R. Gunawan, H. Yuana, dan S. Kirom. (2023). "Implementasi Metode Queue pada Sistem Antrian Online Berbasis Web Studi Kasus UPTD Puskesmas Sananwetan". JATI (Jurnal Mahasiswa Teknik Informatika), Vol. 7, No. 3, hlm. 1538-1545. https://doi.org/10.36040/jati.v7i3.6687.
<br>[3] A. Wijoyo, A. R. Prasetiyo, A. A. Salsabila, K. Nife, Murni, dan P. B. Nadapdap. (2024). "Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian". JRIIN: Jurnal Riset Informatika dan Inovasi, Vol. 1, No. 12, hlm. 1244-1246. Diakses melalui https://jurnalmahasiswa.com/index.php/jriin/article/view/1060.
<br>[4] S. N. Aini dan R. Kurniawan. (2025). "Sistem Antrian Pasien Berbasis Web dengan Algoritma Circular Queue pada Klinik Pratama Rawat Inap Ar-Razi". CESS (Journal of Computer Engineering, System and Science), Vol. 10, No. 2, hlm. 666-678. Diakses melalui https://jurnal.unimed.ac.id/2012/index.php/cess/article/download/67447/27654/155420.
<br>[5] Informatics Laboratory. "Modul 8 Queue". Modul Praktikum Struktur Data. Telkom University.
