#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// Fungsi untuk mengecek apakah list kosong
bool isEmpty(linkedList list) {
    return list.first == Nil;
}

// Membuat linked list kosong
void createlist(linkedList &list) {
    list.first = Nil;
}

// Membuat node baru
address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;

    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;

    return nodeBaru;
}

// Menghapus node dari memori
void dealokasi(address &nodeHapus) {
    if (nodeHapus != Nil) {
        delete nodeHapus;
        nodeHapus = Nil;
    }
}

// Menambahkan node di awal list
void insertFirst(linkedList &list, address nodeBaru) {
    if (nodeBaru != Nil) {
        nodeBaru->next = list.first;
        list.first = nodeBaru;
    }
}

// Menambahkan node setelah node Prev
void insertAfter(linkedList &list, address nodeBaru, address Prev) {
    if (nodeBaru == Nil) {
        cout << "Node baru tidak valid!" << endl;
    } else if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

// Menambahkan node di akhir list
void insertLast(linkedList &list, address nodeBaru) {
    if (nodeBaru == Nil) {
        return;
    }

    nodeBaru->next = Nil;

    if (isEmpty(list)) {
        list.first = nodeBaru;
    } else {
        address nodeBantu = list.first;

        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->next = nodeBaru;
    }
}

// Menghapus node pertama
void delFirst(linkedList &list) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }

    address nodeHapus = list.first;
    list.first = nodeHapus->next;
    nodeHapus->next = Nil;

    dealokasi(nodeHapus);
}

// Menghapus node terakhir
void delLast(linkedList &list) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }

    address nodeHapus = list.first;

    // Jika hanya ada satu node
    if (nodeHapus->next == Nil) {
        list.first = Nil;
        dealokasi(nodeHapus);
        return;
    }

    // Mencari node sebelum node terakhir
    address nodePrev = Nil;

    while (nodeHapus->next != Nil) {
        nodePrev = nodeHapus;
        nodeHapus = nodeHapus->next;
    }

    nodePrev->next = Nil;
    dealokasi(nodeHapus);
}

// Jika list.h masih menggunakan nama dellast
void dellast(linkedList &list) {
    delLast(list);
}

// Menghapus node setelah node Prev
void delAfter(linkedList &list, address nodeHapus, address nodePrev) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    } else if (nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        nodeHapus->next = Nil;

        dealokasi(nodeHapus);
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

// Menampilkan isi list
void printList(linkedList list) {
    if (isEmpty(list)) {
        cout << "List kosong." << endl;
        return;
    }

    address nodeBantu = list.first;

    while (nodeBantu != Nil) {
        cout << "Nama: " << nodeBantu->isidata.nama
             << ", NIM: " << nodeBantu->isidata.nim
             << ", Usia: " << nodeBantu->isidata.umur
             << endl;

        nodeBantu = nodeBantu->next;
    }
}

// Menghitung jumlah node
int nbList(linkedList list) {
    int count = 0;
    address nodeBantu = list.first;

    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }

    return count;
}

// Menghapus seluruh node dalam list
void deleteList(linkedList &list) {
    address nodeHapus;

    while (list.first != Nil) {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;

        dealokasi(nodeHapus);
    }

    cout << "List sudah terhapus!" << endl;
}
