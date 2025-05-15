// Maxim Tatar 3G 08/05/2025
// Es. 2

#include <stdio.h>

// Dimensione massima del vettore
#define MAX 10

// prototipi delle funzioni
void minimoElemento(int[], int);
void stampa(int[], int);

int main() {

    // Dichiarazione delle variabili locali
    int vettore[MAX];
    int i;

    printf("\n Inserisci %d valori interi\n\n", MAX);

    // Richiesta dei valori all'utente
    for (i = 0; i < MAX; i++) {
        printf(" [%d] Valore: ", i + 1);
        scanf("%d", &vettore[i]);
    }

    // pulizia del Terminale
    system("cls");

    printf("\n Elementi Inseriti: \n");

    // Chiamate alle rispettive funzioni
    stampa(vettore, MAX);
    minimoElemento(vettore, MAX);

    printf("\n\n");
    system("pause");
    return 0;
}

// Funzione stampa del vettore a N dimensione
void stampa(int v[], int dim) {
    int i;

    // ciclo che scorre per tutto il vettore e stampa i valori
    for (i = 0; i < dim; i++) {
        printf(" [%d]", v[i]);
    }
}

// Funzione ricerca del valore minimo di un Vettore a dimensione N
void minimoElemento(int v[], int dim) {

    // Dichiarazione delle variabili
    int minimo = v[0]; // Imposta il valore minimo come il primo primo valore del vettore
    int i;

    for (i = 0; i < dim; i++) {

        // Controllo se il valore nella posizione I del vettore è piu piccolo del minimo
        if (v[i] < minimo) {
            minimo = v[i];
        }
    }

    // stampa del valore minimo
    printf("\n\n Il minimo vale: %d", minimo);
}