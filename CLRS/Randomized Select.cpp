//Median & order statistics
//selection in linear time

#include<iostream>
#include<stdlib.h>6

using namespace std;

int a[100];

int Randomized_Select(int p,int n,int i);
int Partition(int p,int n);
int Rand_Partition(int p,int n);

int main()
{
    int i,n,piv;
    cout<<"How many num : ";
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    cout<<"The n'th element to choose : "<<endl;
    cin>>piv;
    cout<<Randomized_Select(1,n,piv)<<endl;

}

int Rand_Partition(int p,int n)
{
    int i,j,k,temp;

    k=p-n;
    i=rand()%k+1+p;

    temp=a[i];
    a[i]=a[n];
    a[n]=temp;

    return Partition(p,n);
}
int Randomized_Select(int p,int n,int i)
{
    int q,k;

    if(p==n)
    {
        return a[p];
    }

    q=Rand_Partition(p,n);
    k=q-p+1;

    if(i==k)
    {
        return a[q];
    }

    else if(i<k)
    {
        return  Randomized_Select(p,q-1,i);
    }

    else
    {
        return  Randomized_Select(q+1,n,i-k);
    }

}
int Partition(int p,int n)
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
