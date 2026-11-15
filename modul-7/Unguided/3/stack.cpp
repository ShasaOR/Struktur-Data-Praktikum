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