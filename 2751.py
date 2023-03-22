N = int(input())
arr = [int(input()) for i in range(N)]

def merge_sort(arr, start, end):
    if end - start <= 1:
        return
    mid = (start+end)//2
    merge_sort(arr, start, mid)
    merge_sort(arr, mid, end)
    
    left = arr[start:mid].copy()
    right = arr[mid:end].copy()
    i, j, k = 0, 0, start
    
    while k < end:
        if i == len(left):
            arr[k] = right[j]
            j += 1
        elif j == len(right):
            arr[k] = left[i]
            i += 1
        else:
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
        k += 1

merge_sort(arr, 0, N)

for a in arr:
    print(a)