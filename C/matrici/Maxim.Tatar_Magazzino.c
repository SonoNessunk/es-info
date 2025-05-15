#include <stdio.h>
#include <string.h>

#define MAXRIGHE 2000
#define LUN 80

void stampa(char[]);
void stampaM(char[MAXRIGHE][LUN]);

int main() {

    char magazzino[MAXRIGHE][LUN];
    char prod[LUN];
    char comando[LUN];
    char temp[LUN];
    char dir;
    int qta;

    int nRighe = 0;

    do {

        printf("\n Comando: ");
        gets(comando);
        
        if (strcmp(comando, "FINE" != 0)) {
            strcpy(magazzino[nRighe], comando);
            nRighe++;
        }

    } while (strcmp(comando, "FINE") != 0);

    int i, j;

    printf("\n\n Magazzino: \n");
    stampaM(magazzino);

    i = 0;
    while (comando[i] != ' ') {
        prod[i] = comando[i];
        i++;
    }

    // printf("\n\n Prodotto: ");
    // stampa(prod);

    // prod[i] = 0;

    // i++;

    // dir = comando[i];

    // i++;

    // j = 0;

    // while(comando[i] != 0) {
    //     temp[j] = comando[i];
    //     i++;
    //     j++;
    // }

    // temp[j] = 0;
    // qta = atoi(temp);

    // printf("\n\n Temp: ");
    // stampa(temp);
}

void stampa(char vettore[]) {

    int i;
    for (i = 0; i < strlen(vettore); i++) {
        printf(" [%c]", vettore[i]);
    }
    printf("\n\n");
}

void stampaM(char vettore[MAXRIGHE][LUN]) {

    int i, j;
    for (i = 0; i < MAXRIGHE; i++) {
        for (j = 0; j < strlen(vettore); j++) {
            printf(" [%c]", vettore[i][j]);
        }
        printf("\n");
    }
}