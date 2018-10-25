from cs50 import get_int

row = get_int('Height: ')
while True:
    if row < 0 or row > 23:
        row = get_int('Height: ')
    else:
        break

for i in range(0, row):
    for sp in range(0, row-i-1):
        print('', end=' ')
    for j in range(0, i+2):
        print('#', end='')
    print('')
