#include<iostream>
#include<string.h>

using namespace std;
void Fibonacci(int flag);
long long mat[2][2],stdi[2][2],temp[2][2],z=0,ans[2][2];

int main()
{
    long long a[50],b,x,c,d,m,n,i,j,flag;

    mat[0][0]=0;
    mat[1][0]=1;
    mat[0][1]=1;
    mat[1][1]=1;

    stdi[0][0]=0;
    stdi[1][0]=1;
    stdi[0][1]=1;
    stdi[1][1]=1;

    cin>>n;
    x=0;

    while(n>0)
    {
        a[x++]=n%2;
        n/=2;
    }
    x--;
    if(a[0])
    {
        z=1; //It is a global variable...
    }

    for(c=1; c<=x; c++)
    {
        flag=a[c];
        Fibonacci(flag);
    }

    cout<<ans[1][1]<<endl;

    return 0;
}

void Fibonacci(int flag)
{
    long long i,j,k;

    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            temp[i][j]=0;
            for(k=0; k<2; k++)
            {
                temp[i][j]+=mat[i][k]*mat[k][j];
            }
        }
    }

    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            mat[i][j]=temp[i][j];
        }
    }

    if(flag)
    {
        z++;
        if(z==1)
        {
            for(i=0; i<2; i++)
            {
                for(j=0; j<2; j++)
                {
                    stdi[i][j]=mat[i][j];
                }
            }
        }
        else
        {
            for(i=0; i<2; i++)
            {
                for(j=0; j<2; j++)
                {
                    ans[i][j]=0;
                    for(k=0; k<2; k++)
                    {
                        ans[i][j]+=mat[i][k]*stdi[k][j];
                    }
                }
            }

            for(i=0; i<2; i++)
            {
                for(j=0; j<2; j++)
                {
                    stdi[i][j]=ans[i][j];
                }
            }
        }
    }

    if(z==1)
    {
        ans[1][1]=mat[1][1];
    }

}

