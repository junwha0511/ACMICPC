def facto(N):
    if N == 0:
        return 1
    else:
        return facto(N-1)*N
def combination(N, R):
    return int(facto(N)/(facto(R)*facto(N-R)))

N = int(input())
for i in range(N):
    w, e = map(int, input().split(' '))
    print(combination(e, w))