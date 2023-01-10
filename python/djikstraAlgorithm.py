import sys
import heapq

V = 5
vertices = ['A', 'B', 'C', 'D', 'E']

graph = [
    [0, 5, 2, 0, 0],
    [5, 0, 1, 2, 3],
    [2, 1, 0, 4, 5],
    [0, 2, 4, 0, 0],
    [0, 3, 5, 0, 0]
]

parent = [0] * V
dist = [sys.maxsize] * V

def djikstra(source):
    for i in range(V):
        dist[i] = sys.maxsize
        parent[i] = -1
    dist[source] = 0

    pq = []
    heapq.heappush(pq, (0, source))

    while len(pq) > 0:
        u = heapq.heappop(pq)[1]
        if dist[u] == sys.maxsize:
            continue
        for v in range(V):
            if graph[u][v] and dist[v] > dist[u] + graph[u][v]:
                dist[v] = dist[u] + graph[u][v]
                parent[v] = u
                heapq.heappush(pq, (dist[v], v))


source = 0
djikstra(source)
print("Shortest Path Tree :")
for i in range(V):
    if i == source:
        continue
    print(vertices[parent[i]] + " - " + vertices[i] + " (weight: " + str(graph[parent[i]][i]) + ")")