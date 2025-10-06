#include <math.h>
#include <stdio.h>

struct point {
    double x;
    double y;
};

typedef struct point Point;

Point leggiPunto();
double distanzaDaOrigine(Point);
double distanzaTraPunti(Point, Point);
int qudrante(Point);
int sonoAllineati(Point, Point, Point);
int insterseca(Point, Point);

void main() {
    Point punto1;
    Point punto2;
    Point punto3;

    int scelta;

    printf("\n Punto 1\n");
    punto1 = leggiPunto();
    printf("\n Punto 2\n");
    punto2 = leggiPunto();
    printf("\n Punto 3\n");
    punto3 = leggiPunto();

    do {

        system("cls");

        printf("\n Punto nel Piano\n");
        printf("\n 1. Distanza del Punto dall'origine");
        printf("\n 2. Distanza tra 2 Punti");
        printf("\n 3. Quadrante del Punto");
        printf("\n 4. Verifica se i tre Punti sono sonoAllineati");
        printf("\n 5. Verifica se il segmento di 2 Punti interseca un asse");
        printf("\n 0. Esci");

        printf("\n\n Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 1: {
                printf("\n Distanza dall'origne del Punto 1: %.2lf", distanzaDaOrigine(punto1));
                printf("\n Distanza dall'origne del Punto 2: %.2lf", distanzaDaOrigine(punto2));
                printf("\n Distanza dall'origne del Punto 3: %.2lf", distanzaDaOrigine(punto3));
                break;
            }

            case 2: {
                printf("\n Distanza tra i Punti 1 & 2: %.2lf", distanzaTraPunti(punto1, punto2));
                printf("\n Distanza tra i Punti 1 & 3: %.2lf", distanzaTraPunti(punto1, punto3));
                printf("\n Distanza tra i Punti 2 & 3: %.2lf", distanzaTraPunti(punto2, punto3));
                break;
            }

            case 3: {
                printf("\n Quadrante del Punto 1: %d", qudrante(punto1));
                printf("\n Quadrante del Punto 2: %d", qudrante(punto2));
                printf("\n Quadrante del Punto 3: %d", qudrante(punto3));
                break;
            }

            case 4: {
                if (sonoAllineati(punto1, punto2, punto3)) {
                    printf("\n I Punti 1, 2 e 3 sono sono allineati");
                } else {
                    printf("\n I Punti 1, 2 e 3 non sono sono allineati");
                }

                break;
            }

            case 5: {
                if (insterseca(punto1, punto2)) {
                    printf("\n La retta dei Punti 1 & 2 interseca gli assi");
                } else {
                    printf("\n La retta dei Punti 1 & 2 non interseca gli assi");
                }

                if (insterseca(punto1, punto3)) {
                    printf("\n La retta dei Punti 1 & 3 interseca gli assi");
                } else {
                    printf("\n La retta dei Punti 1 & 3 non interseca gli assi");
                }

                if (insterseca(punto2, punto3)) {
                    printf("\n La retta dei Punti 2 & 3 interseca gli assi");
                } else {
                    printf("\n La retta dei Punti 2 & 3 non interseca gli assi");
                }

                break;
            }

            case 0: {
                printf("\n Uscita in corso...");

                break;
            }

            default: {
                printf("\n Scelta non valida!");

                break;
            }
        }

        printf("\n\n");
        system("pause");

    } while (scelta != 0);
}

Point leggiPunto() {
    Point p;

    printf(" X: ");
    scanf("%lf", &p.x);
    printf(" Y: ");
    scanf("%lf", &p.y);

    return p;
}

double distanzaDaOrigine(Point p) {
    return sqrt(pow(p.x, 2) + pow(p.y, 2));
}

double distanzaTraPunti(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int qudrante(Point p) {

    if (p.x >= 0 && p.y >= 0) {
        return 1;
    }

    if (p.x <= 0 && p.y >= 0) {
        return 2;
    }

    if (p.x <= 0 && p.y <= 0) {
        return 3;
    }

    if (p.x >= 0 && p.y <= 0) {
        return 4;
    }
}

int sonoAllineati(Point p1, Point p2, Point p3) {
    double retta1;
    double retta2;
    int result;

    retta1 = (p2.y - p1.y) / (p2.x - p1.x);
    retta2 = (p3.y - p2.y) / (p3.x - p2.x);

    if (retta1 == retta2) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}

int insterseca(Point p1, Point p2) {
    int result;

    if (qudrante(p1) == qudrante(p2)) {
        result = 0;
    } else {
        result = 1;
    }

    return result;
}