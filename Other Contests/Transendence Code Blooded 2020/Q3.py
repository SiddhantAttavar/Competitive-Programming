for i in range(1, int(input()) + 1):
    print('Case #' + str(i), end = ': ')
    len = int(input())
    n = input()
    res = 2
    for i in range(1, len):
        if n[i] == '1' and n[i - 1] != '1':
            res += 2
    if n[-1] == '1':
        res -= 2
    else:
        res -= 1
    print(res)
