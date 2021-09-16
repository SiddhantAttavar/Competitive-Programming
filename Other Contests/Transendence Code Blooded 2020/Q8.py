for i in range(1, int(input()) + 1):
    print('Case #' + str(i), end = ': \n')
    n, q = map(int, input().split())
    sign = [0] * n
    par = [0] * n
    a = list(map(int, input().split()))
    for j in range(n):
       if a[j] != 0:
           sign[j] = 1 if a[j] > 0 else -1
           par[j] = 1 if a[j] % 2 == 0 else -1
    for j in range(q):
        op, l, r = input().split()
        l, r = int(l) - 1, int(r) - 1
        if op == 'U':
            if r == 0:
                sign[l] = par[l] = 0
            else:
                sign[l] = 1 if (r + 1) > 0 else -1
                par[l] = 1 if r % 2 == 1 else -1
        elif op == 'S':
            if a[l] == 0 or a[r] == 0:
                print(0)
            else:
                print('+' if sign[l] == sign[r] else '-')
        else:
            if a[l] == 0 or a[r] == 0:
                print('E')
            else:
                print('E' if sign[l] == 1 and sign[r] == 1 else 'O')
