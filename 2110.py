N, C = map(int, input().split(' '))

houseCoords = []
for i in range(N):
    houseCoords.append(int(input()))
houseCoords.sort()

def findNearestPoint(houseCoords, start, end, point):    
    while start+1 < end:
        mid = (start+end)//2

        if houseCoords[mid] < point:
            start = mid
        elif houseCoords[mid] == point:
            return point
        else:
            end = mid

    if(abs(point-houseCoords[start])>abs(point-houseCoords[end])):
        return houseCoords[end]
    else:
        return houseCoords[start]

        

sp = houseCoords[0]
ep = houseCoords[-1]
interval = (ep - sp) / C

routerCoords = []

for i in range(0, C):
    routerCoords.append(findNearestPoint(houseCoords, 0, N-1, sp+(interval*i)))

minI = float('inf')

for i in range(0, C-1):
    routerInterval = abs(routerCoords[i]-routerCoords[i+1])
    if minI > routerInterval:
        minI = routerInterval

print(minI)