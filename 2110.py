#공유기 수가 많으면 거리를 늘리고
#공유기 수가 적으면 거리를 줄인다
import sys

N, C = map(int, sys.stdin.readline().split(' '))

houseCoords = [int(sys.stdin.readline()) for i in range(N)]

houseCoords.sort()

left = 1
right = (houseCoords[-1]-houseCoords[0])//(C-1)+1
maxInterval = (left+right)//2

while left<=right:
    mid = (right+left)//2
    routerCount = 1
    lastPoint = 0

    for i in range(1, N):
        if houseCoords[i]-houseCoords[lastPoint] >= mid:
            lastPoint = i
            routerCount += 1

    if routerCount >= C:
        left = mid+1
        maxInterval = mid
    else:
        right = mid-1

sys.stdout.write(str(maxInterval))
        





