
txt = input().lower()
max = -1
maxAlpha = ''
flag = False
for c in 'abcdefghijklmnopqrstuvwxyz':
    cnt = txt.count(c)
    if cnt > max:
        max = cnt
        maxAlpha = c
        if flag:
            flag = False
    elif cnt == max:
        flag = True
if flag:
    print('?')
else:
    print(maxAlpha.upper())