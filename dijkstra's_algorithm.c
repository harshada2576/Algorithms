#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 50   // maximum vertices

int V;  // number of vertices

int min_dist(int dist[], bool visited[]) {  // finding minimum dist
    int minimum = INT_MAX, ind = -1,k;
    for ( k = 0; k < V; k++) {
        if (!visited[k] && dist[k] <= minimum) {
            minimum = dist[k];
            ind = k;
        }
    }
    return ind;
}

void greedy_dijkstra(int graph[MAX][MAX], int src) {
    int dist[MAX],k,count;
    bool visited[MAX];

    for ( k = 0; k < V; k++) {
        dist[k] = INT_MAX;
        visited[k] = false;
    }

    dist[src] = 0; // Source vertex dist is set 0

    for ( count = 0; count < V - 1; count++) {
        int m = min_dist(dist, visited);
        visited[m] = true;

        for ( k = 0; k < V; k++) {
            // update the dist of neighbouring vertex
            if (!visited[k] && graph[m][k] && dist[m] != INT_MAX &&
                dist[m] + graph[m][k] < dist[k]) {
                dist[k] = dist[m] + graph[m][k];
            }
        }
    }

    printf("\nVertex\tDistance from Source\n");
    for ( k = 0; k < V; k++) {
        if (dist[k] == INT_MAX)
            printf("%c\tINF\n", 65 + k); // print INF if unreachable
        else
            printf("%c\t%d\n", 65 + k, dist[k]);
    }
}

int main() {
    int graph[MAX][MAX];
    int E,i,j; // number of edges
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    // initialize graph
    for ( i = 0; i < V; i++) {
        for ( j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter number of edges: ");
    scanf("%d", &E);-
    printf("Enter edges (u v w):\n");
    printf("Note: Vertices are numbered from 0 to %d\n", V - 1);
    for ( i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected graph
    }
    int src;
    printf("Enter source vertex (0 to %d): ", V - 1);
    scanf("%d", &src);
    greedy_dijkstra(graph, src);
    return 0;
}

