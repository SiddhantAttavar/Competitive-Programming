import numpy as np
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

def printMat(data):
	for i in data:
		for j in i:
			print('O.#'[j], end = '')
		print()
	print()

d = {'O': 0, '.': 1, '#': 2}
data = list(map(lambda x: [d[i] for i in x], data))
data = np.asarray(data)
# for i in data:print(*i)

def next_cycle(data):
	n = len(data)
	m = len(data[0])
	for _ in range(4):
		for j in range(m):
			y = 0
			for i in range(n):
				if data[i][j] == 0:
					data[i][j], data[y][j] = data[y][j], data[i][j]
					y += 1
				elif data[i][j] == 2:
					y = i + 1 
		data = np.rot90(data, k = 3)

t = 0
time = {}
states = []
fin = ''

def dfs(u, x):
	global fin
	k = '\n'.join([''.join(map(str, i)) for i in u])
	# print(k)
	# print()
	if k in time:
		cycle_size = x - time[k]
		rem = (1000000000 - time[k]) % cycle_size
		print(cycle_size, time[k], rem)
		fin = states[time[k] + rem]
		return

	time[k] = len(states)
	states.append(k)
	next_cycle(u)
	dfs(u, x + 1)

dfs(data, 0)
print(fin)

# slow = np.copy(data)
# fast = np.copy(data)
# next_cycle(fast)
# while (slow != fast).any():
# 	next_cycle(slow)
# 	next_cycle(fast)
# 	next_cycle(fast)
# 	# printMat(slow)
# 	# printMat(fast)
# 	# print()
#
# x = 1000000000
# u = np.copy(data)
# while (u != slow).any():
# 	next_cycle(u)
# 	x -= 1
#
# y = 1
# next_cycle(u)
# while (u != slow).any():
# 	next_cycle(u)
# 	y += 1
#
# print(x, y)
#
# for i in range(x % y):
# 	next_cycle(u)
# printMat(u)

# res = 0
# old_data = np.zeros(data.shape)
# i = 0
# while (old_data != data).any():
# 	old_data = np.copy(data)
# 	next_cycle(data)
# 	print(i)
# 	i += 1
# 	if i == 1000000000:
# 		break
# 	# printMat(data)
# 	# break

# printMat(data)
# data = np.rot90(data, k = 3)
# printMat(data)

fin = fin.splitlines()
n = len(fin)
m = len(fin[0])
print()
print(n, m)
res = 0
for i in range(n):
	for j in range(m):
		if fin[i][j] == '0':
			res += n - i

print(res)
submit(res, part = 'b', day = 14, year = 2023)
