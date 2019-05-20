#include <stdio.h>
#include "Queue.h"

/**
 * BFS for 7 vertex input graph by using adjacency matrix
 * @param G graph
 * @param start vertex
 * @param n Number of vertices
 */
void BFS(int G[][7], int start, int n){
    int i = start,j;
    Queue* q = queueFactory(7);
    int visited[7] = {0};

    printf("%d ", i);       // visit by printing
    visited[i] = 1;
    enqueue(q,i);

    while( !isEmpty(q) ){
        i = dequeue(q);
        for(j = 1; j < n; j++)
            if(G[i][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q,j);
            }
    }
}

int main() {
    /*
     *          Input Graph
     *
     *               1
     *             /   \
     *            /     \
     *           2       3
     *           \      /
     *            \    /
     *              4
     *            /  \
     *           /    \
     *          5      6
     *
     */
    int G[7][7] = {
                    {0,0,0,0,0,0,0},
                    {0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0},
                };

    BFS(G,4,7);
    printf("\n");
    BFS(G,5,7);
    printf("\n");
    BFS(G,3,7);

    return 0;
}