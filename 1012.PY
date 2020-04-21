#핵심 포인트: map 문제지만 map 전체를 생각하면 항상 메모리 초과가 뜰 수 밖에 없다
T = int(input())

for t in range(T):
    (M,N,K) = [int(i) for i in input().split(' ')]
    map = [[-1 for j in range(M)] for  i in range(N)]
    cnt = 0
    xyList = []
    
    for k in range(K):
        (x,y) = [int(i) for i in input().split(' ')]
        xyList.append((x,y))

    newList = [[xyList.pop(0)]]

    while len(xyList):
        for i in range(len(xyList)):
            if len(newList[cnt])==0:
                newList[cnt].append(xyList.pop(i))
                break
            elif (xyList[i][0]+1, xyList[i][1]) in newList[cnt]:
                newList[cnt].append(xyList.pop(i))
                break
            elif (xyList[i][0]-1, xyList[i][1]) in newList[cnt]:
                newList[cnt].append(xyList.pop(i))
                break
            elif (xyList[i][0], xyList[i][1]+1) in newList[cnt]:
                newList[cnt].append(xyList.pop(i))
                break
            elif (xyList[i][0], xyList[i][1]-1) in newList[cnt]:
                newList[cnt].append(xyList.pop(i))
                break
        else:
            newList.append([])
            cnt+=1
       
    print(cnt+1)            
                                
