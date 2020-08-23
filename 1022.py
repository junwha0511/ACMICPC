RIGHT, UP, LEFT, DOWN = (0, 1, 2, 3)
r1, c1, r2, c2 = [int(n) for n in input().split(' ')]

n = max(map(abs, (r1, c1, r2, c2)))

#paper = [[-1]*(2*n+1) for i in range(2*n+1)]
paper = [[-1]*(c2-c1+1) for i in range(r2-r1+1)]
x, y = (0, 0)

length = 0
turn = 0
direction = 0
i = 1
while i < (2*n+1)**2:
    dx, dy = (0, 0)
    if direction == RIGHT:
        dx = 1
        length += 1
    elif direction == UP:
        dy = -1
    elif direction == LEFT:
        dx = -1
        length += 1
    elif direction == DOWN:
        dy = +1
    for j in range(length):
        if c1 <= x <= c2 and r1 <= y <= r2:
            paper[y-r1][x-c1] = i
        x += dx
        y += dy
        i += 1
        print(i)
    direction = (direction+1)%4
space = len(str((2*n+1)**2))

for i in range(r2-r1+1):
    for j in range(c2-c1+1):
        stringNum = str(paper[i][j])
        print(' '*(space-len(stringNum))+stringNum, end = ' ')
    print()

# for i in range(r1, r2+1):
#     for j in range(c1, c2+1):
#         print(paper[i][j], end = ' ')
#     print()

