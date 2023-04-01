'''

RxC grid

막대가 땅과 수평을 이루면서 날아감

 A
CB<-
 D
A가 속해있는 클러스터가 바닥을 포함한다면 정지, otherwise 클러스터 전체 낙하
B는 클러스터에서 제거
C, D도 가능한데...? ㅠㅠ

클러스터는 따로 트래킹하지 않고 매 번 BFS로 탐색한다

1. A로부터 BFS를 통해 클러스터를 수집한다
2. 바닥이 단 하나라도 존재할 경우, 다음 iteration으로 넘어간다.
3. Otherwise, 클러스터 전체를 돌면서 낙하할 수 있는 최소 높이를 찾는다 (아래쪽으로 미네랄 or 바닥 diff)
    - 클러스터를 모두 c로 마킹
    - 미네랄과 최소 높이
4. 바닥이 발견되지 않았을 경우, 미네랄이 낙하해야하는만큼 클러스터 내 모든 미네랄을 대상 좌표로 이동시킨다. (단, 이 때 src와 dest가 꼬이는 것에 주의하자)
    - dest를 x로 바꾼다
    - src가 c일 경우(타 미네랄에 의해 바뀌지 않음) src를 .으로 변경한다
5. 모든 o를 x로 치환한다.

*** A, C, D 중 같은 클러스터가 아닌 것들을 모아야함!!!
'''
move_vectors = ((0, 1), (0, -1), (1, 0), (-1, 0))

def check_reachable_dfs(grid, src, dst, visited, R, C):
    if src[0] == dst[0] and src[1] == dst[1]:
        return True
    for v in move_vectors:
        y = i + v[0] 
        x = j + v[1]
        if y >= 0 and y < R and x >= 0 and x < C and not visited[y][x] and grid[y][x] == MINERAL:
            visited[y][x] = True
            result = check_reachable_dfs(grid, (y, x), dst, visited, R, C)
            if result:
                return True
    return False
        
SPACE = "."
MINERAL = "x"
CLUSTER = "c"

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
    
    i = h
    targets = []
    for j in range(0, C) if direction == 1 else range(C-1, -1, -1):
        if grid[i][j] == MINERAL:
            grid[i][j] = SPACE
            
            if i < R-1 and grid[i+1][j] == MINERAL:
                targets.append((i+1, j))
            if i > 0 and grid[i-1][j] == MINERAL:
                targets.append((i-1, j))

            if direction == 1:
                if j < C-1 and grid[i][j+1] == MINERAL:
                    targets.append((i, j+1))
            else:
                if j > 0 and grid[i][j-1] == MINERAL:
                    targets.append((i, j-1))
            break
    
    complement_targets = []
    
    while len(targets) > 0:
        src = targets.pop()
        complement_targets.append(src)
        
        maintain = []
        while len(targets) > 0:
            dst = targets.pop()
            visited = [[False for _ in range(C)] for __ in range(R)]
            visited[src[0]][src[1]] = True
            if not check_reachable_dfs(grid, src, dst, visited, R, C):
                maintain.append(dst)
        targets = maintain
    
    for target in complement_targets:
        cluster = [target]
        q = [target]
        
        cluster_on_floor = False
        
        visited = [[False for _ in range(C)] for __ in range(R)]
        visited[target[0]][target[1]] = True
        
        # BFS
        while len(q) > 0 and not cluster_on_floor:
            i, j = q.pop()
            if i == 0:
                cluster_on_floor = True
                break
            for v in move_vectors:
                y = i + v[0] 
                x = j + v[1]
                if y >= 0 and y < R and x >= 0 and x < C and not visited[y][x] and grid[y][x] == MINERAL:
                    visited[y][x] = True
                    q.append((y, x))
                    cluster.append((y, x))
        
        if cluster_on_floor:
            continue 
        
        # Mark clusters
        for (i, j) in cluster:
            grid[i][j] = CLUSTER
        
        # Find min diff
        min_diff = R
        for (i, j) in cluster:
            for k in range(i-1, -1, -1):
                if grid[k][j] == CLUSTER:
                    break
                if grid[k][j] == MINERAL:
                    diff = i - k - 1 # i - diff = k + 1
                    if diff < min_diff:
                        min_diff = diff
                elif k == 0 and i < min_diff:
                    min_diff = i  
        # Falling
        for (i, j) in cluster:
            if grid[i][j] == CLUSTER:
                grid[i][j] = SPACE
            grid[i-min_diff][j] = MINERAL

for i in range(R-1, -1, -1):
    for j in range(C):
        print(grid[i][j], end="")
    print()
