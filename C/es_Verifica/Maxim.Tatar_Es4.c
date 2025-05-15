#include <stdio.h>

void ctrlZero(int[], int);

int main() {

    int vettore[7];
    int i;

    for (i = 0; i < 7; i++) {
        printf(" Inserisci un numero intero: ");
        scanf("%d", &vettore[i]);
    }

    ctrlZero(vettore, 7);

    printf("\n\n");
    system("pause");
    return 0;
}

void ctrlZero(int vettore[], int dim) {
    int i;
    int conta = 0;
    for (i = 0; i < dim; i++) {
        if (vettore[i] == 0) {
            conta++;
        }
    }

    printf("\n Il numero di zeri e': %d\n", conta);
}