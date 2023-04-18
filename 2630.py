def count_square(g, sx, sy, ex, ey):
    if sx == ex and sy == ey:
        if g[sx][sy] == 0:
            return (1, 0)
        return (0, 1)

    sub_squares = [
        count_square(g, sx, sy, (sx+ex)//2, (sy+ey)//2),
        count_square(g, (sx+ex)//2+1, sy, ex, (sy+ey)//2),
        count_square(g, sx, (sy+ey)//2+1, (sx+ex)//2, ey),
        count_square(g, (sx+ex)//2+1, (sy+ey)//2+1, ex, ey),
    ]
    
    w = 0
    b = 0
    for i in range(len(sub_squares)):
        w += sub_squares[i][0]
        b += sub_squares[i][1]
    
    if w == 0: # b must be 4
        return (0, 1)
    if b == 0:
        return (1, 0)
    return (w, b)
    

N = int(input())
g = [list(map(int, input().split())) for _ in range(N)]
print(*count_square(g, 0, 0, N-1, N-1), sep="\n")
