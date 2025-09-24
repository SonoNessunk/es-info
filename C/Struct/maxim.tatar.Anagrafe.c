#include <stdio.h>
#include <stdlib.h>

#define MAX_PERSONE 100

typedef enum { maschio = 1, femmina } GENERE;

typedef struct {
    int giorno;
    int mese;
    int anno;
} DATA;

typedef struct {
    char nome[41];
    char cognome[41];
    char codiceFiscale[17];
    GENERE sesso;
    DATA dataNascita;
} PERSONA;

void inserimento(PERSONA[], int);
void lettura(PERSONA[]);
void modifica(PERSONA[], PERSONA);
void eliminazione(PERSONA[], PERSONA);

void salvaSuFile(PERSONA[], int);
int caricaDaFile(PERSONA[]);
void stampaPersone(PERSONA[], int);

void main() {
    int scelta;
    PERSONA popolazione[MAX_PERSONE];
    int enesimo;

    do {

        system("cls");

        printf("\n 1. Inserimento");
        printf("\n 2. Lettura");
        printf("\n 3. Modifica");
        printf("\n 4. Eleminazione");
        printf("\n 0. Uscita");

        printf("\n\n Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                printf("\n inserimento");
                enesimo = caricaDaFile(popolazione);
                inserimento(popolazione, enesimo);
                break;
            }
            case 2: {
                printf("\n lettura");
                enesimo = caricaDaFile(popolazione);
                stampaPersone(popolazione, enesimo);
                break;
            }
            case 3: {
                printf("\n modifica");
                break;
            }
            case 4: {
                printf("\n eleminazione");
                break;
            }
            case 0: {
                printf("\n Uscita in corso...\n");
                break;
            }
            default: {
                printf("\n Scelta non valida!");
            }
        }

        printf("\n Premi un tasto per continuare...");
        getch();

    } while (scelta != 0);
}

void inserimento(PERSONA persone[], int n) {

    PERSONA persona;

    printf("\n Nome persona: ");
    scanf("%s", persona.nome);

    printf("\n Cognome persona: ");
    scanf("%s", persona.cognome);

    printf("\n Codice Fiscale: ");
    scanf("%s", persona.codiceFiscale);

    printf("\n Data di Nascita");
    printf("\n Giorno: ");
    scanf("%d", &persona.dataNascita.giorno);
    printf("\n Mese (numero): ");
    scanf("%d", &persona.dataNascita.mese);
    printf("\n Anno: ");
    scanf("%d", &persona.dataNascita.anno);

    persone[n] = persona;
    n++;
    salvaSuFile(persone, n);
}

void salvaSuFile(PERSONA persone[], int n) {

    FILE *f = fopen("popolazione.dat", "wb");
    if (!f) {
        perror("Errore apertura file");
        return;
    }

    // Scrivo il numero di persone
    fwrite(&n, sizeof(int), 1, f);

    // Scrivo l'array di persone
    fwrite(persone, sizeof(PERSONA), n, f);

    fclose(f);
    printf("Dati salvati su file.\n");
}

int caricaDaFile(PERSONA persone[]) {
    FILE *f = fopen("popolazione.dat", "rb");
    if (!f) {
        printf("File non trovato, partenza con lista vuota.\n");
        return 0;
    }
    int n = 0;
    fread(&n, sizeof(int), 1, f);
    if (n > MAX_PERSONE) {
        printf("File corrotto o dati non validi.\n");
        fclose(f);
        return 0;
    }
    fread(persone, sizeof(PERSONA), n, f);
    fclose(f);
    return n;
}

void stampaPersone(PERSONA persone[], int n) {
    int i;

    if (n == 0) {
        printf(" NESSUNA PERSONA");
        return;
    }

    for (i = 0; i < n; i++) {
        PERSONA p = persone[i];
        printf("\n Persona %d", i + 1);
        printf("\n Nome %s", p.nome);
        printf("\n Cognome %s", p.cognome);
        printf("\n Codice Fiscale %s", p.codiceFiscale);
        printf("\n Sesso %d", p.sesso);
        printf("\n Data di Nascita\n Giorno %d\n Mese %d\n Anno %d", p.dataNascita.giorno, p.dataNascita.mese,
               p.dataNascita.anno);
        printf("\n____________________________________");
    }
}