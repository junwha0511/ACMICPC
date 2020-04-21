N = int(input())

for i in range(1, N):
    print('*'*(i), ' '*(2*(N-i)-1), sep='', end=' ')
    print('*'*(i))

print('*'*(2*N))

for i in range(N-1, 0, -1):
    print('*'*(i), ' '*(2*(N-i)-1), sep='', end=' ')
    print('*'*(i))


