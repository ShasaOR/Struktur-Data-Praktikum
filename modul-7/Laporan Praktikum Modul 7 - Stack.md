<div align="center">

# Laporan Praktikum Modul 7 - Stack

Shasa Olivia Rose - 109082500207

</div>

## Dasar Teori

### A. Konsep Dasar Stack

Stack atau tumpukan adalah struktur data linear yang cara kerjanya mirip tumpukan piring: piring yang paling akhir ditaruh di atas akan jadi yang pertama diambil. Prinsip ini dikenal dengan nama LIFO (Last In First Out), yaitu data yang terakhir masuk akan keluar paling awal \[1\]\[3\].

#### 1. Prinsip LIFO

Karena sifat LIFO, data yang ada di bagian bawah tidak bisa diambil sebelum data di atasnya keluar lebih dulu. Satu-satunya jalan masuk dan jalan keluar adalah bagian paling atas tumpukan \[4\].

#### 2. Penunjuk TOP

Komponen stack pada dasarnya sama seperti singly linked list, bedanya akses hanya boleh dilakukan di elemen paling awal yang disebut TOP \[4\]. Stack yang masih kosong ditandai dengan TOP bernilai Nil pada representasi pointer atau bernilai 0 pada representasi tabel.

#### 3. Penerapan Stack

Stack dipakai di banyak tempat, misalnya untuk mengevaluasi ekspresi matematika, mengatur memori, dan fitur undo/redo \[1\]. Fitur undo cocok memakai stack karena aksi terakhir yang dilakukan pengguna memang aksi pertama yang dibatalkan \[2\].

### B. Operasi Dasar pada Stack

Operasi utama pada stack hanya ada dua, yaitu Push untuk menyisipkan data dan Pop untuk mengambil data \[4\]. Keduanya hanya menyentuh elemen TOP sehingga tidak perlu menelusuri isi stack, dan inilah alasan kenapa waktu eksekusinya konstan atau O(1) \[2\].

#### 1. Push

Push menambahkan elemen baru ke puncak tumpukan dan sama dengan insert first pada list biasa. Pada representasi pointer, elemen baru dibuat lebih dulu, pointer `next`-nya diarahkan ke TOP yang lama, lalu TOP dipindah ke elemen baru \[4\]. Pada representasi tabel, cukup menaikkan nilai TOP satu langkah lalu mengisi data di posisi itu.

#### 2. Pop

Pop mengambil elemen di puncak dan mirip dengan delete first pada list linear \[4\]. Pada representasi tabel, data di posisi TOP diambil lalu TOP turun satu langkah. Menurut modul, data lama tidak benar-benar dihapus dari array, hanya sudah dianggap berada di luar stack \[4\].

#### 3. Primitif Pendukung

Selain push dan pop, ada beberapa primitif yang menemani, seperti `createStack` untuk membentuk stack kosong dan `isEmpty` untuk mengecek apakah stack masih kosong. Pada representasi pointer masih ada `alokasi` dan `dealokasi`, sedangkan pada representasi tabel keduanya tidak diperlukan karena tidak ada pengelolaan memori \[4\].

### C. Representasi Stack

Stack bisa dibuat dengan dua cara, memakai array atau memakai linked list, dan keduanya sama-sama dibahas sebagai cara implementasi stack di C++ \[3\].

#### 1. Representasi Pointer

Setiap elemen berisi `info` dan `next`, sedangkan stack hanya menyimpan satu pointer `Top`. Jumlah elemen bisa bertambah sesuai kebutuhan karena memorinya dialokasikan saat dibutuhkan \[1\]\[4\].

#### 2. Representasi Tabel

Data disimpan dalam array berindeks dengan jumlah tumpukan yang terbatas sampai indeks Imax. Stack kosong ditandai Top = 0 dan tidak perlu manajemen memori \[4\]. Praktikum kali ini memakai array berukuran 10 pada Guided dan 20 pada Unguided.

#### 3. Perbandingan

Studi perbandingan keduanya menyebutkan bahwa array lebih efisien untuk akses data yang ukurannya tetap, sedangkan linked list lebih unggul soal fleksibilitas ukuran dan alokasi memori dinamis \[1\]. Ukuran array juga harus ditentukan di awal \[1\]. Gagasan membatasi kapasitas stack agar pemakaian memori terkontrol ini juga dikenal sebagai bounded stack \[2\].

## Guided

### 1. \[Header - stack.h\]

```C++
/* file : stack.h
   contoh ADT stack dengan representasi tabel */
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype {
    char nim[20];
    char nama[20];
};
struct Stack {
    infotype info[10];
    int Top;
};

/* prototype */
/******** pengecekan apakah Stack kosong *********/
int isEmpty(Stack S);
/* mengembalikan nilai 0 jika stack kosong */

/******** pembuatan Stack ********/
void createStack(Stack &S);
/* I.S. sembarang
   F.S. terbentuk stack dengan Top=0 */

/******** penambahan elemen pada Stack ********/
void push(Stack &S, infotype X);
/* I.S. Stack mungkin kosong
   F.S. menambahkan elemen pada stack dengan nilai X, TOP=TOP+1 */

/******** penghapusan elemen pada Stack ********/
void pop(Stack &S, infotype &X);
/* I.S. stack tidak kosong
   F.S. nilai info pada indeks TOP disimpan pada X, kemudian TOP=TOP-1 */

/******** proses semua elemen Stack *********/
void viewStack(Stack S);
/* I.S. stack mungkin kosong
   F.S. jika stack tidak kosong menampilkan semua info yang ada pada stack
*/
#endif // STACK_H_INCLUDED
```

File header ini berisi cetakan ADT stack yang dipakai program. Baris `#ifndef` dan `#define` di awal fungsinya supaya header tidak ter-include dua kali saat dikompilasi. `iostream` ikut dipanggil di sini karena `stack.cpp` nanti butuh `cout`.

Data yang disimpan dibungkus dalam `struct infotype` yang isinya `nim` dan `nama`, masing-masing char array 20 karakter. Lalu `struct Stack` terdiri dari array `info` berukuran 10 sebagai tempat data dan `Top` sebagai penunjuk puncak. Karena arraynya cuma 10, stack ini paling banyak menampung 10 data, dan Top bernilai 0 berarti stack kosong.

Di bawahnya ada lima prototype fungsi: `isEmpty`, `createStack`, `push`, `pop`, dan `viewStack`. Ada satu hal yang gampang kebalik, yaitu `isEmpty` di sini mengembalikan 0 kalau stack kosong, bukan 1 seperti kebiasaan umumnya (sesuai komentar di modul).

### 2. \[Implementasi - stack.cpp\]

```C++
#include "stack.h"

int isEmpty(Stack S) {
    /* Top = 0 berarti kosong, sesuai komentar di stack.h dikembalikan 0 */
    if (S.Top == 0) {
        return 0;
    } else {
        return 1;
    }
}

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype X) {
    if (S.Top < 10) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = X;   /* Top 1..10 dipetakan ke indeks array 0..9 */
    } else {
        cout << "Stack penuh, data tidak bisa ditambahkan" << endl;
    }
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S) != 0) {
        X = S.info[S.Top - 1];
        S.Top = S.Top - 1;
    } else {
        cout << "Stack kosong, tidak ada data yang bisa diambil" << endl;
    }
}

void viewStack(Stack S) {
    if (isEmpty(S) == 0) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "Isi stack (dari TOP):" << endl;
        for (int i = S.Top; i >= 1; i--) {
            cout << i << ". " << S.info[i - 1].nim << " - "
                 << S.info[i - 1].nama << endl;
        }
    }
}
```

Di file ini semua prototype tadi diisi. `isEmpty` cuma mengecek Top: kalau 0 dikembalikan 0 (kosong), selain itu dikembalikan 1. Jadi kalau di kode lain ketemu `isEmpty(S) != 0`, artinya stack justru ada isinya.

`createStack` tinggal mengisi Top dengan 0 sehingga stack dianggap kosong. Isi array tidak perlu dibersihkan.

`push` mengecek dulu apakah Top masih di bawah 10. Kalau masih muat, Top dinaikkan satu lalu data X disimpan di `info[Top - 1]`. Dikurangi 1 karena Top dihitung dari 1 sampai 10, sedangkan indeks array mulai dari 0. Kalau sudah penuh, yang keluar hanya pesan dan datanya tidak dimasukkan.

`pop` kebalikannya. Kalau stack tidak kosong, isi `info[Top - 1]` disalin ke X, lalu Top turun satu. Data lama di array sebenarnya masih ada, hanya saja sudah di luar jangkauan stack dan akan tertimpa kalau ada push berikutnya, sama seperti gambar pop di modul. Kalau stack kosong, muncul pesan dan X dibiarkan.

`viewStack` menampilkan isi dari puncak ke dasar. Loop-nya mulai dari i = Top lalu turun sampai 1, dan tiap barisnya mencetak nomor, NIM, dan nama. Kalau stack kosong, cukup tampil tulisan "Stack kosong".

### 3. \[Program Utama - main.cpp\]

```C++
#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    infotype data, hasil;

    createStack(S);
    cout << "Stack baru dibuat, Top = " << S.Top << endl;
    viewStack(S);

    cout << endl << "--- Push 3 data ---" << endl;
    strcpy(data.nim, "103112400001");
    strcpy(data.nama, "Andi");
    push(S, data);

    strcpy(data.nim, "103112400002");
    strcpy(data.nama, "Budi");
    push(S, data);

    strcpy(data.nim, "103112400003");
    strcpy(data.nama, "Citra");
    push(S, data);
    viewStack(S);

    cout << endl << "--- Pop 1 data ---" << endl;
    pop(S, hasil);
    cout << "Data yang diambil: " << hasil.nim << " - " << hasil.nama << endl;
    viewStack(S);

    cout << endl << "--- Pop sampai kosong ---" << endl;
    pop(S, hasil);
    pop(S, hasil);
    pop(S, hasil);
    viewStack(S);

    return 0;
}
```

Program utama menjalankan fungsi-fungsi tadi secara berurutan. Awalnya stack dibuat dan langsung ditampilkan, hasilnya kosong dengan Top = 0. Setelah itu tiga data dimasukkan lewat `push`: Andi, Budi, dan Citra. Isi variabel `data` diatur pakai `strcpy` karena NIM dan nama bertipe char array yang tidak bisa diisi langsung dengan tanda `=`, makanya `<cstring>` ikut di-include. Waktu `viewStack` dipanggil, urutan tampilnya Citra, Budi, Andi, sebab Citra masuk paling akhir dan posisinya di TOP.

Satu kali `pop` mengambil Citra, ditampung ke `hasil` lalu dicetak, sehingga stack tersisa Budi dan Andi. Di bagian terakhir `pop` dipanggil tiga kali padahal isinya tinggal dua. Pop pertama dan kedua mengambil Budi dan Andi, sedangkan pop ketiga sudah tidak menemukan data sehingga yang muncul pesan "Stack kosong, tidak ada data yang bisa diambil". `viewStack` terakhir pun menampilkan "Stack kosong". Dari sini kelihatan pengecekan kosong di `pop` memang bekerja.

## Unguided

### 1. Membuat ADT Stack dengan array (createStack, push, pop, printInfo, balikStack) beserta `main.cpp`-nya

**\[Header - stack.h\]**

```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int Top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif // STACK_H_INCLUDED
```

**\[Implementasi - stack.cpp\]**

```C++
#include "stack.h"

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype x) {
    if (S.Top < 20) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.Top == 0) {
        cout << "Stack kosong" << endl;
        return -1;
    }
    infotype x = S.info[S.Top - 1];
    S.Top = S.Top - 1;
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.Top; i >= 1; i--) {
        cout << S.info[i - 1] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    for (int i = 0; i < S.Top / 2; i++) {
        infotype temp = S.info[i];
        S.info[i] = S.info[S.Top - 1 - i];
        S.info[S.Top - 1 - i] = temp;
    }
}
```

**\[Program Utama - main.cpp\]**

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](assets/output%201.png)

Soal pertama meminta ADT stack dari array berisi bilangan bulat dengan kapasitas 20. Di `stack.h`, `infotype` didefinisikan sebagai `int`, lalu `struct Stack` berisi `info[20]` dan `Top`. Cara kerja Top sama seperti di Guided: 0 berarti kosong dan elemen ke-Top disimpan di indeks `Top - 1`.

`push` menaikkan Top lalu mengisi data baru, dan menolak kalau stack sudah penuh. `pop` dibuat sebagai function yang mengembalikan nilai (sesuai bentuk `function pop ... -> infotype` di soal), jadi angka yang diambil bisa langsung dipakai. Kalau stack kosong, yang dikembalikan -1 dan muncul pesan. `printInfo` mencetak isi dari TOP ke bawah dengan awalan `[TOP]`. Untuk `balikStack`, urutan dibalik dengan menukar elemen paling bawah dengan paling atas, lalu bergerak ke tengah. Loop-nya cukup sampai `Top / 2` supaya pasangan yang sama tidak ditukar dua kali.

Di `main`, soal menulis `Push` dengan huruf P besar, tapi C++ membedakan huruf besar dan kecil, jadi yang dipakai `push` sesuai nama di header. Alurnya: push 3, 4, 8, lalu pop (8 keluar), push 2 dan 3, pop lagi (3 keluar), terakhir push 9. Isi stack dari bawah jadi 3, 4, 2, 9 sehingga `printInfo` menampilkan `[TOP] 9 2 4 3`. Setelah `balikStack` hasilnya `[TOP] 3 4 2 9`. Keduanya sama dengan output contoh di modul.

### 2. Menambahkan prosedur `pushAscending` pada stack

**\[Header - stack.h\]**

```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int Top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif // STACK_H_INCLUDED
```

**\[Implementasi - stack.cpp\]**

```C++
#include "stack.h"

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype x) {
    if (S.Top < 20) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.Top == 0) {
        cout << "Stack kosong" << endl;
        return -1;
    }
    infotype x = S.info[S.Top - 1];
    S.Top = S.Top - 1;
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.Top; i >= 1; i--) {
        cout << S.info[i - 1] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    for (int i = 0; i < S.Top / 2; i++) {
        infotype temp = S.info[i];
        S.info[i] = S.info[S.Top - 1 - i];
        S.info[S.Top - 1 - i] = temp;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (S.Top >= 20) {
        cout << "Stack penuh" << endl;
        return;
    }
    int pos = S.Top;   /* indeks (0..19) tempat x akan ditaruh */
    while (pos > 0 && S.info[pos - 1] > x) {
        S.info[pos] = S.info[pos - 1];   /* geser elemen yang lebih besar ke atas */
        pos--;
    }
    S.info[pos] = x;
    S.Top = S.Top + 1;
}
```

**\[Program Utama - main.cpp\]**

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### Output Unguided 2 :

##### Output 2

![Screenshot Output Unguided 2](assets/output%202.png)

Soal kedua menambah `pushAscending`, yaitu memasukkan data baru sambil menjaga isi stack tetap terurut, dengan angka terkecil di dasar dan terbesar di TOP. Itu sebabnya outputnya terbaca 9 8 4 3 3 2 kalau dilihat dari TOP.

Caranya, posisi untuk `x` dicari dulu. Variabel `pos` mulai dari ujung, yaitu tempat tepat di atas elemen teratas. Selama elemen di bawahnya lebih besar dari `x`, elemen itu digeser satu tempat ke atas dan `pos` turun. Begitu ketemu elemen yang lebih kecil atau sama (atau sudah sampai dasar), `x` ditaruh di `pos` dan Top naik satu. Contohnya waktu stack berisi 3, 4, 8 lalu 2 masuk: 8, 4, dan 3 digeser semua, jadi 2 menempati dasar dan stack menjadi 2, 3, 4, 8. Saat 3 kedua masuk, hanya 8 dan 4 yang bergeser sehingga 3 yang baru duduk di samping 3 yang lama. Terakhir 9 langsung ditaruh di puncak tanpa menggeser apa pun karena sudah paling besar.

Bagian lain tidak berubah, `stack.h` hanya ketambahan satu prototype. Setelah `balikStack` dipanggil, urutannya terbalik menjadi `[TOP] 2 3 3 4 8 9`.

### 3. Menambahkan prosedur `getInputStream` pada stack

**\[Header - stack.h\]**

```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int Top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif // STACK_H_INCLUDED
```

**\[Implementasi - stack.cpp\]**

```C++
#include "stack.h"

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype x) {
    if (S.Top < 20) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.Top == 0) {
        cout << "Stack kosong" << endl;
        return -1;
    }
    infotype x = S.info[S.Top - 1];
    S.Top = S.Top - 1;
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.Top; i >= 1; i--) {
        cout << S.info[i - 1] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    for (int i = 0; i < S.Top / 2; i++) {
        infotype temp = S.info[i];
        S.info[i] = S.info[S.Top - 1 - i];
        S.info[S.Top - 1 - i] = temp;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (S.Top >= 20) {
        cout << "Stack penuh" << endl;
        return;
    }
    int pos = S.Top;   /* indeks (0..19) tempat x akan ditaruh */
    while (pos > 0 && S.info[pos - 1] > x) {
        S.info[pos] = S.info[pos - 1];   /* geser elemen yang lebih besar ke atas */
        pos--;
    }
    S.info[pos] = x;
    S.Top = S.Top + 1;
}

void getInputStream(Stack &S) {
    int c = cin.get();
    while (c != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            push(S, c - '0');   /* ubah karakter angka jadi nilai int */
        }
        c = cin.get();
    }
}
```

**\[Program Utama - main.cpp\]**

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### Output Unguided 3 :

##### Output 3

![Screenshot Output Unguided 3](assets/output%203.png)

Soal ketiga menambah `getInputStream`, yang membaca ketikan pengguna karakter demi karakter dan memasukkannya ke stack sampai Enter ditekan. Pembacaannya memakai `cin.get()` karena fungsi ini, berbeda dengan `cin >>`, ikut membaca karakter spasi dan Enter (`'\n'`). Loop berhenti ketika karakter yang terbaca `'\n'` atau `EOF` kalau input habis. Variabel `c` bertipe `int` supaya bisa dibandingkan dengan `EOF`.

Yang terbaca itu karakter, bukan angka. Karakter '4' sebenarnya kode ASCII, bukan nilai 4, jadi sebelum di-push dikurangi `'0'` (`c - '0'`) supaya jadi angka aslinya. Ada pengecekan juga agar hanya karakter '0' sampai '9' yang masuk, jadi huruf atau spasi akan diabaikan dan tidak mengacaukan isi stack.

Pada contoh input `4729601`, digit masuk satu per satu dari kiri sehingga 1 jadi yang terakhir dan berada di TOP, hasilnya `[TOP] 1 0 6 9 2 7 4`. Setelah dibalik menjadi `[TOP] 4 7 2 9 6 0 1`, yaitu urutan yang sama seperti saat diketik. Kapasitas stack tetap 20, jadi kalau angka yang diketik lebih dari itu, sisanya ditolak dengan pesan "Stack penuh".

## Kesimpulan

Dari praktikum ini terlihat bahwa stack itu sederhana tapi aturannya ketat: semua yang masuk dan keluar lewat TOP, jadi data terakhir yang masuk pasti keluar paling dulu (LIFO). Dengan representasi tabel, stack cukup dibuat dari sebuah array dan satu variabel Top tanpa alokasi memori, tapi kapasitasnya terbatas sehingga `push` harus mengecek penuh dan `pop` harus mengecek kosong terlebih dulu. Latihan Unguided juga menunjukkan stack bisa dikembangkan lebih jauh dari sekadar push dan pop, misalnya dibalik dengan `balikStack`, dijaga tetap terurut dengan `pushAscending`, atau diisi dari input pengguna lewat `getInputStream`. Semua program sudah dicoba dan outputnya cocok dengan contoh yang ada di modul.

## Referensi

\[1\] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). "Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List". JUTECH: Journal Education and Technology, 5(2), 484-498. Diakses melalui [https://doi.org/10.31932/jutech.v5i2.4263](https://doi.org/10.31932/jutech.v5i2.4263). \
\[2\] Ramadhan, R. A., & Ikasari, I. H. (2026). "Penerapan Struktur Data Stack untuk Implementasi Fitur Undo pada Aplikasi Sederhana: Literature Review". Journal of Computer Science and Information Technology (JCSIT), 3(3), 163-170. Diakses melalui [https://journal.ppmi.web.id/index.php/jcsit/article/download/3955/2617/28627](https://journal.ppmi.web.id/index.php/jcsit/article/download/3955/2617/28627). \
\[3\] Rahman, S., Hartono, Joni, Dafitri, H., Tanjung, J. P., & Chiuloto, K. (2025). "Struktur Data dan Algoritma: Pendekatan Visual dan Praktis dalam C++". Medan: Universitas Medan Area Press. Diakses melalui [https://phki-pghc.uma.ac.id/wp-content/uploads/2025/06/web-8.pdf](https://phki-pghc.uma.ac.id/wp-content/uploads/2025/06/web-8.pdf). \
\[4\] Informatics Laboratory, Fakultas Informatika, Telkom University. "Modul 7 Stack". Modul Praktikum Struktur Data.