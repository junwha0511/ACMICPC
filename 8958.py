N = int(input())
for i in range(N):
    results = input()
    for j in range(len(results), 0, -1):
        results = results.replace('X'*j,'.')
    results = results.split('.')
    sum = 0
    for o in results:
        sum += int(len(o)*(len(o)+1)/2)
    print(sum)