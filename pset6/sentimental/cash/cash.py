from cs50 import get_float
q = 25.00
d = 10.00
n = 5.00
p = 1.00

count = 0
owed = get_float('Change owed: ')
while True:
    if owed < 0.0:
        owed = get_float('Change owed: ')
    else:
        break
owedi = owed * 100
while True:
    if owedi < q:
        break
    owedi = owedi - q
    count = count + 1
while True:
    if owedi < d:
        break
    owedi = owedi - d
    count = count + 1
while True:
    if owedi < n:
        break
    owedi = owedi - n
    count = count + 1
while True:
    if owedi < p:
        break
    owedi = owedi - p
    count = count + 1

print(count)