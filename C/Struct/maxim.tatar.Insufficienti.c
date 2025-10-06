#include <stdio.h>
#include <string.h>

#define NUMERO_STUDENTI 10

typedef struct studente {
    char nome[40];
    char cognome[40];
    unsigned int voto;
} STUDENTE;

STUDENTE leggiStudente();
void popola(STUDENTE[], int);
int contaInsufficienti(STUDENTE[], int);
void stampa(STUDENTE[], int);

void main() {
    STUDENTE listaStudenti[NUMERO_STUDENTI];

    printf("\n Conta Studenti Insufficienti \n\n");

    popola(listaStudenti, NUMERO_STUDENTI);

    stampa(listaStudenti, NUMERO_STUDENTI);

    printf("\n Il numero di insufficienti e': %d\n", contaInsufficienti(listaStudenti, NUMERO_STUDENTI));
}

STUDENTE leggiStudente() {
    STUDENTE studente;

    printf(" Inserisci Nome: ");
    gets(studente.nome);

    printf(" Inserisci Cognome: ");
    gets(studente.cognome);

    printf(" Inserisci Voto: ");
    scanf("%d", &studente.voto);

    fflush(stdin);

    return studente;
}

void popola(STUDENTE studenti[], int numeroStudenti) {
    int i;

    for (i = 0; i < numeroStudenti; i++) {
        printf("\n Studente N %d\n", i + 1);
        studenti[i] = leggiStudente();
    }
}

int contaInsufficienti(STUDENTE studente[], int numeroStudenti) {
    int i;
    int insufficienti = 0;

    for (i = 0; i < numeroStudenti; i++) {
        if (studente[i].voto < 6) {
            insufficienti++;
        }
    }

    return insufficienti;
}

void stampa(STUDENTE studenti[], int numeroStudenti) {
    int i;

    system("cls");

    for (i = 0; i < numeroStudenti; i++) {
        printf("\n Studente N %d", i + 1);
        printf("\n Nome: %s", studenti[i].nome);
        printf("\n Cognome: %s", studenti[i].cognome);
        printf("\n Voto: %d\n", studenti[i].voto);
    }
}