#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int V = 7;

char vertices[V] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

int graph[V][V] = {
{0, 2, 3, 3, 0, 0, 0},
{0, 0, 4, 0, 3, 0, 0},
{0, 0, 0, 5, 1, 6, 0},
{0, 0, 0, 0, 0, 7, 0},
{0, 3, 0, 0, 0, 8, 0},
{0, 0, 0, 7, 8, 0, 9},
{0, 0, 0, 0, 8, 0, 0}
};

typedef pair<int, int> PII;

vector<pair<int, PII>> edges;

vector<bool> visited(V, false);

vector<int> parent(V, -1);

int totalWeight = 0;

void prim(int source)
{
vector<int> minWeight(V, INT_MAX);
vector<int> vertex(V);
minWeight[source] = 0;
vertex[source] = source;

visited[source] = true;

for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
        if (graph[i][j])
            edges.push_back({graph[i][j], {i, j}});

sort(edges.begin(), edges.end());

for (int i = 0; i < edges.size(); i++)
{
    int weight = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    if (!visited[v] && weight < minWeight[v])
    {
        minWeight[v] = weight;
        vertex[v] = u;

        visited[v] = true;

        parent[v] = u;

        totalWeight += weight;
}
}
}

int main()
{
  int source = 0;
  prim(source);

  cout << "Edges and Weights: " << endl;
  for (int i = 1; i < V; i++)
      cout << vertices[parent[i]] << " - " << vertices[i] << " (weight: " << graph[parent[i]][i] << ")" << endl;

  cout << "Total Weight: " << totalWeight << endl;

cout << "Path spanning tree: " << endl;
for (int i = 1; i < V; i++) {
    cout << vertices[i] << " <- ";
    int curr = i;
    while (parent[curr] != -1) {
        cout << vertices[parent[curr]] << " <- ";
        curr = parent[curr];
    }
    cout << endl;
}

  return 0;
}