#include "Cesare.h"
#include <String>

int main(int argc, char **argv) {
    Cesare cesare = Cesare();
    string testo;
    int chiave;

    cout << " Cifrario di Cesare" << endl << endl;

    cout << " Testo da Crittografare: ";
    getline(cin, testo);

    cout << " Chiave per Crittografare: ";
    cin >> chiave;

    cesare.setTesto(testo);
    cesare.setChiave(chiave);
    cesare.Conversione();

    cout << endl << endl;

    cout << " Testo Originale: " << cesare.getTesto() << endl;
    cout << " Chiave: " << cesare.getChiave() << endl;
    cout << " Testo Criptato: " << cesare.getTestoCriptato() << endl;

    return 0;
}
