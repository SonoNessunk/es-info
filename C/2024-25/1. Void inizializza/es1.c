#include <stdio.h>

void inizializza(int[], int);

int main() {

    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;

    inizializza(v, 10);

    for (i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}

void inizializza(int vettore[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        vettore[i] = 0;
    }
}