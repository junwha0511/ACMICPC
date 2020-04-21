(a, b) = [int(i[::-1]) for i in input().split()]
print(a if a > b else b)