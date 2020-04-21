T = int(input())

for i in range(T):
    newTxt = ''
    (n, txt) = input().split(' ')
    n = int(n)
    for c in txt:
        newTxt += c * n
    print(newTxt)