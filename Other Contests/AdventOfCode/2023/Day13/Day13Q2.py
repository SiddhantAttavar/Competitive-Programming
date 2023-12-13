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

	return -1

res = 0
l = [list(map(list, i.splitlines())) for i in data.split('\n\n')]
for i in l:
	res += solve(i)
	# flag = False
	# for j in range(len(i)):
	# 	for k in range(len(i[j])):
	# 		i[j][k] = '.' if i[j][k] == '#' else '#'
	# 		x = solve(i)
	# 		if x != -1 and x != y:
	# 			print(x)
	# 			res += x
	# 			flag = True
	# 			break
	# 		i[j][k] = '.' if i[j][k] == '#' else '#'
	# 	if flag:
	# 		break

print(res)
submit(res, part = 'b', day = 13, year = 2023)
