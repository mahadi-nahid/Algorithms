#include<stdio.h>

int Max(int A, int B)
{
    if(A>B)
    {
        return A;
    }
    else
    {
        return B;
    }
}

int CutRod(int P[],int N)
{
    int Q;
    int i;

    if(N==0)
    {
        return 0;
    }
    Q = -9999999;

    for(i=1;i<=N;i++)
    {
        Q = Max(Q,P[i]+CutRod(P,N-1));
    }

    return Q;
}

int main()
{
    int P[] = {1,5,8,9,10,17,17,20,24,30};
    int N;

    while(scanf("%d", &N)==1)
    {
        printf("Ans = %d\n", CutRod(P,N));
    }

    return 0;
}
