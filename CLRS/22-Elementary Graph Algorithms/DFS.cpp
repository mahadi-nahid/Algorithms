#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std;

vector<int>adj[200];
int N, E;
bool col[200];
int dis[200];

void DFS(int s)
{
    col[s] = 1;
    for(int i=0;i<adj[s].size();i++)
    {
        if(!col[adj[s][i]])
        {
            DFS(adj[s][i]);
        }
    }
    return;
}

int main()
{
    int i, j, k, x, y;
    int t;
    cin>>t;

    while(t--)
    {
        cin>>N>>E;

        for(i=0;i<E;i++)
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int cnt = 0;
        memset(col,0,sizeof(col));

        for(i=0;i<+N;i++)
        {
            if(!col[i])
            {
                cnt++;
                DFS(i);
            }
            cout<<"Components :  "<<cnt<<endl;
        }

        cout<<"Components :  "<<cnt<<endl;
    }

    system("PAUSE");

    return 0;
}
