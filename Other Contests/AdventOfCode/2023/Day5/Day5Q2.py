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
l = list(map(int, data[0].split(':')[1].split()))
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
		j.sort(key = lambda x: x[1])
		# print(a, b, *j)

# print(graph)

def dfs(u, l, s, graph):
	# print(u, l, s)
	if s == 'location':
		return u

	a, o = list(graph[s].items())[0]
	# print(a, o)
	for y, x, z in o:
		# print(u, l, y, x)
		if x <= u and u + l - 1 < x + z:
			return dfs(y + (u - x), l, a, graph)
		elif x <= u and u < x + z:
			return min(dfs(y + (u - x), x + z - u, a, graph), dfs(x + z, l - (x + z - u), s, graph))
		elif x < u + l and u + l - 1 < x + z:
			return min(dfs(u, x - u, s, graph), dfs(y + (x - u), l - (x - u), a, graph))
	# print('debug', u, l, s, graph[s].values())
	return dfs(u, l, a, graph)

for i in range(0, len(l), 2):
	v = set()
	res = min(res, dfs(l[i], l[i + 1], 'seed', graph))

print(res)
submit(res, part = 'b', day = 5, year = 2023)
