#L1-metric이 최대가 되려면 y축 상으로, x축 상으로 가장 멀어야 함
#즉, 전체 좌표의 콜라이더를 찾으면 콜라이더 외곽의 좌표들을 조합해 답을 추릴 수 있음
def getL1MetricDistance(coor1, coor2):
    return abs(coor1[0]-coor2[0]) + abs(coor1[1]-coor2[1])

N = int(input())

coordinates = []
for n in range(N):
    coordinates.append(tuple(map(int, input().split(' '))))

# minX = coordinates[0][0]
# maxX = coordinates[0][0]
# minY = coordinates[0][1]
# maxY = coordinates[0][1]

# for x,y in coordinates:
#     if x < minX:
#         minX = x
#     elif x > maxX:
#         maxX = x
#     if y < minY:
#         minY = y
#     elif y > maxY:
#         maxY = y

# lineCoords = []
# for x,y in coordinates:
#     if x == minX or x == maxX or y == minY or y == maxY:
#         lineCoords.append((x,y))

maxL1MetricDistance = -1

for coor1 in coordinates:
    for coor2 in coordinates:
        if coor1[0] != coor2[0] and coor1[1] != coor2[1]:
            L1MetricDistance = getL1MetricDistance(coor1, coor2)
            if L1MetricDistance > maxL1MetricDistance:
                maxL1MetricDistance = L1MetricDistance

print(maxL1MetricDistance)