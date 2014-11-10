/*----------------------------------
/           
/         Building MaxHeap...
/
/-----------------------------------*/

#include<stdio.h>

void BuildMaxHeap(int*, int);
void MaxHeapify(int*, int, int);
int Parent(int);
int Left(int);
int Right(int);

int main(int argc, char* agrgv)
{
    int A[100];
    int N;
    int i, j;

    scanf("%d", &N);

    for(i=1;i<=N;i++)
    {
        scanf("%d", &A[i]);
    }

    BuildMaxHeap(A,N);

    printf("The Maxheap is:\n\n");

    for(i=1;i<=N;i++)
    {
        printf("%d  ", A[i]);
    }

    return 0;
}

int Parent(int i)
{
        return (int)(i/2);
}

int Left(int i)
{
    return (2*i);
}

int Right(int i)
{
    return (2*i+1);
}

void MaxHeapify(int A[], int i, int n)
{
    int l, r;
    int Largest;
    int Temp;


    l = Left(i);
    r = Right(i);

    if((l <= n) && (A[l] > A[i]))
    {
        Largest = l;
    }
    else
    {
        Largest = i;
    }

    if((r <= n) && (A[r] > A[Largest]))
    {
        Largest = r;
    }
    if(Largest != i)
    {
        Temp = A[i];
        A[i] = A[Largest];
        A[Largest] = Temp;

        MaxHeapify(A,Largest,n);
    }

}


void BuildMaxHeap(int A[], int n)
{
    int p;
    int i;

    p = (int)(n/2);

    for(i=p;i>=1;i--)
    {
        MaxHeapify(A,i,n);
    }
}
