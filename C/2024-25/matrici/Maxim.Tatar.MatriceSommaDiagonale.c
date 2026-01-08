#include <stdio.h>

#define RIG 10
#define COL 10

void inizilizza(int[RIG][COL], int, int);
void stampa(int[RIG][COL], int, int);
void sommaDiag(int[RIG][COL], int, int);

int main() {

    int matrice[RIG][COL];

    printf("\n Somma Diagonale Matrice\n\n");

    inizilizza(matrice, RIG, COL);
    stampa(matrice, RIG, COL);
    sommaDiag(matrice, RIG, COL);

    printf("\n\n");
    system("PAUSE");
    return 0;
}

void inizilizza(int p[RIG][COL], int righe, int colonne) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < righe; i++) {
        for (j = 0; j < colonne; j++) {
            p[i][j] = rand() % 100;
        }
    }
}

void stampa(int p[RIG][COL], int righe, int colonne) {
    int i, j;
    for (i = 0; i < righe; i++) {
        for (j = 0; j < colonne; j++) {
            printf(" [%2d]", p[i][j]);
        }
        printf("\n");
    }
}

void sommaDiag(int p[RIG][COL], int righe, int colonne) {

    int i, j;
    int somma = 0;

    for (i = 0; i < righe; i++) {
        for (j = 0; j < colonne; j++) {
            if (i == j) {
                somma += p[i][j];
            }
        }
    }

    printf("\n\n Somma diagonale: %d", somma);
}