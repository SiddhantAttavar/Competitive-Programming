from aocd import get_data, submit
data = get_data(day = 12, year = 2021).splitlines()

from sys import setrecursionlimit
setrecursionlimit(int(1e9))

def dfs(u, b):
	global res
	if u == 'end':
		res += 1
		return
	
	visited[u] += 1

	for v in graph[u]:
		if v.isupper():
			dfs(v, b)
		elif visited[v] == 0:
			dfs(v, b)
		elif visited[v] == 1 and not b:
			dfs(v, True)
	
	visited[u] -= 1

graph = {}

for l in data:
	u, v = l.split('-')
	if u not in graph:
		graph[u] = []
	if v not in graph:
		graph[v] = []
	
	graph[u].append(v)
	graph[v].append(u)

visited = {i: 0 for i in graph.keys()}
visited['start'] = 2
res = 0
dfs('start', False)

print(res)
# submit(res, part = 'b', day = 12, year = 2021)
