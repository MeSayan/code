// Program to find Dijkstra's shortest path using
// priority_queue in STL
//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;
# define INF 0x3f3f3f3f
 
// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
 
    // prints shortest path from s
    void shortestPath(int *T, int s, int dest);
};
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

int waittime(int * T, int t, int v, int dest) {
  if ( v == dest)
    return 0;
  else {
    int R = t % T[v];
    if ( R == 0) return 0;
    else return(T[v] - R);
  }
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int * T, int src, int dest)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // http://geeksquiz.com/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);
 
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
            int t = dist[u] + weight;
            //cout << t << endl;
 
            //  If there is shorted path to v through u.
            if (dist[v] > t + waittime(T,t,v,dest))
            {
                // Updating distance of v
                dist[v] = t + waittime(T,t,v,dest);
                //cout << "Dist" << dist[v] << endl;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    /*
    // Print shortest distances stored in dist[]
    printf("Vertex   Distance\n");
    for (int i = 1; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
    */
    printf("%d\n", dist[dest]);
}
 
// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int src, dest, i;
    int N, M;
  
    cin >> src >> dest >> N >> M;
    int T[N+1];
    Graph G(N+1);
    
    for( i = 1; i <= N; i++)
      scanf("%d", T+i);
    
    for( i = 1; i <= M; i++) {
      int u,v,w;
      cin >> u >> v >> w;
      G.addEdge(u,v,w);
    }
    
    G.shortestPath(T, src, dest);
 
    return 0;
}