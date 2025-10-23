#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_PAROLE 1000

void main() {
    FILE *f1 = fopen("file1.txt", "r");
    FILE *f2 = fopen("file2.txt", "r");
    FILE *out = fopen("risultati.txt", "w+");

    char parole[MAX_PAROLE][MAX_LEN];
    char parola[MAX_LEN];
    int conta;
    int i;

    if (!f1 || !f2 || !out) {
        printf("\n Errore nell'apertura dei file.");
        return;
    }

    while (fscanf(f1, "%s", parola) == 1 && conta < MAX_PAROLE) {
        strcpy(parole[conta++], parola);
    }

    while (fscanf(f2, "%s", parola) == 1) {
        for (i = 0; i < conta; i++) {
            if (strcmp(parola, parole[i]) == 0) {
                fprintf(out, "%s\n", parola);
                break;
            }
        }
    }

    fclose(f1);
    fclose(f2);
    fclose(out);

    printf("Parole comuni scritte in risultati.txt\n");
}