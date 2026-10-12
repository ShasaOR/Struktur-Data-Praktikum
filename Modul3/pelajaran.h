#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct Pelajaran {
    string namamapel;
    string kodepel;
};

Pelajaran create_pelajaran(string namamapel, string kodepel);
void tampil_pelajaran(Pelajaran pel);

#endif