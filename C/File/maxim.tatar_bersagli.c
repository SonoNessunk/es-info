#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *MyFopen(char *, char *);
int MyFclose(FILE *);
int MyError(char *);

void main(int argc, char const *argv[]) {
    const int MAX_BERSAGLI = 100;
    const int MAX = 80;
    const char FILE_BERSAGLI[] = "bersagli.txt";

    int numeroBersaglio;
    int bersagliX[MAX_BERSAGLI];
    int bersagliY[MAX_BERSAGLI];

    int numeroColpi;
    int numeroColpiCentrati;

    FILE *f;

    char riga[MAX];
    int centroX;
    int centroY;
    int i;
    int r;
    int trovato;

    f = MyFopen(FILE_BERSAGLI, "r+");
    numeroBersaglio = 0;

    while (fgets(riga, MAX, f) != NULL) {
        r = sscanf(riga, "%d %d", &bersagliX[numeroBersaglio], &bersagliY[numeroBersaglio]);
        if (r != 2) {
            MyError(" Formato errato\n");
        }
        numeroBersaglio++;
    }
    MyFclose(f);

    if (argc != 2) {
        MyError(" ERRORE: manca nome file\n");
    }

    f = MyFopen(argv[1], "r+");

    numeroColpi = 0;
    numeroColpiCentrati = 0;

    while (fgets(riga, MAX, f) != NULL) {
        r = sscanf(riga, "%d %d", &centroX, &centroY);
        if (r != 2) {
            MyError(" Formato errato\n");
        }
        numeroColpi++;

        trovato = 0;
        for (i = 0; i < numeroBersaglio && trovato == 0; i++) {
            printf(" cX: %d\n bX: %d\n cY: %d\n bY: %d\n", centroX, bersagliX[i], centroY, bersagliY[i]);
            if (centroX == bersagliX[i] && centroY == bersagliY[i]) {
                trovato = 1;
            }
        }

        if (trovato == 1) {
            numeroColpiCentrati++;
        }
    }

    MyFclose(f);

    printf(" Colpi sparati: %d", numeroColpi);
    printf(" Colpi andati a segno: %d", numeroColpiCentrati);
    if (numeroColpi != 0) {
        printf(" (%.2f%%)", numeroColpiCentrati * 100.0 / numeroColpi);
    }
    printf("\n");
    exit(0);
}

FILE *MyFopen(char *name, char *mode) {
    FILE *file;
    file = fopen(name, mode);
    if (file == NULL) {
        printf(" Impossibile aprire %s\n", name);
        exit(1);
    }
    return file;
}

int MyFclose(FILE *f) {
    int risultato;
    if (f == NULL) {
        printf(" ERRORE INTERNO \n");
        exit(1);
    }
    risultato = fclose(f);
    if (risultato != 0) {
        printf(" Impossibile chiudere \n");
        exit(1);
    }
    return risultato;
}

int MyError(char *message) {
    fputs(message, stderr);
    exit(1);
}