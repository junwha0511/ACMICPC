input()
n = int(input())
sum = 0
while True:
    sum += n % 10
    n //= 10
    if n == 0:
        break
print(sum)

