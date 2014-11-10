#include <stdio.h>
#include<stdlib.h>
#include<iostream>


#define MAXVERTICES 20
#define MAXEDGES 20
#define FALSE 0
#define TRUE 1
#define TRISTATE 3

using namespace std;

//typedef enum {FALSE, TRUE, TRISTATE} bool;
typedef struct node node;

int count=0;


struct node
{
    int dst;
    node *next;
};

void printGraph( node *graph[], int nvert )
{
    /*
     * prints the graph.
     */
    int i, j;
    for( i=0; i<nvert; ++i )
    {
        node *ptr;
        for( ptr=graph[i]; ptr; ptr=ptr->next )
            printf( "[%d] ", ptr->dst );
        printf( "\n" );
    }
}

void insertEdge( node **ptr, int dst )
{
    /*
     * insert a new node at the start.
     */
    node *newnode = (node *)malloc( sizeof(node) );
    newnode->dst = dst;
    newnode->next = *ptr;
    *ptr = newnode;
}

void buildGraph( node *graph[], int edges[2][MAXEDGES], int nedges )
{
    /*
     * fills graph as adjacency list from array edges.
     */
    int i;

    for( i=0; i<nedges; ++i )
    {
        insertEdge( graph+edges[0][i], edges[1][i] );
        insertEdge( graph+edges[1][i], edges[0][i] ); // undirected graph.
    }
}

void dfs( int v, int *visited, node *graph[] )
{
    /*
     * recursively traverse graph from v using visited.
     * and mark all the vertices that come in dfs path to TRISTATE.
     */
    node *ptr;

    visited[v] = TRISTATE;
    //printf( "%d \n", v );
    for( ptr=graph[v]; ptr; ptr=ptr->next )
        if( visited[ ptr->dst ] == FALSE )
            dfs( ptr->dst, visited, graph );
}
void printSetTristate( int *visited, int nvert )
{
    /*
     * prints all vertices of visited which are TRISTATE.
     * and set them to TRUE.
     */
    int i;
    printf("\n");

    for( i=0; i<nvert; ++i )
        if( visited[i] == TRISTATE )
        {
            printf( "%d ", i );
            visited[i] = TRUE;
        }
    printf( "\n\n" );
}

void compINC(node *graph[], int nvert)
{
    /*
     * prints all connected components of graph represented using INC lists.
     */
    int *visited;
    int i;

    visited = (int *)malloc( nvert*sizeof(int) );
    for( i=0; i<nvert; ++i )
        visited[i] = FALSE;

    for( i=0; i<nvert; ++i )
        if( visited[i] == FALSE )
        {
            dfs( i, visited, graph );
            // print all vertices which are TRISTATE.
            // and mark them to TRUE.
            printSetTristate( visited, nvert );
            count++;
        }
    free( visited );
}

int main(int argc, char ** argv)
{
    int a, b;

    int edges[MAXEDGES][MAXEDGES] ;

    int nvert = 7; // no of vertices.
    int nedges = 6; // no of edges in the graph.

    printf("Enter the edges: i.e 1 2\n\n");

    //input..
    for(int i=0;i<nedges; ++i)
    {
        scanf("%d%d", &a, &b);
        edges[0][i] = a;
        edges[1][i] = b;

    }


    node **graph = (node **)calloc( nvert, sizeof(node *) );

    buildGraph(graph, edges, nedges); //for builing the graph (list representation)

    printGraph(graph, nvert);//For Print the graph

    compINC(graph, nvert);

    printf("\nTotal Block :   %d\n\n", count);

    return 0;
}
