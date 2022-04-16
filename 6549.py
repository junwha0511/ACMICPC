
 
def getMaxWithMiddle(A, p, q):
    m = (p+q)//2
    
    i = m
    j = m
    min_height = A[m]
    max_area = 0
    
    while True:
        min_height = min(min(A[i], A[j]), min_height)

        while (i-1) >= p and min_height <= A[i-1]:
            i -= 1
        
        while (j+1) <= q and min_height <= A[j+1]:
            j += 1

        max_area = max(((j-i+1)*min_height), max_area)

        if i > p and j < q:
            if A[i-1] <= A[j+1]:
                j += 1
            else:
                i -= 1
        elif i > p:
            i -= 1
        elif j < q:
            j += 1
        else:
            break

    return max_area

def getMaxArea(A, p, q):
    if p == q: 
        return A[p]
    
    m = (p+q)//2
    
    leftMaxArea = getMaxArea(A, p, m)
    rightMaxArea = getMaxArea(A, m+1, q)
    midMaxArea = getMaxWithMiddle(A, p, q)

    return max(max(leftMaxArea, rightMaxArea), midMaxArea)

while True:
    a = list(map(int, input().split(" ")))
    length = a[0]
    a = a[1:]

    if not length: 
        break
    
    print(getMaxArea(a, 0, length-1))