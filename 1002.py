def getPositionCount(x1, y1, r1, x2, y2, r2):
    distance = ((x1-x2)**2+(y1-y2)**2)**0.5
    if x1 == x2 and y1 == y2: #중심 일치
        if r1 == r2: #같은 원
            return -1
        else: #교점이 없는 두 원
            return 0
    elif distance == (r1+r2) or distance == abs(r1-r2): #외접 혹은 내접
        return 1
    elif distance > (r1+r2) or distance < abs(r1-r2): #교점이 없는 두 원
        return 0
    elif distance < (r1+r2): #두 교점을 가지는 원
        return 2

lineNum = int(input())

for i in range(lineNum):
    x1, y1, r1, x2, y2, r2 = map(int, input().split(' '))
    print(getPositionCount(x1, y1, r1, x2, y2, r2))