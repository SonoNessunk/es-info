#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int copiafile(char[], char[]);
FILE *myfopen(char *, char *);
int myfclose(FILE *);

#define OK 1
#define ERROR 0
#define MAXLINE 100

void main() {
    char fileDaCopiare[20] = "";
    char fileDoveIncollare[20] = "";

    printf("\n Lettura e Scrittura File \n\n");

    printf(" Inserire il nome del file dove copiare il contenuto: ");
    scanf("%s", fileDaCopiare);

    printf(" Inserire il nome del file dove incollare il contenuto: ");
    scanf("%s", fileDoveIncollare);

    copiafile(fileDaCopiare, fileDoveIncollare);

    printf("\n\n");
}

int copiafile(char fileCopia[], char fileIncolla[]) {
    char line[MAXLINE];
    FILE *fin;
    FILE *fout;

    if ((fin = myfopen(fileCopia, "r")) == NULL) {
        return ERROR;
    }

    if ((fout = fopen(fileIncolla, "w")) == NULL) {
        fclose(fin);
        return ERROR;
    }

    while (fgets(line, MAXLINE, fin) != NULL) {
        fputs(line, fout);
    }

    myfclose(fin);
    myfclose(fout);

    return OK;
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