'''
Naive: typical fibo
1000000000
000000000 => O(N)도 1000000000초
O(logN)은 필요함
모듈로 1000000000에서 줄일 수 있는 방법을 찾아야

https://math.stackexchange.com/questions/3718940/logic-behind-pisano-period
(Proof by pigeonhole principle)
Pi(n) for 10^k = 15*10^(k-1)

'''
N = int(input())
M = 10**6
P = 15*10**5

f = [None for _ in range(P+1)]
f[0] = 0
f[1] = 1

for i in range(2, P+1):
    f[i] = (f[i-1] + f[i-2]) % M

print(f[N%P])