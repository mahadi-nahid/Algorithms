/*--------------------------
|
|       BFS Code
|
\*------------------------------------*/


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

long Q[sz], Head = 0, Tail = 0;
long Vertex, Edge, Start, End, Unode;

void BSF();
void PrintPath();
void Enqueue(long);
long Dequeue();

void Enqueue(long Data)
{
    Q[Tail] = Data;
    Tail++;
}

long Dequeue()
{
    if(Head==Tail) return -1;
    Head++;
    return Q[Head-1];
}

void BFS()
{
    long Adj;

    for(Unode=1;Unode<=Vertex;Unode++)
    {
        Color[Unode] = 'W';
        Distance[Unode] = INF;
        Par[Unode] = NIL;
    }

    Color[Start] = 'G';
    Distance[Start] = 0;
    Par[Start] = NIL;

    Enqueue(Start);

    while(Head!=Tail)
    {
        Unode = Dequeue();

        for(Adj=1;Adj<=Edge;Adj++)
        {
            if(Matrix[Unode][Adj]==1)  // There is A Path Between Unode To Adj
            {
                if(Color[Adj] == 'W')
                {
                    Color[Adj] = 'G';
                    Distance[Adj] = Distance[Unode]+1;
                    Par[Adj] = Unode;
                    Enqueue(Adj);
                }
            }
        }

        Color[Unode] = 'B';
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

    while(1)
    {
        cout<<"Enter A Starting Point and A Ending Point : "<<endl;
        cin>>Start>>End;

        if(Start == 0 || End == 0) break;

        BFS();

        cout<<"The Distance Between Node " << Start<< " to Node "<< End<<" is : "<<Distance[End]<< endl;
        cout<<"The Path is Shown Below : "<<endl;

        PrintPath(Start,End);

        cout<<endl;

    }

    system("PAUSE");

    return 0;
}






