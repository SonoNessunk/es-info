#include <stdio.h>
#include <string.h>

// costanti per gli Arrey
#define MAX 100
#define MAXNOMI 20
#define MAXMATERIA 20

void ordinaAlfabetico(char[MAX][MAXNOMI], char[MAX][MAXMATERIA], int[MAX], int);
void ordinaDecrescente(int[MAX], int);
void votoMedioStudente(char[MAX][MAXNOMI], int[MAX], int);

int main() {
    int voti[MAX];
    char nomi[MAX][MAXNOMI];
    char materia[MAX][MAXMATERIA];

    char scelta;
    int i = 0;
    int j = 0;

    do {
        printf("\n Gestore Voti Classe\n\n");
        // Input nome dello studente
        printf(" Inserisci il nome dello studente: ");
        scanf("%s", nomi[i]);

        // Input materia
        printf(" Inserisci la materia: ");
        scanf("%s", materia[i]);

        // Input voto dello studente
        printf(" Inserisci il voto dello studente: ");
        scanf("%d", &voti[i]);

        // Domanda se si vuole continuare
        printf("\n Vuoi continuare? (s/n): ");
        scanf(" %c", &scelta);
        system("cls");

        i++;
    } while (scelta == 's' && i < MAX);

    printf("\n\n studenti inseriti\n\n");

    printf(" +-----------------+-----------------+-------+\n");
    printf(" | Studente        | Materia         | Voto  |\n");
    printf(" +-----------------+-----------------+-------+\n");

    for (j = 0; j < i; j++) {
        printf(" | %-15s | %-15s | %5d |\n", nomi[j], materia[j], voti[j]);
        printf(" +-----------------+-----------------+-------+\n");
    }

    // funzione per ordinare in ordine alfabetico
    ordinaAlfabetico(nomi, materia, voti, i);

    // funzione per ordinamento decrescente dei voti
    ordinaDecrescente(voti, i);

    // Calculate and display the average grade
    votoMedioStudente(nomi, voti, i);

    printf("\n\n");
    system("PAUSE");
    return 0;
}

// funzioni per l'ordinamento alfabetico dei nomi
void ordinaAlfabetico(char nomi[MAX][MAXNOMI], char materia[MAX][MAXMATERIA], int voti[MAX], int n) {
    int i;
    int j;
    char tempNome[MAXNOMI];
    char tempMateria[MAXMATERIA];
    int tempVoto;

    // Ordinamento in ordine alfabetico dei nomi
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(nomi[i], nomi[j]) > 0) {
                strcpy(tempNome, nomi[i]);
                strcpy(nomi[i], nomi[j]);
                strcpy(nomi[j], tempNome);

                strcpy(tempMateria, materia[i]);
                strcpy(materia[i], materia[j]);
                strcpy(materia[j], tempMateria);

                tempVoto = voti[i];
                voti[i] = voti[j];
                voti[j] = tempVoto;
            }
        }
    }

    // stampa dei nomi ordinati
    printf("\n Studenti ordinati in ordine alfabetico\n\n");

    printf(" +-----------------+-----------------+-------+\n");
    printf(" | Studente        | Materia         | Voto  |\n");
    printf(" +-----------------+-----------------+-------+\n");
    for (j = 0; j < i; j++) {
        printf(" | %-15s | %-15s | %5d |\n", nomi[j], materia[j], voti[j]);
        printf(" +-----------------+-----------------+-------+\n");
    }
}

// funzione per l'ordinamento decrescente dei voti
void ordinaDecrescente(int voti[MAX], int dim) {
    int i;
    int j;
    int tempVoto = 0;


    // ordinamento dei voti in modo decrescente
    for (i = 0; i < dim - 1; i++) {
        for (j = i + 1; j < dim; j++) {
            if (voti[i] < voti[j]) {
                tempVoto = voti[i];
                voti[i] = voti[j];
                voti[j] = tempVoto;
            }
        }
    }
    // stampa dei voti
    printf("\n\n Voti ordinati in ordine decrescente\n\n");

    for (i = 0; i < dim; i++) {
        printf(" [%d]", voti[i]);
    }
}

// funzione per la media dello studente
void votoMedioStudente(char nomi[MAX][MAXNOMI], int voti[MAX], int dim) {
    int i;
    int conta;
    int somma = 0;
    char studente[MAXNOMI];

    printf("\n inserire nome dello studento di cui si vuole sapere la media\n\n");
    scanf("%s", studente);

    // calcola la media e la stampa
    for (i = 0; i < dim; i++) {
        if (strcmp(nomi[i], studente) == 0) {
            somma += voti[i];
            conta++;
        }
    }

    // controllo se c'è o meno un' studente tramite conta
    if (conta > 0) {
        printf("\n\n Voto medio degli studenti: %.2f\n", (float)somma / conta);
    } else {
        printf("\n Studente non trovato\n");
    }
}
