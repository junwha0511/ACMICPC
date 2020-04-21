n = int(input())
c = n
i = 0
while True:    
    i+=1
    new = c//10+c%10
    c = (c%10)*10 + new%10
    if c==n:
        break
print(i)