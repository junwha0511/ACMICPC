#<차집합의 원소의 개수: N(집합)-N(교집합)> 대칭차집합의 원소의 개수는 N(A)+N(B)-2N(교집합)  
#set() 미사용 코드

NA, NB = map(int, input().split(' '))
A = list(map(int, input().split(' ')))
B = list(map(int, input().split(' ')))

def mergeSort(li):
    if len(li) == 1:
        return li

    i = mergeSort(li[:len(li)//2])
    f = mergeSort(li[len(li)//2:])
    newList = []
    while len(i)+len(f):
        if len(i) == 0:
            newList.append(f[0])
            del f[0]
        elif len(f) == 0:
            newList.append(i[0])
            del i[0]
        elif i[0] < f[0]:
            newList.append(i[0])
            del i[0]
        elif f[0] <= i[0]:
            newList.append(f[0])
            del f[0]
    return newList

def binarySearch(target, li):
    left = 0
    right = len(li)-1

    while left <= right:
        mid = (left+right) // 2
        
        if li[mid] == target:
            return True
        elif li[mid] < target:
            left = mid+1
        elif li[mid] > target:
            right = mid-1

    return False        


A = mergeSort(A)
B = mergeSort(B)
            
interN = 0

for b in B:
    if binarySearch(b, A):
        interN += 1

print(len(A)+len(B)-2*interN)

            