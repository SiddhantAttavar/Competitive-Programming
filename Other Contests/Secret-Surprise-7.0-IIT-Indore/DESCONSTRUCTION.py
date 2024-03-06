n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
b = [list(map(int, input().split())) for _ in range(n)]

for i in range(n - 1):
	for j in range(m - 1):
		x = b[i][j] - a[i][j]
		a[i][j] += x
		a[i + 1][j] += x
		a[i][j + 1] += x
		a[i + 1][j + 1] += x

flag = True
for j in range(m):
	if a[n - 1][j] != b[n - 1][j]:
		flag = False
		break

for i in range(n - 1):
	if a[i][m - 1] != b[i][m - 1]:
		flag = False
		break

if flag:
	print('YES')
else:
	print('NO')
	
