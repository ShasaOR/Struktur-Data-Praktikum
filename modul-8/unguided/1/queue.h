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