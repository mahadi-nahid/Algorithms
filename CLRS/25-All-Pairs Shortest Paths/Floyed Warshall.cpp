#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std;

int mat[200][200];
int N, E;
bool color[200][200];
int dis[200][200];

void rezet()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i==j) mat[i][j] = 0;
            else mat[i][j] = (i<<30);
        }
    }
}

void fl()
{
    rezet();
    int i, j ,k;
    for(k=1;k<+N;k++)
    {
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                mat[i][j] = min(mat[i][k]+mat[k][j], mat[i][j]);
            }
        }
    }
}

void view()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout<< mat[i][j]<<"  ";
        }
        puts("\n");
    }
}

int main()
{
    int i, j, k, x, y;
    int t;
    cin>>t;

    while(t--)
    {
        cin>>N>>E;
        int w;
        for(i=1;i<=E;i++)
        {
            cin>>x>>y>>w;

            mat[x][y] = w;
        }
        fl();
        view();
    }


    system("PAUSE");

    return 0;
}
