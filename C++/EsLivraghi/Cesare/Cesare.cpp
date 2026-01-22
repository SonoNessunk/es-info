#include "Cesare.h"

#include <string>

using namespace std;

void Cesare::setTesto(string Testo) {
    testo = Testo;
}
void Cesare::setChiave(int K) {
    k = K;
}

string Cesare::getTesto() {
    return testo;
}
int Cesare::getChiave() {
    return k;
}
string Cesare::getTestoCriptato() {
    return testoCriptato;
}

void Cesare::Conversione() {
    testoCriptato = "";
    int shift = k % 26;
    if (shift < 0) {
        shift += 26;
    }
    for (int i = 0; i < testo.length(); i++) {
        char c = testo[i];
        if (c == 32) {
            testoCriptato += 32;
        }
        if (c >= 'a' && c <= 'z') {
            char cifrato = 'a' + (c - 'a' + shift) % 26;
            testoCriptato += cifrato;
        }
        if (c >= 'A' && c <= 'Z') {
            char cifrato = 'A' + (c - 'A' + shift) % 26;
            testoCriptato += cifrato;
        }
    }
}

Cesare::Cesare() {
}

Cesare::~Cesare() {
}
