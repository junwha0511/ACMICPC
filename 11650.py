N = int(input())


coorList = []

for n in range(N):
    coorList.append(list(map(int, input().split(' '))))

coorList.sort(key=lambda x: x[1])

for n in range(N):
    print(coorList[n][0], coorList[n][1])
