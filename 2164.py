'''
N - 1을 버리고 2가 제일 밑으로 감
N-1 - 3을 버리고 4가 제일 밑으로 감
N-2 - 5를 버리고 6이 제일 밑으로 감
...

2 4 6 8, ...이 아래에 쌓이게 됨

N이 홀수라면, 
4, 6, 8, ... N-1, 2 순서로 카드 위치


N이 짝수라면, 
2, 4, 6, 8, ..., N 순서로 카드 위치

1: 1
2: 2
3: 2
4: 4
5: 4
6: 4
7: 6
8: 8
9: 8
10: 


홀수번째 모두 제거?

즉, 홀수번째가 모두 사라지고 순서가 유지되는 것
단, 이 때 짝수로 항상 끝나야함. 만약 끝 부분이 제거되었다면 앞에서 당겨올 것


한 번 iteration을 할 때마다 1/2가 됨 => 1개가 나을 때까지 반복
1 + 2 + 4 + ... + 2^(lgN) = O(N)
'''

N = int(input())

numbers = [i+1 for i in range(N)]

top = 0
bottom = N-1

while bottom-top >= 1:
    top += 1 # Discard
    numbers.append(numbers[top])
    top += 1 # Discard
    bottom += 1

print(numbers[bottom])