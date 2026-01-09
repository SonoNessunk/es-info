#include <iostream>
#include <math.h>

#include "Rettangolo.h"

using namespace std;

float Rettangolo::perimetro(float base, float altezza) {
    return 2 * (base + altezza);
}

float Rettangolo::area(float base, float altezza) {
    return base * altezza;
}

float Rettangolo::diagonale(float base, float altezza) {
    return sqrt(pow(base, 2) + pow(altezza, 2));
}

Rettangolo::Rettangolo() {
    base = 3;
    altezza = 4;

    cout << endl << " Oggetto rettangolo e' stato creato" << endl << endl;
    return;
}

Rettangolo::~Rettangolo() {
    cout << endl << " Oggetto rettangolo e' stato distrutto" << endl << endl;
    return;
}
