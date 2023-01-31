
// C++ program for A Modified Dijkstra's Algorithm for solving the problem of finding the maximum load path  single source shortest path algorithm. 
//The program is for adjacency matrix representation of the graph

#include <iostream>
using namespace std;
#include <limits.h>  //to use INT_MIN
 
// Number of vertices in the graph
#define V 9
 
// A utility function to find the vertex with maximum distance value, from the set of vertices not yet included in shortest path tree
int maxDistance(int dist[], bool sptSet[])
{
 
    // Initialize max value
    int max = INT_MIN, max_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] >= max)
            max = dist[v], max_index = v;
 
    return max_index;
}
 
// A utility function to print the constructed distance array
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}
 
// Function that implements Dijkstra's single source shortest path algorithm for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the longest distance from src to i
 
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in longest path tree or longest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MIN, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find longest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the maximum distance vertex from the set of vertices not yet processed. u is always equal to src in the first iteration.
        int u = maxDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet, there is an edge from u to v, 
            //and total weight of path from src to  v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MIN
                && dist[u] + graph[u][v] > dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    printSolution(dist);
}
 
// driver's code
int main()
{
 
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 13, 0 },
                        { 4, 0, 13, 0, 0, 0, 0, 22, 0 },
                        { 0, 13, 0, 12, 0, 4, 0, 0, 2 },
                        { 0, 0, 12, 0, 15, 28, 0, 0, 0 },
                        { 0, 0, 0, 15, 0, 20, 0, 0, 0 },
                        { 0, 0, 4, 28, 20, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 13, 22, 0, 0, 0, 0, 1, 0, 12 },
                        { 0, 0, 2, 0, 0, 0, 6, 12, 0 } };
 
    // Function call
    dijkstra(graph, 0);
 
    return 0;
}
