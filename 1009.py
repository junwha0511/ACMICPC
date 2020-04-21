import sys
n = int(sys.stdin.readline().rstrip('\n'))
for i in range(n):
    (a,b) = (int(i) for i in sys.stdin.readline().rstrip('\n').split(' '))
    b%=4
    c = ((a%10)**(b if b!=0 else 4))%10
    print(c if c!=0 else 10)