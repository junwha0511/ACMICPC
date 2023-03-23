N = int(input())
numbers = list(map(int, input().split()))
    
M = int (input())
keys = list(map(int, input().split()))

count = {}

for n in numbers:
    count[n] = 0
    
for m in keys:
    count[m] = 0
    
for n in numbers:
    count[n] += 1

for key in keys:
    print(count[key], end=" ")
print()