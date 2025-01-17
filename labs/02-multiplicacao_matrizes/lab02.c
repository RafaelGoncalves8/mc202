/* Lab 02 - Multiplicacao de matrizes
 * Rafael Goncalves
 *
 * O objetivo do programa é imprimir os elementos de A*B onde A é a
 * matriz de permutacao criada a partir do vetor dado p e B é a
 * matriz dada como entrada, ambas de dimensao n.*/


#include <stdio.h>


/* dimensao maxima das matrizes */
#define N 312


void create_permutation_matrix(int p[], int A[][N], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (p[j] == i+1)
                A[i][j] = 1;
            else
                A[i][j] = 0;
        }
    }
}


void print_matrix_multiplication (int A[][N], double B[][N],
                                         int n) {
    int i, j, k;
    double c;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c = 0;
            for (k = 0; k < n; k++)
                c += A[i][k]  * B[k][j];
            if (j == n-1)
                printf("%.1f\n", c);
            else
                printf("%.1f ", c);
        }
    }
}


int main(){
    int i, j;
    int n;             /* dimensao das matrizes */
    int p[N];          /* vetor de permutacao */
    int A[N][N];       /* matriz de permutacao */
    double B[N][N];    /* matriz B que sera lida */

    /* leitura de variáveis */
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &B[i][j]);

    /* cria a matriz de permutacao A a partir do vetor p */
    create_permutation_matrix(p, A, n);

    /* calcula e imprime a matriz A*B */
    print_matrix_multiplication(A, B, n);

    return 0;
}
