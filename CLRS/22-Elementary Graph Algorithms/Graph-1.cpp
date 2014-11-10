#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

#define MAX 100


void BuildAdjMatrix(int Adj[][MAX], int N);
int Outdegree(int Adj[][MAX], int X, int N);
int Indegree(int Adj[][MAX], int X, int N);

void BuildAdjMatrix(int Adj[][MAX], int N)
{
    int i, j;


    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cout<<"Enter 1 If There Is An Edge From "<< i <<" To "<<j<<" Otherwise Enter 0 "<<endl;
            cin>>Adj[i][j];
        }
    }
}

int Outdegree(int Adj[][MAX], int X, int N)
{
    int i;
    int count = 0;

    for(i=0;i<N;i++)
    {
        if(Adj[X][i]==1)
        {
            count++;
        }
    }
    return count;
}

int Indegree(int Adj[][MAX], int X, int N)
{
    int i;
    int count = 0;

    for(i=0;i<N;i++)
    {
        if(Adj[i][X]==1)
        {
            count++;
        }
    }

    return count;
}

int main(int argc, char* argev[])
{
    int Adj[MAX][MAX];
    int Node, N, i;

    cout<<"Enter The Number Of Nodes int The Graph"<<endl;
    cin>>N;

    BuildAdjMatrix(Adj,N);

    for(i=0;i<N;i++)
    {
        cout<<"The Indegree  of Node "<<i<<" Is :  "<<Indegree(Adj, i, N)<<endl;
        cout<<"The Outdegree of Node "<<i<<" Is :  "<<Outdegree(Adj, i, N)<<endl<<endl;
    }

    system("PAUSE");
    return 0;
}

