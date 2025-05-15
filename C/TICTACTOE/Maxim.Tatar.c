#include <stdio.h>

#define T 3

void stampaGriglia(char[T][T], int, int);
void inserisciMossa(char[T][T], int, char);
char calcolaVincitore(char[T][T]);

int main() {

    char tris[T][T] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char simbolo;
    int mossa;
    char esito = '.';
    int turno = 1;
    int numeroGiocate = 0;

    stampaGriglia(tris, T, T);

    for (numeroGiocate = 0; (numeroGiocate < 9) && (esito == '.'); numeroGiocate++) {
        if (turno == 1) {
            simbolo = 'X';
            printf("\n Dove vuole inserire la mossa? (1-9): ");
            scanf("%d", &mossa);
            inserisciMossa(tris, mossa, simbolo);
            turno = 2;
        } else {
            simbolo = 'O';
            printf("\n Dove vuole inserire la mossa? (1-9): ");
            scanf("%d", &mossa);
            inserisciMossa(tris, mossa, simbolo);
            turno = 2;
        }

        esito = calcolaVincitore(tris);
        if (esito != '.') {
            printf("\nIl giocatore (%c) ha vintoo!!!!\n", esito);
        }
    }

    calcolaVincitore(tris);
}

void stampaGriglia(char matrice[T][T], int n_righe, int m_colonne) {
    int i, j;
    for (i = 0; i < n_righe; i++) {     // righe indice i
        for (j = 0; j < m_colonne; j++) // colonne indice j
            if (j != 0)
                printf(" |%2c", matrice[i][j]);
            else
                printf(" %2c", matrice[i][j]);
        if (i != n_righe - 1)
            printf("\n ---|---|--- \n");
        else
            printf("\n");
    }
}

void inserisciMossa(char matrice[T][T], int mossa, char simbolo) {
    int i, j;
    for (i = 0; i < T; i++) {
        for (j = 0; j < T; j++) {
            if (matrice[i][j] == mossa + '0') {
                matrice[i][j] = simbolo;
            }
        }
    }
}

char calcolaVincitore(char a[T][T]) {
    char trovato = '.';

    if ((a[0][0] == 'O') && (a[0][1] == 'O') && (a[0][2] == 'O'))
        trovato = 'O';
    else if ((a[1][0] == 'O') && (a[1][1] == 'O') && (a[1][2] == 'O'))
        trovato = 'O';
    else if ((a[2][0] == 'O') && (a[2][1] == 'O') && (a[2][2] == 'O'))
        trovato = 'O';
    else if ((a[0][0] == 'X') && (a[0][1] == 'X') && (a[0][2] == 'X'))
        trovato = 'X';
    else if ((a[1][0] == 'X') && (a[1][1] == 'X') && (a[1][2] == 'X'))
        trovato = 'X';
    else if ((a[2][0] == 'X') && (a[2][1] == 'X') && (a[2][2] == 'X'))
        trovato = 'X';
    // controllo le colonne
    else if ((a[0][0] == 'O') && (a[1][0] == 'O') && (a[2][0] == 'O'))
        trovato = 'O';
    else if ((a[0][1] == 'O') && (a[1][1] == 'O') && (a[2][1] == 'O'))
        trovato = 'O';
    else if ((a[0][2] == 'O') && (a[1][2] == 'O') && (a[2][2] == 'O'))
        trovato = 'O';
    else if ((a[0][0] == 'X') && (a[1][0] == 'X') && (a[2][0] == 'X'))
        trovato = 'X';
    else if ((a[0][1] == 'X') && (a[1][1] == 'X') && (a[2][1] == 'X'))
        trovato = 'X';
    else if ((a[0][2] == 'X') && (a[1][2] == 'X') && (a[2][2] == 'X'))
        trovato = 'X';
    // controllo la diagonle principale
    else if ((a[0][0] == 'O') && (a[1][1] == 'O') && (a[2][2] == 'O'))
        trovato = 'O';
    else if ((a[0][0] == 'X') && (a[1][1] == 'X') && (a[2][2] == 'X'))
        trovato = 'X';
    // controllo la diagonale secondaria
    else if ((a[0][2] == 'O') && (a[1][1] == 'O') && (a[2][0] == 'O'))
        trovato = 'O';
    else if ((a[0][2] == 'X') && (a[1][1] == 'X') && (a[2][0] == 'X'))
        trovato = 'X';
    return trovato;
}