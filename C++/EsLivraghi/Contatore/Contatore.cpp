#include "Contatore.h"

void Contatore::set_valore(int Valore) {
    valore = Valore;
}

int Contatore::get_valore() {
    return valore;
}

void Contatore::plus() {
    valore++;
}

void Contatore::minus() {
    valore--;
}

Contatore::Contatore() {
    valore = 0;
}

Contatore::~Contatore() {
}
