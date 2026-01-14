#ifndef BICICLETTA_H
#define BICICLETTA_H

class Bicicletta {
  private:
    int cadenza;
    int marcia;
    int velocita;

  public:
    void set_cadenza(int cadenza);
    void set_marcia(int marcia);
    void set_velocita(int velocita);

    int get_cadenza();
    int get_marcia();
    int get_velocita();

    void accelera(int incremento);
    void frena(int decremento);

    void mostra_stato();

    Bicicletta();
    Bicicletta(int cadenza, int marcia, int velocita);

    ~Bicicletta();
};

#endif
