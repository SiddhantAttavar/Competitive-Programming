from aocd import get_data, submit
data = get_data(day = 15, year = 2021).splitlines()
# data = '''1163751742
# 1381373672
# 2136511328
# 3694931569
# 7463417111
# 1319128137
# 1359912421
# 3125421639
# 1293138521
# 2311944581'''.splitlines()

from queue import PriorityQueue

mat = [list(map(int, i)) for i in data]
l = [[0] * (5 * len(mat[0])) for _ in range(5 * len(mat))]

for i in range(5):
	for j in range(5):
		for x in range(len(mat)):
			for y in range(len(mat[0])):
				l[i * len(mat) + x][j * len(mat[0]) + y] = (mat[x][y] + i + j - 1) % 9 + 1

n = len(l)
m = len(l[0])	

dist = [[int(1e9)] * m for _ in range(n)]
pq = PriorityQueue()
dist[0][0] = 0
pq.put((0, 0, 0))
res = 0

while not pq.empty():
	d, x, y = pq.get()

	if x == n - 1 and y == m - 1:
		res = d
		break
		
	for i, j in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]:
		if i >= 0 and i < n and j >= 0 and j < m and dist[i][j] > d + l[i][j]:
			dist[i][j] = d + l[i][j]
			pq.put((dist[i][j], i, j))

# print(res)
submit(res, part = 'b', day = 15, year = 2021)
