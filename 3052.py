numbers = [int(input())%42 for i in range(10)]
numbers.sort()
cnt = 1
for i in range(1,10):
    if numbers[i] != numbers[i-1]:
        cnt+=1
print(cnt)
