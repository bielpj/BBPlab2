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
    // Declarem la variable i:
    int i;

    // Iniciem un for per imprimir els nombres demanats a partir del nombre "from".
    for (i = from; i < from + numel; i++)
    {
        printf("Element %d: %f\n", i, vect[i]);
    }
}

// Exercici 2:
void PrintRow(float mat[N][N], int row, int from, int numel)
{
    int i;

    // Iniciem un for per imprimir els nombres demanats a partir del nombre "from" de la fila.
    for (i = from; i < from + numel; i++)
    {
        printf("Element %d de la fila %d: %f\n", i, row, mat[row][i]);
    }
}

// Exercici 3:
void MultEscalar(float vect[N], float vectres[N], float alfa)
{
    for (int i = 0; i < N; i++)
    {
        vectres[i] = vect[i] * alfa;
    }
}

// Exercici 4:
float Scalar(float vect1[N], float vect2[N])
{
    float resultat = 0.0;
    for (int i = 0; i < N; i++)
    {
        resultat += vect1[i] * vect2[i];
    }
    return resultat;
}

// Exercici 5:
float Magnitude(float vect[N])
{
    float resultat = sqrt(Scalar(vect, vect));
    return resultat;
}

// Exercici 6:
int Ortogonal(float vect1[N], float vect2[N])
{
    float resultat = Scalar(vect1, vect2);
    if (resultat == 0)
        return 1;
    else
        return 0;
}

// Exercici 7
void Projection(float vect1[N], float vect2[N], float vectres[N])
{
    float resultat_escalar = Scalar(vect1, vect2);
    float resultat_modul = Magnitude(vect2);
    float resultat_divisio = resultat_escalar / resultat_modul;
    MultEscalar(vect2, vectres, resultat_divisio);
}

// Exercici 8
float Infininorm(float M[N][N])
{
    float max_suma = 0.0;
    for (int i = 0; i < N; i++)
    {
        float suma_linia = 0.0;
        for (int j = 0; j < N; j++)
        {
            suma_linia += fabs(M[i][j]);
        }
        if (suma_linia > max_suma)
            max_suma = suma_linia;
    }
    return max_suma;
}

// Exercici 9
float Onenorm(float M[N][N])
{
    float max_suma = 0.0;
    for (int i = 0; i < N; i++)
    {
        float suma_columna = 0.0;
        for (int j = 0; j < N; j++)
        {
            suma_columna += fabs(M[j][i]);
        }
        if (suma_columna > max_suma)
            max_suma = suma_columna;
    }
    return max_suma;
}

// Exercici 10
float NormFrobenius(float M[N][N])
{
    float sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum += M[i][j] * M[i][j];
        }
    }
    return sqrt(sum);
}

// Exercici 11
int DiagonalDom(float M[N][N])
{
    for (int i = 0; i < N; i++)
    {
        float sum = 0.0;
        for (int j = 0; j < N; j++)
        {
            if (i != j)
                sum += fabs(M[i][j]);
        }
        if (fabs(M[i][i]) < sum)
            return 0;
    }
    return 1;
}
