key = list(input())

key.sort()

tree = []

interval = len(key)
for i in range(1, len(key)+1):
    
    for j in range(i):
        start = j*interval
        end = (j+1)*interval
        mid = (start+end)//2
        if key[mid] != None:
            tree.append(key[mid])
            key[mid] = None
    interval = (interval-1)//2

print(tree)


12345678

