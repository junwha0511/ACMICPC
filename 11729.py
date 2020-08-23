def moveTower(initial, middle, final, N):
    if N == 1:
        print(initial, final)
    else:        
        moveTower(initial, final, middle, N-1)

        print(initial, final)
        
        moveTower(middle, initial, final, N-1)


N = int(input())
print(2**N-1)
moveTower(1, 2, 3, N)