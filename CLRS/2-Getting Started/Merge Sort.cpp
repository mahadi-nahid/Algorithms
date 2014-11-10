/*--------------------------------
/
/       # No Problem "OK" #
/
/*-------------------------------*/

#include<stdio.h>

void MergeSort(int*, int, int);
void Merge(int*, int, int, int);

int main(int argc, char* agrgv)
{
    int A[100];

    int N;
    int i, j;

    printf("How Many Number: ");
    scanf("%d", &N);

    for(i=1;i<=N;i++)
    {
        scanf("%d", &A[i]);
    }

    MergeSort(A,3,7);

    printf("The Sorted Data:\n\n");
    for(i=1;i<=N;i++)
    {
        printf("%d   ", A[i]);
    }

    return 0;

}


void Merge(int A[], int P, int Q, int R)
{
    int N1, N2;
    int Left[100], Right[100];
    int i, j, k;

    N1 = Q-P+1;
    N2 = R-Q;

    for(i=1;i<=N1;i++)
    {
        Left[i] = A[P+i-1];
    }

    for(i=1;i<=N2;i++)
    {
        Right[i] = A[Q+i];
    }

    Left[N1+1] = 9999999;
    Right[N2+1] = 9999999;

    i = 1;
    j = 1;

    for(k=P;k<=R;k++)
    {
        if(Left[i] <= Right[j])
        {
            A[k] = Left[i];
            i = i+1;
        }

        else
        {
            A[k] = Right[j];
            j = j+1;
        }
    }
}

void MergeSort(int A[], int P, int R)
{
    int Q;

    if(P<R)
    {
        Q = (int)((P+R)/2);

        MergeSort(A,P,Q);
        MergeSort(A,Q+1,R);
        Merge(A,P,Q,R);
    }
}
