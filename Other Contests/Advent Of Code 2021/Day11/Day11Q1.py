from aocd import get_data, submit
data = get_data(day = 11, year = 2021).splitlines()

from queue import Queue
a = [list(map(int, i)) for i in data]
n = len(a)
m = len(a[0])
res = 0

for _ in range(100):
	q = Queue()
	visited = [[False] * m for _ in range(n)]

	for i in range(n):
		for j in range(m):
			a[i][j] += 1
			if a[i][j] > 9:
				visited[i][j] = True
				q.put((i, j))

	while not q.empty():
		i, j = q.get()
		res += 1
		
		for x in range(max(0, i - 1), min(i + 2, n)):
			for y in range(max(0, j - 1), min(j + 2, m)):
				a[x][y] += 1
				if a[x][y] > 9 and not visited[x][y]:
					visited[x][y] = True
					q.put((x, y))
	
	for i in range(n):
		for j in range(m):
			if visited[i][j]:
				a[i][j] = 0

print(res)
# submit(res, part = 'a', day = 11, year = 2021)
