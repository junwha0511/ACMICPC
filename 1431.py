N = int(input())
lines = []
for i in range(N):
    lines.append(input())
lines.sort(key = lambda x: (len(x), 
    sum([(int(x[i]) if x[i].isdigit() else 0) for i in range(len(x))]),x))

for l in lines:
    print(l)
