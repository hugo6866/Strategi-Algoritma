from typing import List, Tuple

def prim(graph: List[List[int]], V: int, source: int) -> Tuple[List[int], int]:
    edges = []
    visited = [False] * V
    parent = [-1] * V
    total_weight = 0
    min_weight = [float('inf')] * V
    vertex = [0] * V
    min_weight[source] = 0
    vertex[source] = source

    visited[source] = True

    for i in range(V):
        for j in range(V):
            if graph[i][j]:
                edges.append((graph[i][j], (i, j)))
    
    edges.sort()

    for i in range(len(edges)):
        weight = edges[i][0]
        u = edges[i][1][0]
        v = edges[i][1][1]

        if not visited[v] and weight < min_weight[v]:
            min_weight[v] = weight
            vertex[v] = u

            visited[v] = True

            parent[v] = u

            total_weight += weight

    return parent, total_weight

def main():
    V = 7
    source = 0
    vertices = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
    graph = [
    [0, 2, 3, 3, 0, 0, 0],
    [0, 0, 4, 0, 3, 0, 0],
    [0, 0, 0, 5, 1, 6, 0],
    [0, 0, 0, 0, 0, 7, 0],
    [0, 3, 0, 0, 0, 8, 0],
    [0, 0, 0, 7, 8, 0, 9],
    [0, 0, 0, 0, 8, 0, 0]
    ]

    parent, total_weight = prim(graph, V, source)

    print("Edges and Weights:")
    for i in range(1, V):
        print(f"{vertices[parent[i]]} - {vertices[i]} (weight: {graph[parent[i]][i]})")

    print(f"Total Weight: {total_weight}")

    print("Path spanning tree:")
    for i in range(1, V):
        print(vertices[i], end=" <- ")
        curr = i
        while parent[curr] != -1:
            print(vertices[parent[curr]], end=" <- ")
            curr = parent[curr]
        print()

if __name__ == "__main__":
    main()
