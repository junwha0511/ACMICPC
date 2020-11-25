N = int(input())

todoRange = [[] for i in range(366)]
calender = [[False for j in range(1000)] for i in range(365)]

for i in range(N):
    S, E = map(int, input().split(' '))
    todoRange[S-1].append(E-1)

for d in todoRange:
    d.sort(reverse=True)

conti, maxHeight, width, area = (False, 0, 0, 0)

height = [0 for i in range(366)]
for i in range(365):
    for r in todoRange[i]:
        row = 0
        for k in range(1000):
            if not calender[i][k]:
                row = k
                break
        for j in range(i, r+1):
            calender[j][row] = True
            if height[j] < (row+1):
                    height[j] = row+1
for i in range(366):
    if height[i] != 0:
        if not conti:
            conti = True
        width += 1
        if height[i] > maxHeight:
            maxHeight = height[i]
    elif height[i] == 0 and conti:
        area += maxHeight * width 
        conti, maxHeight, width = (False, 0, 0)
    
print(area)

# for i in range(15):
#     for j in range(15):
#         print('■' if calender[j][i] else '□', end=' ')
#     print()
    