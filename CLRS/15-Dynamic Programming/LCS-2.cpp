#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>

#define MAX 105

using namespace std;

int C[MAX][MAX],B[MAX][MAX];

int i, j, k;

int M, N;

char X[MAX],Y[MAX];

void Print_LCS(int i,int j)
{
    if(i==0||j==0)
    {
        return;
    }

    if(B[i][j]==1)
    {
        Print_LCS(i-1,j-1);
        cout<<X[i-1];
    }
    else if(B[i][j]==2)
    {
        Print_LCS(i-1,j);
    }
    else
    {
        Print_LCS(i,j-1);
    }
}

int LCS_LENGTH()
{
    memset(C,0,sizeof(C));

    for(i=1; i<=M; i++)
        for(j=1; j<=N; j++)
        {
            if(X[i-1]==Y[j-1])
            {
                C[i][j]=C[i-1][j-1]+1;
                B[i][j]=1;
            }
            else if(C[i-1][j]>=C[i][j-1])
            {
                C[i][j]=C[i-1][j];
                B[i][j]=2;
            }
            else
            {
                C[i][j]=C[i][j-1];
                B[i][j]=3;
            }

        }
    return C[M][N];
}

int main(int argc, char** argv)
{
    char Yes[10];

    strcpy(Yes,"yes");

    while(strcmp(Yes,"yes")==0)
    {
        cout<<"Enter The First String :"<<endl;
        gets(X);
        cout<<"Enter The Second String: "<<endl;
        gets(Y);
        M=strlen(X);
        N=strlen(Y);

        LCS_LENGTH();

        cout<<endl;

        Print_LCS(M,N);
        cout<<endl;
        cout<<"Do You Want To continue Again ?(yes/no) :____"<<endl;
        gets(Yes);
    }

    system("PAUSE");

    return 0;
}

