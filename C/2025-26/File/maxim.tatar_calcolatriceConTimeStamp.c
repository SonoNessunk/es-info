#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Addizione(int, int, int);
void Sottrazione(int, int, int);
void Moltiplicazione(int, int, int);
void Divisione(int, int, int);
void Potenza(int, int, int);
void Radice(int, int);
void TimeNow();

FILE *myfopen(char *name, char *mode);
int myfclose(FILE *f);

FILE *filePointer;
char buffer[80];

int main() {

    int scelta;
    int numeroUno;
    int numeroDue;
    int numeroOperazione;

    printf("\n Calcolatrice - Salva Risultati in File");

    do {

        system("cls");

        printf("\n Calcolatrice - Scegliere l'operazione\n");

        printf("\n +----------------------+");
        printf("\n | 1 - Addizione        |");
        printf("\n | 2 - Sottrazione      |");
        printf("\n | 3 - Moltiplicazione  |");
        printf("\n | 4 - Divisione        |");
        printf("\n | 5 - Potenze          |");
        printf("\n | 6 - Radice Quadrata  |");
        printf("\n | 0 - Esci             |");
        printf("\n +----------------------+");

        printf("\n\n Scelta: ");
        scanf("%d", &scelta);

        system("cls");

        switch (scelta) {
            case 1: {
                numeroOperazione++;
                Addizione(numeroUno, numeroDue, numeroOperazione);
                break;
            }

            case 2: {
                numeroOperazione++;
                Sottrazione(numeroUno, numeroDue, numeroOperazione);
                break;
            }

            case 3: {
                numeroOperazione++;
                Moltiplicazione(numeroUno, numeroDue, numeroOperazione);
                break;
            }

            case 4: {
                numeroOperazione++;
                Divisione(numeroUno, numeroDue, numeroOperazione);
                break;
            }

            case 5: {
                numeroOperazione++;
                Potenza(numeroUno, numeroDue, numeroOperazione);
                break;
            }

            case 6: {
                numeroOperazione++;
                Radice(numeroUno, numeroOperazione);
                break;
            }

            case 0: {
                printf(" Uscita in corso...\n");
                break;
            }

            default: {
                printf("\n Scelta non valida!");
            }
        }

        printf("\n Premi un tasto per continuare...");
        getch();

    } while (scelta != 0);
}

void Addizione(int a, int b, int numeroOperazione) {

    TimeNow();

    printf("\n Calcolatrice - Addizione\n");

    printf("\n primo numero: ");
    scanf("%d", &a);

    printf("\n secondo numero: ");
    scanf("%d", &b);

    printf("\n\n Risultato: %d + %d = %d\n", a, b, a + b);

    filePointer = myfopen("cronologia.txt", "a");
    fprintf(filePointer, "%d) %d + %d = %d\n", numeroOperazione, a, b, a + b);
    fprintf(filePointer, "Eseguito il: %s\n\n", buffer);
    myfclose(filePointer);
}

void Sottrazione(int a, int b, int numeroOperazione) {

    TimeNow();

    printf("\n Calcolatrice - Sottrazione\n");

    printf("\n Primo numero: ");
    scanf("%d", &a);

    printf("\n Secondo numero: ");
    scanf("%d", &b);

    printf("\n\n Risultato: %d - %d = %d\n", a, b, a - b);

    filePointer = myfopen("cronologia.txt", "a");
    fprintf(filePointer, "%d) %d - %d = %d\n", numeroOperazione, a, b, a - b);
    fprintf(filePointer, "Eseguito il: %s\n\n", buffer);
    myfclose(filePointer);
}

void Moltiplicazione(int a, int b, int numeroOperazione) {

    TimeNow();

    printf("\n Calcolatrice - Moltiplicazione\n");

    printf("\n Primo numero: ");
    scanf("%d", &a);

    printf("\n Secondo numero: ");
    scanf("%d", &b);

    printf("\n\n Risultato: %d * %d = %d\n", a, b, a * b);

    filePointer = myfopen("cronologia.txt", "a");
    fprintf(filePointer, "%d) %d * %d = %d\n", numeroOperazione, a, b, a * b);
    fprintf(filePointer, "Eseguito il: %s\n\n", buffer);
    myfclose(filePointer);
}

void Divisione(int a, int b, int numeroOperazione) {

    TimeNow();

    printf("\n Calcolatrice - Divisione\n");

    printf("\n Primo numero: ");
    scanf("%d", &a);

    printf("\n Secondo numero: ");
    scanf("%d", &b);

    if (b == 0) {
        printf("\n Errore: Divisione per zero non permessa.");
        return;
    }

    printf("\n\n Risultato: %d / %d = %.2f\n", a, b, (float)a / (float)b);

    filePointer = myfopen("cronologia.txt", "a");
    fprintf(filePointer, "%d) %d / %d = %.2f\n", numeroOperazione, a, b, (float)a / (float)b);
    fprintf(filePointer, "Eseguito il: %s\n\n", buffer);
    myfclose(filePointer);
}

void Potenza(int a, int b, int numeroOperazione) {

    TimeNow();

    printf("\n Calcolatrice - Potenza");

    printf("\n Inserisci la base: ");
    scanf("%d", &a);

    printf("\n Inserisci l'esponente: ");
    scanf("%d", &b);

    printf("\n\n Risultato: %d ^ %d = %.2f\n", a, b, pow(a, b));

    filePointer = myfopen("cronologia.txt", "a");
    fprintf(filePointer, "%d) %d ^ %d = %.2f\n", numeroOperazione, a, b, pow(a, b));
    fprintf(filePointer, "Eseguito il: %s\n\n", buffer);
    myfclose(filePointer);
}

void Radice(int a, int numeroOperazione) {

    TimeNow();

    printf("\n Calcolatrice - Radice Quadrata\n");

    printf("\n Inserisci il numero: ");
    scanf("%d", &a);

    if (a < 0) {
        printf("\n Errore: Radice quadrata di un numero negativo non permessa.\n");
        return;
    }

    printf("\n\n Risultato: radice quadrata di %d = %.2f\n", a, sqrt(a));
    filePointer = myfopen("cronologia.txt", "a");
    fprintf(filePointer, "%d) radice quadrata di %d = %.2f\n", a, sqrt(a));
    fprintf(filePointer, "Eseguito il: %s\n\n", buffer);
    myfclose(filePointer);
}

FILE *myfopen(char *name, char *mode) {
    FILE *f;

    f = fopen(name, mode);

    if (f == NULL) {
        printf("\n Impossibile aprire %s\n", name);
        exit(1);
    }
    return f;
}

int myfclose(FILE *f) {
    int ris;

    if (f == NULL) {
        printf("\n ERRORE INTERNO");
        exit(1);
    }
    ris = fclose(f);

    if (ris != 0) {
        printf("\n Impossibile chiudere");
        exit(1);
    }
    return ris;
}

void TimeNow() {
    time_t now;
    struct tm *timeinfo;

    time(&now);
    timeinfo = localtime(&now);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
}