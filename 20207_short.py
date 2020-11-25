g,o,c,w,a=[0]*366,0,0,0,0
for i in range(int(input())):
    S,E=map(int,input().split(' '))
    for j in range(S-1,E):
        g[j]+=1
for i in range(366):
    if g[i]!=0 and not o:
        c=g[i]
        o=1
    if o and g[i]!=0:
        w+=1
        c=g[i] if c<g[i] else c
    else:
        a,c,w,o=a+c*w,0,0,0
print(a)