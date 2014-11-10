#include<stdio.h>

int Max(int,int);
int MemorizedCutRod(int*,int);
int MemorizedCutRodAux(int*,int,int*);


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

int MemorizedCutRod(int P[], int N)
{
    int R[N+5];
    int i;

    for(i=0;i<=N;i++)
    {
        R[i] = -999999;
    }

    return MemorizedCutRodAux(P,N,R);

}

int MemorizedCutRodAux(int P[], int N, int R[])
{
    int Q;

    if(R[N] >= 0)
    {
        return R[N];
    }
    if(N==0)
    {
        Q = 0;
    }
    else
    {
        Q = -99999;

        for(int i=1;i<=N;i++)
        {
            Q = Max(Q, P[i]+MemorizedCutRodAux(P,N-1,R));
        }
    }

    R[N] = Q;

    return Q;

}

int main()
{
    int P[] = {1,5,8,9,10,17,17,20,24,30};
    int N;

    while(scanf("%d", &N)==1)
    {
        printf("Ans = %d\n", MemorizedCutRod(P,N));
    }

    return 0;
}

