import sys
stack = []

def push(s, x):
    s.append(x)

def empty(s):
    if not len(s):
        return 1
    else:
        return 0

def pop(s):
    if not len(s):
        return -1
    else:
        t = s[-1]
        del s[-1]
        return t

def size(s):
    return len(s)

def top(s):
    if not len(s):
        return -1
    else:
        return s[-1]

T = int(sys.stdin.readline().rstrip('\n'))
for i in range(T):
    inst = int(sys.stdin.readline().rstrip('\n'))
    if inst == 0:
        pop(stack)
    else:    
        push(stack, inst)
print(sum(stack))