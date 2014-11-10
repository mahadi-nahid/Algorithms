/*--------------------------------
/
/       # No Problem "OK" #
/
/*-------------------------------*/

#include<stdio.h>

void InsertionSort(int*, int);

int main()
{
    int A[100];
    int N;
    int i, j;

    printf("How Many Number: ");
    scanf("%d", &N);

    for(i=1; i<=N; i++)
    {
        scanf("%d", &A[i]);
    }


    InsertionSort(A,N);

    printf("The Sorted Data:\n\n");

    for(i=1; i<=N; i++)
    {
        printf("%d   ", A[i]);
    }

    return 0;
}


void InsertionSort(int A[], int N)
{
    int Key;
    int i, j;

    for(j=2; j<=N; j++)
    {
        Key = A[j];

        i = j-1;

        while(i>0 && A[i]>Key)
        {
            A[i+1] = A[i];
            i=i-1;
        }

        A[i+1] = Key;
    }
}

