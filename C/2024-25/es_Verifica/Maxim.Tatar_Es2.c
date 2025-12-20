#include <stdio.h>

void prodVettore(int[], int);

int main() {

    int vettore[10];
    int i;
    for (i = 0; i < 10; i++) {
        printf(" Inserisci un numero intero: ");
        scanf("%d", &vettore[i]);
    }

    prodVettore(vettore, 10);

    printf("\n\n");
    system("pause");
    return 0;
}

void prodVettore(int vettore[], int dim) {
    int prodotto = 1;
    int i;
    for (i = 0; i < dim; i++) {
        prodotto *= vettore[i];
    }
    printf("\n Il prodotto vale: %d\n", prodotto);
}