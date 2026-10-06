#include <iostream>
#include <iomanip>

using namespace std;

void inputMatriks(int M[3][3], string nama) {
    cout << "Masukkan elemen matriks " << nama << " (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nama << "[" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }
}

void cetakMatriks(int M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(5) << M[i][j];
        }
        cout << endl;
    }
}

int main() {
    int A[3][3], B[3][3], C[3][3];

    cout << "========================================\n";
    cout << "  PROGRAM OPERASI MATRIKS 3X3           \n";
    cout << "========================================\n";

    inputMatriks(A, "A");
    cout << endl;
    inputMatriks(B, "B");

    cout << "\nMatriks A:\n";
    cetakMatriks(A);

    cout << "\nMatriks B:\n";
    cetakMatriks(B);

    // 1. Penjumlahan
    cout << "\n--- HASIL PENJUMLAHAN (A + B) ---\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    cetakMatriks(C);

    // 2. Pengurangan
    cout << "\n--- HASIL PENGURANGAN (A - B) ---\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    cetakMatriks(C);

    // 3. Perkalian Matriks
    cout << "\n--- HASIL PERKALIAN (A * B) ---\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cetakMatriks(C);

    return 0;
}