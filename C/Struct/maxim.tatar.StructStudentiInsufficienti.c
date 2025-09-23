#include <stdio.h>
#include <string.h>

#define NUMERO_STUDENTI 10

typedef struct studente {
    char nome[40];
    char cognome[40];
    unsigned int voto;
} STUDENTE;

int ContaInsufficienti(STUDENTE[], int);

void main() {
    int i;
    int numeroInsufficienti;
    STUDENTE listaStudenti[NUMERO_STUDENTI];

    for (i = 0; i < NUMERO_STUDENTI; i++) {
        strcpy(listaStudenti[i].nome, "nome");
        strcpy(listaStudenti[i].cognome, "cognome");
        listaStudenti[i].voto = i;
    }

    numeroInsufficienti = ContaInsufficienti(listaStudenti, NUMERO_STUDENTI);

    printf(" Il numero di insufficienti e': %d\n", numeroInsufficienti);
}

int ContaInsufficienti(STUDENTE studente[], int numeroStudenti) {
    int i;
    int insufficienti = 0;

    for (i = 0; i < numeroStudenti; i++) {
        if (studente[i].voto < 6) {
            insufficienti++;
        }
    }

    return insufficienti;
}