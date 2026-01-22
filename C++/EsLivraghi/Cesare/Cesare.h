#ifndef CESARE_H
#define CESARE_H
#include <iostream>

using namespace std;

class Cesare {
  private:
    string testo;
    string testoCriptato;
    int k;

  public:
    void setTesto(string Testo);
    void setChiave(int K);

    string getTesto();
    int getChiave();
    string getTestoCriptato();

    void Conversione();
    Cesare();
    ~Cesare();
};

#endif
