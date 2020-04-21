N = int(input())

for i in range(N-1, 0, -1):
    print(' '*(i), '*'*(2*(N-i)-1), sep='')

for i in range(0, N+1):
    print(' '*(i), '*'*(2*(N-i)-1), sep='')