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