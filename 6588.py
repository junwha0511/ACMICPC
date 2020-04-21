import sys

primes = [True if i%2 == 1 else False for i in range(1000001)]
primes[0] = False
primes[1] = False

for i in range(3, 1000000, 2):
    if primes[i]:
        j = 2
        while (i*j) < 1000001:
            primes[i*j] = False
            j+=1
while True:
    n = int(sys.stdin.readline())

    if n == 0:
        break

    for p in range(n-3, 2, -2):
        if primes[p] and primes[n-p]:
            print(str(n)+' = '+str(n-p)+' + '+str(p))
            break
    else:
        print("Goldbach's conjecture is wrong.")
