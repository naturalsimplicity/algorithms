

def main():
    s1 = input()[::-1]
    s2 = input()[::-1]

    s1 += '0' * (max(len(s1), len(s2)) - len(s1))
    s2 += '0' * (max(len(s1), len(s2)) - len(s2))

    res = ''
    i = 0
    prev = 0
    while i < len(s1):
        res += str((int(s1[i]) + int(s2[i]) + prev) % 2)
        prev = (int(s1[i]) + int(s2[i]) + prev) // 2
        i += 1
    if prev == 1:
        res += '1'
    print(res[::-1])

if __name__ == '__main__':
    main()
