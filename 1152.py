txt = ' '+input()
cnt = 0
for i in range(len(txt)-1):
    if txt[i] == ' ' and txt[i+1] != ' ':
        cnt+=1
print(cnt)

