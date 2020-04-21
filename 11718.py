import sys
lines = []
for i in range(100):
    a = sys.stdin.readline()
    if a == '\n':
        break
    else:
        lines.append(a.rstrip('\n'))

[print(line) for line in lines]