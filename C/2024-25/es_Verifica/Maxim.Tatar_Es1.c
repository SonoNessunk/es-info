#include <stdio.h>

#define MAX 100

void sommaVett(int[], int);

int main() {
    int vettore[MAX];
    int i = 0;
    int numero = 0;
    printf("\n Inserisci un numero intero positivo (Negativo per terminare) \n\n");
    do {
        printf(" Numero: ");
        scanf("%d", &numero);
        if (numero > 0) {
            vettore[i] = numero;
            i++;
        }

    } while (numero >= 0 && i < MAX);

    sommaVett(vettore, i);

    printf("\n\n");
    system("pause");
    return 0;
}

void sommaVett(int vettore[], int dim) {
    int somma = 0;
    int i;
    for (i = 0; i < dim; i++) {
        somma += vettore[i];
    }
    printf("\n La somma Vale: %d", somma);
}