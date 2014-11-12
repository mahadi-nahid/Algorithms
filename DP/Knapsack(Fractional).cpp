#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct pp
{
    int w,price;
    double rate;
};
pp aa[100];
bool comp(pp a,pp b)
{
    if(a.rate<b.rate)
        return false;
    return true;
}
int main()
{
    int n,i,j,size;
    double value=0.0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>aa[i].w>>aa[i].price;
        aa[i].rate=aa[i].price/aa[i].w;
    }
    cin>>size;
    sort(aa+1,aa+n,comp);
    for(i=1;i<=n;i++)
    {
        if(size==0)
            break;
        if(aa[i].w>=size)
        {
               value+=size*aa[i].rate;
               size=0;
        }
        else if(aa[i].w<size)
        {
               value+=aa[i].w*aa[i].rate;
               size=size-aa[i].w;
        }
    }
    cout<<value<<endl;
    return 0;

}
/*
5
5 150
2 40
1 100
10 20
5 25
7
*/
