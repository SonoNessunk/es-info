#include <stdio.h>

void visualizza(int[], int);

int main() {
    int v[10] = {21, 2, 33, 4, 5, 46, 7, 85, 89};
    int i;

    visualizza(v, 10);

    return 0;
}

void visualizza(int vettore[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", vettore[i]);
    }
}