#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define MAX 100

bool B[MAX][MAX];

int C[MAX][MAX];

int i, j, k;
char X[MAX], Y[MAX];

void LCS_Length(int M, int N);
void Print_LCS(int i, int j);

void Print_LCS(int i, int j)
{
    if(i==0 || j==0)
    {
        return;
    }

    if(B[i][j]==1)
    {
        Print_LCS(i-1,j-1);
        printf("%c ", X[i-1]);
    }

    else if(B[i][j] == 2)
    {
        Print_LCS(i-1,j);
    }
    else
    {
        Print_LCS(i, j-1);
    }

}

void LCS_Length(int M, int N)
{

    for(i=0;i<M;i++)
    {
        C[i][0] = 0;
    }
    for(i=0;i<N;i++)
    {
        C[0][i] = 0;
    }

    for(i=1;i<=M;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(X[i-1] == Y[j-1])
            {
                C[i][j] = C[i-1][j-1]+1;
                B[i][j] = 1;
            }
            else if(C[i-1][j]>=C[i][j-1])
            {
                C[i][j] = C[i-1][j];
                B[i][j] = 2;
            }
            else
            {
                C[i][j] = C[i][j-1];
                B[i][j] = 3;
            }
        }
    }
}

int main(int argc, char** argv)
{

    gets(X);
    gets(Y);

    int M, N;

    N = strlen(X);
    M = strlen(Y);

    LCS_Length(M,N);
    Print_LCS(i,j);


    system("PAUSE");
    return 0;
}
