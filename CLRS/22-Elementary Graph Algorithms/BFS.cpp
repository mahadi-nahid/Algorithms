#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std;

vector<int>adj[200];
int N, E;
bool color[200];
int dis[200];

void BFS(int s)
{
    memset(color,0,sizeof(color));
    queue<int>Q;
    Q.push(s);
    dis[s] = 0;

    while(!Q.empty())
    {
        int p=Q.front();
        Q.pop();

        for(int i=0;i<adj[p].size();i++)
        {
            int v=adj[p][i];
            if(!color[v])
            {
                Q.push(v);
                color[v] = 1;
                dis[v] = dis[p]+1;
            }
        }
    }
}

void view(int s)
{
    cout<<"Distance From "<<s<<" is: ";
    cout<<endl;

    for(int i=0;i<N;i++)
    {
        cout<<"Node :"<< i+1<<"-->"<<dis[i]<<endl;
    }
}

int main()
{
    int i, j, k, x, y;
    int t;
    int S;

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

        cin>>S;
        BFS(S);
        view(S);
    }

    system("PAUSE");

    return 0;}
