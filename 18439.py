a = input()
b = input()

#preprocess
alphabet = set(a)|set(b)

for i in range(len(a)):
    if not (a[i] in alphabet):
        del a[i]
for i in range(len(b)):
    if not (b[i] in alphabet):
        del b[i]

def findLength(subA, B):
    comparator = subA[:]
    print(comparator)
    for i in range(len(B)):
        if (len(comparator)>0) and (comparator[0] == B[i]):
            comparator = comparator[1:]
            
    if len(comparator) == 0:
        return len(subA)

    maxLength = 0
    for i in range(len(subA)):
        tempLength = findLength(subA[:i]+subA[i+1:], B)
        if tempLength > maxLength:
            maxLength = tempLength
            
    return maxLength

if len(a) < len(b):
    print(findLength(a, b))
else:
    print(findLength(b, a))
