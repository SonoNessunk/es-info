#include <math.h>
#include <stdio.h>

struct point {
    double x;
    double y;
};

typedef struct point Point;

double DistanzaDaOrigine(Point p);
double DistanzaTraPunti(Point p1, Point p2);
int Qudrante(Point p);
int SonoAllineati(Point p1, Point p2, Point p3);
int Insterseca(Point p1, Point p2);

void main() {
    // PROGRAMMA
}

double DistanzaDaOrigine(Point p) {
    return sqrt(pow(p.x, 2) + pow(p.y, 2));
}

double DistanzaTraPunti(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int Qudrante(Point p) {
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

int SonoAllineati(Point p1, Point p2, Point p3) {
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

int Insterseca(Point p1, Point p2) {
    int result;

    if (Qudrante(p1) == Qudrante(p2)) {
        result = 0;
    } else {
        result = 1;
    }

    return result;
}