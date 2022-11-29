#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int src, dest, weight;
};

    struct Graph {
    int V, E;

    // graph is represented as an array of edges.
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i < V; i++)
       
    dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    char name[] = {'s','t','x','y','z'};
    cout<<"Shortest Paths from src are: "<<"\n"<<"  Dest\tDist\n";
    for (int i = 0; i < V; i++) {
            cout<<name[i]<<"\t"<<dist[i]<<"\n";
    }
}


int main()
{
   
    int V = 5; // Number of vertices in graph
    int E = 10; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    cout<<"Enter edges - (src-dest-weight form)\n";

    for(int i=0;i<E;i++){
        cin>>graph->edge[i].src;
        cin>>graph->edge[i].dest;
        
cin>>graph->edge[i].weight;
    }

    BellmanFord(graph, 0);

    return 0;
}
