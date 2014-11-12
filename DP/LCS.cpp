#include<stdio.h>
#include<string.h>
#include<string.h>
#include<iostream>
#define M 105

using namespace std;
int i,j,z,m,c[M][M],n,b[M][M];
char y[M],x[M];
void Print(int i,int j)
{
    if(i==0||j==0)
    return;
    if(b[i][j]==1)
    {
        Print(i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]==2)
    Print(i-1,j);
    else
    Print(i,j-1);
}
int lcs()
{
    memset(c,0,sizeof(c));

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }

        }
    return c[m][n];
}
int main()
{
    while( gets(x))
    {
        gets(y);
        m=strlen(x);
        n=strlen(y);
        lcs();
        Print(m,n);
        cout<<endl;
    }
    return 0;
}
