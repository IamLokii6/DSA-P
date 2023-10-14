#ifndef DISTANCE
#define DISTANCE
#define V 9

int minDistance(int dist[], bool sptSet[]);
void printSolution(int dist[]);
void dijkstra(int graph[V][V], int src);

#endif