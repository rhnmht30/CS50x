import sys
from cs50 import get_string


def main():
    if len(sys.argv) != 2:
        print('Wrong number of arguments')
        sys.exit(1)
    k = sys.argv[1]
    sizek = len(k)
    code = list()
    for i in k:
        if not i.isalpha():
            sys.exit(1)
        if i.islower():
            code.append(ord(i) - 97)
        if i.isupper():
            code.append(ord(i) - 65)

    pt = get_string('Plaintext: ')
    ct = list()
    size = len(pt)
    c = 0
    for j in range(0, size):
        if c < sizek:
            if pt[j].islower():
                ct.append(chr((((ord(pt[j]) + code[c]) - 97) % 26) + 97))
                c = c + 1
            elif pt[j].isupper():
                ct.append(chr((((ord(pt[j]) + code[c]) - 65) % 26) + 65))
                c = c + 1
            else:
                ct.append(pt[j])
        if c == sizek:
            c = 0
    print('ciphertext:', ''.join(str(e) for e in ct))


if __name__ == "__main__":
    main()