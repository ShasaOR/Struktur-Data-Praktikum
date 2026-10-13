#include "list.h"[cite: 5]

#include <iostream>[cite: 5]
using namespace std;[cite: 5]

int main(){[cite: 5]
    LinkedList List;[cite: 5]
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;[cite: 5]
    createList(List);[cite: 5]

    dataMahasiswa mhs;[cite: 5]

    nodeA = alokasi("Dhimas", "2311102151", 20);[cite: 5]
    nodeB = alokasi("Arvin", "221110014", 21);[cite: 5]
    nodeC = alokasi("Rizal", "231110029", 20);[cite: 5]
    nodeD = alokasi("Satrio", "2211102173", 21);[cite: 5]
    nodeE = alokasi("Joshua", "2311102133", 21);[cite: 5]

    insertFirst(List, nodeA);[cite: 5]
    insertLast(List, nodeB);[cite: 5]
    insertAfter(List, nodeC, nodeA);[cite: 5]
    insertAfter(List, nodeD, nodeC);[cite: 5]
    insertLast(List, nodeE);[cite: 5]

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;[cite: 5]
    printList(List);[cite: 5]
    cout << "Jumlah node : " << nbList(List) << endl;[cite: 5]
    cout << endl;[cite: 5]

    delFirst(List);[cite: 5]
    delLast(List);[cite: 5]
    delAfter(List, nodeD, nodeC);[cite: 5]

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;[cite: 5]
    printList(List);[cite: 5]
    cout << "Jumlah node : " << nbList(List) << endl;[cite: 5]
    cout << endl;[cite: 5]

    deleteList(List);[cite: 5]
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;[cite: 5]
    printList(List);[cite: 5]
    cout << "Jumlah node : " << nbList(List) << endl;[cite: 5]
    cout << endl;[cite: 5]

    return 0;[cite: 5]
}[cite: 5]