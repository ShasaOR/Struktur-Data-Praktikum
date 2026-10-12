#include <iostream>

using namespace std;

// Prosedur menampilkan isi array 2D 3x3
void tampilkanArray2D(int arr[3][3], string namaArray) {
    cout << "Isi " << namaArray << ":" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Prosedur menukar isi dari 2 array integer 2D pada posisi tertentu
void tukarElemenArray2D(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        int temp = arr1[baris][kolom];
        arr1[baris][kolom] = arr2[baris][kolom];
        arr2[baris][kolom] = temp;
    } else {
        cout << "Indeks posisi di luar batas (0-2)!" << endl;
    }
}

// Prosedur menukar isi dari variabel yang ditunjuk oleh 2 buah pointer
void tukarNilaiPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int val1 = 10;
    int val2 = 20;
    int *ptr1 = &val1;
    int *ptr2 = &val2;

    cout << "--- KONDISI AWAL ---" << endl;
    tampilkanArray2D(A, "Array A");
    tampilkanArray2D(B, "Array B");
    cout << "Pointer 1 (*ptr1): " << *ptr1 << ", Pointer 2 (*ptr2): " << *ptr2 << endl << endl;

    // Menukar elemen array 2D pada baris 1, kolom 1 (indeks [1][1])
    tukarElemenArray2D(A, B, 1, 1);
    cout << "--- SETELAH TUKAR ELEMEN ARRAY 2D (Posisi [1][1]) ---" << endl;
    tampilkanArray2D(A, "Array A");
    tampilkanArray2D(B, "Array B");
    cout << endl;

    // Menukar nilai variabel yang ditunjuk pointer
    tukarNilaiPointer(ptr1, ptr2);
    cout << "--- SETELAH TUKAR NILAI POINTER ---" << endl;
    cout << "Pointer 1 (*ptr1): " << *ptr1 << ", Pointer 2 (*ptr2): " << *ptr2 << endl;

    return 0;
}