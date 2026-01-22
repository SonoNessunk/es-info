#include "Contatore.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    Contatore contatore = Contatore();
    int valore;
    int numero;

    cout << " Contatore" << endl;

    cout << " Valore del contatore: ";
    cin >> valore;

    contatore.set_valore(valore);

    cout << " Numero di incremento o decremento (POS incremento e NEG decremento): ";
    cin >> numero;

    if (numero > 0) {
        for (int i = 0; i < numero; i++) {
            contatore.plus();
        }
    } else if (numero < 0) {
        for (int i = numero; i < 0; i++) {
            contatore.minus();
        }
    }

    cout << " Valore contatore: " << contatore.get_valore() << endl;

    return 0;
}
