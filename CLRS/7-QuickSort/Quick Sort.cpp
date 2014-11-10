/*---------------------------------------------------
/
/       # No Problem "OK" #
/       #  Yahoooo!!! # # Pivot = First Element #
/
/*------------------------------------------------*/

#include<stdio.h>
using namespace std;

int Partition(int*, int, int);
void QuickSort(int*, int, int);


int main()
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

    QuickSort(A,1,N);

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


void QuickSort(int A[], int P, int R)
{
    int Q;

    if(P<R)
    {
        Q = Partition(A,P,R);

        QuickSort(A,P,Q-1);
        QuickSort(A,Q+1,R);
    }
}
