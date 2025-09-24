#include <stdio.h>
#include <string.h>

#define NUMERO_STUDENTI 5

typedef struct studente {
    char nome[40];
    char cognome[40];
    unsigned int voto;
} STUDENTE;

int ContaInsufficienti(STUDENTE[], int);
STUDENTE LeggiStudente();
void Popola(STUDENTE[], int);
void Stampa(STUDENTE[], int);

void main() {
    STUDENTE listaStudenti[NUMERO_STUDENTI];


    printf("\n Conta Studenti Insufficienti \n\n");

    Popola(listaStudenti, NUMERO_STUDENTI);

    Stampa(listaStudenti, NUMERO_STUDENTI);

    printf(" Il numero di insufficienti e': %d\n", ContaInsufficienti(listaStudenti, NUMERO_STUDENTI));
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

STUDENTE LeggiStudente() {
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

void Popola(STUDENTE studenti[], int numeroStudenti) {
    int i;

    for (i = 0; i < numeroStudenti; i++) {
        studenti[i] = LeggiStudente();
    }
}

void Stampa(STUDENTE studenti[], int numeroStudenti) {
    int i;

    for (i = 0; i < numeroStudenti; i++) {
        printf(" Nome: %s", studenti[i].nome);
        printf(" Cognome: %s", studenti[i].cognome);
        printf(" Voto: %d\n", studenti[i].voto);
    }
}