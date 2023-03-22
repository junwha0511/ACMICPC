'''
다익스트라  
'''
from queue import PriorityQueue
import heapq

MAX = float("inf")


N, M, K, X = map(int, input().split())

edge = [[] for _ in range(N)]
dist = [MAX for _ in range(N)]
queue = []

for i in range(M):
    A, B = map(int, input().split())
    edge[A-1].append(B-1) # TODO: increase at print

# init from first node
X -= 1
dist[X] = 0
heapq.heappush(queue, (dist[X], X))

if len(edge[X]) == 0:
    print(-1)
else:
    while len(queue) > 0: # Filter out deprecated nodes
        # Select min node
        min_dist, min_node = heapq.heappop(queue)
        
        if dist[min_node] < min_dist:
            continue
        
        new_dist = min_dist + 1 
        for dest in edge[min_node]:
            if new_dist < dist[dest]:
                dist[dest] = new_dist
                heapq.heappush(queue, (dist[dest], dest))

node_exist = False
for node in range(N):
    if dist[node] == K:
        node_exist = True
        print(node+1)
if not node_exist:
    print(-1)