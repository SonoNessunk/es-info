#include "Cliente.h"

void Cliente::set_nome(string Nome) {
  nome = Nome;
}
void Cliente::set_cognome(string Cognome) {
  cognome = Cognome;
}
void Cliente::set_indirizzo(string Indirizzo) {
  indirizzo = Indirizzo;
}

string Cliente::get_nome() {
  return nome;
}
string Cliente::get_cognome() {
  return cognome;
}
string Cliente::get_indirizzo() {
  return indirizzo;
}