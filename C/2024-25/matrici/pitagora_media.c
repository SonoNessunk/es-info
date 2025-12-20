#include <stdio.h>
#include <time.h>

#define RIG 10
#define COL 10

void inizilizza(float[RIG][COL]);
void stampa(float[RIG][COL]);
void media(float[RIG][COL]);

int main() {

    float matrice[RIG][COL];

    printf("\n Media\n");

    printf("\n Dimensione Matrice %d x %d\n\n", RIG, COL);

    inizilizza(matrice);

    stampa(matrice);

    media(matrice);
}

void inizilizza(float p[RIG][COL]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < RIG; i++) {
        for (j = 0; j < COL; j++) {
            p[i][j] = (float)(rand() % 100) / 3.2;
        }
    }
}

void stampa(float p[RIG][COL]) {
    int i, j;
    for (i = 0; i < RIG; i++) {
        for (j = 0; j < COL; j++) {
            printf(" [%5.2f]", p[i][j]);
        }
        printf("\n");
    }
}

void media(float p[RIG][COL]) {
    int i, j;
    float somma = 0;
    for (i = 0; i < RIG; i++) {
        for (j = 0; j < COL; j++) {
            somma += p[i][j];
        }
    }
    printf("\n Media: %.2f\n", somma / (RIG * COL));
}