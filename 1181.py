N = int(input())

arr = [input() for _ in range(N)]

def merge_sort(arr, start, end):
    if end-start <= 1:
        return
    mid = (start+end)//2
    merge_sort(arr, start, mid)
    merge_sort(arr, mid, end)
    
    left = arr[start:mid]
    right = arr[mid:end]
    
    k = start
    i, j = 0, 0
    while k < end:
        if i == len(left):
            arr[k] = right[j]
            j += 1
        elif j == len(right):
            arr[k] = left[i]
            i += 1
        else:
            if len(right[j]) == len(left[i]):
                if right[j] < left[i]:
                    arr[k] = right[j]
                    j += 1
                else:
                    arr[k] = left[i]
                    i += 1
            elif len(right[j]) < len(left[i]):
                arr[k] = right[j]
                j += 1
            else:
                arr[k] = left[i]
                i += 1        
        k += 1

merge_sort(arr, 0, N)

print(arr[0])
for i in range(1, len(arr)):
    if arr[i] != arr[i-1]:
        print(arr[i])