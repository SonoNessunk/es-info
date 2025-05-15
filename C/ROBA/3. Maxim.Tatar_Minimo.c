#include <stdio.h>
#include <time.h>

void inizializza(int v[], int n);
void stampa(int v[], int n);
void ricerca(int v[], int n);

int main() {

    int v[10];

    inizializza(v, 10);
    stampa(v, 10);

    ricerca(v, 10);

    printf("\n\n");
    system("pause");
    return 0;
}

void inizializza(int v[], int n) {
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }
}

void stampa(int v[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
}

void ricerca(int v[], int n) {

    int i;
    int min = v[0];
    int pos = 0;

    for (i = 1; i < n; i++) {
        if (v[i] < min) {
            min = v[i];
            pos = i;
        }
    }

    printf("\n\n Il minimo e' %d", min);
    printf("\n Il minimo si trova alla posizione %d", pos);
}