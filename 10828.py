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
    inst = sys.stdin.readline().rstrip('\n')
    if len(inst)>=4 and inst[0:4]=='push':
        push(stack, int(inst.split(' ')[1]))
    elif inst == 'empty':
        print(empty(stack))
    elif inst == 'pop':
        print(pop(stack))
    elif inst == 'size':
        print(size(stack))
    elif inst == 'top':
        print(top(stack))