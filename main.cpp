//Libraries
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std; 

//Constants
const int INT_MAX = 1e6;

//Data structure to store adjacency list nodes
struct Node {
  int src, weight;
  Node *dest;
};

//Data structure to store graph edge
struct Edge{
  int src, dest, weight;
};

//Class for Graph
class Graph{
  public:
    //Function to allocate new node of Adjacency List
    Node* getAdjListNode(int src, int weight, Node* dest){
      Node* newNode = new Node;
      newNode->src = src;
      newNode->weight = weight;
      newNode->dest = dest; //point new node to current destination
      return newNode;
    }

    void addEdge (vector<Node*>& adj, int src, int dest, int weight){ 
      adj[src] = getAdjListNode(dest, weight, adj[src]);
    }

    void printList (vector<Node*>& adj, int V){
      cout << "Adjacency List (Source, Destination, Weight): " << endl;
      cout << "Riverside - 0, Moreno - 1, Perris - 2, Hemet - 3 " << endl;
      for (int i = 0; i < V; i++){
        cout << "Node " << i << ": ";
        Node* temp = adj[i];
        while (temp != NULL){
          cout << " (" << i << ", "<< temp->src << ", " << temp->weight << ") ";
          temp = temp->dest;
        }
        cout << endl;
      }
    }
};

int minDistance(vector<Node*> &adj, int dist[], bool visited[], int V){
    // Initialize min value
    int min = INT_MAX, min_index;

    // Loop through all vertices
    for (int v = 0; v < V; v++) {
      // Check if the vertex v is not visited and has a smaller distance than the current minimum
      if (!visited[v] && dist[v] < min) {
        // Update the minimum distance and the corresponding index
        min = dist[v];
        min_index = v;
      }
    }

    // Return the index of the vertex with the minimum distance
    return min_index;
  }


void dijkstra(vector<Node*> &adj, int src, int dist[], bool visited[], int V) {
  // //Initializing all distances as INFINITE and shortPath[] as false
  for (int i = 0; i < V; i++) {
    dist[i] = INT_MAX;
    visited[i] = false;
  }
  
  //Distance of source vertex to itself
  dist[src] = 0; 

  //Find shortest path for all vertices
  for(int count = 0; count < V - 1; count++) {
    int u = minDistance(adj, dist, visited, V);
    visited[u] = true; //// Mark the current vertex as visited

    Node* temp = adj[u];
    while (temp != NULL){
      int v = temp->src;
      if(!visited[v] && dist[u] != INT_MAX && dist[u] + temp->weight < dist[v]){
        dist[v] = (dist[u] + temp->weight);
      }
      temp = temp->dest;
    }
  }
}

void costShortest(vector<Node*> &adj, int V){
  int totCost = 0;
  bool visited[V];

  for(int src = 0; src< 3; src++){
    int dist[V];
    for(int i = 0; i < V; i++){
      visited[i] = false;
    }
  
    dijkstra(adj, src, dist, visited, V);

    int dest = (src + 1) % V;
    cout << "Node " << src << " -> " << dest << " = " << dist[dest] << endl;
    totCost += dist[dest];
  }
  cout << "Minimum cost  = " << totCost << endl;
  cout << "Shortest path =  " << totCost << endl;
}

int main() {
  // Create a graph object
  Graph graph;

  //Number of Nodes
  int V = 4;

  //Array of pointers to Node to represent adjacency list
  vector<Node*> adj(V);

  //Riverside - 0; Moreno - 1; Perris - 2; Hemet - 3
  Edge edges[] = {
    {0, 1, 16}, {0, 2, 24}, {0, 3, 33},
    {1, 0, 16}, {1, 2, 18}, {1, 3, 26},
    {2, 0, 24}, {2, 1, 18}, {2, 3, 30},
    {3, 0, 33}, {3, 1, 26}, {3, 2, 30}
  };

  //Fill adjacency list
  for (const Edge& edge: edges){
    graph.addEdge(adj, edge.src, edge.dest, edge.weight);
  }

  //Print the adjacency list
  graph.printList(adj, V);
  cout << endl; 

  //Finding shortest Path
  costShortest(adj, V);
  
  return 0;
}