
//ADJACENCY MATRIX REPRESENTATION
//SC:N*N
#include <iostream>
using namespace std;

class Graph 
{
  private:
  bool** adjMatrix;
  int numVertices;

   public:
  // Initialize the matrix to zero
  Graph(int numVertices) 
  {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) 
    {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j) 
  {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  // Remove edges
  void removeEdge(int i, int j) 
  {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  // Print the martix
  void printMatrix() 
  {
    for (int i = 0; i < numVertices; i++) 
    {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }
};

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.printMatrix();
}


/////////////////////////////////////////////////////////////////////////////////

//ADJACENCY LIST REPRESENTATION
//SC:N+E
 
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

// A utility function to delete an edge in undirected graph.
void delEdge(vector<int> adj[], int u, int v)
{
    // Traversing through the first vector list
    // and removing the second element from it
    for (int i = 0; i < adj[u].size(); i++) 
    {
        if (adj[u][i] == v) 
        {
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }
 
    // Traversing through the second vector list
    // and removing the first element from it
    for (int i = 0; i < adj[v].size(); i++) 
    {
        if (adj[v][i] == u) 
        {
            adj[v].erase(adj[v].begin() + i);
            break;
        }
    }
}
   
void printGraph(vector<int> adj[], int V) 
{ 
    for (int i = 0; i < V; i++) 
    { 
        for (int x : adj[i]) 
           cout << x <<" "; 
        cout<<"\n"; 
    } 
} 
  
int main() 
{ 
    int V = 4; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    printGraph(adj, V); 
    cout<<"after deletion:"<<endl;
    delEdge(adj, 1, 3);
    printGraph(adj, V); 
    return 0; 
} 