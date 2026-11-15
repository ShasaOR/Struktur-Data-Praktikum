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