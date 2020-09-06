N, M = map(int, input().split(" "))
staff = list(map(int, input().split(" ")))

st = 0
et = 1000000000000

while st < et:
    mt = (st + et) // 2

    balloonCount = 0
    for i in range(N): 
        balloonCount += mt // staff[i]
    
    if balloonCount > M:
        et = mt
    elif balloonCount == M:
        print(mt)
        break
    elif balloonCount < M:
        st = mt
