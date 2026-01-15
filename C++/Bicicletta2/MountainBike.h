#include "Bicicletta.h"

#include <iostream>

using namespace std;

class MountainBike : public Bicicletta {
  private:
    int numero_amortizzatori;
    string tipo_amortizzatori;

  public:
    void set_numero_amortizzatori(int n);
    void set_tipo_amortizzatori(string s);

    int get_numero_amortizzatori();
    string get_tipo_amortizzatori();

    // void accelera(int inc, int attrito);
    void mostra_stato();

    MountainBike();
    ~MountainBike();
};