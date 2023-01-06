#include <iostream>

using namespace std;

struct Edge {
  int u; // source
  int v; // destination
  int w; // weight
};

struct Graph {
  int vertices;
  int edges;

  struct Edge *edge;
};

struct Graph *initializeGraph(int vertices, int edges) {
  struct Graph *graph = new Graph;
  graph->vertices = vertices;
  graph->edges = edges;
  graph->edge = new Edge[edges];
  return graph;
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == 2147483647) {
      cout << "INFINITY" << endl;
    } else {
      cout << arr[i] << endl;
    }
  }
}

void bellmanFord(struct Graph *graph) {
  int vertices = graph->vertices;
  int edges = graph->edges;
  int *distance = new int[vertices];
  bool negativeWeight = false;

  for (int i = 0; i < vertices; i++) {
    distance[i] = 2147483647;
  }

  distance[0] = 0;

  for (int i = 1; i <= vertices - 1; i++) {
    for (int j = 0; j < edges; j++) {
      int source = graph->edge[j].u;
      int destination = graph->edge[j].v;
      int weight = graph->edge[j].w;
      if (distance[source] != 2147483647 && distance[source] + weight < distance[destination]) {
        distance[destination] = distance[source] + weight;
      }
    }
  }

  for (int i = 0; i < edges; i++) {
    int source = graph->edge[i].u;
    int destination = graph->edge[i].v;
    int weight = graph->edge[i].w;
    if (distance[source] != 2147483647 && distance[source] + weight < distance[destination]) {
      cout << "FALSE" << endl;
      negativeWeight = true;
      return;
    }
  }

  if (!negativeWeight) {
    cout << "TRUE" << endl;
  }

  printArray(distance, vertices);

  delete[] distance;
}

int main() {
  int vertices = 0;
  int edges = 0;

  cin >> vertices >> edges;

  struct Graph *graph = initializeGraph(vertices, edges);

  for (int i = 0; i < edges; i++) {
    cin >> graph->edge[i].u >> graph->edge[i].v >> graph->edge[i].w;
  }

  bellmanFord(graph);

  return 0;
}