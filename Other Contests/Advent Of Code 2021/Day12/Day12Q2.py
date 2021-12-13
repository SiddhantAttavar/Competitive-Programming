from aocd import get_data, submit
data = get_data(day = 12, year = 2021).splitlines()

from sys import setrecursionlimit
setrecursionlimit(int(1e9))

graph = {}
edges = []

for l in data:
	u, v = l.split('-')
	if u not in graph:
		graph[u] = []
	if v not in graph:
		graph[v] = []
	
	graph[u].append(v)
	graph[v].append(u)

	edges.append((u, v))

res = 0
n = len(graph)
nodes = list(graph.keys())
for i in range(1 << n):
	s = set()
	for j in range(n):
		if i & (1 << j):
			s.add(nodes[j])
	
	for u, v in edges:
		if u in s and v in s:
			break
	else:
		res += 1

print(res)
# submit(res, part = 'b', day = 12, year = 2021)
