// Maxim Tatar 3G 08/05/2025
// Es. 3

#include <stdio.h>

// Dimensione massima del vettore
#define MAX 10

// prototipi delle funzioni
void controllo(int[], int);

int main() {

    // Dichiarazione delle variabili locali
    int vettore[MAX];
    int i;

    printf("\n Inserire %d valori \n\n", MAX);

    // Inserimento dei valori nel vettore
    for (i = 0; i < MAX; i++) {
        printf(" [%d] Valore: ", i + 1);
        scanf("%d", &vettore[i]);
    }

    // Chimata alla funzione
    controllo(vettore, MAX);

    printf("\n\n");
    system("pause");
    return 0;
}

// Funzione che controlla se in posizione I è un multiplo di 5 e stampa l'elemento successivo (I + 1)
void controllo(int v[], int dim) {

    int i;

    for (i = 0; i < dim - 1; i++) {

        // controlla se l'elemento del vettore in posizione I è un multiplo di 5
        if (v[i] % 5 == 0) {
            printf(" [%d]", v[i + 1]);
        }
    }
}