#include "pelajaran.h"
#include <iostream>

Pelajaran create_pelajaran(string namamapel, string kodepel) {
    Pelajaran pel;
    pel.namamapel = namamapel;
    pel.kodepel = kodepel;
    return pel;
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "nama pelajaran: " << pel.namamapel << endl;
    cout << "nilai: " << pel.kodepel << endl;
}