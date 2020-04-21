def isSquareNum(n, m):
    i = 0
    while n != 1:
        if n%m != 0:
            return False
        n //= m
        i += 1
    return i
N = int(input())
M = int(input())

sqns = []
sum = 0
for i in range(N, M+1):
    for j in range(1, int(N**0.5)):
        sqn = isSquareNum(i, j)
        if sqn and (N <= j**sqn <= M):
            sum += j**sqn
            sqns.append(j**sqn)

print(sum)
print(sqns[0])