#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titolo[80];
    char autore[50];
    int anno;
} LIBRO;

LIBRO leggiLibro();
void aggiungiLibroCatalogo();
void rimuoviLibrocatalogo();
void mostraCatalogo();
void cercaLibroTitolo();
void salvaSuFile(LIBRO[], int);

void main() {
    int scelta;

    do {
        system("cls");
        printf(" 1. Aggiungere Libro\n");
        printf(" 2. Rimuovi Libro\n");
        printf(" 3. Mostra Catalogo\n");
        printf(" 4. Cerca libro per Titolo\n");
        printf(" 0. Uscita\n");

        printf("\n\n Scelta: ");
        scanf("%d", &scelta);

        system("cls");

        switch (scelta) {

            case 1: {
                printf("\n Aggiungere Libro al catalogo\n");
                aggiungiLibroCatalogo();
                break;
            }
            case 2: {
                printf("\n Rimuovere Libro dal catalogo\n");
                rimuoviLibrocatalogo();
                break;
            }
            case 3: {
                printf("\n Mostra catalogo");
                mostraCatalogo();
                break;
            }
            case 4: {
                printf("\n Cerca libro per titolo");
                cercaLibroTitolo();
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

LIBRO leggiLibro() {
    LIBRO libro;
    printf(" Titolo: ");
    scanf(" %[^\n]", libro.titolo);
    printf(" Autore: ");
    scanf(" %[^\n]", libro.autore);
    printf(" anno: ");
    scanf("%d", &libro.anno);
    return libro;
}

void mostraCatalogo() {
    FILE *fp;
    LIBRO libro;

    fp = fopen("catalogo.dat", "rb");
    if (!fp) {
        printf("\n Errore: impossibile aprire il file");
        return;
    }

    while (fread(&libro, sizeof(libro), 1, fp) == 1) {
        printf("\n %s - %s [%d]", libro.titolo, libro.autore, libro.anno);
    }

    fclose(fp);
}

void aggiungiLibroCatalogo() {
    FILE *fp;
    LIBRO libro;
    int i;
    fp = fopen("catalogo.dat", "ab");

    if (!fp) {
        printf("\n Impossibile aprire il file in scrittura.\n");
        return;
    }

    libro = leggiLibro();
    fwrite(&libro, sizeof(libro), 1, fp);

    fclose(fp);
    printf("\n Dati salvati con successo\n");
}

void salva(LIBRO libro) {
}

void cercaLibroTitolo() {
    FILE *fp;
    LIBRO libro;
    char titoloDaCercare[80];

    fp = fopen("catalogo.dat", "rb");
    if (!fp) {
        printf("\n Errore: impossibile aprire il file");
        return;
    }

    printf(" Titolo libro: ");
    scanf(" %[^\n]", titoloDaCercare);

    while (fread(&libro, sizeof(libro), 1, fp) == 1) {
        if (strcmp(titoloDaCercare, libro.titolo) == 0) {
            printf("\n %s - %s [%d]", libro.titolo, libro.autore, libro.anno);
        }
    }

    fclose(fp);
}

void cercaLibroAutore() {
    FILE *fp;
    LIBRO libro;
    char autoreDaCercare[80];

    fp = fopen("catalogo.dat", "rb");
    if (!fp) {
        printf("\n Errore: impossibile aprire il file");
        return;
    }

    printf(" Autore libro: ");
    scanf(" %[^\n]", autoreDaCercare);

    while (fread(&libro, sizeof(libro), 1, fp) == 1) {
        if (strcmp(autoreDaCercare, libro.titolo) == 0) {
            printf("\n %s - %s [%d]", libro.titolo, libro.autore, libro.anno);
        }
    }

    fclose(fp);
}

void rimuoviLibrocatalogo() {
    char titoloLibro[80];
    char autoreLibro[50];
    int i;
    int trovato = 0;

    printf("\n Titolo del Libro da Rimuovere: ");
    scanf(" %[^\n]", titoloLibro);

    printf("\n Autore del Libro da Rimuovere: ");
    scanf(" %[^\n]", autoreLibro);

    FILE *fp = fopen("catalogo.dat", "rb");
    if (!fp) {
        printf("\n Errore apertura file.\n");
        return;
    }

    FILE *fpTemp = fopen("catalogo.dat-bak", "wb");
    if (!fpTemp) {
        printf("\n Errore apertura file temporaneo.\n");
        return;
    }

    LIBRO libro;

    while (fread(&libro, sizeof(libro), 1, fp) == 1) {
        if (strcmp(titoloLibro, libro.titolo) != 0 && strcmp(autoreLibro, libro.autore) != 0) {
            fwrite(&libro, sizeof(LIBRO), 1, fpTemp);
        } else {
            trovato = 1;
        }
    }

    fclose(fp);
    fclose(fpTemp);

    if (trovato) {
        remove("catalogo.dat");
        rename("catalogo.dat-bak", "catalogo.dat");

        printf("\n Libro rimosso con successo.\n");
    } else {
        remove("catalogo-bak");

        printf("\n Nessuna libro trovato.\n");
    }
}
