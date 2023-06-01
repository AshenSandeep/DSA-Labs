#include<bits/stdc++.h>
using namespace std;

// Function to find the vertex with minimum distance
int minDistance(int dist[], bool visited[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
void averageTime(int dist[]){
    int total=0;
    for(int i=0;i<6;i++){
        total+=dist[i];
    }
    cout<<"Average Time: "<<(double)total/5;
}
// Function to print the constructed distance array
void printSolution(int dist[], int vertices) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < vertices; i++)
        cout << i << " \t\t" << dist[i] << endl;
    averageTime(dist);    
}


void dijkstra(int graph[6][6], int source, int vertices) {
    int dist[vertices]; // dist[i] save the shortest distance between(srt to i)

    bool visited[vertices]; 
    //set all distance of vertices as INFINITY
    
    for (int i = 0; i < vertices; i++){
        dist[i] = INT_MAX;
        visited[i] = false;               //set the visited array as false
    }
    
    dist[source] = 0;    //distance from source to itself is zero 

    
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, visited, vertices);

        
        visited[u] = true;  // mark the current vertice as true

        // Update dist value of the adjacent vertices 
        for (int v = 0; v < vertices; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    
    printSolution(dist, vertices);
}

int main() {
    int graph[6][6] = {{0, 10, 0, 0, 15, 5},
                       {10, 0, 10, 30, 0, 0},
                       {0, 10, 0, 12, 5, 0},
                       {0, 30, 12, 0, 0, 20},
                       {15, 0, 5, 0, 0, 0},
                       {5, 0, 0, 20, 0, 0}};
                       
    dijkstra(graph, 5, 6);

    return 0;
}