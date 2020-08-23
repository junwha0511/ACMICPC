m, M = map(int, input().split(' '))

count = 0

for n in range(m, M+1):
    square = n**0.5
    if int(square) != square:
        count += 1



    