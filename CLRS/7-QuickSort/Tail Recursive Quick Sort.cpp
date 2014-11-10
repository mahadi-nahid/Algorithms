/*---------------------------------------------------
/	Md. Mahadi Hasan Nahid
/   Tail Recursive Quick Sort
/*------------------------------------------------*/

#include<stdio.h>

int Partition(int*, int, int);
void TailRecursiveQuickSrot(int*, int, int);

int main(int argc, char* agrgv)
{
    int A[100];
    int N;
    int i, j;

    printf("How Many Numbers: ");
    scanf("%d", &N);

    for(i=1;i<=N;i++)
    {
        scanf("%d", &A[i]);
    }

    TailRecursiveQuickSrot(A,1,N);

    printf("The Sorted Data:\n\n");

    for(i=1;i<=N;i++)
    {
        printf("%d   ", A[i]);
    }

    return 0;

}

int Partition(int A[], int P, int R)
{
    int X;
    int i, j;
    int Temp;


    X = A[P];

    i = P;

    for(j=P+1;j<=R;j++)
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

void TailRecursiveQuickSrot(int A[], int P, int R)
{
    int Q;

    if(P<R)
    {
        Q = Partition(A,P,R);

        TailRecursiveQuickSrot(A,P,Q-1);
        TailRecursiveQuickSrot(A,Q+1,R);
    }
}
