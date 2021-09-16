for i in range(1, int(input()) + 1):
    print('Case #' + str(i), end = ': ')
    s = input()
    res = ''
    c = 1
    for i in s:
        if i == '<':
            c = 0
        elif i == '>':
            c = len(res)
        else:
            res = res[:c] + i + res[c:]
            c += 1
    print(res)
