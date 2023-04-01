'''
행렬 A의 B 제곱

By associative property,
A^B = (A^B/2)*(A^B/2) (if B%2 == 0)
A^B = (A^B/2)*(A^B/2)*A (otherwise)

슈트라센 필요 없음.

'''

N, B = map(int, input().split())

def matmul(A, B):
    C = [[0 for _ in range(N)] for __ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] = (C[i][j] + ((A[i][k] * B[k][j])%1000)) % 1000
    return C

def matmul_divide_and_conquer(A, B):
    if B == 1:
        return A

    AHB = matmul_divide_and_conquer(A, B//2)
    AHB2 = matmul(AHB, AHB)
    if B % 2 == 0:
        return AHB2
    else:
        return matmul(AHB2, A)

A = []

for i in range(N):
    A.append(list(map(int, input().split())))

C = matmul_divide_and_conquer(A, B)

for i in range(N):
    for j in range(N):
        print(C[i][j]%1000, end=" ")
    print()