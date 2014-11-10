/*---------------------------------------------------
/
/       # No Problem "OK" #
/       # But Not Able To Find The Position #
/
/*------------------------------------------------*/

#include<stdio.h>

int FindMaximumSubArray(int*, int, int);
int FindMaxCrossingSubArray(int*, int, int, int);

int L_Low, L_High, R_Low, R_High, C_Low, C_High;

int main()
{
    int A[100];
    int N;
    int i,j;
    int MaxSum;

    printf("How Many Number: ");
    scanf("%d", &N);

    for(i=1;i<=N;i++)
    {
        scanf("%d", &A[i]);
    }

    MaxSum = FindMaximumSubArray(A,1,N);

    printf("Max Sum = %d",MaxSum);

    return 0;
}

int FindMaximumSubArray(int A[], int Low, int High)
{
    int L_Sum, R_Sum, C_Sum;
    int Mid;

    if(High == Low)
    {
        return A[Low];
    }

    else
    {
        Mid = (int)((Low+High)/2);

        L_Sum = FindMaximumSubArray(A,Low,Mid);
        R_Sum = FindMaximumSubArray(A,Mid+1,High);
        C_Sum = FindMaxCrossingSubArray(A,Low,Mid,High);

        if(L_Sum >= R_Sum && L_Sum >= C_Sum)
        {
            return L_Sum;
        }

        else if(R_Sum >= L_Sum && R_Sum >= C_Sum)
        {
            return R_Sum;
        }

        else
        {
            return C_Sum;
        }

    }
}

int FindMaxCrossingSubArray(int A[], int Low, int Mid, int High)
{
    int LeftSum, RightSum, Sum;
    int i, j;

    LeftSum = -9999999;
    Sum = 0;

    for(i=Mid;i>=Low;i--)
    {
        Sum += A[i];

        if(Sum > LeftSum)
        {
            LeftSum = Sum;
        }
    }

    RightSum = -999999;
    Sum = 0;

    for(j=Mid+1;j<=High;j++)
    {
        Sum += A[j];

        if(Sum > RightSum)
        {
            RightSum = Sum;
        }
    }

    return (LeftSum+RightSum);
}
