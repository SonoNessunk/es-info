#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

FILE *MyFopen(char *name, char *mode);
int MyFclose(FILE *f);

int main(int argc, char *argv[]) {

    FILE *f;
    int i, j;
    char ch;
    if (argc != 2) {
        printf("Numero argomenti errato\n");
        exit(1);
    }
    f = MyFopen(argv[1], "w");

    printf("\n\n");
    for (i = 0; i < 26; i++) {
        ch = i + 'A';
        for (j = 0; j <= i; j++) {
            fputc(ch, f);
        }
        fputc('\n', f);
    }
    MyFclose(f);
    exit(0);
    return 0;
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