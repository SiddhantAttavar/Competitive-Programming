from aocd import get_data, submit
data = get_data(day = 11, year = 2021).splitlines()
# data = '''5483143223
# 2745854711
# 5264556173
# 6141336146
# 6357385478
# 4167524645
# 2176841721
# 6882881134
# 4846848554
# 5283751526'''.splitlines()

from queue import Queue
a = [list(map(int, i)) for i in data]
n = len(a)
m = len(a[0])
res = 1

while True:
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
		
		for x in range(max(0, i - 1), min(i + 2, n)):
			for y in range(max(0, j - 1), min(j + 2, m)):
				a[x][y] += 1
				if a[x][y] > 9 and not visited[x][y]:
					visited[x][y] = True
					q.put((x, y))
	
	flag = True
	for i in range(n):
		for j in range(m):
			if visited[i][j]:
				a[i][j] = 0
			else:
				flag = False
	
	if flag:
		# submit(res, part = 'b', day = 11, year = 2021)
		break

	res += 1
