M, N = map(int, input().split())
is_prime = [True for i in range(N+1)]
is_prime[0], is_prime[1] = False, False

for i in range(2, N+1):
    if is_prime[i]:
        j = 2
        while i*j <= N:
            is_prime[i*j] = False
            j += 1
            
for i in range(M, N+1):
    if is_prime[i]:
        print(i)