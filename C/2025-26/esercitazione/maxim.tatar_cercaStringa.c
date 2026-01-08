#include <stdio.h>
#include <string.h>

#define MAX 50

void main() {

    FILE *f;
    char nomeFile[MAX];
    char parola[MAX];
    char stringa[MAX];
    int conta;

    printf(" Nome del File: ");
    scanf(" %[^\n]", nomeFile);

    f = fopen(nomeFile, "r");

    if (!f) {
        printf("\n Errore apertura del file %s", nomeFile);
        return;
    }

    printf("\n Inserire parola da cercare: ");
    scanf(" %[^\n]", parola);

    while (fscanf(f, "%s", stringa) != EOF) {
        if (strcmp(parola, stringa) == 0) {
            conta++;
        }
    }

    printf("\n La parola %s e' presente nel file %s: %d volte", parola, nomeFile, conta);
    fclose(f);

    printf("\n\n");
    system("pause");
}