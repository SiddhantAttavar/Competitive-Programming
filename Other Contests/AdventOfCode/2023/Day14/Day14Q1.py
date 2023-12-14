from aocd import get_data, submit
data = get_data(day = 14, year = 2023).splitlines()
# data = '''O....#....
# O.OO#....#
# .....##...
# OO.#O....O
# .O.....O#.
# O.#..O.#.#
# ..O..#O..O
# .......O..
# #....###..
# #OO..#....'''.splitlines()

res = 0
n = len(data)
m = len(data[0])
for j in range(m):
	c = 0
	y = n
	for i in range(n):
		if data[i][j] == 'O':
			res += y
			y -= 1
		elif data[i][j] == '#':
			y = n - i - 1

print(res)
submit(res, part = 'a', day = 14, year = 2023)
