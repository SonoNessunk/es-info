#include <stdio.h>

#define MAX 30

void insert(int[], int);
void intersezione(int[], int[], int, int);

int main() {

    int vettore[MAX];
    int vettore2[MAX];
    int dim1;
    int dim2;

    printf("\n Inserisci la dimensione del primo vettore: ");
    scanf("%d", &dim1);

    insert(vettore, dim1);

    printf("\n Inserisci la dimensione del secondo vettore: ");
    scanf("%d", &dim2);

    insert(vettore2, dim2);

    intersezione(vettore, vettore2, dim1, dim2);

    system("pause");
    return 0;
}

void insert(int vettore[], int dim) {
    int i;
    for (i = 0; i < dim; i++) {
        printf(" Inserisci un numero: ");
        scanf("%d", &vettore[i]);
    }
}

void intersezione(int vettore[], int vettore2[], int dim1, int dim2) {
    int i;
    int j;
    int k = 0;
    int vettore3[MAX];
    int conta = 0;

    for (i = 0; i < dim1; i++) {
        for (j = 0; j < dim2; j++) {
            if (vettore[i] == vettore2[j]) {
                vettore3[k] = vettore[i];
                k++;
            }
        }
    }

    for (i = 0; i < k; i++) {
        printf(" [%d]", vettore3[i]);
    }
}