N = int(input())
lines = [input() for i in range(N)]
cnt = 0
for txt in lines:
    apb = []
    for c in txt:
        if not (c in apb):
            apb.append(c)
    for c in apb:
        lastIdx = -1    
        for i in range(len(txt)):
            if txt[i] == c:
                if lastIdx == -1 or lastIdx+1 == i:
                    lastIdx = i
                else:
                    break
        else:
            continue
        break
    else:
        cnt+=1
print(cnt)