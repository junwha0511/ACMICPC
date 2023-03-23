N, M = map(int, input().split())
cards = list(map(int, input().split()))

max = 0
for i in range(N):
    for j in range(i+1, N):
        for k in range(j+1, N):
            if i == j or j == k or i == k:
                continue
            sum = cards[i] + cards[j] + cards[k]
            if sum > max and sum <= M:
                max = sum
print(max)