from aocd import get_data, submit
data = get_data(day = 3, year = 2023).splitlines()
# data = '''467..114..
# ...*......
# ..35..633.
# ......#...
# 617*......
# .....+.58.
# ..592.....
# ......755.
# ...$.*....
# .664.598..'''.splitlines()
# data = open('input.txt').readlines()

data = [i + '.' for i in data]

n = len(data)
m = len(data[0])
q = [[-1] * m for _ in range(n)]
o = []
t = 0

for i in range(n):
	x = 0
	l = -1
	for j in range(m):
		if data[i][j].isdigit():
			if l == -1:
				l = j
			x = 10 * x + int(data[i][j])
		else:
			if l == -1:
				continue

			flag = False
			for a in range(max(0, i - 1), min(n - 1, i + 1) + 1):
				for b in range(max(0, l - 1), min(m - 1, j) + 1):
					if not data[a][b].isdigit() and data[a][b] != '.':
						flag = True
						break
				if flag:
					break
			
			if flag:
				o.append(x)
				for k in range(l, j):
					q[i][k] = t
				t += 1

			x = 0
			l = -1

# print(o)
# for i in range(n):
# 	print(*q[i])

res = 0
for i in range(n):
	for j in range(m):
		if data[i][j] != '*':
			continue

		s = set()
		for a in range(max(0, i - 1), min(n - 1, i + 1) + 1):
			for b in range(max(0, j - 1), min(m - 1, j + 1) + 1):
				s.add(q[a][b])
		if len(s) != 3:
			continue
		s.remove(-1)
		x, y = list(s)
		res += o[x] *o[y]

print(res)
submit(res, part = 'b', day = 3, year = 2023)
