// Maxim Tatar 3G 08/05/2025
// Es. 1

#include <stdio.h>

// Dimensione massima del vettore
#define MAX 100

// Prototipi delle funzioni
void calcolaResistenza(float[], int);

int main() {

    // Dichiarazione delle variabili locali
    float resistenze[MAX];
    float valore;
    int conta = 0;

    printf("\n Inserisci il valore della resistenza (Minore di 0 si Arresta, con Massimo di %d valori)\n\n", MAX);

    // ripete finche il valore e maggiore di 0 e che il numero di valori non superino il massimo(MAX)
    do {

        printf(" [%d] Valore: ", conta + 1);
        scanf("%f", &valore);

        // controlla se il valore inserito e maggiore di 0
        if (valore > 0) {
            resistenze[conta] = valore;
            conta++;
        }

    } while (valore > 0 && conta < MAX);

    // chiamata alla funzione
    calcolaResistenza(resistenze, conta);

    printf("\n\n");
    system("pause");
    return 0;
}

void calcolaResistenza(float v[], int dim) {

    float resEq = 0;
    int i;

    // somma a resEq tutte le 1/Rn
    for (i = 0; i < dim; i++) {
        resEq += 1 / v[i];
    }

    // flippa 1/resEq --> resEq
    resEq = 1 / resEq;

    // stampa di resEq
    printf(" La resistenza Eq vale: %.2f", resEq);
}