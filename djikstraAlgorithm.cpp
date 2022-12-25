#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits> 

using namespace std;

const int V = 5;

char vertices[V] = {'A', 'B', 'C', 'D', 'E'};

int graph[V][V] = {
    {0, 5, 2, 0, 0},
    {5, 0, 1, 2, 3},
    {2, 1, 0, 4, 5},
    {0, 2, 4, 0, 0},
    {0, 3, 5, 0, 0}
};

vector<int> parent(V);
vector<int> dist(V);

void djikstra(int source)
{
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (dist[u] == INT_MAX)
        {
            continue;
        }

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && dist[v] > dist[u] + graph[u][v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int source = 0;
    djikstra(source);

    cout << "Shortest Path Tree (SPT):" << endl;
    for (int i = 0; i < V; i++)
    {
        if (i == source)
        {
            continue;
        }

        cout << vertices[parent[i]] << " - " << vertices[i] << " (weight: " << graph[parent[i]][i] << ")" << endl;
    }

    return 0;
}
