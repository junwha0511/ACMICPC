M = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
D = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
m, d = map(int, input().split(' '))
print(D[(sum(M[0:m])+d) % 7])