def powC(a, b, c):
    if b == 0:
        return 1
    
    result = powC(a, b//2, c)**2
    if b%2 == 0:
        return result % c
    else:
        return result*a %c

A, B, C = map(int, input().split(" "))
print(powC(A, B, C))
