#include "Bicicletta.h"
#include <iostream>

using namespace std;

void Bicicletta::set_cadenza(int Cadenza) {
    cadenza = Cadenza;
}

void Bicicletta::set_marcia(int Marcia) {
    cadenza = Marcia;
}

void Bicicletta::set_velocita(int Velocita) {
    cadenza = Velocita;
}

int Bicicletta::get_cadenza() {
    return cadenza;
}

int Bicicletta::get_marcia() {
    return marcia;
}

int Bicicletta::get_velocita() {
    return velocita;
}

void Bicicletta::accelera(int incremento) {
    velocita += incremento;
}

void Bicicletta::frena(int decremento) {
    velocita -= decremento;
}

void Bicicletta::mostra_stato() {

    cout << endl << " -----------------------------" << endl;
    cout << " Stato Bici" << endl;
    cout << " -----------------------------" << endl;
    cout << "  Cadenza:    " << cadenza << endl;
    cout << "  Marcia:     " << marcia << endl;
    cout << "  Velocita:   " << velocita << endl;
    cout << " -----------------------------" << endl;
}

Bicicletta::Bicicletta() {
    cout << " ~~~ L'oggetto Bicicletta e' stato creato ~~~" << endl;

    cadenza = 0;
    marcia = 0;
    velocita = 0;
}

Bicicletta::Bicicletta(int Cadenza, int Marcia, int Velocita) {
    cadenza = Cadenza;
    marcia = Marcia;
    velocita = Velocita;

    cout << endl << " ~~~ L'oggetto Bicicletta e' stato creato ~~~" << endl;
}

Bicicletta::~Bicicletta() {
    cout << endl << " ~~~ L'oggetto Bicicletta e' stato distrutto ~~~" << endl;
}
