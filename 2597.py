N = int(input())
scores = [0] + [int(input()) for i in range(N)]
maxScores = [0, scores[1]]+[0]*(N-1)
before = [False]*(N+1)
for i in range(1, N):
    if not before[i]:
        maxScores[i+1] = max(maxScores[i]+scores[i+1], maxScores[i+1])
        if maxScores[i+1] == maxScores[i]+scores[i+1]:
            before[i+1] = True
    if i+2 < N+1:
        maxScores[i+2] = max(maxScores[i]+scores[i+2], maxScores[i+2])
        if maxScores[i+2] == maxScores[i]+scores[i+2]:
            before[i+2] = False

      
print(maxScores[-1])