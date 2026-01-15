#include "Elettrodomestico.h"

#include <iostream>

using namespace std;

void Elettrodomestico::set_potenza(float Potenza) {
  potenza = Potenza;
}
void Elettrodomestico::set_oreUtilizzo(float OreUtilizzo) {
  oreUtilizzo = OreUtilizzo;
}

float Elettrodomestico::get_potenza() {
  return potenza;
}
float Elettrodomestico::get_oreUtilizzo() {
  return oreUtilizzo;
}

float Elettrodomestico::calcolaConsumo() {
  return potenza * oreUtilizzo;
}

Elettrodomestico::Elettrodomestico(float Potenza, float OreUtilizzo) {

  potenza = Potenza;
  oreUtilizzo = OreUtilizzo;

  cout << " Oggetto PARENT allocato" << endl;
}

Elettrodomestico::~Elettrodomestico() {
  cout << " Oggetto PARENT distrutto" << endl;
}
