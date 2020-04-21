(N,M) = [int(i) for i in input().split(' ')]
inputBoard = []
chessBoard1 = []
chessBoard2 = []
cnt = float('infinity')
for i in range(N):
    inputBoard.append(input())
for i in range(8):
    if i%2==0:
        chessBoard1.append('WB'*4)
        chessBoard2.append('BW'*4)
    else:
        chessBoard1.append('BW'*4)
        chessBoard2.append('WB'*4)
for i in range(N-8+1):
    for j in range(M-8+1): 
        cnt1 = 0
        cnt2 = 0
        for k in range(8): 
            for l in range(8):
                if inputBoard[i+k][j+l] != chessBoard1[k][l]:
                    cnt1+=1    
                if inputBoard[i+k][j+l] != chessBoard2[k][l]:
                    cnt2+=1
        cnt = (cnt1 if cnt1<cnt2 else cnt2) if cnt1<cnt or cnt2<cnt else cnt
print(cnt)