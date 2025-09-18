#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

FILE *myfopen(char *name, char *mode);
int myfclose(FILE *f);

void main() {
    char car;
    FILE *fp;
    char nomeFile[20] = "";

    printf("\n Lettura carattere da File \n\n");
    printf(" Inserire il nome del file: ");
    scanf("%s", nomeFile);
    printf(" Contenuto del file \"%s\":\n\n ", nomeFile);

    fp = myfopen(nomeFile, "r");
    while (!feof(fp)) {
        car = fgetc(fp);
        printf("%c", car);
        if (car == '\n') {
            printf(" ");
        }
    }
    myfclose(fp);

    printf("\n\n");
}

FILE *myfopen(char *name, char *mode) {
    FILE *file;
    file = fopen(name, mode);
    if (file == NULL) {
        printf(" Impossibile aprire %s\n", name);
        exit(1);
    }
    return file;
}

int myfclose(FILE *f) {
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