#ifndef ELETTRODOMESTICOSMART_H
#define ELETTRODOMESTICOSMART_H

#include "Elettrodomestico.h"

class ElettrodomesticoSmart : public Elettrodomestico {
  private:
    float risparmio;

  public:
    float calcolaConsumo();
    void calcolaConsumo(float *risultato);

    ElettrodomesticoSmart(float Potenza, float OreUtilizzo, float Risparmio = 0.8);
    ElettrodomesticoSmart();
    ~ElettrodomesticoSmart();

  protected:
};

#endif