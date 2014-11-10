/*---------------------------------------------------
/	Md. Mahadi Hasan Nahid
/   Radix Sort
/*------------------------------------------------*/

#include <stdio.h>
#define MAX 100

void print(int *a,int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
}

void radixsort(int *a,int n)
{
    int i,b[MAX],m=0,exp=1;

    for(i=0; i<n; i++)  //For Counting Sort..
    {
        if(a[i]>m)
            m=a[i];
    }

    while(m/exp>0)
    {
        int array[10]= {0};
        for(i=0; i<n; i++)
            array[a[i]/exp%10]++;
        for(i=1; i<10; i++)
            array[i]+=array[i-1];
        for(i=n-1; i>=0; i--)
            b[--array[a[i]/exp%10]]=a[i];
        for(i=0; i<n; i++)
            a[i]=b[i];
        exp*=10;

        printf("\nPASS   : ");
        print(a,n);

    }
}


int main(int argc, char* agrgv)
{
    int arr[MAX];
    int i,n;

    printf("Enter totalnumber of elements (n < %d) : ",MAX);
    scanf("%d",&n);

    printf("Enter %d Elements : ",n);
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);


    printf("\nARRAY ELEMENTS ARE : ");
    print(&arr[0],n);

    radixsort(&arr[0],n);

    printf("\nSORTED ELEMENTS ARE: ");
    print(&arr[0],n);
    printf("\n");

    return 0;
}


