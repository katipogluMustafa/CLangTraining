#include <stdio.h>
#include "Stack.h"

/**
 * Depth First Search by using adjacency matrix
 * @param G the graph
 * @param start starting vertex
 * @param n number of vertices
 */
void DFS(int G[][7], int start, int n){
    int j;
    static int visited[7] = {0};

    if( visited[start] == 0 ){      // if not visited
        printf("%d ", start);       // visit by printing out
        visited[start] = 1;
        for(j = 1; j <= n; j++ )                      // explore
            if( G[start][j] == 1 && visited[j] != 1 )
                DFS(G,j,n);
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

    DFS(G, 4, 7);

    return 0;
}