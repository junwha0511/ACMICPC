'''
Naive: typical fibo
1000000000
000000000 => O(N)도 1000000000초
O(logN)은 필요함
모듈로 1000000000에서 줄일 수 있는 방법을 찾아야
0 1 1 2 3 5
f[n] = f[2]*f[n-1] + f[1]*f[n-2]
= f[3]*f[n-2] + f[2]*f[n-3]
= f[4]*f[n-3] + f[3]*f[n-4]
= f[5]*f[n-4] + f[4]*f[n-5]
= f[6]*f[n-5] + f[5]*f[n-6]
...
= f[k]*f[n-(k-1)] + f[k-1]*f[n-k]

=> k를 정하면 log_k(N)만에 계산이 가능하다! (k씩 건너 뛰기)

hmm
'''

N = int(input())
P = 1000000
K = 1000000
f = [None for _ in range(K+1)]
f[0] = 0
f[1] = 1

for i in range(2, K+1):
    f[i] = (f[i-1] + f[i-2]) % P

q = [(1, N)]
result = 0
while len(q) > 0:
    c, n = q.pop()
    if n <= K:
        result = (result + ((c*f[n]) % P)) % P
    else:
        q.append(((c*f[K])%P, n-(K-1)))
        q.append(((c*f[K-1])%P, n-K))
print(result)