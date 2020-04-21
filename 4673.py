def d(n):
    sum = n
    while True:
        sum+=n%10
        n//=10
        if n==0:
            break
    return sum
numbers = []
for num in range(1,10001):
    dNum = d(int(num))
    if not (dNum in numbers):
        numbers.append(dNum)

for i in range(1, 10001):
  if not (i in numbers):
      print(i)  