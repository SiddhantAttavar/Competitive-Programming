from aocd import get_data, submit
data = get_data(day = 11, year = 2023).splitlines()
# data = '''...#......
# .......#..
# #.........
# ..........
# ......#...
# .#........
# .........#
# ..........
# .......#..
# #...#.....'''.splitlines()

res = 0
h = []
v = []
n = len(data)
m = len(data[0])
for i in range(n):
	if data[i] == '.' * m:
		h.append(i)
for j in range(m):
	for i in range(n):
		if data[i][j] != '.':
			break
	else:
		v.append(j)

# print(*data, sep = '\n')
# print(h, v)
# print(len(data), len(data[0]))

l = []
for i in range(n):
	for j in range(m):
		if data[i][j] == '#':
			l.append((i, j))

res = 0
for x, y in l:
	for a, b in l:
		p = 0
		for i in h:
			p += (a <= i and i < x) or (x <= i and i < a)
		q = 0
		for j in v:
			q += (b <= j and j < y) or (y <= j and j < b)
		res += abs(a - x) + abs(b - y) + 999999 * (p + q)

res //= 2
print(res)
# submit(res, part = 'b', day = 11, year = 2023)
