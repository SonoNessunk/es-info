#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("\n 4. Eliminazione");
        printf("\n 0. Uscita");

        printf("\n\n Scelta: ");
        scanf("%d", &scelta);
        getchar(); // per evitare problemi col buffer

        switch (scelta) {
            case 1:
                printf("\n Inserimento\n");
                enesimo = caricaDaFile(popolazione);
                inserimento(popolazione, enesimo);
                break;
            case 2:
                printf("\n Lettura\n");
                enesimo = caricaDaFile(popolazione);
                stampaPersone(popolazione, enesimo);
                break;
            case 3:
                printf("\n Modifica (non ancora implementata)\n");
                break;
            case 4:
                printf("\n Eliminazione (non ancora implementata)\n");
                break;
            case 0:
                printf("\n Uscita in corso...\n");
                break;
            default:
                printf("\n Scelta non valida!");
        }

        printf("\n Premi INVIO per continuare...");
        getchar();

    } while (scelta != 0);
}

void inserimento(PERSONA persone[], int n) {
    PERSONA persona;

    printf("\n Nome persona: ");
    scanf("%40s", persona.nome);

    printf("\n Cognome persona: ");
    scanf("%40s", persona.cognome);

    printf("\n Codice Fiscale: ");
    scanf("%16s", persona.codiceFiscale);

    printf("\n Sesso (1=maschio, 2=femmina): ");
    scanf("%d", (int *)&persona.sesso);

    printf("\n Data di Nascita");
    printf("\n Giorno: ");
    scanf("%d", &persona.dataNascita.giorno);
    printf("\n Mese: ");
    scanf("%d", &persona.dataNascita.mese);
    printf("\n Anno: ");
    scanf("%d", &persona.dataNascita.anno);

    persone[n] = persona;
    n++;
    salvaSuFile(persone, n);
}

void salvaSuFile(PERSONA persone[], int n) {
    FILE *f = fopen("popolazione.txt", "w");
    int i;

    if (!f) {
        perror("Errore apertura file");
        return;
    }

    fprintf(f, "%d\n", n);

    for (i = 0; i < n; i++) {
        PERSONA p = persone[i];
        fprintf(f, "%s\n%s\n%s\n%d\n%d %d %d\n", p.nome, p.cognome, p.codiceFiscale, p.sesso, p.dataNascita.giorno,
                p.dataNascita.mese, p.dataNascita.anno);
    }

    fclose(f);
    printf("Dati salvati su file .txt.\n");
}

int caricaDaFile(PERSONA persone[]) {
    FILE *f = fopen("popolazione.txt", "r");
    int i;
    if (!f) {
        printf("File non trovato. Inizio con lista vuota.\n");
        return 0;
    }

    int n;
    if (fscanf(f, "%d\n", &n) != 1 || n > MAX_PERSONE) {
        printf("File corrotto o numero persone non valido.\n");
        fclose(f);
        return 0;
    }

    for (i = 0; i < n; i++) {
        PERSONA p;
        fgets(p.nome, sizeof(p.nome), f);
        p.nome[strcspn(p.nome, "\n")] = 0;

        fgets(p.cognome, sizeof(p.cognome), f);
        p.cognome[strcspn(p.cognome, "\n")] = 0;

        fgets(p.codiceFiscale, sizeof(p.codiceFiscale), f);
        p.codiceFiscale[strcspn(p.codiceFiscale, "\n")] = 0;

        fscanf(f, "%d\n", (int *)&p.sesso);
        fscanf(f, "%d %d %d\n", &p.dataNascita.giorno, &p.dataNascita.mese, &p.dataNascita.anno);

        persone[i] = p;
    }

    fclose(f);
    return n;
}

void stampaPersone(PERSONA persone[], int n) {
    int i;
    if (n == 0) {
        printf("NESSUNA PERSONA PRESENTE\n");
        return;
    }

    for (i = 0; i < n; i++) {
        PERSONA p = persone[i];
        printf("\nPersona %d", i + 1);
        printf("\n Nome: %s", p.nome);
        printf("\n Cognome: %s", p.cognome);
        printf("\n Codice Fiscale: %s", p.codiceFiscale);
        printf("\n Sesso: %s", p.sesso == maschio ? "Maschio" : "Femmina");
        printf("\n Data di Nascita: %02d/%02d/%04d", p.dataNascita.giorno, p.dataNascita.mese, p.dataNascita.anno);
        printf("\n----------------------------------");
    }
}
