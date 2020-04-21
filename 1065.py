def isSeq(n):
    diff = ((n//10)%10) - (n%10)
    num = n//10
    while True:
        if num//10 == 0:
            return True
        if ((num//10)%10) - (num%10) == diff:
            num//=10
        else:
            return False

N = int(input())
sum = 0
for i in range(1, N+1):
    if isSeq(i):
        sum+=1
print(sum)