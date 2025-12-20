#include <stdio.h>

void sommaVett(float[], int);
void mediaVett(float[], int);

int main() {

    float vettore[8];
    int i;
    for (i = 0; i < 8; i++) {
        printf(" Inserisci un numero: ");
        scanf("%f", &vettore[i]);
    }

    sommaVett(vettore, 8);
    mediaVett(vettore, 8);

    printf("\n\n");
    system("pause");
    return 0;
}

void sommaVett(float vettore[], int dim) {
    float somma = 0;
    int i;
    for (i = 0; i < dim; i++) {
        somma += vettore[i];
    }
    printf("\n La somma vale: %.2f", somma);
}

void mediaVett(float vettore[], int dim) {
    float somma = 0;
    int i;
    for (i = 0; i < dim; i++) {
        somma += vettore[i];
    }
    printf("\n La media vale: %.2f", somma / dim);
}