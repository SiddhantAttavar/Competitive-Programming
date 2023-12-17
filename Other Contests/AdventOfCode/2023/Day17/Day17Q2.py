from queue import PriorityQueue
from aocd import get_data, submit
data = get_data(day = 17, year = 2023).splitlines()
# data = '''2413432311323
# 3215453535623
# 3255245654254
# 3446585845452
# 4546657867536
# 1438598798454
# 4457876987766
# 3637877979653
# 4654967986887
# 4564679986453
# 1224686865563
# 2546548887735
# 4322674655533'''.splitlines()
# data = '''111111111111
# 999999999991
# 999999999991
# 999999999991
# 999999999991'''.splitlines()

res = 0
data = [list(map(int, i)) for i in data]
n = len(data)
m = len(data[0])
d = [[[int(1e9)] * 4 for _ in range(m)] for _ in range(n)]
l = [(0, 1), (0, -1), (1, 0), (-1, 0)]
pq = PriorityQueue()
pq.put((0, 0, 0, 0))
pq.put((0, 0, 0, 2))
d[0][0][0] = 0
d[0][0][2] = 0

while not pq.empty():
	x, i, j, k = pq.get()
	# print(x, i, j, k)

	if d[i][j][k] != x:
		continue

	v = [2, 3] if k <= 1 else [0, 1]
	for o in v:
		p, q = i, j
		c = 0
		for _ in range(3):
			p, q = (p + l[o][0], q + l[o][1])
			if p < 0 or q < 0 or p >= n or q >= m:
				break
			c += data[p][q]
		for _ in range(7):
			p, q = (p + l[o][0], q + l[o][1])
			if p < 0 or q < 0 or p >= n or q >= m:
				break
			c += data[p][q]
			if d[p][q][o] > (d[i][j][k] + c):
				d[p][q][o] = d[i][j][k] + c
				pq.put((d[p][q][o], p, q, o))

# for i in range(n):
# 	for j in range(m):
# 		print(i, j, *d[i][j])

res = min(d[n - 1][m - 1])
print(res)
submit(res, part = 'b', day = 17, year = 2023)
