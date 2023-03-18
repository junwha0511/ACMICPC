'''
초등학교 교실
NxN
한 칸에는 한 명의 학생만
|r1 - r2| + |c1 - c2| = 1이면 인접함 (위 아래)
1. 좋아하는 학생이 인접한 칸에 가장 많은 칸
2. 1을 만족하는 칸 중 -> 인접한 칸에 비어있는 칸이 가장 많은 칸
3. 행의 번호 가장 작은
4. 열의 번호 가장 작은

NxN 
'''

def count_likes(grid, N, x, y, likes):
    cnt = 0
    
    if x != 0:
        if grid[x-1][y] in likes:
            cnt += 1
    if x != N-1:
        if grid[x+1][y] in likes:
            cnt += 1
    if y != 0:
        if grid[x][y-1] in likes:
            cnt += 1
    if y != N-1:
        if grid[x][y+1] in likes:
            cnt += 1
       
    return cnt  
            
def count_empties(grid, N, x, y):
    cnt = 0
    
    if x != 0:
        if grid[x-1][y] == None:
            cnt += 1
    if x != N-1:
        if grid[x+1][y] == None:
            cnt += 1
    if y != 0:
        if grid[x][y-1] == None:
            cnt += 1
    if y != N-1:
        if grid[x][y+1] == None:
            cnt += 1
       
    return cnt  

satisfy_score_map = [0, 1, 10, 100, 1000]

N = int(input())
likes_map = {}
students = []

for i in range(N*N):
    info = input().split(" ")
    likes_map[info[0]] = info[1:]
    students.append(info[0])

seats = [[None for _ in range(N)] for __ in range(N)]


for sid in students:
    opt_x = N
    opt_y = N
    opt_like_cnt = -1
    opt_empty_cnt = -1
    
    for i in range(N):
        for j in range(N):
            if seats[i][j] == None: # only when empty
                like_cnt = count_likes(seats, N, i, j, likes_map[sid])
                if like_cnt > opt_like_cnt:
                    opt_like_cnt = like_cnt
                    opt_empty_cnt = count_empties(seats, N, i, j)
                    opt_x, opt_y = i, j
                elif like_cnt == opt_like_cnt:   
                    empty_cnt = count_empties(seats, N, i, j)
                    if empty_cnt > opt_empty_cnt: # like cnt is already same
                        opt_empty_cnt = empty_cnt
                        opt_x, opt_y = i, j
                    elif empty_cnt == opt_empty_cnt:
                        if i < opt_x: # like and empty is already same
                            opt_x, opt_y = i, j
                        elif i == opt_x and j < opt_y:
                            opt_x, opt_y = i, j
                        # otherwise, current is optimal one (smaller row or col)
                    # otherwise, current is optimal one (more empty)
                # otherwise, current is optimal one (more likes)        
    seats[opt_x][opt_y] = sid

score = 0
for i in range(N):
    for j in range(N):
        score += satisfy_score_map[count_likes(seats, N, i, j, likes_map[seats[i][j]])]
print(score)