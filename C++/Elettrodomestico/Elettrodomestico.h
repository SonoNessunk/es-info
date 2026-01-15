#ifndef ELETTRODOMESTICO_H
#define ELETTRODOMESTICO_H

class Elettrodomestico {
protected:
  float potenza;
  float oreUtilizzo;

public:
  void set_potenza(float Potenza);
  void set_oreUtilizzo(float OreUtilizzo);

  float get_potenza();
  float get_oreUtilizzo();

  float calcolaConsumo();

  Elettrodomestico(float Potenza, float OreUtilizzo);
  ~Elettrodomestico();
};

#endif
