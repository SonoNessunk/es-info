#include <stdio.h>
#include <time.h>

void inizializza(int v[], int n);
void stampa(int v[], int n);
void ricerca(int v[], int n, int x);

int main() {
    int n;
    int v[15];

    inizializza(v, 15);
    stampa(v, 15);

    printf("\n\n Inserisci il numero da cercare: ");
    scanf("%d", &n);

    ricerca(v, 15, n);

    printf("\n\n");
    return 0;
}

void inizializza(int v[], int n) {
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        v[i] = rand() % 100 + 1;
    }
}

void stampa(int v[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
}

void ricerca(int v[], int n, int x) {
    int i;
    int trovato = 0;
    for (i = 0; i < n; i++) {
        if (v[i] == x) {
            trovato = 1;
            printf("\n Il numero %d e' stato trovato alla posizione %d", x, i);
        }
    }

    if (trovato == 0) {
        printf("\n Il numero %d non e' stato trovato", x);
    }
} 