#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include "distance.h"

void dijkstra(int graph[V][V], int src)
{
    int dist[V];

    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    printSolution(dist);
}