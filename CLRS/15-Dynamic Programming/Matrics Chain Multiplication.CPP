#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define INF 217000

long q,p[10],m[10][10],s[10][10];
int i,j,k,l,n;

void PrintOptimalParens(int i,int j)
{

    if(i==j)
        printf(" A%d",i);

    else
    {

        printf(" (");
        PrintOptimalParens(i,s[i][j]);

        printf(" *");

        PrintOptimalParens(s[i][j]+1,j);
        printf(" )");

    }

    return;

}

void MatrixChainOrder()
{

    for(l=2; l<=n; l++)
        for(i=1; i<=n-l+1; i++)
        {

            j=i+l-1;
            m[i][j]=INF;

            for(k=i; k<=j-1; k++)
            {

                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];

                if(q<m[i][j])
                {

                    m[i][j]=q;
                    s[i][j]=k;

                }

            }

        }

    return;


}

int main(int argc, char** argv)
{
    printf("how many matrix orders are to be given? :");
    scanf("%d",&n);

    printf("\ngive the order of matrix1 :");
    scanf("%d %d",&p[0],&p[1]);

    for(i=2; i<=n; i++)
    {

        printf("\ngive the order of matrix : %d :",i);
        scanf("%d %d",&l,&p[i]);

        if(p[i-1]!=l)
        {
            printf("incompatible order is given!!!!!");

            exit(0);
        }

    }

    MatrixChainOrder();

    printf("\nthe cost matrix m is shown below:\n");

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(m[i][j]==0)
            {
                printf("      ");
                continue;
            }
            printf("%6ld",m[i][j]);
        }

        printf("\n");
    }

    printf("\nthe path matrix s is shown below:\n");

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(s[i][j]==0)
            {
                printf("      ");
                continue;
            }
            printf("%6ld",s[i][j]);
        }

        printf("\n");
    }


    printf("The matrix chain order is shown below:\n");
    PrintOptimalParens(1,n);
    printf("\n");

}


