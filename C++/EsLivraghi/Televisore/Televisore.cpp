#include "Televisore.h"

void Televisore::PulsanteAccensione() {
    acceso = !acceso;
    if (acceso) {
        cout << " TV accesa" << endl;
    } else {
        cout << " TV spenta" << endl;
    }
}
void Televisore::ImpostaCanale(int Canale) {
    if (acceso && canale >= 0 && canale <= 99) {
        canale = Canale;
        cout << " Canale impostato: " << canale << endl;
    }
}
void Televisore::CanaleSuccessivo() {
    if (acceso && canale < 99) {
        canale++;
        cout << " Canale: " << canale << endl;
    }
}
void Televisore::CanalePrecedente() {
    if (acceso && canale > 0) {
        canale--;
        cout << " Canale: " << canale << endl;
    }
}
void Televisore::AumentaVolume() {
    if (acceso && volume < 10) {
        volume++;
        cout << " Volume: " << volume << endl;
    }
}

void Televisore::AbbassaVolume() {
    if (acceso && volume > 0) {
        volume--;
        cout << " Volume: " << volume << endl;
    }
}
void Televisore::PulsanteSilenzioso() {
    if (acceso) {
        silenzioso = !silenzioso;
    }

    if (silenzioso) {
        cout << " Volume Mutato" << endl;
    } else {
        cout << " Volume Smutato" << endl;
    }
}
void Televisore::PrintTv() {
    cout << endl;

    if (acceso) {
        cout << " TV ACCESA" << endl;
        cout << " Canale: " << canale << endl;
        cout << " Volume: ";
        if (silenzioso)
            cout << volume << " MUTE" << endl;
        else
            cout << volume << endl;
    } else {
        cout << " TV SPENTA" << endl;
    }
}

Televisore::Televisore() {
    acceso = false;
    volume = 5;
    canale = 0;
    silenzioso = false;
}

Televisore::~Televisore() {
}
