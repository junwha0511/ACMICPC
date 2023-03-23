'''
H*X+Y
X < W
Y < H
'''

T = int(input())
for _ in range(T): 
    H, W, N = map(int, input().split())
    c = N%H
    print(str(c if c != 0 else H)+str(N//H+1 if c != 0 else N//H).zfill(2))