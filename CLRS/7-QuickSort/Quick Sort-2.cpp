/*---------------------------------------------------
/	Md. Mahadi Hasan Nahid
/	Quick Sort
/*------------------------------------------------*/

#include<stdio.h>
using namespace std;

int Partition(int*, int, int);
void QuickSort(int*, int, int);


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

    X=A[R];
    i=P-1;

    for(j=P;j<=R-1;j++)
    {
        if(A[j]<=X)
        {
            i++;
            Temp=A[i];
            A[i]=A[j];
            A[j]=Temp;
        }
    }
    Temp=A[i+1];
    A[i+1]=A[R];
    A[R]=Temp;
    return i+1;

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
