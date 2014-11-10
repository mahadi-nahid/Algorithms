/*---------------------------------------------------
/	Md. Mahadi Hasan Nahid
/   Counting Sort
/*------------------------------------------------*/

#include <iostream>

using namespace std;

void Counting_sort(int [],int B[], int, int);

int main(int argc, char* agrgv)
{
    int n,k = 0, A[15], B[15];

    cout << "Enter the number of input : ";
    cin  >> n;

    cout << "\nEnter the elements to be sorted :\n";
    for ( int i = 1; i <= n; i++)
    {
        cin >> A[i];
        if(A[i] > k)
        {
            k = A[i];
        }
    }

    Counting_sort(A,B, k, n);

    cout << "\nThe Sorted array is : ";
    for(int i = 1; i <= n; i++)
    {
        cout << B[i] << "  " ;
    }


}

void Counting_sort(int A[],int B[],int k, int n)
{
    int i, j;
    int C[100];

    for(i = 0; i <= k; i++)
    {
        C[i] = 0;
    }
    for(j =1; j <= n; j++)
    {
        C[A[j]] = C[A[j]] + 1;
    }
    for(i = 1; i <= k; i++)
    {
        C[i] = C[i] + C[i-1];
    }
    for(j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

}
