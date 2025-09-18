#include <stdio.h>

#define RIG 10
#define COL 10

void inizilizza(int[RIG][COL]);
void stampa(int[RIG][COL]);

int main() {

    int matrice[RIG][COL];

    printf("\n Matrice di Pitagora\n");

    printf("\n Dimensione Matrice %d x %d\n\n", RIG, COL);

    inizilizza(matrice);

    stampa(matrice);
}

void inizilizza(int p[RIG][COL]) {
    int i, j;
    for (i = 0; i < RIG; i++) {
        for (j = 0; j < COL; j++) {
            p[i][j] = (i + 1) * (j + 1);
        }
    }
}

void stampa(int p[RIG][COL]) {
    int i, j;
    for (i = 0; i < RIG; i++) {
        for (j = 0; j < COL; j++) {
            printf(" [%3d]", p[i][j]);
        }
        printf("\n");
    }
}