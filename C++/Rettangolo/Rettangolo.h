#ifndef RETTANGOLO_H
#define RETTANGOLO_H

class Rettangolo {
  public:
    float base;
    float altezza;

    float perimetro(float base, float altezza);
    float area(float base, float altezza);
    float diagonale(float base, float altezza);

    Rettangolo();
    ~Rettangolo();
};

#endif
