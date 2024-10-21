#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Al executar, cal fer ho així: gcc -o exe "NOM ARXIU" -lm

// Definim M
#define N 512

// Introduïm les matrius i els vectors
int Mat[N][N];
int MatDD[N][N];
int v1[N], v2[N], v3[N], v4[N];

// Funció donada:
void InitData()
{
    int i, j;
    srand(334411);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            Mat[i][j] = (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)));
            if ((abs(i - j) <= 3) && (i != j))
                MatDD[i][j] = (((i * j) % 3) ? -1 : 1) * (rand() / (1.0 * RAND_MAX));
            else if (i == j)
                MatDD[i][j] = (((i * j) % 3) ? -1 : 1) * (10000.0 * (rand() / (1.0 * RAND_MAX)));
            else
                MatDD[i][j] = 0.0;
        }

    for (i = 0; i < N; i++)
    {
        v1[i] = (i < N / 2) ? (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX))) : 0.0;
        v2[i] = (i >= N / 2) ? (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX))) : 0.0;
        v3[i] = (((i * j) % 5) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)));
    }
}

// Exercici 1:
void PrintVect(float vect[N], int from, int numel)
{
    // Demanem from i numel i els convertim en variables:
    printf("Introdueix a partir de quina posició vols els nombres del vectors: ");
    scanf("%d", &from);
    printf("Introdueix el nombre d'elements que vols mostrar: ");
    scanf("%d", &numel);

    // declarem la variable i:
    int i = 0;

    // Iniciem un for per imprimir els nombres demanats a partir del nombre "from".
    for (vect[i] = from; i < from + numel; i++)
    {
        printf("Element %d: %f\n", i, vect[i]);
    }
}

// Exercici 2:
void PrintRow(float mat[N][N], int row, int from, int numel)
{
    // Demanem la filera, a partir d'on volem els nombres i la qualtitat de nombres:
    printf("Introdueixi la fila la qual vols agafar els nombres: ");
    scanf("%d", &row);
    printf("Introdueix a partir de quina posició vols els nombres del vectors: ");
    scanf("%d", &from);
    printf("Introdueix el nombre d'elements que vols mostrar: ");
    scanf("%d", &numel);

    int i = 0;

    // Iniciem un for per imprimir els nombres demanats a partir del nombre "from" de la línia 2.
    for (mat[row][i] = from; i < from + numel; i++)
    {
        printf("Element %d de la fila %d: %f\n", i, row, mat[row][i]);
    }
}

// Exercici 3:
