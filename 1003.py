seq = [[1,0] + [-1]*39, [0,1] + [-1]*39]

def fibo(n, i):
    if n == 0:
        return seq[i][0]
    elif n == 1:
        return seq[i][1]
    else:
        if seq[i][n] == -1:
            seq[i][n] = fibo(n-1, i) + fibo(n-2, i)
            return seq[i][n]
        else:
            return seq[i][n]



T = int(input())
for i in range(T):
    n = int(input())
    print(fibo(n, 0), fibo(n, 1))      
