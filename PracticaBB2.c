#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
void PrintVect(int vect[N], int from, int numel)
{
    int i;
    for (i = from; i < from + numel; i++)
    {
        printf("Element %d: %d\n", i, vect[i]);
    }
}

// Exercici 2:
void PrintRow(int mat[N][N], int row, int from, int numel)
{
    int i;
    for (i = from; i < from + numel; i++)
    {
        printf("Element %d de la fila %d: %d\n", i, row, mat[row][i]);
    }
}

// Exercici 3:
void MultEscalar(int vect[N], int vectres[N], int alfa)
{
    for (int i = 0; i < N; i++)
    {
        vectres[i] = vect[i] * alfa;
    }
}

// Exercici 4:
float Scalar(int vect1[N], int vect2[N])
{
    int resultat = 0;
    for (int i = 0; i < N; i++)
    {
        resultat += vect1[i] * vect2[i];
    }
    return resultat;
}

// Exercici 5:
float Magnitude(int vect[N])
{
    return sqrt(Scalar(vect, vect));
}

// Exercici 6:
float Ortogonal(int vect1[N], int vect2[N])
{
    return Scalar(vect1, vect2) == 0;
}

// Exercici 7:
void Projection(int vect1[N], int vect2[N], int vectres[N])
{
    int resultat_escalar = Scalar(vect1, vect2);
    float resultat_modul = Magnitude(vect2);
    float resultat_divisio = resultat_escalar / resultat_modul;
    MultEscalar(vect2, vectres, resultat_divisio);
}

// Exercici 8
float Infininorm(int M[N][N])
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
float Onenorm(int M[N][N])
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
float NormFrobenius(int M[N][N])
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
int DiagonalDom(int M[N][N])
{
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
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

// Exercici 12
void Matriu_x_Vector(int M[N][N], int vect[N], int vectres[N])
{
    for (int i = 0; i < N; i++)
    {
        vectres[i] = 0;
        for (int j = 0; j < N; j++)
        {
            vectres[i] += M[i][j] * vect[j];
        }
    }
}

// Exercici 13
float Jacobi(int M[N][N], int vect[N], int vectres[N], unsigned iter)
{
    int x_prev[N];
    int i, j, k;

    for (i = 0; i < N; i++)
    {
        vectres[i] = 0.0;
    }

    for (k = 0; k < iter; k++)
    {
        for (i = 0; i < N; i++)
        {
            x_prev[i] = vectres[i];
        }

        for (i = 0; i < N; i++)
        {
            float sigma = 0.0;
            for (j = 0; j < N; j++)
            {
                if (j != i)
                {
                    sigma += M[i][j] * x_prev[j];
                }
            }
            vectres[i] = (vect[i] - sigma) / M[i][i];
        }
    }
    return 1;
}

// Final

int main()
{
    InitData();

    // A
    printf("V1 del 0 al 9 i del 256 al 265:\n");
    PrintVect(v1, 0, 10);
    PrintVect(v1, 256, 10);

    printf("V2 del 0 al 9 i del 256 al 265:\n");
    PrintVect(v2, 0, 10);
    PrintVect(v2, 256, 10);

    printf("V3 del 0 al 9 i del 256 al 265:\n");
    PrintVect(v3, 0, 10);
    PrintVect(v3, 256, 10);

    // B
    printf("Mat fila 0 del 0 al 9:\n");
    PrintRow(Mat, 0, 0, 10);
    printf("Mat fila 100 del 0 al 9:\n");
    PrintRow(Mat, 100, 0, 10);

    // D
    printf("MatDD fila 0 del 0 al 9:\n");
    PrintRow(MatDD, 0, 0, 10);
    printf("MatDD fila 100 del 95 al 104:\n");
    PrintRow(MatDD, 100, 95, 10);

    // D
    printf("Norma infinit de Mat: %.2f\n", Infininorm(Mat));
    printf("Norma 1 de Mat: %.2f\n", Onenorm(Mat));
    printf("Norma de Frobenius de Mat: %.2f\n", NormFrobenius(Mat));
    printf("La matriu Mat %s diagonal dominant\n", DiagonalDom(Mat) ? "és" : "no és");

    printf("Infininorma de MatDD = %.2f\n", Infininorm(MatDD));
    printf("Norma ú de MatDD = %.2f\n", Onenorm(MatDD));
    printf("Norma de Frobenius de MatDD = %.2f\n", NormFrobenius(MatDD));
    printf("La matriu MatDD %s diagonal dominant\n", DiagonalDom(MatDD) ? "és" : "no és");

    // E
    printf("Escalar <V1, V2> = %.2f\n", Scalar(v1, v2));
    printf("Escalar <V1, V3> = %.2f\n", Scalar(v1, v3));
    printf("Escalar <V2, V3> = %.2f\n", Scalar(v2, v3));

    // F
    printf("Magnitud de V1 = %.2f\n", Magnitude(v1));
    printf("Magnitud de V2 = %.2f\n", Magnitude(v2));
    printf("Magnitud de V3 = %.2f\n", Magnitude(v3));

    // G
    printf("V1 i V2 %s ortogonals\n", Ortogonal(v1, v2) ? "són" : "no són");
    printf("V1 i V3 %s ortogonals\n", Ortogonal(v1, v3) ? "són" : "no són");
    printf("V2 i V3 %s ortogonals\n", Ortogonal(v2, v3) ? "són" : "no són");

    // H
    MultEscalar(v3, v4, 2);
    printf("V3 x 2, elements del 0 al 9 i del 256 al 265:\n");
    PrintVect(v4, 0, 10);
    PrintVect(v4, 256, 10);

    // I
    Projection(v2, v3, v4);
    printf("Projecció de V2 sobre V3 (elements 0 a 9):\n");
    PrintVect(v4, 0, 10);

    Projection(v1, v2, v4);
    printf("Projecció de V1 sobre V2 (elements 0 a 9):\n");
    PrintVect(v4, 0, 10);

    // J
    Matriu_x_Vector(Mat, v2, v4);
    printf("Multiplicació de Mat per V2 (elements 0 a 9):\n");
    PrintVect(v4, 0, 10);
}
