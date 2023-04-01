'''
이항계수 구하기

1 ~ 4,000,000
곱셈 최적화 문제임

     n!
----------
 k!(n-k)!

= (n)(n-1)...(n-k+1)/k!

페르마의 소정리
a^(p-1) === 1 (mod p)
a^(p-2) === a^(-1) (mod p)

(n)(n-1)...(n-k+1)/k!
= ((n)(n-1)...(n-k+1)) * (k!)^(p-2)
'''

D = 1000000007

def factorial(n, k):
    result = 1
    for i in range(k, n+1):
        result = (result*i) % D 
    return result

def pow(b, e):
    if e == 0:
        return 1
    if e == 1:
        return b
    
    r = pow(b, e//2) % D
    if e % 2 == 0:
        return r*r % D
    if e % 2 == 1:
        return r*r*b % D
    
n, k = map(int, input().split())

print(factorial(n, n-k+1)*pow(factorial(k, 1), D-2)%D)