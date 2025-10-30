#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMERO_STUDENTI 2

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
void salvaSuFile(STUDENTE[], int);
int caricaDaFile(STUDENTE[], int);

void main() {

    STUDENTE listaStudenti[NUMERO_STUDENTI];
    int scelta;

    printf("\n Gestione Studenti \n\n");

    do {

        system("cls");
        printf("1. Inserisci Studenti\n");
        printf("2. Cerca Studente per Matricola\n");
        printf("0. Uscita\n");

        printf("\n\n Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                printf("\n Inserimento Studenti\n");
                popola(listaStudenti, NUMERO_STUDENTI);
                break;
            }
            case 2: {
                printf("\n Ricerca Studenti per Matricola\n");
                cercaStudente(listaStudenti, NUMERO_STUDENTI);
                break;
            }
            case 0: {
                printf("\n Uscita in corso...");
                break;
            }
            default: {
                printf("\n Scelta non valida");
                break;
            }
        }

        printf("\n\n");
        system("pause");

    } while (scelta != 0);
}

STUDENTE leggiStudente() {
    STUDENTE studente;

    printf(" Inserisci Matricola: ");
    scanf(" %[^\n]", studente.matricola);

    printf(" Inserisci Cognome: ");
    scanf(" %[^\n]", studente.cognome);

    printf(" Inserisci Nome: ");
    scanf(" %[^\n]", studente.nome);

    printf(" Inserisci Classe: ");
    scanf(" %[^\n]", studente.classe);

    printf(" Inserisci Specializzazione: ");
    scanf(" %[^\n]", studente.specializzazione);

    return studente;
}

void popola(STUDENTE studenti[], int numeroStudenti) {
    int i;

    for (i = 0; i < numeroStudenti; i++) {
        printf("\n Studente N %d\n", i + 1);
        studenti[i] = leggiStudente();
    }

    salvaSuFile(studenti, numeroStudenti);
}

void cercaStudente(STUDENTE studenti[], int numeroStudenti) {
    char matricola[41];
    int i;
    int trovato = 0;

    printf("\n Inserisci Matricola: ");
    scanf(" %[^\n]", matricola);

    for (i = 0; i < numeroStudenti; i++) {
        if (strcmp(matricola, studenti[i].matricola) == 0) {
            printf("\n Studente Trovato\n\n");
            printf("\n Cognome: %s", studenti[i].cognome);
            printf("\n Nome: %s", studenti[i].nome);
            printf("\n Classe: %s", studenti[i].classe);
            printf("\n Specializzazione: %s\n", studenti[i].specializzazione);
            trovato = 1;
            break;
        }
    }

    if (!trovato) {
        printf("\n Nessun studente trovato con questa matricola.\n");
    }
}

void stampa(STUDENTE studenti[], int numeroStudenti) {
    int i;

    for (i = 0; i < numeroStudenti; i++) {
        printf("\n Studente N %d", i + 1);
        printf("\n Matricola: %s", studenti[i].matricola);
        printf("\n Cognome: %s", studenti[i].cognome);
        printf("\n Nome: %s", studenti[i].nome);
        printf("\n Classe: %s", studenti[i].classe);
        printf("\n Specializzazione: %s\n", studenti[i].specializzazione);
    }
}

void salvaSuFile(STUDENTE studenti[], int numeroStudenti) {

    FILE *fp;
    int i;
    fp = fopen("Studenti.txt", "w");

    if (!fp) {
        printf("\n Impossibile aprire il file in scrittura.\n");
        return;
    }

    for (i = 0; i < numeroStudenti; i++) {
        fprintf(fp, "%s %s %s %s %s\n",
                studenti[i].matricola,
                studenti[i].cognome,
                studenti[i].nome,
                studenti[i].classe,
                studenti[i].specializzazione);
    }

    fclose(fp);
    printf("\nDati salvati con successo in Studenti.txt\n");
}