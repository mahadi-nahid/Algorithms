#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int p[100],n,m[10][10],s[10][10];
void Print(int i,int j)
{
    if(i==j)
    cout<<"A"<<i;
    else{
        cout<<"(";
        Print(i,s[i][j]);
        Print(s[i][j]+1,j);
        cout<<")";
    }

}
void MCM()
{
    int i,j,k,l,q;
    for(i=1;i<=n;i++)
    m[i][i]=0;
    for(l=2;l<=n;l++)
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=1000000;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }

}
int main()
{
    int i,j,k;
    cin>>n;
    k=n+1;
    for(i=0;i<k;i++)
    cin>>p[i];
    MCM();
    Print(1,n);
    return 0;
}
