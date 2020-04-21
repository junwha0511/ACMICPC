N = int(input())
cnts = [N]*(N+1)

cnts[1] = 0
for i in range(1, N+1):
    if i < N:
        cnts[i+1] = min(cnts[i+1], cnts[i] + 1)
    if i*3 < N+1:
        cnts[i*3] = min(cnts[i]+1, cnts[i*3])
    if i*2 < N+1:
        cnts[i*2] = min(cnts[i]+1, cnts[i*2])
print(cnts[N])