#ifndef CONTATORE_H
#define CONTATORE_H

class Contatore {
  private:
    int valore;

  public:
    void set_valore(int Valore);
    int get_valore();

    void plus();
    void minus();

    Contatore();
    ~Contatore();

  protected:
};

#endif
