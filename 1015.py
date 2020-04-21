n = int(input())
A = [int(i) for i in input().split()]
B = A[:]
P = [-1 for i in range(n)]
B.sort()
for i in range(n):
    for j in range(n):
        if A[i]==B[j]:
            B[j] = -1
            P[i] = j
            break
for num in P:
    print(num, end=' ')


