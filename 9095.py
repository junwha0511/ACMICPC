N = int(input())
cnt = [0, 1, 2, 4]+[-1]*(8)

def count(n):
    if cnt[n] != -1:
        return cnt[n]
    else:
        cnt[n] = count(n-1)+count(n-2)+count(n-3)
        return cnt[n]

for i in range(N):
    print(count(int(input())))