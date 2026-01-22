#include "Televisore.h"
#include <iostream>

int main(int argc, char **argv) {
    Televisore tv = Televisore();
    int scelta;
    int canale;

    do {
        system("cls");
        cout << " +--------- Telecomando TV ---------+" << endl;
        cout << " |  1  TV on/off                    |" << endl;
        cout << " |  2  Imposta canale               |" << endl;
        cout << " |  3  Canale SU                    |" << endl;
        cout << " |  4  Canale GIU                   |" << endl;
        cout << " |  5  Volume SU                    |" << endl;
        cout << " |  6  Volume GIU                   |" << endl;
        cout << " |  7  Mute on/off                  |" << endl;
        cout << " |  8  Stampa Tv                    |" << endl;
        cout << " |  0  Exit                         |" << endl;
        cout << " +----------------------------------+" << endl;

        cout << " Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: {
                tv.PulsanteAccensione();
                break;
            }
            case 2: {
                cout << " Canale da impostare: ";
                cin >> canale;
                tv.ImpostaCanale(canale);
                break;
            }
            case 3: {
                tv.CanaleSuccessivo();
                break;
            }
            case 4: {
                tv.CanalePrecedente();
                break;
            }
            case 5: {
                tv.AumentaVolume();
                break;
            }
            case 6: {
                tv.AbbassaVolume();
                break;
            }
            case 7: {
                tv.PulsanteSilenzioso();
                break;
            }
            case 8: {
                tv.PrintTv();
                break;
            }
            case 0: {
                cout << " Uscita in corso..." << endl;
                break;
            }
            default: {
                cout << " Scelta non valida!" << endl;
                break;
            }
        }

        cout << endl << endl;
        system("pause");

    } while (scelta != 0);

    return 0;
}
