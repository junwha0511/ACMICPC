line = input()
for i in range(0, len(line)//10):
    print(line[10*i:10*(i+1)])
print(line[10*(len(line)//10):])
