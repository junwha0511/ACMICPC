def powC(a, b, c):
    if b == 0:
        return 1
    
    if b%2 == 0:
        return powC(a, b//2, c)*powC(a, b//2, c) % c
    else:
        return powC(a, b//2, c)*powC(a, b//2, c)*a %c

A, B, C = map(int, input().split(" "))
print(powC(A, B, C))
