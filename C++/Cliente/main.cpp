#include "Cliente.h"
#include <iostream>
#include <string>

using namespace std;
int main(int argc, char **argv) {

  Cliente cliente;

  Cliente c1 = Cliente();

  string nome;
  string cognome;
  string indirizzo;

  cout << endl << " Dati da inserire Cliente cliente (STATICO)" << endl;
  cout << " Nome: ";
  getline(cin, nome);
  cliente.set_nome(nome);

  cout << " Cognome: ";
  getline(cin, cognome);
  cliente.set_cognome(cognome);

  cout << " Indirizzo: ";
  getline(cin, indirizzo);
  cliente.set_indirizzo(indirizzo);

  cout << endl << " Dati da inseriti Cliente cliente (STATICO)" << endl;

  cout << " Il Nome del cliente inserito e': " << cliente.get_nome() << endl;
  cout << " Il Cognome del cliente inserito e': " << cliente.get_cognome() << endl;
  cout << " L'indirizzo del cliente inserito e': " << cliente.get_indirizzo() << endl;

  return 0;
}
