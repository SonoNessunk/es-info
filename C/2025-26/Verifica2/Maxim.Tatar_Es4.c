// Maxim Tatar 3G 08/05/2025
// Es. 4

#include <stdio.h>
#include <time.h>

// Dimensione massima della matrice
#define MAX 8

// Prototipi delle funzioni
void inizializza(int[MAX][MAX], int);
void stampa(int[MAX][MAX], int);
void controllo(int[MAX][MAX], int);

int main() {

    int matrice[MAX][MAX];

    // Chiamate alle rispettive funzioni
    inizializza(matrice, MAX);
    stampa(matrice, MAX);
    controllo(matrice, MAX);

    printf("\n\n");
    system("pause");
    return 0;
}

// Funzione che inizialliza la matrice quadrata a valori casuali varianti tra 1 e 7
void inizializza(int v[MAX][MAX], int dim) {

    int i;
    int j;

    // Creazione del seme in base all'orario dell'esecuzione del programma
    srand(time(NULL));

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {

            // Imposta un valore casuale tra 0 e 6 e somma +1 diventando numeri casuali da 1 a 7
            v[i][j] = rand() % 7 + 1;
        }
    }
}

// Funzione che stampa la matrice
void stampa(int v[MAX][MAX], int dim) {

    int i;
    int j;

    // Stampa ogni elemento della matrice e ogni volta che finisce di stampare tutte le colonne di una riga stampa un \n
    // e ricomincia con la prossima riga
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf(" [%d]", v[i][j]);
        }
        printf("\n");
    }
}

// Funzione che controlla quanti 4 ci sono nella matrice
void controllo(int v[MAX][MAX], int dim) {

    int conta = 0;
    int i;
    int j;

    // Conta quanti elementi sono pari a 4
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            if (v[i][j] == 4) {
                conta++;
            }
        }
    }

    // Stampa il numero di elementi pari a 4
    printf("\n Ci sono %d [4]", conta);
}