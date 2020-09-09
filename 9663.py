N = int(input())
greed = [[False]*N for i in range(N)]

def isValidPos(greed, x, y):
    for i in range(N):
        if i != x and greed[y][i] == True:
            return False
        if i != y and greed[i][x] == True:
            return False

        for j in range(x):
            if abs(x-j) == abs(y-i):
                if greed[i][j] == True:
                    return False

    return True

def placeQueen(greed, x):
    if x == N:
        return 1
    
    cnt = 0
    for y in range(N):
        if isValidPos(greed, x, y):
            greed[y][x] = True
            cnt += placeQueen(greed, x+1)
            greed[y][x] = False

    return cnt

print(placeQueen(greed, 0))