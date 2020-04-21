(a,b) = [int(i) for i in input().split(' ')]
dp = [0]


for i in range(1, 1000):
    tSum = 0
    n = i
    while n!=0:
        tSum += n % 10
        n //= 10
    dp.append(tSum)    

if b<1000:
    print(dp[b]-dp[a-1])
else:
    sum = 0
    n = b
    while True:
        

