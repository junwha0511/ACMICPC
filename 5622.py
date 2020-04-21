apb = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']
numbers = input()
time = 0
for n in numbers:
    for i in range(8):
        if n in apb[i]:
            time += 3+i
            break
print(time)