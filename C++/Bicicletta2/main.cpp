#include <iostream>

#include "Bicicletta.h"
#include "MountainBike.h"

using namespace std;

int main(int argc, char **argv) {

    MountainBike bici1;
    // Bicicletta bici2 = Bicicletta(40, 1, 20);

    cout << endl << " -----------------------------" << endl;
    cout << "      BICI 1 (Costruttore senza param)" << endl;
    cout << " -----------------------------" << endl;
    cout << "    Cadenza:    " << bici1.get_cadenza() << endl;
    cout << "    Marcia:     " << bici1.get_marcia() << endl;
    cout << "    Velocita:   " << bici1.get_velocita() << endl;
    cout << " -----------------------------" << endl;

    bici1.set_cadenza(35);
    bici1.set_marcia(2);
    bici1.set_velocita(10);
    bici1.accelera(15);
    bici1.frena(10);

    bici1.mostra_stato();

    // cout << endl << endl << endl;

    // cout << endl << " -----------------------------" << endl;
    // cout << "      BICI 2 (Costruttore con param)" << endl;
    // cout << " -----------------------------" << endl;
    // cout << "    Cadenza:    " << bici1.get_cadenza() << endl;
    // cout << "    Marcia:     " << bici1.get_marcia() << endl;
    // cout << "    Velocita:   " << bici1.get_velocita() << endl;
    // cout << " -----------------------------" << endl;

    // bici2.accelera(15);
    // bici2.frena(10);

    // bici2.mostra_stato();

    return 0;
}
