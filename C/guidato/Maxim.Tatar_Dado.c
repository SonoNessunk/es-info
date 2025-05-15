#include <stdio.h>
#include <time.h>

#define FACCE 100

void lanciaDadi(int[], int, int);

void calcolaFrequenza(float[], int[], int, int);

void visualizzaRisultati();

int main() {

    int numeriLanci;

    int lanciFatti[FACCE];
    float frequenze[FACCE];

    printf("\n Introdurre il numero di lanci: ");
    scanf("%d", &numeriLanci);

    lanciaDadi(lanciFatti, numeriLanci, FACCE);

    calcolaFrequenza(frequenze, lanciFatti, numeriLanci, FACCE);

    visualizzaRisultati(frequenze, lanciFatti, FACCE);

    printf("\n\n");
    system("pause");
    return 0;
}

void lanciaDadi(int v[], int volte, int d) {

    int i;
    int lancio;
    srand(time(NULL));

    for (i = 0; i < d; i++) {

        v[i] = 0;
    }

    for (i = 0; i < volte; i++) {

        lancio = rand() % 6 + 1;

        switch (lancio) {
            case 1: {
                v[0]++;
                break;
            }
            case 2: {
                v[1]++;
                break;
            }
            case 3: {
                v[2]++;
                break;
            }
            case 4: {
                v[3]++;
                break;
            }
            case 5: {
                v[4]++;
                break;
            }
            case 6: {
                v[5]++;
                break;
            }
        }
    }
}

void calcolaFrequenza(float freq[], int lanci[], int volte, int d) {

    int i;

    for (i = 0; i < d; i++) {

        freq[i] = (float)lanci[i] / volte;

    }
}

void visualizzaRisultati(float frequenze[], int lanci[], int d) {

    int i;

    printf("\n Valori dado: ");
    for (i = 0; i < d; i++) {
        printf(" %8d", i + 1);
    }

    printf("\n  Estrazioni: ");
    for (i = 0; i < d; i++) {
        printf(" %8d", lanci[i]);
    }

    printf("\n   Frequenze: ");
    for (i = 0; i < d; i++) {
        printf(" %8.2f", frequenze[i]);
    }
}