#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

#define INF 217000
#define Max 100

int  P[15],M[Max][Max],S[Max][Max];
int N, Q;
int i,j,k,l;

void PrintOptimalParens(int i,int j);
void MatrixChainOrder();
void PrintPathMAtrix();
void PrintCostMatrix();


void PrintCostMatrix()
{
    cout<<"\nThe Cost Matrix M Is Shown Below :" <<endl;

    cout<<"     1";
    for(i=2;i<=N;i++)
    {
        cout<<"-----"<<i;
    }
    cout<<endl;
    for(i=1; i<=N; i++)
    {

        for(j=1; j<=N; j++)
        {
            if(M[i][j]==0)
            {
                printf("      ");
                continue;
            }
            printf("%6ld",M[i][j]);
        }

        cout<<"    ---i";
        printf("\n");
    }

}
void PrintPathMAtrix()
{
    printf("\nthe path matrix s is shown below:\n");
    cout<<"     1";
    for(i=2;i<=N;i++)
    {
        cout<<"-----"<<i;
    }
    cout<<endl;
    for(i=1; i<=N; i++)
    {

        for(j=1; j<=N; j++)
        {
            if(S[i][j]==0)
            {
                printf("      ");
                continue;
            }
            printf("%6ld",S[i][j]);
        }

        cout<<"    ---i";
        printf("\n");
    }

}
void PrintOptimalParens(int i,int j)
{

    if(i==j)
        printf(" A%d",i);

    else
    {

        printf(" (");
        PrintOptimalParens(i,S[i][j]);

        printf(" *");

        PrintOptimalParens(S[i][j]+1,j);
        printf(" )");

    }

    return;

}

void MatrixChainOrder()
{

    for(l=2; l<=N; l++)
        for(i=1; i<=N-l+1; i++)
        {

            j=i+l-1;
            M[i][j]=INF;

            for(k=i; k<=j-1; k++)
            {

                Q=M[i][k]+M[k+1][j]+P[i-1]*P[k]*P[j];

                if(Q<M[i][j])
                {

                    M[i][j]=Q;
                    S[i][j]=k;

                }

            }

        }

    return;


}

int main(int argc, char** argv)
{
    cout<<"How many matrix orders are to be given? : ";
    cin>>N;

    cout<<"\ngive the order of matrix : 1 : ";
    cin>>P[0]>>P[1];

    for(i=2; i<=N; i++)
    {

        cout<<"\ngive the order of matrix : "<<i<<" : ";
        cin>>l>>P[i];

        if(P[i-1]!=l)
        {
            cout<<"Incorrect (invalid) Order Is Given!!!!!"<<endl;

            exit(0);
        }

    }

    MatrixChainOrder();

    PrintCostMatrix();
    PrintPathMAtrix();



    printf("The matrix chain order is shown below:\n");

    PrintOptimalParens(1,N);


    system("PAUSE");
    printf("\n");

}


