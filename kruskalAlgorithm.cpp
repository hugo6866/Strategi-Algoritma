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

vector<int> parent(V);

int totalWeight = 0;

int findSet(int i)
{
if (parent[i] == i)
return i;
return findSet(parent[i]);
}

void kruskal(int source)
{
for (int i = 0; i < V; i++)
parent[i] = i;

for (int i = 0; i < V; i++)
    for (int j = i + 1; j < V; j++) // fix: iterate only over upper triangle of the matrix
        if (graph[i][j])
            edges.push_back({graph[i][j], {i, j}});

sort(edges.begin(), edges.end());

for (int i = 0; i < edges.size(); i++)
{
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    int setU = findSet(u);
    int setV = findSet(v);

    if (setU != setV)
    {
        parent[setU] = setV; // update parent array
        totalWeight += edges[i].first;
        cout << vertices[u] << " - " << vertices[v] << " (weight: " << edges[i].first << ")" << endl;
    }
}
}


int main()
{
int source = 0;
kruskal(source);

cout << "Total Weight: " << totalWeight << endl;

cout << "Path spanning tree: " << endl;
for (int i = 0; i < V; i++) {
if (parent[i] != i) {
cout << vertices[i] << " <- " << vertices[parent[i]] << endl;
}
}

return 0;
}
