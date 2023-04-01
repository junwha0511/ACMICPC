'''

RxC grid

막대가 땅과 수평을 이루면서 날아감



클러스터는 따로 트래킹하지 않고 매 번 BFS로 탐색한다
동시에 클러스터 두 개가 떨어지는 일은 없으므로 공중에 떠 있는 클러스터는 하나 이하여야 한다.

 A
CB<-
 D
 
1. B를 지우고, 남아있는 모든 미네랄을 공중상태(A)로 표시한다
2. 바닥과 접해있는 모든 클러스터에 대해 BFS를 수행하여 공중상태(A)인 미네랄을 바닥상태(G)로 변경한다
3. 공중상태(A)인 모든 미네랄에 대해 바닥 혹은 바닥상태 미네랄과의 최단거리를 구해 하강을 진행한다.

'''

move_vectors = ((0, 1), (0, -1), (1, 0), (-1, 0))

       
SPACE = "."
MINERAL_AIR = "x"
MINERAL_GROUND = "g"


R, C = map(int, input().split())

grid = []
for _ in range(R):
    grid.insert(0, list(input()))

N = int(input())

direction = 0

h_list= list(map(int, input().split()))
for iter in range(N):
    direction = (direction + 1) % 2
    h = h_list[iter] - 1
    
    # Make all mineral in air
    for i in range(R):
        for j in range(C):
            if grid[i][j] == MINERAL_GROUND:
                grid[i][j] = MINERAL_AIR
                
    # Break a mineral
    i = h
    is_break = False
    for j in range(0, C) if direction == 1 else range(C-1, -1, -1):
        if grid[i][j] == MINERAL_AIR:
            grid[i][j] = SPACE
            is_break = True
            break
    if not is_break:
        continue
    
    # BFS: mark ground clusters
    i = 0
    j = 0
    is_cluster_met = False
    for j in range(C):
        if not is_cluster_met and grid[i][j] == MINERAL_AIR:
            # BFS will make cluster as MINERAL_GROUND
            q = [(i, j)]
            grid[i][j] = MINERAL_GROUND
            while len(q) > 0:
                y, x = q.pop()
                for v in move_vectors:
                    yy = y + v[0] 
                    xx = x + v[1]
                    if yy >= 0 and yy < R and xx >= 0 and xx < C and grid[yy][xx] == MINERAL_AIR:
                        grid[yy][xx] = MINERAL_GROUND
                        q.append((yy, xx))
                        
    # Find min diff
    air_cluster = []
    min_diff = R
    for i in range(R):
        for j in range(C):
            if grid[i][j] == MINERAL_AIR:
                air_cluster.append((i, j))
                for k in range(i-1, -1, -1):
                    if grid[k][j] == MINERAL_AIR:
                        break
                    if grid[k][j] == MINERAL_GROUND:
                        diff = i - k - 1 # i - diff = k + 1
                        if diff < min_diff:
                            min_diff = diff
                    elif k == 0 and i < min_diff:
                        min_diff = i  
    # Falling
    for (i, j) in air_cluster:
        grid[i-min_diff][j] = MINERAL_GROUND
        if grid[i][j] == MINERAL_AIR:
            grid[i][j] = SPACE

for i in range(R-1, -1, -1):
    for j in range(C):
        if grid[i][j] == MINERAL_GROUND:
            grid[i][j] = MINERAL_AIR
        print(grid[i][j], end="")
    print()
