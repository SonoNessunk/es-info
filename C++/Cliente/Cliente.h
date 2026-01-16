#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>

using namespace std;

class Cliente {
private:
  string nome;
  string cognome;
  string indirizzo;

public:
  void set_nome(string Nome);
  void set_cognome(string Cognome);
  void set_indirizzo(string Indirizzo);

  string get_nome();
  string get_cognome();
  string get_indirizzo();
};

#endif
