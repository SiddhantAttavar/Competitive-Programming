from aocd import get_data, submit
data = get_data(day = 8, year = 2023).splitlines()
# data = '''RL
#
# AAA = (BBB, CCC)
# BBB = (DDD, EEE)
# CCC = (ZZZ, GGG)
# DDD = (DDD, DDD)
# EEE = (EEE, EEE)
# GGG = (GGG, GGG)
# ZZZ = (ZZZ, ZZZ)'''.splitlines()
# data = '''LLR
#
# AAA = (BBB, BBB)
# BBB = (AAA, ZZZ)
# ZZZ = (ZZZ, ZZZ)'''.splitlines()

res = 0
d = {}
s = data[0]
for r in data[2:]:
	x, _, y, z = r.split()
	# print(x, y[1:-1], z[:-1])
	d[x] = (y[1:-1], z[:-1])

u = 'AAA'
i = 0
while u != 'ZZZ':
	u = d[u]['LR'.index(s[i])]
	i = (i + 1) % len(s)
	res += 1

print(res)
submit(res, part = 'a', day = 8, year = 2023)
