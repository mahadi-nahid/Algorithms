/*Dijkstra's Algorithm by chormen*/
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NIL 0
#define sz 51
#define INF 100000

#define Parent(i) (i>>1)
#define Left(i) (i<<1)
#define Right(i) (i<<1)+1

long source,vertex,flag[sz];
long adj[sz],dist[sz],par[sz];
long adjMat[sz][sz],costMat[sz][sz];

long heap[sz*25],heap_size;

void InitializeSingleSource()
{
    long ind;

    for(ind=1; ind<=vertex; ind++)
    {
        dist[ind]=INF;
        par[ind]=NIL;
    }
}

void Insert(long node, long key)
{
    long ind;

    heap_size+=1;
    ind=heap_size;

    while(ind>1 && dist[heap[Parent(ind)]]>key)
    {
        heap[ind]=heap[Parent(ind)];


        ind=Parent(ind);
    }

    heap[ind]=node;
}

void Heapify(long ind)
{
    long smallest,left,right,temp;

    left=Left(ind);
    right=Right(ind);

    if(left<=heap_size && dist[heap[left]]<dist[heap[ind]])
        smallest=left;
    else
        smallest=ind;

    if(right<=heap_size && dist[heap[right]]<dist[heap[smallest]])
        smallest=right;

    if(smallest!=ind)
    {
        temp=heap[smallest];
        heap[smallest]=heap[ind];
        heap[ind]=temp;

        Heapify(smallest);
    }
}

long ExtractMin()
{
    long uNode,weight;

    uNode=heap[1];
    weight=dist[heap[1]];

    heap[1]=heap[heap_size];
    heap_size-=1;

    Heapify(1);
    return uNode;
}

void Relax(long uNode, long vNode, long weight)
{
    if(dist[vNode]>dist[uNode]+weight)
    {
        Insert(vNode,weight);

        par[vNode]=uNode;
        dist[vNode]=dist[uNode]+weight;
    }
}

void Dijkstra()
{
    long uNode,vNode,weight,ind;

    InitializeSingleSource();

    scanf("%ld",&source);
    dist[source]=0;

    heap_size=0;
    memset(flag,0,sizeof(0));

    Insert(source,0);

    while(heap_size>0 && flag[0]<=vertex)
    {
        uNode=ExtractMin();
        if(flag[uNode])
            continue;
        flag[0]+=1;
        flag[uNode]=1;

        for(ind=1; ind<=adj[uNode]; ind++)
        {
            vNode=adjMat[uNode][ind];
            if(flag[vNode])
                continue;

            weight=costMat[uNode][vNode];
            Relax(uNode,vNode,weight);
        }
    }
}


int main(int argc, char** argv)
{
    long ind,cost,uNode,vNode,edges,kase=0;
    printf("Enter number of vertices: ");
    while(scanf("%ld",&vertex)==1)
    {
        printf("Enter number of edges: ");
        scanf("%ld",&edges);
        for(ind=1; ind<=edges; ind++)
        {
            scanf("%ld %ld",&uNode,&vNode);
            scanf("%ld",&cost);

            adj[uNode]+=1;
            adjMat[uNode][adj[uNode]]=vNode;
            costMat[uNode][vNode]=cost;
        }

        Dijkstra();

        printf("Graph %ld : The shortest distance from sources to all:\n",++kase);
        for(ind=1; ind<=vertex; ind++)
        {
            if(ind==source) continue;
            printf("Node %ld is at distance %ld\n",ind,dist[ind]);
        }
    }

    system("PAUSE");

    return 0;
}
