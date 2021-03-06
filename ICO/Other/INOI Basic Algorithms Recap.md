# INOI Basic Algorithms Recap

## INOI Problems:
Graph: 6
DP: 11
Greedy: 1

## Graph:
 - DFS
```python
def dfs(u):
	visited[u] = true
	for v in graph[u]:
		if (!visited[v]):
			dfs(v)
```

 - BFS
```python
q = {s}
visited[s] = true
while !q.empty():
	u = q.pop()
	for v in graph[u]:
		if !visited[v]:
			visited[v] = true
			q.push(v)
```

 - Dijkstra
```python
dist = [INF] * n
dist[s] = 0
pq = dist
while !pq.empty():
	d, u = pq.pop()
	for v, w : graph[u]:
		if dist[u] + w < dist[v]:
			dist[v] = dist[u] + w
			pq.push(dist[v], v)
```

 - Flloyd Warshal Algorithm
```python
cost = [[INF] * n] * n
for u, v, w in edges:
	cost[u][v] = w
for i in [0, n):
	cost[i][i] = 0
for k in [0, n):
	for i in [0, n):
		for j in [0, n):
			cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j])
```

 - Bellman Ford Algorithm
```python
dist = [INF] * n
dist[s]
for i in [0, n - 1):
	for u, v, w in edges:
		dist[v] = min(dist[v], dist[u] + w)
```

 - Strongly Connected Components
```python
# topologically sort graph
graph = graph.transpose()
visited = [False] * n
for i in topoSort:
	if !visited[i]:
		scc.push_back(new SCC)
		dfs(i) # All reachable vertices are in the SCC
```

## Dynamic Programming:
 - First try to find a greedy solution
 - If there is not obvious solution
 - Check the constraints, if it allows O(n^2)  or O(n^3)
 - Then it is likely to be DP
 - Find which state represents the subproblem  best
 - Create the recurrence relation
 - Find out the order of filling in the DP table
 - Types:
	- dp[prefix]
	- dp[suffix]
	- dp[left][right]
	- dp[bitmask]

## Greedy:
 - Think of intuitive solution
 - Try to prove why it works
 - If not try to create counter examples
 - Check constraints
 - If it only allows O(n) and O(nlogn) solution
 - Then it is likely to be greedy
