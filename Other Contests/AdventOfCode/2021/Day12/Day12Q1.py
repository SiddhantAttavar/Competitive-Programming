from aocd import get_data, submit
data = get_data(day = 12, year = 2021).splitlines()
# data = '''start-A
# start-b
# A-c
# A-b
# b-d
# A-end
# b-end'''.splitlines()

from sys import setrecursionlimit
setrecursionlimit(int(1e9))

def dfs(u):
	global res
	if u == 'end':
		res += 1
	
	visited[u] = True
	for v in graph[u]:
		if not visited[v] or v.isupper():
			dfs(v)
	
	visited[u] = False

graph = {}

for l in data:
	u, v = l.split('-')
	if u not in graph:
		graph[u] = []
	if v not in graph:
		graph[v] = []
	graph[u].append(v)
	graph[v].append(u)

visited = {i: False for i in graph.keys()}
visited['start'] = True
res = 0
dfs('start')

print(res)
# submit(res, part = 'a', day = 12, year = 2021)
