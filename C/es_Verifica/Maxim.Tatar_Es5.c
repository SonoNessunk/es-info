#include <stdio.h>

void controlli(int[], int);

int main() {

    int vettore[6];
    int numero;
    int contaMin = 0;
    int contaMax = 0;
    int i;
    for (i = 0; i < 6; i++) {
        printf(" Inserisci un numero intero: ");
        scanf("%d", &vettore[i]);
    }
    printf("\n Inserisci un numero di controllo: ");
    scanf("%d", &numero);

    for (i = 0; i < 6; i++) {
        if (vettore[i] < numero) {
            contaMin++;
        }
        if (vettore[i] > numero) {
            contaMax++;
        }
    }

    printf("\n Il numero di valori minori e': %d", contaMin);
    printf("\n Il numero di valori maggiori e': %d", contaMax);

    printf("\n\n");
    system("pause");
    return 0;
}