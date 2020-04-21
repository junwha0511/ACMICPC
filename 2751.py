n = int(input())
numbers = []
[numbers.append(int(input())) for i in range(n)]
numbers.sort()
[print(i) for i in numbers]