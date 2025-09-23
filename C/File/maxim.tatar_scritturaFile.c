#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

FILE *MyFopen(char *, char *);
int MyFclose(FILE *);

void main() {
    FILE *fp;
    char c;
    char nomeFile[20] = "";

    printf("\n Scrittura carattere da File \n\n");
    printf(" Inserire il nome del file: ");
    scanf("%s", nomeFile);
    printf(" Inserire i caratteri da scrivere: ");

    fp = MyFopen(nomeFile, "w");
    int i = 0;
    while ((c = getche()) != '\r') {
        fprintf(fp, "%c", c);
    }
    MyFclose(fp);
    printf("\n\n");
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