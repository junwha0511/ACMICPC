line = input().split(' ')
ascending = sorted(line)
descending = sorted(line, reverse=True)

if line == ascending:
    print('ascending')
elif line == descending:
    print('descending')
else:
    print('mixed')