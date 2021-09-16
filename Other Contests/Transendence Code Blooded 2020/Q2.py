for i in range(1, int(input().strip()) + 1):
    print('Case #' + str(i), end = ': ')
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    res = []
    t = 1
    step = (a[-1] - a[0]) // (n - 1)
    for j in range(a[0] + step, a[-1], step):
        if a[t] == j:
            t += 1
        else:
            res.append(j)
    print(' '.join(map(str, res)))
