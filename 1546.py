N = int(input())
scores = [int(i) for i in input().split(' ')]
scores.sort()
print(scores[-1])
sum = 0
for i in range(N):
    sum += (scores[i]/scores[-1])*100
print(sum/N)
