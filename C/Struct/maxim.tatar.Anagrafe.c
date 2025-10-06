#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONE 100

typedef enum {
    maschio = 1,
    femmina
} GENERE;

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
    char luogoNascita[41];
} PERSONA;

void inserimento(PERSONA[], int);
void lettura(PERSONA[], int);
void modifica(PERSONA[], int n);
void eliminazione(PERSONA[], int n);

void salvaSuFile(PERSONA[], int);
int caricaDaFile(PERSONA[]);

char *stringaMaiuscola(char *);

void main() {
    int scelta;
    PERSONA popolazione[MAX_PERSONE];
    int numeroPersone;

    do {
        numeroPersone = caricaDaFile(popolazione);
        system("cls");

        printf("\n 1. Inserimento");
        printf("\n 2. Lettura");
        printf("\n 3. Modifica");
        printf("\n 4. Eliminazione");
        printf("\n 0. Uscita");

        printf("\n\n Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                system("cls");
                printf("\n Inserimento\n");
                inserimento(popolazione, numeroPersone);
                break;
            }
            case 2: {
                printf("\n Lettura\n");
                lettura(popolazione, numeroPersone);
                break;
            }
            case 3: {
                printf("\n Modifica\n");
                modifica(popolazione, numeroPersone);
                break;
            }
            case 4: {
                printf("\n Eliminazione\n");
                eliminazione(popolazione, numeroPersone);
                break;
            }
            case 0: {
                printf("\n Uscita in corso...");
                break;
            }
            default: {
                printf("\n Scelta non valida!");
            }
        }

        printf("\n\n");
        system("pause");
    } while (scelta != 0);
}

char *stringaMaiuscola(char *stringa) {
    int i;
    for (i = 0; stringa[i] != 0; i++) {
        stringa[i] = toupper(stringa[i]);
    }
    return stringa;
}

void inserimento(PERSONA persone[], int n) {
    PERSONA persona;

    printf("\n Nome persona: ");
    scanf("%s", persona.nome);

    printf("\n Cognome persona: ");
    scanf("%s", persona.cognome);

    printf("\n Codice Fiscale: ");
    scanf("%s", stringaMaiuscola(persona.codiceFiscale));

    printf("\n Sesso (1=maschio, 2=femmina): ");
    scanf("%d", &persona.sesso);

    printf("\n Data di Nascita\n");
    printf(" Giorno: ");
    scanf("%d", &persona.dataNascita.giorno);
    printf(" Mese: ");
    scanf("%d", &persona.dataNascita.mese);
    printf(" Anno: ");
    scanf("%d", &persona.dataNascita.anno);

    printf("\n Luogo di Nascita: ");
    scanf("%s", persona.luogoNascita);

    persone[n] = persona;
    n++;
    salvaSuFile(persone, n);
}

void modifica(PERSONA persone[], int n) {

    char codiceFiscale[17];
    int i;
    int trovato = 0;
    int scelta;

    printf("\n Inserisci il codice fiscale della persona: ");
    scanf("%s", codiceFiscale);
    stringaMaiuscola(codiceFiscale);

    for (i = 0; i < n; i++) {
        if (strcmp(persone[i].codiceFiscale, codiceFiscale) == 0) {
            trovato = 1;

            do {
                system("cls");

                printf("\n Persona trovata\n");
                printf("\n  Nome: %s", persone[i].nome);
                printf("\n  Cognome: %s", persone[i].cognome);
                printf("\n  Codice Fiscale: %s", stringaMaiuscola(persone[i].codiceFiscale));
                printf("\n  Sesso: ");
                if (persone[i].sesso == 1) {
                    printf("Maschio");
                } else {
                    printf("Femmina");
                }
                printf("\n  Data di Nascita: %02d/%02d/%04d", persone[i].dataNascita.giorno, persone[i].dataNascita.mese, persone[i].dataNascita.anno);
                printf("\n  Luogo di Nascita: %s", persone[i].luogoNascita);

                printf("\n\n Cosa vuoi modificare?");
                printf("\n 1. Nome");
                printf("\n 2. Cognome");
                printf("\n 3. Codice Fiscale");
                printf("\n 4. Sesso");
                printf("\n 5. Data di Nascita");
                printf("\n 6. Luogo di Nascita");
                printf("\n 0. Niente");

                printf("\n\n Scelta: ");
                scanf("%d", &scelta);

                switch (scelta) {
                    case 1: {
                        printf("\n Nuovo Nome: ");
                        scanf("%s", persone[i].nome);
                        break;
                    }

                    case 2: {
                        printf("\n Nuovo Cognome: ");
                        scanf("%s", persone[i].cognome);
                        break;
                    }

                    case 3: {
                        printf("\n Nuovo Codice Fiscale: ");
                        scanf("%s", persone[i].codiceFiscale);
                        break;
                    }

                    case 4: {
                        printf("\n Nuovo Sesso(1=maschio, 2=femmina): ");
                        scanf("%d", &persone[i].sesso);
                        break;
                    }

                    case 5: {
                        printf("\n Data di Nascita\n");
                        printf(" Giorno: ");
                        scanf("%d", &persone[i].dataNascita.giorno);
                        printf(" Mese: ");
                        scanf("%d", &persone[i].dataNascita.mese);
                        printf(" Anno: ");
                        scanf("%d", &persone[i].dataNascita.anno);
                        break;
                    }

                    case 6: {
                        printf("\n Nuovo Luogo di Nascita: ");
                        scanf("%s", persone[i].luogoNascita);
                        break;
                    }

                    case 0: {
                        printf("\n Uscita...");
                        break;
                    }

                    default: {
                        printf("\n Scelta non valida!");
                        break;
                    }
                }
            } while (scelta != 0);
        }
    }

    if (trovato) {
        salvaSuFile(persone, n);
    } else {
        printf("\n Codice Fiscale non trovato.");
    }
}

void eliminazione(PERSONA persone[], int n) {
    char codiceFiscale[17];
    int i;
    int j;
    int trovato = 0;
    int scelta;

    printf("\n Inserisci il codice fiscale della persona: ");
    scanf("%s", codiceFiscale);
    stringaMaiuscola(codiceFiscale);
    for (i = 0; i < n; i++) {
        if (strcmp(persone[i].codiceFiscale, codiceFiscale) == 0) {
            trovato = 1;
            system("cls");

            printf("\n Persona trovata\n");
            printf("\n  Nome: %s", persone[i].nome);
            printf("\n  Cognome: %s", persone[i].cognome);
            printf("\n  Codice Fiscale: %s", stringaMaiuscola(persone[i].codiceFiscale));
            printf("\n  Sesso: ");
            if (persone[i].sesso == 1) {
                printf("Maschio");
            } else {
                printf("Femmina");
            }
            printf("\n  Data di Nascita: %02d/%02d/%04d", persone[i].dataNascita.giorno, persone[i].dataNascita.mese,
                   persone[i].dataNascita.anno);
            printf("\n  Luogo di Nascita: %s", persone[i].luogoNascita);

            printf("\n Sei sicuro di voler elimanare questa persona? (1:si 0:no)");
            scanf("%d", &scelta);

            if (scelta) {
                for (j = i; j < n - 1; j++) {
                    persone[j] = persone[j + 1];
                }
                n--;
                printf("\n Persona eliminata con successo.\n");
            } else {
                printf("\n Eliminazione annulata");
            }
        }
    }

    if (trovato) {
        salvaSuFile(persone, n);
    } else {
        printf("\n Codice Fiscale non trovato.");
    }
}

void salvaSuFile(PERSONA persone[], int n) {
    FILE *f = fopen("anagrafe.txt", "w");
    int i;

    if (!f) {
        perror("\n Errore apertura file\n");
        return;
    }

    fprintf(f, "%d\n", n);

    for (i = 0; i < n; i++) {
        PERSONA p = persone[i];
        fprintf(f, "%s\n", p.nome);
        fprintf(f, "%s\n", p.cognome);
        fprintf(f, "%s\n", stringaMaiuscola(p.codiceFiscale));
        fprintf(f, "%d\n", p.sesso);
        fprintf(f, "%d\n", p.dataNascita.giorno);
        fprintf(f, "%d\n", p.dataNascita.mese);
        fprintf(f, "%d\n", p.dataNascita.anno);
        fprintf(f, "%s\n", p.luogoNascita);
    }

    fclose(f);
    printf("\n Dati salvati su file anagrafe.txt");
}

int caricaDaFile(PERSONA persone[]) {
    FILE *f = fopen("anagrafe.txt", "r");
    int i;
    if (!f) {
        printf("\n File non trovato. Inizio con lista vuota.\n");
        return 0;
    }

    int n;
    if (fscanf(f, "%d\n", &n) != 1 || n > MAX_PERSONE) {
        printf("\n File corrotto, numero persone non valido o lista vuota.\n");
        fclose(f);
        return 0;
    }

    for (i = 0; i < n; i++) {
        PERSONA p;

        fscanf(f, "%s", p.nome);
        fscanf(f, "%s", p.cognome);
        fscanf(f, "%s", stringaMaiuscola(p.codiceFiscale));
        fscanf(f, "%d", &p.sesso);
        fscanf(f, "%d %d %d", &p.dataNascita.giorno, &p.dataNascita.mese, &p.dataNascita.anno);
        fscanf(f, "%s", p.luogoNascita);

        persone[i] = p;
    }

    fclose(f);
    return n;
}

void lettura(PERSONA persone[], int n) {
    int i;
    if (n == 0) {
        printf("\n Nessuna persona presente\n");
        return;
    }

    for (i = 0; i < n; i++) {
        PERSONA p = persone[i];
        printf("\n Persona %d", i + 1);
        printf("\n  Nome: %s", p.nome);
        printf("\n  Cognome: %s", p.cognome);
        printf("\n  Codice Fiscale: %s", stringaMaiuscola(p.codiceFiscale));
        printf("\n  Sesso: ");
        if (p.sesso == 1) {
            printf("Maschio");
        } else {
            printf("Femmina");
        }
        printf("\n  Data di Nascita: %02d/%02d/%04d", p.dataNascita.giorno, p.dataNascita.mese, p.dataNascita.anno);
        printf("\n  Luogo di Nascita: %s", p.luogoNascita);
        printf("\n----------------------------------");
    }
}
