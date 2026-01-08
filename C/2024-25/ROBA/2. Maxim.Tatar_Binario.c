#include <stdio.h>

void stampa(int v[], int n);
void ricerca(int v[], int n, int x);

int main() {

    int v[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int n;

    stampa(v, 15);

    printf("\n Scegliere un numero da cercare: ");
    scanf("%d", &n);

    ricerca(v, 15, n);

    printf("\n\n");
    system("pause");
    return 0;
}

void stampa(int v[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
}

void ricerca(int v[], int max, int x) {
    int i;
    int trovato = 0;
    int inizio = 0;
    int medio;
    int fine = max - 1;

    do {
        medio = (inizio + fine) / 2;

        if (v[inizio] == x || v[medio] == x || v[fine] == x) {
            trovato = 1;
        } else {

            if (v[medio] <= x) {
                inizio = medio + 1;
            } else {
                fine = medio - 1;
            }
        }

    } while (trovato == 0 && inizio < fine);

    if (trovato == 1) {
        printf("\n Elemento %d trovato", x);
    } else {
        printf("\n Elemento %d non trovato", x);
    }
}