# DSAII
A Modified Dijkstra's Algorithm for Solving the Problem of Finding the Maximum Load Path C++ code

Djikstra applied this characteristic the other way around, for example, we overstate the distances between each vertex and the origin. After that, we go to each node and its neighbours to determine the shortest subpath there. In order to identify the next best answer, the algorithm takes a greedy approach with the expectation that the final result will be the best solution for the entire problem.

The Basic Algorithm for Dijkstra:-
function dijkstra(G, S)
    for each vertex V in G
        distance[V] <- infinite
        previous[V] <- NULL
        If V != S, add V to Priority Queue Q
    distance[S] <- 0
	
    while Q IS NOT EMPTY
        U <- Extract MIN from Q
        for each unvisited neighbour V of U
            tempDistance <- distance[U] + edge_weight(U, V)
            if tempDistance < distance[V]
                distance[V] <- tempDistance
                previous[V] <- U
    return distance[], previous[]
    
Performance of Dijkstra algorithm
The Dijkstra algorithm takes O((n+m)logn) time where n is the number of nodes in graph G and m is the number of edges in graph G

Advantage of Dijkstra
Considerably low complexity, which is almost linear

Disadvantage of Dijkstra
Can not work when dealing with negative weight

Dijkstra's algorithm are modified because to determine the maximum load rather than the shortest path. Based on Dijkstra’s Algorithm, the starting location, s and the destination, t can be found in O((n+m)logn) time. However, since determining the greatest load path is not the same as determining the shortest path, Dijkstra's algorithm needs to be adjusted. The issue of determining the maximum load path can then be successfully solved. The weight in Dijkstra's algorithm represents factors like time, cost, and distance. The weight in the modified Dijkstra's algorithm only represents the load capacity when it is constrained by a road.

Modified Dijkstra's Algorithm
function dijkstra(G, S)
    for each vertex V in G
        distance[V] <- infinite
        previous[V] <- NULL
        If V != S, add V to Priority Queue Q
    distance[S] <- 0
	
    while Q IS NOT EMPTY
        U <- Extract MAX from Q
        for each unvisited neighbour V of U
            tempDistance <- distance[U] + edge_weight(U, V)
            if tempDistance < distance[V]
                distance[V] <- tempDistance
                previous[V] <- U
    return distance[], previous[]

Performance of the modified dijkstra
The modified dijkstra takes O((n+m)logn) time where n is the number of nodes in graph G and m is the number of edges in graph G
When to use dijkstra and modified dijkstra algorithm

Dijkstra algorithm are use for solving the problem of finding the shortest path, In social networking applications, in a telephone network, and to find the locations in the map meanwhile the Modified Dijkstra algorithm are use to find the maximum load path.


    
    
