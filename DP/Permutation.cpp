#include<stdio.h>
#include<string.h>

int m,n,cur[1000];
bool col[1000];

void permutation(int d)
{
    if(d==(m+1))
    {
        for(int j=1;j<d;j++)
        {
            printf("%d ",cur[j]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(col[i]==1)
        {
            cur[d]=i;
            col[i]=false;
            permutation(d+1);
            col[i]=true;
        }
    }
}

int main()
{
    memset(col,true,sizeof(col));
    scanf("%d %d",&n,&m);
    permutation(1);
    return 0;
}
