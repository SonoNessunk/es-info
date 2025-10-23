#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMERO_STUDENTI 10

typedef struct studente {
    char matricola[41];
    char cognome[41];
    char nome[41];
    char classe[3];
    char specializzazione[41];
} STUDENTE;

STUDENTE leggiStudente();
void popola(STUDENTE[], int);
void cercaStudente(STUDENTE[], int);
void stampa(STUDENTE[], int);
void salvaSuFile();

void main() {

    FILE *fp;
    STUDENTE listaStudenti[NUMERO_STUDENTI];
    int scelta;

    printf("\n Studenti \n\n");

    do {

        system("cls");
        printf("1. Inserisci Studenti\n");
        printf("2. Stampa Studenti");
        printf("3. Cerca Studente\n");
        printf("0. Uscita\n");

        printf("\n\n Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                printf("\n Inserimento Studentu");
                popola();
                break;
            }
            case 2: {
                break;
            }
            case 2: {
                break;
            }
            case 0: {
                printf("\n Uscita in corso...");
            }
            default: {
                printf("\n Scelta non valida");
                break;
            }
        }

        printf("\n\n");
        system("pause");

    } while (scelta != 0);

    popola(listaStudenti, NUMERO_STUDENTI);

    stampa(listaStudenti, NUMERO_STUDENTI);

    // printf("\n Il numero di insufficienti e': %d\n", cercaStudente(listaStudenti, NUMERO_STUDENTI));
}

STUDENTE leggiStudente() {
    STUDENTE studente;

    printf(" Inserisci Matricola: ");
    scanf(" %[^\n]", studente.matricola);

    printf(" Inserisci Cognome: ");
    scanf(" %[^\n]", studente.cognome);

    printf(" Inserisci Classe: ");
    scanf(" %[^\n]", studente.classe);

    printf(" Inserisci Speci: ");
    scanf("%d", &studente.specializzazione);

    return studente;
}

void popola(STUDENTE studenti[], int numeroStudenti) {
    int i;

    for (i = 0; i < numeroStudenti; i++) {
        printf("\n Studente N %d\n", i + 1);
        studenti[i] = leggiStudente();
    }
}

void cercaStudente(STUDENTE studenti[], int numeroStudenti) {
    char matricola[41];
    int i;
    printf("\n Inserisci Matricola: ");
    scanf(" %[^\n]", matricola);

    for (i = 0; i < numeroStudenti; i++) {
        if (strcmp(matricola, studenti[i].matricola) == 0) {
            printf("\n Cognome: %s", studenti[i].cognome);
            printf("\n Nome: %s", studenti[i].nome);
            printf("\n Classe: %s", studenti[i].classe);
            printf("\n Specializzazione: %s\n", studenti[i].specializzazione);
        }
    }
}

void stampa(STUDENTE studenti[], int numeroStudenti) {
    int i;

    system("cls");

    for (i = 0; i < numeroStudenti; i++) {
        printf("\n Studente N %d", i + 1);
        printf("\n Matricola: %s", studenti[i].matricola);
        printf("\n Cognome: %s", studenti[i].cognome);
        printf("\n Nome: %s", studenti[i].nome);
        printf("\n Classe: %s", studenti[i].classe);
        printf("\n Specializzazione: %s\n", studenti[i].specializzazione);
    }
}