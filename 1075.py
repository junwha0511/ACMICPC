N, F = int(input()), int(input())
for i in range(N-(N%100), (N-(N%100))+100):
    if i%F == 0:
        print(str(i)[-2:])
        break

