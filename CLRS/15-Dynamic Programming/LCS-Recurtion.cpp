#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int i = 0, j, k, sz1, sz2, sz3;

char S1[100], S2[100], S3[100];
int n = 0;


int lcs(int sz1, int sz2)
{
    if(sz1<0 || sz2<0) return 0;

    else
    {
        if(S1[sz1] == S2[sz2])
        {
            S3[sz1--] = S1[sz1];
            //printf("---%c", S1[sz1]);

            n = lcs(sz1-1, sz2-1) + 1;
        }
        else
        {
            n = max(lcs(sz1,sz2-1), lcs(sz1-1,sz2));
        }


    }

    return n;
}



int main()
{

    gets(S1);
    gets(S2);

    sz1 = strlen(S1);
    sz2 = strlen(S2);


    n = lcs(sz1,sz2);

    printf("\n\n -----::::: %d\n", n-1);

    for(j=n;j>=0;j--)
    {
        printf("%c", S3[j]);
    }


}
