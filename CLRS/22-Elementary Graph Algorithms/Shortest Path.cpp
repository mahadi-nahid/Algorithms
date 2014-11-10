#include <stdio.h>
#include<stdlib.h>
#include<iostream>


//#define MAXVERTICES 20
#define MAXEDGES 20
#define FALSE 0
#define TRUE 1
#define TRISTATE 3
#define MAXINT 99999
#define MAXVERTICES 10


typedef struct node node;
typedef struct setnode setnode;
//typedef enum {FALSE, TRUE} bool;

struct node
{
    int dst;
    int cost;
    node *next;
};

struct setnode
{
    int v;
    setnode *next;
};

void printGraph( node *cost[], int nvert )
{
    /*
     * prints the graph.
     */
    int i, j;

    for( i=0; i<nvert; ++i )
    {
        node *ptr;
        for( ptr=cost[i]; ptr; ptr=ptr->next )
            printf( "[%d,%d] ", ptr->dst, ptr->cost );
        printf( "\n" );
    }
}

void insertEdge( node **ptr, int dst, int cost )
{
    /*
     * insert a new node at the start.
     */
    node *newnode = (node *)malloc( sizeof(node) );
    newnode->dst = dst;
    newnode->cost = cost;
    newnode->next = *ptr;
    *ptr = newnode;
}

void buildGraph( node *cost[], int costnew[][3], int nedges )
{
    /*
     * fills cost as adjacency list from array costnew.
     */
    int i;
    for( i=0; i<nedges; ++i )
        insertEdge( cost+costnew[i][0], costnew[i][1], costnew[i][2] );
}

int choose( int dist[], setnode *s )
{
    /*
     * returns vertex u such that:
     * dist[u] = min{ dist[w] } where w is in set s.
     */
    int u=-1;
    int mindist = MAXINT;
    setnode *ptr;

    for( ptr=s->next; ptr; ptr=ptr->next )
        if( dist[ptr->v] <= mindist )
            u=ptr->v, mindist=dist[ptr->v];
    return u;
}

int getCost( node **cost, int src, int dst )
{
    /*
     * return cost of edge from src to dst.
     */
    node *ptr;
    for( ptr=cost[src]; ptr; ptr=ptr->next )
        if( ptr->dst == dst )
            return ptr->cost;
    return MAXINT;
}

void removeFromSet( setnode *s, int v )
{
    /*
     * remove vertex v from set s.
     */
    setnode *prev, *ptr;
    for( prev=s, ptr=prev->next; ptr; prev=ptr, ptr=ptr->next )
        if( ptr->v == v )
        {
            prev->next = ptr->next;
            free(ptr);
            return;
        }
    // v does NOT exist in the set.
}

void insertIntoSet( setnode *s, int v )
{
    /*
     * add vertex v to the set s.
     */
    setnode *ptr = (setnode *)malloc( sizeof(setnode) );
    ptr->v = v;
    ptr->next = s->next;
    s->next = ptr;
}

bool isInSet( setnode *s, int v )
{
    /*
     * returns TRUE if vertex v is in set s.
     */
    setnode *ptr;
    for( ptr=s->next; ptr; ptr=ptr->next )
        if( ptr->v == v )
            return TRUE;
    return FALSE;
}

void sssp( int v, node **cost, int dist[], int nvert )
{
    /*
     * finds shortest path from v to all other vertices.
     * cost is the cost adjacency list.
     * dist is the vector in which output will be written.
     * nvert is no of vertices in the graph.
     */
    setnode s; // list of vertices yet to be considered.
    int i, u, num, w;
    node *ptr;

    for( i=0; i<nvert; ++i )
    {
        insertIntoSet( &s, i );
        dist[i] = MAXINT;
    }
    for( ptr=cost[v]; ptr; ptr=ptr->next )
        dist[ptr->dst] = ptr->cost;

    removeFromSet( &s, v );
    dist[v] = 0;
    num = 1;

    while( num < nvert-1 )
    {
        u = choose( dist, &s );
        removeFromSet( &s, u );
        num++;
        for( w=0; w<nvert; ++w )
        {
            int c = getCost( cost, u, w );
            if( isInSet( &s, w ) && dist[u]+c < dist[w] )
                dist[w] = dist[u] + c;
        }
    }
}

void printDist( int v, int dist[], int nvert )
{
    /*
     * prints min dist vector.
     */
    int i;

    printf( "min dist from vertex %d...\n", v );
    for( i=0; i<nvert; ++i )
        printf( "dist[%d]=%d.\n", i, dist[i] );
}

int main()
{
    int costnew[][3] =      {                        {0,1,50},
        {0,2,10},
        {0,4,45},
        {1,2,15},
        {1,4,10},
        {2,0,20},
        {2,3,15},
        {3,1,20},
        {3,4,35},
        {4,3,30},
        {5,3,3}
    };
    int dist[MAXVERTICES];
    int nvert = 6;          // no of vertices.
    int nedges = 11;  // no of edges in costnew.
    node **cost = (node **)calloc( nvert, sizeof(node *) );

    buildGraph( cost, costnew, nedges );
    printGraph( cost, nvert );

    sssp( 2, cost, dist, nvert );

    printDist( 2, dist, nvert );

    return 0;
}
