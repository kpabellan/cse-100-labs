#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Graph {
  int vertices;             // Nodes/vertices of the graph
  list<int> *adjacentLists; // Array of adjacenct lists
  void fillStack(int i, bool visited[],
                 stack<int> &Stack); // Fill the stack with vertices in the
                                     // order of their finishing times
  void DFS(int i, bool visited[], vector<int> &indexes); // Depth first search

public:
  Graph(int vertices);        // Constructor
  void addEdge(int u, int v); // Add edges to the graph
  void printSCCID(); // Print SCC ID (Smallest indoex of any vertex in the SCC)
  Graph transpose(); // Transpose the graph
};

// Constructor
Graph::Graph(int vertices) {
  this->vertices = vertices;
  adjacentLists = new list<int>[vertices];
}

// Fill the stack with vertices in the order of their finishing times
void Graph::fillStack(int i, bool visited[], stack<int> &Stack) {
  visited[i] = true;

  for (list<int>::iterator iter = adjacentLists[i].begin();
       iter != adjacentLists[i].end(); iter++) {
    if (!visited[*iter]) {
      fillStack(*iter, visited, Stack);
    }
  }

  Stack.push(i);
}

// Depth first search
void Graph::DFS(int i, bool visited[], vector<int> &indexes) {
  visited[i] = true;
  cout << "Start: " << i << " ";

  indexes.push_back(i);

  for (list<int>::iterator iter = adjacentLists[i].begin();
       iter != adjacentLists[i].end(); iter++) {
    if (!visited[*iter]) {
      DFS(*iter, visited, indexes);
    }
  }
}

// Add edges to the graph
void Graph::addEdge(int u, int v) { adjacentLists[u].push_back(v); }

// Transpose the graph
Graph Graph::transpose() {
  Graph g(vertices);

  for (int i = 0; i < vertices; i++) {
    for (list<int>::iterator iter = adjacentLists[i].begin();
         iter != adjacentLists[i].end(); iter++) {
      g.adjacentLists[*iter].push_back(i);
    }
  }

  return g;
}

// Set correct values to the output
void setOutputValues(vector<int> const &indexes, int output[]) {
  // Find lowest number
  int minimum = 2147483647;
  for (int i = 0; i < indexes.size(); i++) {
    if (indexes[i] < minimum) {
      minimum = indexes[i];
    }
  }

  // Set values
  for (int i = 0; i < indexes.size(); i++) {
    output[indexes[i]] = minimum;
  }
}

// Print SCC ID (Smallest index of any vertex in the SCC)
void Graph::printSCCID() {
  stack<int> Stack;

  bool *visited = new bool[vertices];

  for (int i = 0; i < vertices; i++) {
    visited[i] = false;
  }

  for (int i = 0; i < vertices; i++) {
    if (visited[i] == false) {
      fillStack(i, visited, Stack);
    }
  }

  Graph transposedGraph = transpose();

  for (int i = 0; i < vertices; i++) {
    visited[i] = false;
  }

  int *output = new int[vertices];

  while (Stack.empty() == false) {
    int top = Stack.top();
    Stack.pop();

    if (visited[top] == false) {
      vector<int> Indexes;
      transposedGraph.DFS(top, visited, Indexes);
      cout << endl;
      // setOutputValues(Indexes, output);
    }
  }

  // for (int i = 0; i < vertices; i++) {
  //   cout << output[i] << endl;
  // }
}

int main() {
  int vertices, edges, u, v;

  cin >> vertices;
  cin >> edges;

  Graph g(vertices);

  for (int i = 0; i < edges; i++) {
    cin >> u;
    cin >> v;
    g.addEdge(u, v);
  }

  g.printSCCID();

  return 0;
}