import sys

N = int(input())
primes = [True for i in range(1001)]
primes[0] = False
primes[1] = False

for i in range(2, 1001):
    if primes[i]:
        j = 2
        while (i*j) < 1001:
            primes[i*j] = False
            j+=1
numbers = map(int, input().split(' '))
cnt = 0
for n in numbers:
    if primes[n]:
        cnt += 1
print(cnt)