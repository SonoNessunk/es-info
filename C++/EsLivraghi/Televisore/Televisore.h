#ifndef TELEVISORE_H
#define TELEVISORE_H

#include <iostream>

using namespace std;

class Televisore {

  private:
    bool acceso;
    int volume;
    int canale;
    bool silenzioso;

  public:
    void PulsanteAccensione();
    void ImpostaCanale(int Canale);
    void CanaleSuccessivo();
    void CanalePrecedente();
    void AumentaVolume();
    void AbbassaVolume();
    void PulsanteSilenzioso();
    void PrintTv();

    Televisore();
    ~Televisore();
};

#endif
