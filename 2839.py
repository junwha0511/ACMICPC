N = int(input())

if N%5 == 0:
    print(N//5)
else:
    v5 = N//5
    flag = True
    while v5 >= 0:
        if (N-(5*v5))%3 == 0:
            print(v5+(N-(5*v5))//3)
            flag = False
            break
        else:
            v5 -= 1
    if flag:
        print(-1)