/*--------------------------------
/
/       # No Problem "OK" #
/
/*-------------------------------*/

#include<stdio.h>
#define SIZE 10

void MatrixRead(int A[][SIZE], int);
void MatrixWrite(int A[][SIZE], int);
void SqureMatrixMultiplication(int A[][SIZE],int B[][SIZE],int C[][SIZE], int);

int main()
{
    int N;
    int i, j;

    printf("What Is The Dimention: ");
    scanf("%d", &N);

    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

    printf("Enter Matrix A:\n\n");
    MatrixRead(A,N);

    printf("Enter Matrix B:\n\n");
    MatrixRead(B,N);

    SqureMatrixMultiplication(A,B,C,N);

    printf("The Product Of These Two Matrix Is:\n\n");
    MatrixWrite(C,N);

    return 0;
}

void MatrixRead(int A[][SIZE], int N)
{
    int i, j;

    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}

void MatrixWrite(int A[][SIZE], int N)
{
    int i, j;

    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void SqureMatrixMultiplication(int A[][SIZE], int B[][SIZE], int C[][SIZE], int Row)
{
    int N;
    N  = Row;

    int i, j, k;

    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            C[i][j] = 0;

            for(k=1;k<=N;k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}




