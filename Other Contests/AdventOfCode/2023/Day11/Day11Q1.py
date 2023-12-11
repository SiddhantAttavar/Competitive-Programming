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
n = len(data)
m = len(data[0])
for i in range(n):
	if data[i] == '.' * m:
		h.append(i)
for i in reversed(h):
	data.insert(i, '.' * m)
n += len(h)
v = []
for j in range(m):
	for i in range(n):
		if data[i][j] != '.':
			break
	else:
		v.append(j)
for j in reversed(v):
	for i in range(n):
		# print(j, ''.join(data[i][:j]) + '.' + ''.join(data[i][j:]))
		data[i] = ''.join(data[i][:j]) + '.' + ''.join(data[i][j:])

# print(*data, sep = '\n')
# print(h, v)
m += len(v)
# print(len(data), len(data[0]))

l = []
for i in range(n):
	for j in range(m):
		if data[i][j] == '#':
			l.append((i, j))

res = 0
for x, y in l:
	for a, b in l:
		res += abs(a - x) + abs(b - y)

res //= 2
print(res)
# submit(res, part = 'a', day = 11, year = 2023)
