from collections import defaultdict
from aocd import get_data, submit
data = get_data(day = 5, year = 2023).splitlines()
# data = '''seeds: 79 14 55 13
#
# seed-to-soil map:
# 50 98 2
# 52 50 48
#
# soil-to-fertilizer map:
# 0 15 37
# 37 52 2
# 39 0 15
#
# fertilizer-to-water map:
# 49 53 8
# 0 11 42
# 42 0 7
# 57 7 4
#
# water-to-light map:
# 88 18 7
# 18 25 70
#
# light-to-temperature map:
# 45 77 23
# 81 45 19
# 68 64 13
#
# temperature-to-humidity map:
# 0 69 1
# 1 0 69
#
# humidity-to-location map:
# 60 56 37
# 56 93 4'''.splitlines()

res = int(1e9)
graph = defaultdict(lambda: defaultdict(lambda: []))
l = map(int, data[0].split(':')[1].split())
s = ''
d = ''
for r in data[1:]:
	if not r:
		continue

	if '-' in r:
		s, _, d = r.split()[0].split('-')
		continue
	
	graph[s][d].append(list(map(int, r.split())))

for a, i in graph.items():
	for b, j in i.items():
		j.sort()
		# print(a, b, *j)

# print(graph)

def dfs(u, s, graph, vis):
	# print(u, s)
	vis.add(s)
	if s == 'location':
		return u

	for a, l in graph[s].items():
		if a in vis:
			continue

		for y, x, z in l:
			if x <= u and u < x + z:
				return dfs(y + (u - x), a, graph, vis)
		return dfs(u, a, graph, vis)

for i in l:
	v = set()
	res = min(res, dfs(i, 'seed', graph, v))

print(res)
# submit(res, part = 'a', day = 5, year = 2023)
