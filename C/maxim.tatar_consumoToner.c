#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *MyFopen(char *, char *);
int MyFclose(FILE *);
int MyError(char *);

void main(int argc, char const *argv[]) {

    const int LUNDIP = 5;
    const int MAX = 80;

    char dipartimento[LUNDIP + 1];
    char dipartimentoFile[LUNDIP + 1];

    int statistica;

    FILE *f;

    int quantitaTonerFile;
    int r;
    int min;
    int max;
    int totale;
    int cont;

    char riga[MAX + 1];

    if (argc != 4) {
        MyError(" Numero parametri errato\n");
    }

    strcpy(dipartimento, argv[2]);
    if (strcmp(argv[3], "-min") == 0) {
        statistica = 1;
    } else if (strcmp(argv[3], "-max") == 0) {
        statistica = 2;
    } else if (strcmp(argv[3], "-med") == 0) {
        statistica = 3;
    } else {
        MyError(" Statistica sconosciuta\n");
    }

    f = MyFopen(argv[1], "r+");

    totale = 0;
    cont = 0;
    min = 100;
    max = 0;

    while (fgets(riga, MAX, f) != NULL) {
        r = sscanf(riga, "%s %d", dipartimentoFile, &quantitaTonerFile);
        if (r != 2) {
            printf(" Riga ignorata\n");
        } else {
            if (strcmp(dipartimento, dipartimentoFile) == 0) {
                if (quantitaTonerFile < min) {
                    min = quantitaTonerFile;
                }
                if (quantitaTonerFile > max) {
                    max = quantitaTonerFile;
                }
                totale += quantitaTonerFile;
                cont++;
            }
        }
    }
    MyFclose(f);

    if (cont == 0) {
        printf(" Nessun elemento\n");
    } else if (statistica == 1) {
        printf(" %d\n", min);
    } else if (statistica == 2) {
        printf(" %d\n", max);
    } else if (statistica == 3) {
        printf(" %.1f\n", (float)totale / cont);
    }

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