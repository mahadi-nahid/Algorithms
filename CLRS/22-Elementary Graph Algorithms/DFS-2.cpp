/*--------------------------------
/   DFS code
/--------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;


#define sz 100
#define NIL 0
#define INF 1000000

char Color[100];
long Matrix[sz][sz];
long Distance[sz], Par[sz];
long Fin[sz];

//long Q[sz], Head = 0, Tail = 0;
long Vertex, Edge, Start, End, Unode;
long Time = 0;

void PrintPath(long Start, long End);
void DFS();
void DFS_Visit(long U);

void DFS_Visit(long U)
{
    long Adj;

    Color[U] = 'G';
    Distance[U] = Time = Time++;

    for(Adj=1;Adj<=Vertex;Adj++)
    {
        if(Matrix[U][Adj] == 1)
        {
            if(Color[Adj] == 'W')
            {
                cout<<Adj<<"    ";

                Par[Adj] = U;
                DFS_Visit(Adj);
            }
        }
    }

    Color[U] = 'B';
    Fin[U] = Time = Time++;
}

void DFS()
{
    long Tree  = 0;

    for(Unode=1;Unode<=Vertex;Unode++)
    {
        Color[Unode] = 'W';
        Distance[Unode] = INF;
        Par[Unode] = NIL;
    }

    for(Unode=1;Unode<=Vertex;Unode++)
    {
        if(Color[Unode] == 'W')
        {
            cout<<"Tree " << ++Tree<<endl;
            cout<<Unode<<"    "<<endl;

            DFS_Visit(Unode);

            cout<<endl;
        }
    }
}

void PrintPath(long Start, long End)
{
    if(End==Start)
    {
        cout<<Start;
    }
    else if(Par[End] == NIL)
    {
        cout<<"No Path Exist"<<endl;
    }
    else
    {
        PrintPath(Start,Par[End]);
        cout<<"--->"<<End;
    }
}


int main(int argc, char** argv)
{
    long i;

    cout<<"Give The Number of Vertices and Edges : "<<endl;
    cin>>Vertex>>Edge;

    cout<<"Give The Start Point and End Point of Each vertices : "<<endl;

    for(i=1;i<=Edge;i++)
    {
        cin>>Start>>End;
        Matrix[Start][End] = 1;
        Matrix[End][Start] = 1;
    }

    DFS();

    while(1)
    {
        cout<<"Enter A Starting Point and A Ending Point : "<<endl;
        cin>>Start>>End;

        if(Start == 0 || End == 0) break;

        PrintPath(Start, End);
        cout<<endl;
    }

    system("PAUSE");

    return 0;
}
