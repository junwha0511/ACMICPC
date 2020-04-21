croApb = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
apb = 'abcdefghijklmnopqrstuvwxyz'
txt = input()
cnt = 0
for c in croApb:
    if c == 'z=':
        cnt += txt.count(c) - txt.count('dz=')
    else:
        cnt += txt.count(c)
for c in croApb:
    txt = txt.replace(c, '.')
txt = txt.replace('.', '')
cnt += len(txt)
print(cnt)