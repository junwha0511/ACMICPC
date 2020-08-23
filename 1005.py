# class Node:
#     preNodeList = None
#     constructTime = -1
#     ownConstructTime = None
#     def __init__(self, ownConstructTime):
#         self.preNodeList = []
#         self.ownConstructTime = ownConstructTime

preNode = [None]
constructTime = [None]
ownConstructTime = None
 
def caculateConstructTime(parent):
    if constructTime[parent] == -1:
        maxTime = 0
        for child in preNode[parent]:
            childTime = caculateConstructTime(child)
            if childTime > maxTime:
                maxTime = childTime
        maxTime += ownConstructTime[parent]
        constructTime[parent] = maxTime
    return constructTime[parent]
    
T = int(input())
for t in range(T):
    preNode = [None]
    constructTime = [None]
    ownConstructTime = None
    N, K = map(int, input().split(' '))
    ownConstructTime = [None]+list(map(int, input().split(' ')))
    for n in range(N):
        preNode.append([])
        constructTime.append(-1)
    for k in range(K):
        x, y = map(int, input().split(' '))
        preNode[y].append(x)
    D = int(input())
    print(caculateConstructTime(D))
    

