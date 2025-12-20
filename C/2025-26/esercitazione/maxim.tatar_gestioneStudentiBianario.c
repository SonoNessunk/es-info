#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricola;
    int materie;
} Elemento;

void Salva(char *, int);
void Leggi(char *);

void main() {
    int numeroStudenti;
    printf("\n Gestione Studenti Binario\n\n");

    printf("\n Quanti studenti vuoi inserire? ");
    scanf("%d", &numeroStudenti);

    Salva("elementi.dat", numeroStudenti);
    Leggi("elementi.dat");

    printf("\n\n");
    system("pause");
}

void Salva(char *nomefile, int numeroStudenti) {
    FILE *fp;
    Elemento elemento;
    int i;

    fp = fopen(nomefile, "wb");
    if (!fp) {
        printf("\n Errore: impossibile creare il file %s\n", nomefile);
        exit(1);
    }

    for (i = 0; i < numeroStudenti; i++) {
        printf("\n Inserisci la matricola: ");
        scanf("%d", &elemento.matricola);

        printf(" Inserisci il numero di materie superate: ");
        scanf("%d", &elemento.materie);

        fwrite(&elemento, sizeof(Elemento), 1, fp);
    }

    fclose(fp);
    printf("\n Dati salvati correttamente nel file %s\n\n", nomefile);
}

void Leggi(char *nomefile) {
    FILE *fp;
    Elemento elemento;

    fp = fopen(nomefile, "rb");
    if (!fp) {
        printf("\n Errore: impossibile aprire il file %s\n", nomefile);
        return;
    }

    system("cls");
    printf(" Contenuto del file %s:\n\n", nomefile);

    while (fread(&elemento, sizeof(Elemento), 1, fp) == 1) {
        printf("Matricola: %d     Materie: %d\n", elemento.matricola, elemento.materie);
    }

    fclose(fp);
}
