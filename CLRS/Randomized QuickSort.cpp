//Randomized Quick Sort

#include<iostream>
#include<stdlib.h>

using namespace std;

int a[10];

void quick(int p,int n);
int part(int p,int n);

int main()
{
    int i,n;
    cout<<"How many num : ";
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    quick(1,n);
    cout<<"After sort : "<<endl;
    for(i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}
int Rand_partition(int p,int n)
{
    int i,j,k,temp;
    k=p-n;
    i=rand()%k+1+p;
    temp=a[i];
    a[i]=a[n];
    a[n]=temp;
    return part(p,n);
}
void quick(int p,int n)
{
    int q;
    if(p<n)
    {
        q=Rand_partition(p,n);
        quick(p,q-1);
        quick(q+1,n);
    }
}
int part(int p,int n)
{
    int x,i,j,temp1,temp2;
    x=a[n];
    i=p-1;
    for(j=p;j<=n-1;j++)
    {
        if(a[j]<=x)
        {
            i++;
            temp1=a[i];
            a[i]=a[j];
            a[j]=temp1;
        }
    }
    temp2=a[i+1];
    a[i+1]=a[n];
    a[n]=temp2;
    return i+1;
}
