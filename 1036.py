N = int(input())
base = ''.join([str(i) for i in range(0,10)])+'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
numbers = []
M = ['']
for i in range(N):
    numbers.append(input())
    if len(numbers[-1])>len(M[0]):
        M=[numbers[-1]]
    elif len(numbers[-1])==len(M[0]):
        M.append(numbers[-1])
K = int(input())
m = []
for number in M:
    m.append(base.find(number[0]))
m.sort()
m = m[0:K]

sum = 0
for n in range(len(numbers)):
    for i in m:
        numbers[n] = numbers[n].replace(base[i],'Z')
    for i in range(len(numbers[n])):
        sum+=base.find(numbers[n][i])*36**i 
i = 0
result = ''
while sum!=0:
    result = base[sum%36] + result
    sum //= 36
print(result)
