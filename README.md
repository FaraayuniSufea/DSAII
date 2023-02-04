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

    Input: a graph G, a source vertex s and a destination vertex t
	Output: a path from s to t with the minimum weight 
	1. for 	each vertex v do
	{ status[v]=0; wt[v]=-1; dad[v]=-1; } 
	2. status[s]=2; wt[s]=+∞;
	3. for each edge [s, w] do
	{ status[w]=1; wt[w]=weight(s,w); dad[w]=s; }
	4. while there are fringes do
	v = the fringe with the min wt-value; status[v]=2;
	for each edge[v, w] do
	case 1. status[w]==0:
	{ status[w]=1; wt[w]=wt[v]+weight(v, w);
	dad[w]=v; }
	case 2. (status[w]==1) and (wt[w]>(wt[v]+weight(v,w)): { wt[w]= wt[v]+weight(v, w);
	dad[w]=v; }
    

Dijkstra's algorithm are modified because to determine the maximum load rather than the shortest path. Based on Dijkstra’s Algorithm, the starting location, s and the destination, t can be found in O((n+m)logn) time. However, since determining the greatest load path is not the same as determining the shortest path, Dijkstra's algorithm needs to be adjusted. The issue of determining the maximum load path can then be successfully solved. The weight in Dijkstra's algorithm represents factors like time, cost, and distance. The weight in the modified Dijkstra's algorithm only represents the load capacity when it is constrained by a road.

Modified Dijkstra's Algorithm:-

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

    Input: a graph G, a source vertex s and a destination vertex t
	Output: a path from s to t with the maximum load 
	1. for each vertex v do
	{ status[v]=0; wt[v]=-1; dad[v]=-1; } 
	2. status[s]=2; wt[s]=+∞;
	3. for each edge [s, w] do
	{ status[w]=1; wt[w]=weight(s,w); dad[w]=s; } 
	4. while there are fringes do
	v = the fringe with the max wt-value; status[v]=2;
	for each edge[v, w] do
	case 1. status[w]==0:
	{ status[w]=1; wt[w]=min{wt[v], weight(v,w)}; dad[w]=v; }
	case 2. (status[w]==1) and (wt[w]<min{wt[v],weight(v, w)}): { wt[w]=min{wt[v], weight(v, w)};
	dad[w]=v; }


However the performance for basic dijkstra and a modified dijkstra are remains the same which it takes O((n+m)logn) time. Additionally, the complexity of dijkstra and modified dijkstra is minimal and nearly linear. The Modified Dijkstra algorithm is used to identify the maximum load path, whereas the Dijkstra algorithm is used to solve the problem of finding the shortest path.
    
