#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *MyFopen(char *, char *);
int MyFclose(FILE *);
int MyError(char *);

void main(int argc, char const *argv[]) {
    const int MAX = 80;

    FILE *f;
    char nomeFile[MAX];
    char riga[MAX];

    int r;
    int numero;
    int somma;

    printf("\n Somma numeri da File \n\n");

    if (argc != 2) {
        MyError(" Numero argomenti errato\n");
    }

    strcpy(nomeFile, argv[1]);
    f = MyFopen(nomeFile, "r+");

    somma = 0;

    while (fgets(riga, MAX, f) != NULL) {
        r = sscanf(riga, "%d", &numero);
        if (r == 1) {
            somma += numero;
        } else {
            printf(" Riga ignorata\n");
        }
    }

    MyFclose(f);
    printf(" La somma vale: %d\n", somma);

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