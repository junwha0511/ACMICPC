A, B = map(int, input().split())

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)
    
g = gcd(A, B)
l = A*B//g

print(g)
print(l)
    