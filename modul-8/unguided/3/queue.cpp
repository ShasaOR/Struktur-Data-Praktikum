#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    // Penuh kalau tail tepat di belakang head
    return ((Q.tail + 1) % 5 == Q.head); 
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            // Muter ke indeks 0 kalau ngelewatin batas maksimal
            Q.tail = (Q.tail + 1) % 5; 
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        return -999;
    } else {
        infotype temp = Q.info[Q.head];
        if (Q.head == Q.tail) { // Sisa 1 elemen
            createQueue(Q); 
        } else {
            // Head maju dengan konsep melingkar
            Q.head = (Q.head + 1) % 5; 
        }
        return temp;
    }
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << Q.head << " - " << Q.tail << " : empty queue" << endl;
    } else {
        cout << Q.head << " - " << Q.tail << " : ";
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % 5;
        }
        cout << endl;
    }
}
