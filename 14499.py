''''
NxM
상하좌우 (r, c)

윗면이 1이고, 오른쪽이 3
(x, y)에 놓임

주사위 전체 0 적힘???

지도가 0이면 주사위의 바닥면에 쓰여 있는 수가 칸에 복사됨
0이 아닌 경우에는 칸의 수가 주사위의 바닥면으로 복사됨


그냥 일단 지도를 다 받음

주사위를 어떻게 유지할 것인가?가 가장 중요한 문제
map을 만들면 됨 
왼쪽으로 갔을 때 주어져야 하는 수
오른쪽으로 갔을 때 주어져야 하는 수
...

주사위 회전하면?

1. 지도 입력
2. 주사위 초기화 (map으로 이동 가능한 방향 index 3D 매핑)
3. 이동에 따라 map과 주사위 정보 업데이트

<정면도>
  상
좌   우
  하
<평면도>
  전
좌   우 
  후
  
  
북쪽: B -> F, F -> T, T -> C, C -> B
남쪽: 북쪽 인버스
서쪽: B -> L, L -> T, T -> R, R -> B
동쪽: 서쪽 인버스

'''
EAST = 0
WEST = 1
NORTH = 2
SOUTH = 3

T = 0
B = 1
L = 2
R = 3
F = 4
C = 5 # BACKs

N, M, x, y, K = map(int, input().split()) 

grid = []
for i in range(N):
    grid.append(list(map(int, input().split())))

insts = [i-1 for i in map(int, input().split())]

SN = [B, F, T, C]
EW = [B, R, T, L]

dice_info = [0, 0, 0, 0, 0, 0] 
info_mapping = [0, 1, 2, 3, 4, 5]

directions = ((0, 1), (0, -1), (-1, 0), (1, 0)) # E W N S

for inst in insts:
    dx, dy = directions[inst]
    nx, ny = x+dx, y+dy
    if nx < 0 or nx >= N or ny < 0 or ny >= M:
        continue
    x, y = nx, ny

    seq = None
    # Move and Mapping
    if inst == EAST:
        seq = EW[::-1]
    elif inst == WEST:
        seq = EW 
    elif inst == NORTH:
        seq = SN
    elif inst == SOUTH:
        seq = SN[::-1]

    before = info_mapping[seq[-1]]
    for i in range(4):
        value = info_mapping[seq[i]]
        info_mapping[seq[i]] = before
        before = value
        
    if grid[x][y] == 0:
        grid[x][y] = dice_info[info_mapping[B]]
    else:
        dice_info[info_mapping[B]] = grid[x][y] 
        grid[x][y] = 0
    
    print(dice_info[info_mapping[T]])
