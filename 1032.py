N = int(input())
insts = []

for i in range(N):
    insts.append(list(input()))

pattern = insts[0]

for i in range(1,N):
    for j in range(len(insts[i])):
        if insts[i][j]!=pattern[j]:
            pattern[j] = '?'
print(''.join(pattern))