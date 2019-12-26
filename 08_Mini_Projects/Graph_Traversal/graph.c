//
// Created by Yukawa on 2019-12-14.
//
#include "def.h"

NODE* NodeFactory(long vertex) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->vertex = vertex;
    new_node->next = NULL;
    new_node->last_parent = NULL;
    return new_node;
}

// Insert one by one each artist and movie into hash table
// later we will be using hash as the vertex number in the graph
// Returns total number of vertices to be inserted into the graph
int Insert_Movies_Artists_IntoHT(MOVIES* in_movies, HASH_TABLE* ht){
    char** artists;
    char** movies;
    int artists_size, movies_size;

    // Insert each artists into the hash table
    artists = getAllArtists(in_movies);
    artists_size = count_artists(artists);
    insertArtistsIntoHT(ht,artists,artists_size);

    // Insert each movie into the hash table
    movies = getAllMovies(in_movies);
    movies_size = MAX_NO_OF_MOVIES;                     // Limited by macro for now
    insertMoviesIntoHT(ht,movies,MAX_NO_OF_MOVIES);

    return artists_size + movies_size;
}

GRAPH* GraphFactory(int no_of_vertices){
    GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
    graph->no_of_vertices = no_of_vertices;
    graph->adj_list = (NODE**)malloc(graph->no_of_vertices * sizeof(NODE*));

    int i;
    for(i = 0; i < no_of_vertices; i++)
        graph->adj_list[i] = NULL;

    return  graph;
}

// Given vertex numbers, connect them in the adjacency list of the given graph
void AddEdge(GRAPH* graph, long srcVertex, long destVertex){

    // Add edge from source to destination
    NODE* new_node = NodeFactory(destVertex);
    new_node->next = graph->adj_list[srcVertex];
    graph->adj_list[srcVertex] = new_node;

    // Add edge from destination to source
    new_node = NodeFactory(srcVertex);
    new_node->next = graph->adj_list[destVertex];
    graph->adj_list[destVertex] = new_node;
}

void LinkMoviesAndArtists(GRAPH* graph, MOVIES* in_movies, HASH_TABLE* ht){
    int i,j;
    int no_of_artists_inside_movie;         // Total number of movies to be inserted into the graph

    char* curr_artist;                      // Current Artist name that we want to make connection in the graph
    long curr_artist_hash;                  // Hash will be id of the artist, so we use hash as vertex number


    char* curr_movie;                       // Current Movie name that we want to make connection in the graph
    long curr_movie_hash;                   // current movie vertex number in the graph

    for(i = 0; i < MAX_NO_OF_MOVIES; i++){
        curr_movie = in_movies->arr[i]->title;
        curr_movie_hash = getHash(ht, curr_movie);
        no_of_artists_inside_movie = in_movies->arr[i]->size;

        for(j = 0; j < no_of_artists_inside_movie; j++){
            curr_artist = in_movies->arr[i]->actors[j];
            curr_artist_hash = getHash(ht,curr_artist);
            // Use hash as the vertex number and insert connection between them in the graph
            AddEdge(graph,curr_movie_hash,curr_artist_hash);
        }
    }

}

void printGraphConnections(GRAPH* graph, HASH_TABLE* ht){
    int curr_vertex;
    NODE* temp;
    NODE** list = graph->adj_list;
    char* temp_name;

    for(curr_vertex = 0; curr_vertex < graph->no_of_vertices; curr_vertex++){
        if(list[curr_vertex] != NULL) {                       // if the vertex has connections
            temp_name = ht->arr[curr_vertex];                // Remember vertex number is the hash
            // so we get the name from hash table using the hash(into temp_name)
            printf("Connections of %s: \n", temp_name);

            temp = list[curr_vertex];
            while( temp != NULL){
                printf("  %s", ht->arr[temp->vertex] );
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

GRAPH* PrepareGraph(MOVIES* in_movies, HASH_TABLE* ht){

    // Insert each movie and artists into hash table so that we can use their index as vertex id
    int number_of_vertices = Insert_Movies_Artists_IntoHT(in_movies, ht);

    // Create empty graph
    GRAPH* graph = GraphFactory(number_of_vertices);

    // Link each node inside of the graph with each other
    LinkMoviesAndArtists(graph, in_movies, ht);

    return graph;
}

void printTrace(HASH_TABLE* ht, NODE* curr){
    printf("Reached to: %s From:\n", ht->arr[curr->vertex]);
    int counter = 0;

    curr = curr->last_parent;
    while( curr->vertex != -1 ){
        printf("%s\n", ht->arr[curr->vertex]);
        curr = curr->last_parent;
        counter++;
    }

    if( counter > 6 )
        printf("\nActually No Connection with the node since it takes more than 6 levels...\n");
}

void BFS(GRAPH* G, HASH_TABLE* ht, long srcVertex, long destVertex ){
    long i;
    NODE** list = G->adj_list;
    NODE* temp;

    Queue* q = queueFactory(MAX_NO_OF_MOVIES);
    printf("Starting with Vertex: %s\n", ht->arr[srcVertex]);
    list[srcVertex]->last_parent = NodeFactory(-1);
    enqueue(q,srcVertex);

    while( !isEmpty(q) ){
        i = dequeue(q);
        temp = list[i]->next;
        while(temp != NULL){
            if( temp->last_parent == NULL && temp->last_parent->vertex != -1 ) {                 // if the node doesnt have any parent yet
                temp->last_parent = NodeFactory(i);                                              // set the current node as its parent
                enqueue(q,temp->vertex);

                if( temp->vertex == destVertex )
                    return printTrace(ht,temp);
            }
            temp = temp->next;
        }
    }
    // if reached here this means no connection
    printf("No Connection with %s\n", ht->arr[destVertex]);
}






