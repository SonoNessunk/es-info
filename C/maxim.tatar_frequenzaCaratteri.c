#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

FILE *myfopen(char *name, char *mode);
int myfclose(FILE *f);

void main(int argc, char *argv[]) {
    const int LETT = 26;
    int freq[LETT];
    FILE *f;
    int ch, i;
    if (argc != 2) {
        printf("Numero argomenti errato\n");
        exit(1);
    }
    for (i = 0; i < LETT; i++)
        freq[i] = 0;

    f = myfopen(argv[1], "r");
    ch = fgetc(f);
    while (ch != EOF) {
        if (isalpha(ch)) {
            i = toupper(ch) - 'A';
            freq[i]++;
        }
        ch = fgetc(f);
    }
    myfclose(f);
    for (i = 0; i < LETT; i++) {
        printf("%c : %d\n", i + 'A', freq[i]);
    }
    exit(0);
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