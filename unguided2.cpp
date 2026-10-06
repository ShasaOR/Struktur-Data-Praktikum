#include <iostream>

using namespace std;

// Menukar 3 variabel menggunakan Pointer
void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

// Menukar 3 variabel menggunakan Reference
void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 10, y = 20, z = 30;

    cout << "========================================\n";
    cout << "  SWAP 3 VARIABEL (POINTER & REFERENCE) \n";
    cout << "========================================\n";

    cout << "NILAI AWAL:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    // Menukar dengan Pointer (a -> b, b -> c, c -> a)
    tukarPointer(&x, &y, &z);
    cout << "\nSETELAH TUKAR DENGAN POINTER:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    // Menukar kembali dengan Reference (kembali ke susunan sebelum tukar reference)
    tukarReference(x, y, z);
    cout << "\nSETELAH TUKAR DENGAN REFERENCE:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}