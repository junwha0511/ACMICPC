while True:
    three = list(map(int, input().split()))
    if three[0] == 0:
        break
    three.sort()
    if (three[0]**2+three[1]**2) == three[2]**2:
        print("right")
    else:
        print("wrong")