N, M, V = map(int, input().split())

def dfs(v, edge, result, visited):
    if not visited[v]:
        result.append(v)
        visited[v] = True
        for node in edge[v]:
            dfs(node, edge, result, visited)

def bfs(v, edge, result, visited):
    queue = []
    queue.append(v)
    while len(queue) > 0:
        src = queue.pop()
        if not visited[src]:
            visited[src] = True
            result.append(src)
            for dst in edge[src]:
                queue.insert(0, dst)

edge = [[] for _ in range(N+1)]

for i in range(M):
    A, B = map(int, input().split())
    edge[A].append(B)
    edge[B].append(A)

for i in range(1, N+1):
    edge[i].sort()
    
# DFS
visited = [False for _ in range(N+1)]
dfs_result = []
dfs(V, edge, dfs_result, visited)
print(" ".join(map(str, dfs_result)))

# BFS
visited = [False for _ in range(N+1)]

bfs_result = []
bfs(V, edge, bfs_result, visited)
print(" ".join(map(str, bfs_result)))


