'''
구슱 탈출 2  

빨강 하나, 파랑 하나 -> 빨강 탈출
NxM

상하좌우 빨강-파랑 함께 벽을 만날 때까지 이동함

최소 움직임 횟수

DFS로 존재하는 경로를 모두 탐색
단, 이 때 단위경로는 시작점부터 가장 가까운 벽까지임
또한, 빨강 경로를 확인하면서 파랑 경로를 동일한 방향으로 검증해 해당 path가 유효한지 확인

탐색한 모든 경로 중 최적 경로의 길이를 출력

--------
1. 빨강이 최소 1칸 이동 가능한 방향으로 방향 선택
2. 파랑을 먼저 진행하며 경로상 HOLE 여부 확인, 파랑 위치 업데이트 (예외: 파랑 경로에 빨강이 존재하면 마지막-1까지 탐색하기)
3. 빨강을 진행하여 경로상 HOLE 여부 확인, 
    - HOLE일 경우 n+1 리턴 (현재 움직임 포함)
    - BLUE/WALL일 경우 정지 후 dfs 재귀 호출

- n이 10 이상일 경우 -1 리턴    
- 탐색 경로 벽 -> 멈춤
'''

WALL = "#"
ROAD = "."
RED = "R"
BLUE = "B"
HOLE = "O"

STATE_HOLE = 0
STATE_NONE = 1
STATE_POS = 2

### Function ###
def compare_pos(a, b):
    return a[0] == b[0] and a[1] == b[1]

def check_path(grid, r_pos, b_pos, dim, step):
    r_pos_next = None
    
    # Check blue
    pos = list(b_pos)
    pos[dim] += step
    is_red_in_path = False
    while True:
        if compare_pos(pos, r_pos):
            is_red_in_path = True
        if grid[pos[0]][pos[1]] == HOLE: # Invalid!
            return (STATE_NONE,)
        if grid[pos[0]][pos[1]] == WALL: # End of the loop
            pos[dim] -= step
            break
        pos[dim] += step
    
    if is_red_in_path:
        pos[dim] -= step
                    
    b_pos_next = tuple(pos)
    
    # Check red
    pos = list(r_pos)
    pos[dim] += step
    is_blue_in_path = False
    while True:
        if compare_pos(pos, b_pos):
            is_blue_in_path = True
        if grid[pos[0]][pos[1]] == HOLE: # Path found!
            return (STATE_HOLE,)
        if grid[pos[0]][pos[1]] == WALL: # End of the loop
            pos[dim] -= step
            break
        pos[dim] += step
    # TERMINATION: position is before WALL or HOLE
    if is_blue_in_path:
        pos[dim] -= step
    
    r_pos_next = tuple(pos)
    
    #### BUG POINT ####
    # if compare_pos(r_pos, r_pos_next): # red is in the same place
    #     return (STATE_NONE,) 

    return (STATE_POS, r_pos_next, b_pos_next)

def dfs(grid, g_size, r_pos, b_pos, n):
    if n == 10:
        return -1
    
    path_results = [
        check_path(grid, r_pos, b_pos, 0, +1),
        check_path(grid, r_pos, b_pos, 0, -1),
        check_path(grid, r_pos, b_pos, 1, +1),
        check_path(grid, r_pos, b_pos, 1, -1)
    ]
    
    final_result = []
    
    for path_result in path_results:
        status = path_result[0]
        if status == STATE_HOLE:
            return n+1
        if status == STATE_POS:
            sub_result = dfs(grid, g_size, path_result[1], path_result[2], n+1)
            if sub_result != -1:
                final_result.append(sub_result)
    
    if len(final_result) == 0:
        return -1
    
    return min(final_result)

### Main ###
g_size = list(map(int, input().split(" ")))
r_pos, b_pos = None, None

grid = [None for _ in range(g_size[0])]
for i in range(g_size[0]):
    line = list(input())
    # Extract pos
    for j in range(g_size[1]):
        if line[j] == RED:
            r_pos = (i, j)
            line[j] = ROAD
        elif line[j] == BLUE:
            b_pos = (i, j)
            line[j] = ROAD 
            
    # Construct map
    grid[i] = line

print(dfs(grid, g_size, r_pos, b_pos, 0))