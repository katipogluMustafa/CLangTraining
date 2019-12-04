#include <stdio.h>
#include <stdlib.h>


// for just now instead of sending int** send int [][7]
void dfs(int G[][7], int n, int* visited,int* count, int i){
    *count += 1;
    visited[i] = *count;
    int j;
    for(j = 1; j < n; j++)
        if( G[i][j] == 1 && visited[j] == 0 )
            dfs(G,n,visited,count,j);
}

// n number of vertices, returns visited array which contains order of nodes traversed
int* DFS(int G[][7], int n){
    int* visited = calloc(n, sizeof(int));
    int count = 0,i;

    for(i = 1; i < n; i++)
        if( visited[i] == 0)                // if unvisited
            dfs(G,n,visited,&count,i);

    return visited;
}


int main() {
    /*
     *          Input Graph
     *
     *               1
     *             /   \        Connected Component 1
     *            /     \
     *           2       3
     *
     *              4
     *            /  \          Connected Component 2
     *           /    \
     *          5      6
     *
     */
    // Using Adjacency Matrix
    int G[7][7] = {
            {0,0,0,0,0,0,0},
            {0,0,1,1,0,0,0},
            {0,1,0,0,0,0,0},
            {0,1,0,0,0,0,0},
            {0,0,0,0,0,1,1},
            {0,0,0,0,1,0,0},
            {0,0,0,0,1,0,0},
    };


    int* visited = DFS(G,7);
    int i;
    for(i = 1; i < 7; i++)
        printf("%d --> %d\n",i,visited[i]);

    return 0;
}