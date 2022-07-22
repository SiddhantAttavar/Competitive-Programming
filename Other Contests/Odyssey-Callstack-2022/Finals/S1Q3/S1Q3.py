def get(x):
	if a[x] < 0:
		return x
	a[x] = get(a[x])
	return a[x]

def unite(x, y):
	x = get(x)
	y = get(y)
	
	if x == y:
		return False
	
	if a[x] < a[y]:
		x, y = y, x
	
	a[x] += a[y]
	a[y] = x
	return True

n, m = map(int, input().split())
a = [-1] * n
graph = [[False] * n for _ in range(n)]
for i in range(n):
	graph[i][i] = True
	
for _ in range(m):
	u, v = map(int, input().split())
	u -= 1
	v -= 1
	graph[u][v] = True
	graph[v][u] = True

l = list(map(int, input().split()))
for i in range(n):
	l[i] -= 1

s = set()
res = []
for i in l[::-1]:
	for j in range(n):
		if graph[i][j] and j in s:
			unite(i, j)
	if len(s) == 0:
		res.append(1)
	else:
		flag = False
		for j in s:
			if get(j) != get(i):
				res.append(0)
				break
		else:
			res.append(1)	
	s.add(i)
for i in res[::-1]:
	print(i)
