#include "ElettrodomesticoSmart.h"
#include <iostream>

using namespace std;

float ElettrodomesticoSmart::calcolaConsumo() {
    return Elettrodomestico::calcolaConsumo() * risparmio;
}

void ElettrodomesticoSmart::calcolaConsumo(float *risultato) {
    *risultato = Elettrodomestico::calcolaConsumo() * risparmio;
}

ElettrodomesticoSmart::ElettrodomesticoSmart(float Potenza, float OreUtilizzo, float Risparmio) {
    potenza = Potenza;
    oreUtilizzo = OreUtilizzo;
    risparmio = Risparmio;

    cout << endl << " + Oggetto CHILD allocato" << endl;
}

ElettrodomesticoSmart::ElettrodomesticoSmart() {
    potenza = 0;
    oreUtilizzo = 0;
    risparmio = 0;

    cout << endl << " + Oggetto CHILD allocato" << endl;
}

ElettrodomesticoSmart::~ElettrodomesticoSmart() {
    cout << endl << " - Oggetto CHILD distrutto" << endl;
}
