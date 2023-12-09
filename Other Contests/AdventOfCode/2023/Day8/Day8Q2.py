from math import lcm
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
# data = '''LR
#
# 11A = (11B, XXX)
# 11B = (XXX, 11Z)
# 11Z = (11B, XXX)
# 22A = (22B, XXX)
# 22B = (22C, 22C)
# 22C = (22Z, 22Z)
# 22Z = (22B, 22B)
# XXX = (XXX, XXX)'''.splitlines()

res = 0
d = {}
s = data[0]
for r in data[2:]:
	x, _, y, z = r.split()
	# print(x, y[1:-1], z[:-1])
	d[x] = (y[1:-1], z[:-1])
# print(len(d))

# u = 'AAA'
# l = list(d.keys())
# o = l.copy()
# x = {i: [] for i in d}
# for i in s:
# 	# if res < 10:
# 	# 	print(i, res, l)
# 	for j, u in enumerate(l):
# 		l[j] = d[u]['LR'.index(i)]
# 		x[o[j]].append(l[j])
	# print(len(l), res)

# print(x)
# v = {i: [j for j, r in enumerate(x[i]) if r[-1] == 'Z'] for i in x}
q = [i for i in d if i[-1] == 'A']
l = []
for u in q:
	x = 0
	i = 0
	while u[-1] != 'Z':
		u = d[u]['LR'.index(s[i])]
		i = (i + 1) % len(s)
		x += 1
	l.append(x)
res = lcm(*l)
# while True:
# 	# print(len(q), res)
# 	g = set(v[q[0]])
# 	for i, r in enumerate(q):
# 		g.intersection_update(v[r])
# 		q[i] = x[r][-1]
# 	q = list(set(q))
# 	if len(g):
# 		res += list(g)[0] + 1
# 		break
#
# 	res += len(s)

print(res)
submit(res, part = 'b', day = 8, year = 2023)
