C = int(input())
for i in range(C):
    scores = [int(i) for i in input().split(' ')]
    N = scores.pop(0)
    avg = 0
    for s in scores:
        avg+=s
    avg /= N
    cnt = 0
    for s in scores:
        if s>avg:
            cnt+=1
    print("%.3f" % ((cnt/N)*100)+'%')