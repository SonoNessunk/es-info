#include <iostream>

#include "Elettrodomestico.h"
#include "ElettrodomesticoSmart.h"

using namespace std;

int main(int argc, char **argv) {

    float potenza;
    float oreUtilizzo;

    cout << " Inserire la potenza (Watt): ";
    cin >> potenza;

    cout << " Inserire le ore di utilizzo: ";
    cin >> oreUtilizzo;

    if (potenza > 2000) {
        ElettrodomesticoSmart elettrodomesticoSmart = ElettrodomesticoSmart(potenza, oreUtilizzo);
        cout << endl << " [Smart] Calcola consumo: " << elettrodomesticoSmart.calcolaConsumo() << endl;
    } else {
        Elettrodomestico *elettrodomestico = new Elettrodomestico(potenza, oreUtilizzo);
        cout << endl << " [Standard] Calcola consumo: " << elettrodomestico->calcolaConsumo() << endl;
        cout << " (Chiamata manuale delete)" << endl;
        delete (elettrodomestico);
    }

    return 0;
}
