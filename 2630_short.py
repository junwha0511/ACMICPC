def c(g,x,y,u,v):
    if x==u and y==v:return (1,0) if g[x][y]==0 else (0,1)
    n,m,w,b=(x+u)//2,(y+v)//2,0,0;s=[c(g,x,y,n,m),c(g,n+1,y,u,m),c(g,x,m+1,n,v),c(g,n+1,m+1,u,v)]
    for i,j in s:w+=i;b+=j
    return (1,0) if b==0 else (0,1) if w==0 else (w,b)
N=int(input())-1;g=[list(map(int,input().split())) for _ in range(N+1)];print(*c(g,0,0,N,N),sep="\n")