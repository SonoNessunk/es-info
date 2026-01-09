#include <iostream>

#include "Rettangolo.h"

using namespace std;

int main(int argc, char **argv) {

    Rettangolo rettangolo;

    cout << " Parametri Rettangolo" << endl;
    cout << "   Base: " << rettangolo.base << endl;
    cout << "   Altezza: " << rettangolo.altezza << endl;

    cout << endl << " Calcoli" << endl;
    cout << "   Perimetro: " << rettangolo.perimetro(rettangolo.base, rettangolo.altezza) << endl;
    cout << "   Area: " << rettangolo.area(rettangolo.base, rettangolo.altezza) << endl;
    cout << "   Diagonale: " << rettangolo.diagonale(rettangolo.base, rettangolo.altezza) << endl;

    return 0;
}
