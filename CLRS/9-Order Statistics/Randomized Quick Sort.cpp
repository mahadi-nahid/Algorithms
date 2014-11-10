/*---------------------------------------------------
/
/       # No Problem "OK" #
/       #  Done!! #
/
/*------------------------------------------------*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int RandomizedPartition(int*, int, int);
int Partition(int*, int ,int);
void RandomizedQuickSort(int*, int, int);

int main()
{
    int A[100];
    int N;
    int i, j;

    printf("How Many Data: ");
    scanf("%d", &N);

    for(i=1; i<=N; i++)
    {
        scanf("%d", &A[i]);
    }

    RandomizedQuickSort(A,1,N);

    printf("The Sorted Data:\n\n");

    for(i=1; i<=N; i++)
    {
        printf("%d   ", A[i]);
    }

    return 0;
}


int RandomizedPartition(int A[], int P, int R)
{
    int I, K;
    int Temp;

    K = R-P;
    I = rand()%K+1+P;

    if(I>R)
    {
        I -= R;
    }
    else if(I<P)
    {
        I += P;
    }

    Temp = A[P];
    A[P] = A[I];
    A[I] = Temp;

    return Partition(A,P,R);
}

int Partition(int A[], int P, int R)
{
    int X;
    int i, j;
    int Temp;

    X = A[P];

    i = P;

    for(j=P+1; j<=R; j++)
    {
        if(A[j]<=X)
        {
            i++;

            Temp = A[i];
            A[i] = A[j];
            A[j] = Temp;
        }
    }

    Temp = A[P];
    A[P] = A[i];
    A[i] = Temp;

    return i;
}

void RandomizedQuickSort(int A[], int P, int R)
{
    int Q;

    if(P<R)
    {
        Q = RandomizedPartition(A,P,R);

        RandomizedQuickSort(A,P,Q-1);
        RandomizedQuickSort(A,Q+1,R);
    }
}
