for i in range(int(input())):
    n, m = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if ((i % 2 == 0 and j % 2 == 0 and a[i][j] % 2 == 1) or 
                (i % 2 == 0 and j % 2 == 1 and a[i][j] % 2 == 0) or 
                (i % 2 == 1 and j % 2 == 0 and a[i][j] % 2 == 0) or
                (i % 2 == 1 and j % 2 == 1 and a[i][j] % 2 == 1)):
                a[i][j] += 1
    for i in range(n):
        for j in range(m):
            print(a[i][j], end=' ')
        print()