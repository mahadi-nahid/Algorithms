#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct pp
{
  int s,f,ind;
};
pp ac[100];
bool comp(pp a,pp b)
{
    if(a.f>b.f)
        return false;
    return true;
}
int main()
{
    int m,n,s,k,i,j,ans[100];
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
        {
            cin>>ac[i].s;
            cin>>ac[i].f;
            ac[i].ind=i;
        }
        sort(ac+1,ac+n,comp);
        k=1;
        s=1;
        ans[1]=ac[1].ind;
        for(m=2;m<=n;m++)
            if(ac[m].s>=ac[k].f)
            {
                k=m;
                ans[++s]=ac[m].ind;
            }
            for(i=1;i<=s;i++)
            cout<<ans[i]<<endl;
    }
    return 0;
}
/*11
1 4 3 5 0 6 5 7 3 9 5 9 6 10 8 11 8 12 2 14 12 16
*/
