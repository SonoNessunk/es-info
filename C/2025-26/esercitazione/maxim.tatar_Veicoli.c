#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char targa[10];
    char marca[30];
    char modello[30];
    float costo_intervento;
} VEICOLO;

void main() {

    int scelta;

    printf(" Veicoli da salvare: ");

    do {

        printf(" 1. Inserisci");
        printf(" 2. Ricerca");
        printf(" 3. Costo degli interventi");
        printf(" 0. Uscita");

        switch (scelta) {
            case 1: {
                printf("\n Inserimento Veicoli");
                break;
            }
            case 2: {
                printf("\n Ricerca");
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

        system("pause");
        printf("\n\n");
    } while (scelta != 0);
}

void salva(int num) {
    FILE *fp = fopen("elementi.dat", "ab");
    VEICOLO veicolo;

    if (!fp) {
        printf("\n\n Errore nell'apertura del file");
        return;
    }

    printf("\n Inserisci Targa: ");
    scanf(" %[^\n]", veicolo.targa);

    printf("\n Inserisci Targa: ");
    scanf(" %[^\n]", veicolo.marca);

    printf("\n Inserisci Targa: ");
    scanf(" %[^\n]", veicolo.marca);

    printf("\n Inserisci Targa: ");
    scanf(" %[^\n]", veicolo.modello);

    printf("\n Inserisci Targa: ");
    scanf("%f", &veicolo.costo_intervento);

    fwrite(&veicolo, sizeof(veicolo), 1, fp);

    fclose(fp);
}

void leggi() {
    FILE *fp = fopen("elementi.dat", "rb");
    VEICOLO veicolo;

    if (!fp) {
        printf("\n\n Errore nell'apertura del file!");
        return;
    }

    printf("\n\n Studenti");

    while (fread(&veicolo, sizeof(veicolo), 1, fp) == 1) {
        printf("\n\n Modello: %s", veicolo.modello);
        printf(" | targa: %s", veicolo.targa);
    }

    fclose(fp);
}

void ricerca() {
    FILE *fp = fopen("elementi.dat", "rb");
    VEICOLO veicolo;

    if (!fp) {
        printf("\n\n Errore nell'apertura del file!");
        return;
    }

    printf("\n\n Studenti");

    while (fread(&veicolo, sizeof(veicolo), 1, fp) == 1) {
        printf("\n\n Modello: %s", veicolo.modello);
        printf(" | targa: %s", veicolo.targa);
    }

    fclose(fp);
}