N = int(input())

arr = []
for i in range(N):
    age, name = input().split()
    arr.append((i, int(age), name))

arr.sort(key=lambda x: (x[1], x[0]))

for a in arr:
    print(a[1], a[2])