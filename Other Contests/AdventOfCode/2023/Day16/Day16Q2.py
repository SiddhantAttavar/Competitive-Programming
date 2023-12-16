from queue import Queue
from aocd import get_data, submit
data = get_data(day = 16, year = 2023).splitlines()
# data = r'''.|...\....
# |.-.\.....
# .....|-...
# ........|.
# ..........
# .........\
# ..../.\\..
# .-.-/..|..
# .|....-|.\
# ..//.|....'''.splitlines()

res = 0

# print(data)

n = len(data)
m = len(data[0])
d = [(0, 1), (0, -1), (1, 0), (-1, 0)]
l = [
	{'.': [0], '|': [2, 3], '-': [0], '\\': [2], '/': [3]},
	{'.': [1], '|': [2, 3], '-': [1], '\\': [3], '/': [2]},
	{'.': [2], '|': [2], '-': [0, 1], '\\': [0], '/': [1]},
	{'.': [3], '|': [3], '-': [0, 1], '\\': [1], '/': [0]},
]

s = []
for i in range(n):
	s.append(((i, 0), 0))
	s.append(((i, m - 1), 1))
for i in range(m):
	s.append(((0, i), 2))
	s.append(((n - 1, i), 3))

for (e, f), t in s:
	q = Queue()
	q.put(((e, f), t))
	v = [[[False] * 4 for _ in range(m)] for _ in range(n)]
	v[e][f][t] = True

	while not q.empty():
		(x, y), k = q.get()
		# print(x, y, k)

		for i in l[k][data[x][y]]:
			a, b = x + d[i][0], y + d[i][1]
			if a >= 0 and b >= 0 and a < n and b < m and not v[a][b][i]:
				v[a][b][i] = True
				q.put(((a, b), i))

	curr = 0
	for i in range(n):
		for j in range(m):
			for k in range(4):
				if v[i][j][k]:
					curr += 1
					break
	# print(e, f, t, curr)
	res = max(res, curr)

print(res)
# submit(res, part = 'b', day = 16, year = 2023)
