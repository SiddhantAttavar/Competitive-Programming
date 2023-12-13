from aocd import get_data, submit
data = get_data(day = 13, year = 2023)
# data = '''#.##..##.
# ..#.##.#.
# ##......#
# ##......#
# ..#.##.#.
# ..##..##.
# #.#.##.#.
#
# #...##..#
# #....#..#
# ..##..###
# #####.##.
# #####.##.
# ..##..###
# #....#..#'''

def solve(a):
	# print(a)
	n = len(a)
	m = len(a[0])

	for j in range(m - 1):
		c = 0
		for i in range(n):
			l = j
			r = j + 1
			while l >= 0 and r < m:
				# print(n, m, len(a[i]), l, r)
				if a[i][l] != a[i][r]:
					c += 1
				l -= 1
				r += 1
		if c == 1:
			return j + 1
	
	for i in range(n - 1):
		c = 0
		for j in range(m):
			l = i
			r = i + 1
			while l >= 0 and r < n:
				if a[l][j] != a[r][j]:
					c += 1
				l -= 1
				r += 1
		if c == 1:
			return 100 * (i + 1)

	return 0

res = 0
l = [i.splitlines() for i in data.split('\n\n')]
for i in l:
	res += solve(i)

print(res)
# submit(res, part = 'a', day = 13, year = 2023)
