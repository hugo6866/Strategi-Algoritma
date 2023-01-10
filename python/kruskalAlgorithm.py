from typing import List, Tuple

def kruskal(source: int, V: int, vertices: List[str], graph: List[List[int]]) -> int:
    edges = []
    parent = [i for i in range(V)]
    total_weight = 0

    def find_set(i: int) -> int:
        if parent[i] == i:
            return i
        return find_set(parent[i])

    for i in range(V):
        for j in range(i+1, V):
            if graph[i][j]:
                edges.append((graph[i][j], (i, j)))

    edges.sort()

    for i in range(len(edges)):
        u, v = edges[i][1]
        set_u = find_set(u)
        set_v = find_set(v)

        if set_u != set_v:
            parent[set_u] = set_v
            total_weight += edges[i][0]
            print(f"{vertices[u]} - {vertices[v]} (weight: {edges[i][0]})")

    print(f"Total Weight: {total_weight}")
    print("Path spanning tree: ")
    for i in range(V):
        if parent[i] != i:
            print(f"{vertices[i]} <- {vertices[parent[i]]}")
    
    return total_weight

def main():
    V = 7
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

    source = 0
    kruskal(source, V, vertices, graph)

main()
