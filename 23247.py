'''
Naive: O(N^6)

Prefix Sum? (A로부터의 넓이)
A B C
D E F
G H I
=> 넓이 E를 S[A:E] - S[A:B] - S[A:D] + S[A:A]로 구할 수 있음

Prefix Sum을 구하는 로직 O(N^2)
검증 O(N^4)

Optimizing point: 최대 10칸까지만 보면 됨!!
(0, 0) -> (2, 2) 9칸
(0, 0) -> (3, 3) 16칸

''' 
M, N = map(int, input().split())

grid = []
for _ in range(M):
    grid.append(list(map(int, input().split())))

prefix_sum = grid.copy()
for i in range(M):
    for j in range(N):
        if i != 0:
            prefix_sum[i][j] += prefix_sum[i-1][j]
        if j != 0:
            prefix_sum[i][j] += prefix_sum[i][j-1]
        if i != 0 and j != 0:
            prefix_sum[i][j] -= prefix_sum[i-1][j-1]
            
count = 0                    
for si in range(M):
    for sj in range(N):         
       for ei in range(si, min(si+10, M)):
            for ej in range(sj, min(sj+10, N)):       
                area = grid[ei][ej]
                if si != 0:
                    area -= grid[si-1][ej]
                if sj != 0:
                    area -= grid[ei][sj-1]
                if si != 0 and sj != 0:
                    area += grid[si-1][sj-1]
                if area == 10:
                    count += 1
print(count)