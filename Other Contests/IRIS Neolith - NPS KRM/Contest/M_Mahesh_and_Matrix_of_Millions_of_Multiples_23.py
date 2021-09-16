n, m = map(int,input().split())
L = []
for i in range(n):
    L.append(list(map(int,input().split())))
f = 0
B = L.copy()
for i in range(n):
    for j in range(m):
        if (i + j) % 2:
            B[i][j] = 720720
            f = 1
        else:
            B[i][j] = (L[i][j] ** 4) + 720720
            f = 0
 
for i in B:
    for j in i:
        print (j, end = ' ')
    print()