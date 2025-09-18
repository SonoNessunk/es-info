#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

FILE *myfopen(char *, char *);
int myfclose(FILE *);

void main() {
    FILE *fp;
    char c;
    char nomeFile[20] = "";

    printf("\n Scrittura carattere da File \n\n");
    printf(" Inserire il nome del file: ");
    scanf("%s", nomeFile);
    printf(" Inserire i caratteri da scrivere: ");

    fp = myfopen(nomeFile, "w");
    int i = 0;
    while ((c = getche()) != '\r') {
        fprintf(fp, "%c", c);
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